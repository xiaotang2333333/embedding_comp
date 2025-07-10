#include "MainWindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDir>
void MainWindow::initMotorController(const QString &MotorX,
                                     const QString &MotorY,
                                     const QString &MotorZ)
{
    // 初始化电机控制器
    dm542ControllerX = new Dm542Controller(this, MotorX, X_AXIS);
    dm542ControllerY = new Dm542Controller(this, MotorY, Y_AXIS);
    dm542ControllerZ = new Dm542Controller(this, MotorZ, Z_AXIS);

    // connect(dm542ControllerX, &Dm542Controller::swTrig, this, &MainWindow::onPwmTrig);
    // connect(dm542ControllerY, &Dm542Controller::swTrig, this, &MainWindow::onPwmTrig);
    // connect(dm542ControllerZ, &Dm542Controller::swTrig, this, &MainWindow::onPwmTrig);

    connect(dm542ControllerX, &Dm542Controller::pwmComplete, this, &MainWindow::onPwmComplete);
    connect(dm542ControllerY, &Dm542Controller::pwmComplete, this, &MainWindow::onPwmComplete);
    connect(dm542ControllerZ, &Dm542Controller::pwmComplete, this, &MainWindow::onPwmComplete);

    ui->spinPeriod_X->setValue(dm542ControllerX->getPeriod());
    ui->chkMotorEnable_X->setChecked(dm542ControllerX->getEnable());
    ui->spinPulseCount_X->setValue(dm542ControllerX->getPulseCount());
    ui->spinPeriod_Y->setValue(dm542ControllerY->getPeriod());
    ui->chkMotorEnable_Y->setChecked(dm542ControllerY->getEnable());
    ui->spinPulseCount_Y->setValue(dm542ControllerY->getPulseCount());
    ui->spinPeriod_Z->setValue(dm542ControllerZ->getPeriod());
    ui->chkMotorEnable_Z->setChecked(dm542ControllerZ->getEnable());
    ui->spinPulseCount_Z->setValue(dm542ControllerZ->getPulseCount());
}
void MainWindow::on_chkMotorEnable_X_toggled(bool checked)
{
    if (!dm542ControllerX)
        return;
    if (dm542ControllerX->setEnable(checked))
    {
        ui->btnStartMotor_X->setEnabled(checked);
        ui->spinPeriod_X->setEnabled(checked);
        ui->spinPulseCount_X->setEnabled(checked);
        ui->spinTotalPulses_X->setEnabled(checked);
        ui->spinStepPulses_X->setEnabled(checked);
        if (checked && ui->chkMotorEnable_Y->isChecked())
        {
            ui->btnAutoRun->setEnabled(true);
        }
    }
}
void MainWindow::on_chkMotorEnable_Y_toggled(bool checked)
{
    if (!dm542ControllerY)
        return;
    if (dm542ControllerY->setEnable(checked))
    {
        ui->btnStartMotor_Y->setEnabled(checked);
        ui->spinPeriod_Y->setEnabled(checked);
        ui->spinPulseCount_Y->setEnabled(checked);
        ui->spinTotalPulses_Y->setEnabled(checked);
        ui->spinStepPulses_Y->setEnabled(checked);
        if (checked && ui->chkMotorEnable_X->isChecked())
        {
            ui->btnAutoRun->setEnabled(true);
        }
    }
}
void MainWindow::on_chkMotorEnable_Z_toggled(bool checked)
{
    if (!dm542ControllerZ)
        return;
    if (dm542ControllerZ->setEnable(checked))
    {
        ui->btnStartMotor_Z->setEnabled(checked);
        ui->spinPeriod_Z->setEnabled(checked);
        ui->spinPulseCount_Z->setEnabled(checked);
        ui->spinTotalPulses_Z->setEnabled(checked);
        ui->spinStepPulses_Z->setEnabled(checked);
    }
}
void MainWindow::on_spinPeriod_X_valueChanged(int value)
{
    if (!dm542ControllerX)
        return;
    dm542ControllerX->setPeriod(value);
}
void MainWindow::on_spinPeriod_Y_valueChanged(int value)
{
    if (!dm542ControllerY)
        return;
    dm542ControllerY->setPeriod(value);
}
void MainWindow::on_spinPeriod_Z_valueChanged(int value)
{
    if (!dm542ControllerZ)
        return;
    dm542ControllerZ->setPeriod(value);
}
void MainWindow::on_btnStartMotor_X_clicked()
{
    if (!dm542ControllerX)
        return;
    dm542ControllerX->setPulseCount(ui->spinPulseCount_X->value());
    if (dm542ControllerX->setPwmEnable(true))
    {
        ui->btnStartMotor_X->setEnabled(false);
        ui->spinPulseCount_X->setEnabled(false);
        ui->spinTotalPulses_X->setEnabled(false);
        ui->spinStepPulses_X->setEnabled(false);
        ui->spinPeriod_X->setEnabled(false);
        ui->btnAutoRun->setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Motor Error", "Failed to start motor X. Please check motor connection and settings.");
    }
}
void MainWindow::on_btnStartMotor_Y_clicked()
{
    if (!dm542ControllerY)
        return;
    dm542ControllerY->setPulseCount(ui->spinPulseCount_Y->value());
    if (dm542ControllerY->setPwmEnable(true))
    {
        ui->btnStartMotor_Y->setEnabled(false);
        ui->spinPulseCount_Y->setEnabled(false);
        ui->spinTotalPulses_Y->setEnabled(false);
        ui->spinStepPulses_Y->setEnabled(false);
        ui->spinPeriod_Y->setEnabled(false);
        ui->btnAutoRun->setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Motor Error", "Failed to start motor Y. Please check motor connection and settings.");
    }
}
void MainWindow::on_btnStartMotor_Z_clicked()
{
    if (!dm542ControllerZ)
        return;
    dm542ControllerZ->setPulseCount(ui->spinPulseCount_Z->value());
    if (dm542ControllerZ->setPwmEnable(true))
    {
        ui->btnStartMotor_Z->setEnabled(false);
        ui->spinPulseCount_Z->setEnabled(false);
        ui->spinTotalPulses_Z->setEnabled(false);
        ui->spinStepPulses_Z->setEnabled(false);
        ui->spinPeriod_Z->setEnabled(false);
        ui->btnAutoRun->setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Motor Error", "Failed to start motor Z. Please check motor connection and settings.");
    }
}
void MainWindow::onPwmComplete(const AXIS &whatAmI)
{
    if (isAutoRunning)
    {
        qDebug() << "triggering snapshot";
        if (camHandle && selectedDevice)
            QMetaObject::invokeMethod(imageWorker, "snapshot", Qt::QueuedConnection, Q_ARG(void *, camHandle));
    }
    else
    {
        switch (whatAmI)
        {
        case X_AXIS:
            qDebug() << "PWM completed for X axis";
            if (dm542ControllerX)
            {
                ui->btnStartMotor_X->setEnabled(true);
                ui->spinPulseCount_X->setEnabled(true);
                ui->spinTotalPulses_X->setEnabled(true);
                ui->spinStepPulses_X->setEnabled(true);
                ui->spinPeriod_X->setEnabled(true);
            }
            break;
        case Y_AXIS:
            qDebug() << "PWM completed for Y axis";
            if (dm542ControllerY)
            {
                ui->btnStartMotor_Y->setEnabled(true);
                ui->spinPulseCount_Y->setEnabled(true);
                ui->spinTotalPulses_Y->setEnabled(true);
                ui->spinStepPulses_Y->setEnabled(true);
                ui->spinPeriod_Y->setEnabled(true);
            }
            break;
        case Z_AXIS:
            qDebug() << "PWM completed for Z axis";
            if (dm542ControllerZ)
            {
                ui->btnStartMotor_Z->setEnabled(true);
                ui->spinPulseCount_Z->setEnabled(true);
                ui->spinTotalPulses_Z->setEnabled(true);
                ui->spinStepPulses_Z->setEnabled(true);
                ui->spinPeriod_Z->setEnabled(true);
            }
            break;
        default:
            break;
        }
        if ((!dm542ControllerZ->getPwmEnable()) && (!dm542ControllerY->getPwmEnable()) && (!dm542ControllerX->getPwmEnable()))
        {
            // 所有电机都停止了
            qDebug() << "All motors stopped, re-enabling autorunTask";
            ui->btnAutoRun->setEnabled(true);
        }
    }
}
void MainWindow::onPwmTrig(int trigStat, const AXIS &whatAmI) // 触发的对应轴紧急停止信号处理已在内核模块处理,自动运行需处理其他轴
{
    if (isAutoRunning)
    {
        qDebug() << "PWM trigger received for axis" << whatAmI << "with status" << trigStat;
        // 停止自动运行
        isAutoRunning = false;
        dm542ControllerX->setPwmEnable(false);
        dm542ControllerY->setPwmEnable(false);
        dm542ControllerZ->setPwmEnable(false);
        dm542ControllerX->setPulseCount(0);
        dm542ControllerY->setPulseCount(0);
        dm542ControllerZ->setPulseCount(0);
        // UI更新
        ui->btnAutoRun->setEnabled(true);
        ui->btnStartMotor_X->setEnabled(true);
        ui->btnStartMotor_Y->setEnabled(true);
        ui->btnStartMotor_Z->setEnabled(true);
        ui->spinPulseCount_X->setEnabled(true);
        ui->spinPulseCount_Y->setEnabled(true);
        ui->spinPulseCount_Z->setEnabled(true);
        ui->spinTotalPulses_X->setEnabled(true);
        ui->spinTotalPulses_Y->setEnabled(true);
        ui->spinTotalPulses_Z->setEnabled(true);
        ui->spinStepPulses_X->setEnabled(true);
        ui->spinStepPulses_Y->setEnabled(true);
        ui->spinStepPulses_Z->setEnabled(true);
        ui->spinPeriod_X->setEnabled(true);
        ui->spinPeriod_Y->setEnabled(true);
        ui->spinPeriod_Z->setEnabled(true);
        ui->btnSnapshot->setEnabled(true);
    }
    else
    {
        switch (whatAmI)
        {
        case X_AXIS:
            if (dm542ControllerX)
            {
                ui->btnStartMotor_X->setEnabled(true);
                ui->spinPulseCount_X->setEnabled(true);
                ui->spinTotalPulses_X->setEnabled(true);
                ui->spinStepPulses_X->setEnabled(true);
                ui->spinPeriod_X->setEnabled(true);
            }
            break;
        case Y_AXIS:
            if (dm542ControllerY)
            {
                ui->btnStartMotor_Y->setEnabled(true);
                ui->spinPulseCount_Y->setEnabled(true);
                ui->spinTotalPulses_Y->setEnabled(true);
                ui->spinStepPulses_Y->setEnabled(true);
                ui->spinPeriod_Y->setEnabled(true);
            }
            break;
        case Z_AXIS:
            if (dm542ControllerZ)
            {
                ui->btnStartMotor_Z->setEnabled(true);
                ui->spinPulseCount_Z->setEnabled(true);
                ui->spinTotalPulses_Z->setEnabled(true);
                ui->spinStepPulses_Z->setEnabled(true);
                ui->spinPeriod_Z->setEnabled(true);
            }
            break;
        default:
            break;
        }
    }
    if ((!dm542ControllerZ->getPwmEnable()) && (!dm542ControllerY->getPwmEnable()) && (!dm542ControllerX->getPwmEnable()))
    {
        // 所有电机都停止了
        qDebug() << "All motors stopped, re-enabling autorunTask";
        ui->btnAutoRun->setEnabled(true);
    }
    // 根据触发状态显示相应的警告信息
    QString axisName;
    switch (whatAmI)
    {
    case X_AXIS:
        axisName = "X";
        break;
    case Y_AXIS:
        axisName = "Y";
        break;
    case Z_AXIS:
        axisName = "Z";
        break;
    default:
        axisName = "Unknown";
        break;
    }

    QString message;
    if (trigStat == 0)
    {
        message = QString("Motor %1 stopped due to trigger signal").arg(axisName);
    }
    else
    {
        message = QString("Motor %1 encountered an error (status: %2)").arg(axisName).arg(trigStat);
    }

    QMessageBox::warning(this, "Motor Alert", message);
}
void MainWindow::on_btnAutoRun_clicked()
{
    if (dm542ControllerX && dm542ControllerY)
    {
        if (dm542ControllerX->getEnable() == false || dm542ControllerY->getEnable() == false)
        {
            QMessageBox::warning(this, "Auto Run Error", "Both motors must be enabled to start auto run.");
            return;
        }
        autoRunDataX.totalPulses = ui->spinTotalPulses_X->value();
        autoRunDataX.stepPulses = ui->spinStepPulses_X->value();
        autoRunDataX.currentPulses = 0;
        autoRunDataX.currentStep = 0;
        autoRunDataY.totalPulses = ui->spinTotalPulses_Y->value();
        autoRunDataY.stepPulses = ui->spinStepPulses_Y->value();
        autoRunDataY.currentPulses = 0;
        autoRunDataY.currentStep = 0;
        if (autoRunDataX.stepPulses == 0 || autoRunDataX.totalPulses == 0)
        {
            autoRunDataX.totalPulses = 0;
            autoRunDataX.stepPulses = 0;
        }
        else if ((autoRunDataX.stepPulses > 0) != (autoRunDataX.totalPulses > 0))
        {
            QMessageBox::warning(this, "Auto Run Error", "X axis: Step pulses and total pulses must have the same sign.");
            return;
        }
        else if (autoRunDataX.totalPulses % autoRunDataX.stepPulses != 0)
        {
            QMessageBox::warning(this, "Auto Run Error", "X axis: Total pulses must be a multiple of step pulses.");
            return;
        }

        if (autoRunDataY.stepPulses == 0 || autoRunDataY.totalPulses == 0)
        {
            autoRunDataY.totalPulses = 0;
            autoRunDataY.stepPulses = 0;
        }
        else if ((autoRunDataY.stepPulses > 0) != (autoRunDataY.totalPulses > 0))
        {
            QMessageBox::warning(this, "Auto Run Error", "Y axis: Step pulses and total pulses must have the same sign.");
            return;
        }
        else if (autoRunDataY.totalPulses % autoRunDataY.stepPulses != 0)
        {
            QMessageBox::warning(this, "Auto Run Error", "Y axis: Total pulses must be a multiple of step pulses.");
            return;
        }

        if (autoRunDataX.totalPulses == 0 && autoRunDataY.totalPulses == 0)
        {
            QMessageBox::warning(this, "Auto Run Error", "At least one axis must have valid total pulses and step pulses.");
            return;
        }
        isAutoRunning = true;
        ui->btnAutoRun->setEnabled(false);
        ui->btnStartMotor_X->setEnabled(false);
        ui->btnStartMotor_Y->setEnabled(false);
        // 不修改Z轴按钮状态
        ui->spinPulseCount_X->setEnabled(false);
        ui->spinPulseCount_Y->setEnabled(false);
        // 不修改Z轴脉冲计数状态
        ui->spinTotalPulses_X->setEnabled(false);
        ui->spinTotalPulses_Y->setEnabled(false);
        // 不修改Z轴总脉冲数状态
        ui->spinStepPulses_X->setEnabled(false);
        ui->spinStepPulses_Y->setEnabled(false);
        // 不修改Z轴步进脉冲状态
        ui->spinPeriod_X->setEnabled(false);
        ui->spinPeriod_Y->setEnabled(false);
        // 不修改Z轴周期状态
        ui->btnSnapshot->setEnabled(false);
        QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
        QString runDirName = QString("run_%1").arg(timestamp);
        currentRunDir = autoRunDataDir + "/" + runDirName;
        QDir().mkpath(currentRunDir);

        // 自动运行前释放并重新初始化3D图表
        setup3DSurfaceInWidget();

        // 计算网格尺寸并预分配
        if (autoRunDataY.totalPulses * autoRunDataY.stepPulses > 0)
            surfaceRows = autoRunDataY.totalPulses / autoRunDataY.stepPulses + 1;
        else
            surfaceRows = 1; // 至少一行
        if (autoRunDataX.totalPulses * autoRunDataX.stepPulses > 0)
            surfaceColumns = autoRunDataX.totalPulses / autoRunDataX.stepPulses + 1;
        else
            surfaceColumns = 1; // 至少一列
        resetSurfaceDataProxy();

        // 在零点位置先拍一张照片（修复零起点没扫的问题）
        if (camHandle && selectedDevice)
        {
            QMetaObject::invokeMethod(imageWorker, "snapshot", Qt::QueuedConnection, Q_ARG(void *, camHandle));
        }
    }
}
void MainWindow::executeNextStep()
{
    if (!isAutoRunning || (autoRunDataX.currentPulses == autoRunDataX.totalPulses && autoRunDataY.currentPulses == autoRunDataY.totalPulses))
    {
        qDebug() << "Auto run completed or not started.";
        isAutoRunning = false;
        ui->btnAutoRun->setEnabled(true);
        ui->btnStartMotor_X->setEnabled(true);
        ui->btnStartMotor_Y->setEnabled(true);
        ui->btnStartMotor_Z->setEnabled(dm542ControllerZ && dm542ControllerZ->getEnable());
        ui->spinPulseCount_X->setEnabled(true);
        ui->spinPulseCount_Y->setEnabled(true);
        ui->spinPulseCount_Z->setEnabled(dm542ControllerZ && dm542ControllerZ->getEnable());
        ui->spinTotalPulses_X->setEnabled(true);
        ui->spinTotalPulses_Y->setEnabled(true);
        ui->spinTotalPulses_Z->setEnabled(dm542ControllerZ && dm542ControllerZ->getEnable());
        ui->spinStepPulses_X->setEnabled(true);
        ui->spinStepPulses_Y->setEnabled(true);
        ui->spinStepPulses_Z->setEnabled(dm542ControllerZ && dm542ControllerZ->getEnable());
        ui->spinPeriod_X->setEnabled(true);
        ui->spinPeriod_Y->setEnabled(true);
        ui->spinPeriod_Z->setEnabled(dm542ControllerZ && dm542ControllerZ->getEnable());
        QMessageBox::information(this, "AutoRun Complete",
                                 QString("AutoRun completed!\nData saved to: %2")
                                     .arg(autoRunDataDir));
        return;
    }

    // 支持三种扫描模式：矩形扫描、X单列扫描、Y单列扫描
    if (autoRunDataY.totalPulses == 0)
    {
        // X单列扫描模式（Y轴不动）
        dm542ControllerX->setPulseCount(autoRunDataX.stepPulses);
        if (dm542ControllerX->setPwmEnable(true))
        {
            autoRunDataX.currentPulses += autoRunDataX.stepPulses;
            autoRunDataX.currentStep++;
            qDebug() << "X单列扫描: 运行X轴步进脉冲:" << autoRunDataX.stepPulses;
        }
        else
        {
            QMessageBox::warning(this, "Motor Error", "Failed to start motor X. Please check motor connection and settings.");
            return;
        }
    }
    else if (autoRunDataX.totalPulses == 0)
    {
        // Y单列扫描模式（X轴不动）
        dm542ControllerY->setPulseCount(autoRunDataY.stepPulses);
        if (dm542ControllerY->setPwmEnable(true))
        {
            autoRunDataY.currentPulses += autoRunDataY.stepPulses;
            autoRunDataY.currentStep++;
            qDebug() << "Y单列扫描: 运行Y轴步进脉冲:" << autoRunDataY.stepPulses;
        }
        else
        {
            QMessageBox::warning(this, "Motor Error", "Failed to start motor Y. Please check motor connection and settings.");
            return;
        }
    }
    else
    {
        // 矩形扫描模式
        if (autoRunDataX.currentPulses == autoRunDataX.totalPulses)
        { // x轴清0,运行一次Y,并改变X轴方向
            autoRunDataX.currentPulses = 0;
            autoRunDataX.currentStep = 0;
            autoRunDataX.stepPulses = -autoRunDataX.stepPulses;   // 改变X轴方向
            autoRunDataX.totalPulses = -autoRunDataX.totalPulses; // 改变X轴总脉冲数
            dm542ControllerY->setPulseCount(autoRunDataY.stepPulses);
            if (dm542ControllerY->setPwmEnable(true))
            {
                autoRunDataY.currentPulses += autoRunDataY.stepPulses;
                autoRunDataY.currentStep++;
                qDebug() << "矩形扫描: 运行Y轴步进脉冲:" << autoRunDataY.stepPulses;
            }
            else
            {
                QMessageBox::warning(this, "Motor Error", "Failed to start motor Y. Please check motor connection and settings.");
                return;
            }
        }
        else
        { // x轴运行一次
            dm542ControllerX->setPulseCount(autoRunDataX.stepPulses);
            if (dm542ControllerX->setPwmEnable(true))
            {
                autoRunDataX.currentPulses += autoRunDataX.stepPulses;
                autoRunDataX.currentStep++;
                qDebug() << "矩形扫描: 运行X轴步进脉冲:" << autoRunDataX.stepPulses;
            }
            else
            {
                QMessageBox::warning(this, "Motor Error", "Failed to start motor X. Please check motor connection and settings.");
                return;
            }
        }
    }
}