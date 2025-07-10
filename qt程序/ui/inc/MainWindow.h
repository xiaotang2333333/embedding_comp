#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QFile>
#include <QThread>
#include <QtCharts/QLineSeries>
#include "ui_qtccm.h"
#include "MvCameraControl.h"
#include "ImageAcquisitionWorker.h"
#include "GslInterp.h"
#include "Dm542Controller.h"

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>

QT_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_END_NAMESPACE

namespace QtDataVisualization
{
    class Q3DSurface;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MV_CC_DEVICE_INFO *selectedDevice;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateImage(const QImage &image);
    void onPwmComplete(const AXIS &whatAmI);
    void onPwmTrig(int trigStat, const AXIS &whatAmI);
    void updateChartImage(const double dataPoints);
    void on_btnFindDevice_clicked();
    void on_btnConnectDevice_clicked();
    void on_comboDeviceList_currentIndexChanged(int index);
    void on_leGain_editingFinished();
    void on_leExposureTime_editingFinished();
    void on_leSThreshold_editingFinished();
    void on_leVThreshold_editingFinished();
    void on_chkAutoExposure_toggled(bool checked);
    void on_spinRedBalance_R_valueChanged(int value);
    void on_spinGreenBalance_G_valueChanged(int value);
    void on_spinBlueBalance_B_valueChanged(int value);
    void on_chkAutoGain_toggled(bool checked);
    void on_btnSnapshot_clicked();
    void on_btnReset_clicked();
    void on_chkMotorEnable_X_toggled(bool checked);
    void on_chkMotorEnable_Y_toggled(bool checked);
    void on_chkMotorEnable_Z_toggled(bool checked);
    void on_spinPeriod_X_valueChanged(int value);
    void on_spinPeriod_Y_valueChanged(int value);
    void on_spinPeriod_Z_valueChanged(int value);
    void on_btnStartMotor_X_clicked();
    void on_btnStartMotor_Y_clicked();
    void on_btnStartMotor_Z_clicked();
    void on_btnAutoRun_clicked();

private:
    Ui::MainWindow *ui;
    QFile logFile;
    MV_CC_DEVICE_INFO_LIST camList;
    void *camHandle;
    Dm542Controller *dm542ControllerX, *dm542ControllerY, *dm542ControllerZ;
    QThread *imageThread;
    ImageAcquisitionWorker *imageWorker;
    GslInterp *gslInterp;
    bool isAutoRunning = false;
    QString currentRunDir, autoRunDataDir;
    void saveValueToFile(const float x,const float y,const double hue = 0.0f);
    void executeNextStep();
    QGraphicsPixmapItem *imageItem = nullptr;
    QWidget *surfaceContainer = nullptr;
    typedef struct
    {
        int currentPulses;
        int totalPulses;
        int stepPulses;
        int currentStep;
    } AutoRunData;

    double resetHue = 0.0f, nowHue = 0.0f, resetMovement = 0.0f, nowMovement = 0.0f;
    AutoRunData autoRunDataX, autoRunDataY, autoRunDataZ;

    void setup3DSurfaceInWidget();
    void cleanup3DSurface(); // 添加3D图表清理函数
    Q3DSurface *surfaceGraph = nullptr;
    QSurfaceDataProxy *surfaceProxy = nullptr;
    QSurface3DSeries *surfaceSeries = nullptr;
    QSurfaceDataArray *surfaceDataArray = nullptr;
    int surfaceRows = 0;   // 网格行数
    int surfaceColumns = 0; // 网格列数

    void resetSurfaceDataProxy(); // 重置数据代理

    void initMotorController(const QString &MotorX = "/sys/devices/platform/dm542-x",
                             const QString &MotorY = "/sys/devices/platform/dm542-y",
                             const QString &MotorZ = "/sys/devices/platform/dm542-z");
};

#endif // MAINWINDOW_H