#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/QValue3DAxis>
#include "MainWindow.h"
#include <QRandomGenerator>
#include <QToolTip>
#include <QCursor>
#include <QElapsedTimer>
#include <QDateTime>
#include <QDir>
#include <QMessageBox>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::MainWindow),
      imageThread(new QThread(this)),
      imageWorker(new ImageAcquisitionWorker)
{
    MV_CC_Initialize(); // 初始化 MvCameraControl 库
    ui->setupUi(this);  // 设置 UI
    autoRunDataDir = QApplication::applicationDirPath() + "/autorun_data";
    QDir().mkpath(autoRunDataDir);
    // 初始化图像采集线程
    imageWorker->moveToThread(imageThread);
    connect(imageThread, &QThread::finished, imageWorker, &QObject::deleteLater);
    connect(imageWorker, &ImageAcquisitionWorker::snapshotImage,
            this, &MainWindow::updateImage, Qt::QueuedConnection);
    connect(imageWorker, &ImageAcquisitionWorker::snapshotColorChart, this, &MainWindow::updateChartImage);
    connect(imageWorker, &ImageAcquisitionWorker::snapshotError, this, [this](const QString &error)
            { qDebug() << "Snapshot error:" << error; });
    connect(imageWorker, &ImageAcquisitionWorker::snapshotFinished, this, [this]()
            {
        if (isAutoRunning) {
            qDebug() << "snapshot completed";
            return;
        }
        ui->btnSnapshot->setEnabled(true); });
    imageThread->start();
    gslInterp = new GslInterp(QApplication::applicationDirPath() + "/data.csv", this); // 初始化GSL插值对象
    initMotorController();
    setup3DSurfaceInWidget(); // 设置图表                                                        // 初始化电机控制器
}
void MainWindow::updateImage(const QImage &image)
{
    QGraphicsScene *scene = ui->graphicsView->scene();
    if (!scene)
    {
        scene = new QGraphicsScene(ui->graphicsView);
        ui->graphicsView->setScene(scene);
    }
    if (imageItem)
    {
        scene->removeItem(imageItem); // 从场景中移除
        delete imageItem;             // 显式删除旧的 QGraphicsPixmapItem
        imageItem = nullptr;          // 将指针置空，避免悬空指针
    }

    imageItem = new QGraphicsPixmapItem();
    imageItem->setTransformationMode(Qt::SmoothTransformation);
    scene->addItem(imageItem); // 将新的 item 添加到场景
    imageItem->setPixmap(QPixmap::fromImage(image));
    ui->graphicsView->fitInView(imageItem, Qt::KeepAspectRatio);
}

void MainWindow::updateChartImage(const double dataPoints)
{
    if (dataPoints < 0)
    {
        qDebug() << "Invalid data point received for chart update";
        return;
    }
    nowHue = dataPoints;
    nowMovement = gslInterp->interpolate(nowHue);
    if (isAutoRunning)
    {

        // 确保 surfaceDataArray, autoRunDataY, autoRunDataX, surfaceProxy, surfaceRows, surfaceColumns 都已正确初始化
        // 并且它们是类成员变量
        if (surfaceDataArray && surfaceProxy &&
            autoRunDataY.currentStep < surfaceRows && autoRunDataX.currentStep < surfaceColumns)
        {
            QSurfaceDataRow *row = surfaceDataArray->at(autoRunDataY.currentStep);
            int j_actual;
            if (autoRunDataY.currentStep % 2 == 0)
            {
                j_actual = autoRunDataX.currentStep;
            }
            else
            {
                j_actual = surfaceColumns - 1 - autoRunDataX.currentStep; // 奇数行反转
            }
            QSurfaceDataItem &item = (*row)[j_actual];
            item.setX(static_cast<float>(j_actual));                 // 设置X轴值为当前色调数据点
            item.setY(static_cast<float>(resetMovement-nowMovement));               // 设置Y轴值为当前色调数据点
            item.setZ(static_cast<float>(autoRunDataY.currentStep)); // 设置Z轴值为当前色调数据点
            surfaceProxy->setItem(autoRunDataY.currentStep, j_actual, item);
            saveValueToFile(static_cast<float>(j_actual), static_cast<float>(autoRunDataY.currentStep), nowHue);
        }
        else
        {
            qDebug() << "3D chart update conditions not met or pointers invalid.";
        }
        executeNextStep();
        return;
    }
    ui->lblDistance->setText(QString("Current Movement: %1mm").arg(resetMovement-nowMovement, 0, 'f', 3));
}
MainWindow::~MainWindow()
{
    // 停止并清理图像采集线程
    if (imageThread)
    {
        imageThread->quit();
        imageThread->wait();
        delete imageThread;
    }

    // 释放相机资源 (如果已连接)
    if (camHandle != nullptr)
    {
        MV_CC_CloseDevice(camHandle);
        MV_CC_DestroyHandle(camHandle);
        camHandle = nullptr;
    }

    MV_CC_Finalize(); // 释放 MvCameraControl 库资源
    if (dm542ControllerX)
        delete dm542ControllerX; // 删除 X 轴电机控制器对象
    if (dm542ControllerY)
        delete dm542ControllerY; // 删除 Y 轴电机控制器对象
    if (dm542ControllerZ)
        delete dm542ControllerZ; // 删除 Z 轴电机控制器对象
    delete gslInterp;            // 删除 GSL 插值对象
    delete ui;                   // 删除 UI 对象
}
void MainWindow::saveValueToFile(const float x, const float y, const double hue)
{

    if (!isAutoRunning)
        return;

    QString dataFileName = QString("%1/data_points.csv").arg(currentRunDir); // 更通用地命名文件
    QFile dataFile(dataFileName);

    if (dataFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&dataFile);

        // 如果文件为空，先写入表头
        if (dataFile.size() == 0)
        {
            out << "X,Y,Value\n"; // 更新表头
        }

        // 写入当前步骤的 f(x,y) 数据
        // f_xy_value 通常是一个 double 类型，用 'f' 格式化可以控制精度
        out << QString::number(x, 'f', 2) << ","     // 写入 X 坐标
            << QString::number(y, 'f', 2) << ","     // 写入 Y 坐标
            << QString::number(hue, 'f', 4) << "\n"; // 写入 f(x,y) 值

        dataFile.close();
        qDebug() << "Data point (x,y,f(x,y)) [" << autoRunDataX.currentStep << "," << autoRunDataY.currentStep << "," << hue << "] saved to:" << dataFileName;
    }
    else
    {
        qDebug() << "Failed to open data file:" << dataFileName;
    }
}
void MainWindow::on_btnReset_clicked()
{
    resetHue = nowHue; // 保存当前色调
    resetMovement = nowMovement;
    ui->lblDistance->setText(QString("Distance: 0mm"));
}
void MainWindow::cleanup3DSurface()
{
    if (surfaceContainer)
    {
        // 从布局中移除 widget
        ui->verticalLayout_Q3D->removeWidget(surfaceContainer);
        delete surfaceContainer;
        surfaceContainer = nullptr;
    }

    surfaceGraph = nullptr;
    surfaceProxy = nullptr;
    surfaceSeries = nullptr;
    surfaceDataArray = nullptr;
}

void MainWindow::setup3DSurfaceInWidget()
{
    cleanup3DSurface(); // 确保清理旧的3D曲面实例

    surfaceGraph = new Q3DSurface();
    surfaceContainer = QWidget::createWindowContainer(surfaceGraph, ui->Q3dContainerWidget);

    // 确保 surfaceContainer 被添加到布局中
    // 假设 ui->verticalLayout_Q3D 是 Q3dContainerWidget 的布局
    if (ui->verticalLayout_Q3D->count() == 0) { // 避免重复添加
        ui->verticalLayout_Q3D->addWidget(surfaceContainer);
    } 
    // --- 1. 配置轴 (Axes) ---
    // 形貌图通常需要更具体的轴标签和范围
    QValue3DAxis *axisX = new QValue3DAxis;
    axisX->setTitle("X"); // 根据你的数据，可以改为“列索引”或“宽度”
    axisX->setTitleVisible(true);
    surfaceGraph->setAxisX(axisX); // 设置X轴

    QValue3DAxis *axisY = new QValue3DAxis;
    axisY->setTitle("Z"); // 形貌图的关键，表示高度或强度值
    axisY->setTitleVisible(true);
    surfaceGraph->setAxisY(axisY); // 设置Y轴（高度）

    QValue3DAxis *axisZ = new QValue3DAxis;
    axisZ->setTitle("Y"); // 根据你的数据，可以改为“行索引”或“深度”
    axisZ->setTitleVisible(true);
    surfaceGraph->setAxisZ(axisZ); // 设置Z轴


    // --- 2. 配置数据代理和系列 ---
    surfaceProxy = new QSurfaceDataProxy();
    surfaceSeries = new QSurface3DSeries(surfaceProxy);
    surfaceGraph->addSeries(surfaceSeries); // 将系列添加到图表

    // --- 3. 配置曲面样式 (Surface Style) ---
    // 形貌图通常需要颜色渐变来表示高度
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::darkBlue);   // 最低点颜色
    gr.setColorAt(0.2, Qt::blue);
    gr.setColorAt(0.4, Qt::green);
    gr.setColorAt(0.6, Qt::yellow);
    gr.setColorAt(0.8, Qt::red);
    gr.setColorAt(1.0, Qt::darkRed);    // 最高点颜色
    surfaceSeries->setBaseGradient(gr); // 应用渐变
    surfaceSeries->setColorStyle(Q3DTheme::ColorStyleRangeGradient); // 启用范围渐变着色


    surfaceSeries->setMeshSmooth(true); 

    // 绘制模式：同时显示曲面和线框，可以更好地看清结构
    surfaceSeries->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);

    surfaceGraph->activeTheme()->setType(Q3DTheme::ThemeQt); // Qt默认主题通常视觉效果不错

    surfaceGraph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFrontLow);
    resetSurfaceDataProxy();
}

void MainWindow::resetSurfaceDataProxy()
{
    if (!surfaceProxy)
        return;

    // 创建新的数据数组
    QSurfaceDataArray *newDataArray = new QSurfaceDataArray;
    newDataArray->reserve(surfaceRows);
    for (int i = 0; i < surfaceRows; i++)
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(surfaceColumns);
        for (int j = 0; j < surfaceColumns; j++)
        {
            (*newRow)[j].setPosition(QVector3D(static_cast<float>(j), 0.0f, static_cast<float>(i))); // X=列索引，Y=行索引，Z=强度值(初始为0)
        }
        newDataArray->append(newRow);
    }

    // 将新数据设置到代理。代理会自动删除之前拥有的旧数据数组。
    surfaceProxy->resetArray(newDataArray);
    surfaceDataArray = newDataArray;
}