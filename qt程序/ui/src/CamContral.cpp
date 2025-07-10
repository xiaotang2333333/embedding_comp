#include "MainWindow.h"
#include <QRandomGenerator>
#include <QToolTip>
#include <QCursor>
#include <QElapsedTimer>
#include <QDateTime>
#include <QDir>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include "MvCameraControl.h"

void MainWindow::on_btnFindDevice_clicked()
{
    ui->comboDeviceList->clear();         // 清空下拉框
    ui->btnFindDevice->setEnabled(false); // 禁用按钮
    if (MV_CC_EnumDevices(MV_USB_DEVICE, &camList) == MV_OK)
    {
        if (camList.nDeviceNum > 0)
        {
            for (int i = 0; i < camList.nDeviceNum; ++i)
            {
                MV_CC_DEVICE_INFO *deviceInfo = camList.pDeviceInfo[i];
                QString deviceName = QString::fromUtf8(
                    reinterpret_cast<const char *>(deviceInfo->SpecialInfo.stUsb3VInfo.chModelName),
                    sizeof(deviceInfo->SpecialInfo.stUsb3VInfo.chModelName) // 传入整个数组的长度
                );
                ui->comboDeviceList->addItem(deviceName, QVariant::fromValue(deviceInfo));
            }
        }
        else
        {
            ui->comboDeviceList->addItem("No devices found");
        }
    }
    else
    {
        ui->comboDeviceList->addItem("Error enumerating devices");
    } // 枚举设备
    ui->btnFindDevice->setEnabled(true); // 重新启用按钮
}

void MainWindow::on_comboDeviceList_currentIndexChanged(int index)
{
    MainWindow::selectedDevice = nullptr; // 清除选中的设备
    if (index >= 0)
    {
        QVariant data = ui->comboDeviceList->itemData(index);
        if (data.isValid())
        {
            MainWindow::selectedDevice = data.value<MV_CC_DEVICE_INFO *>();
            ui->btnConnectDevice->setEnabled(true); // 启用连接按钮
        }
    }
}

void MainWindow::on_btnConnectDevice_clicked()
{
    ui->btnConnectDevice->setEnabled(false); // 禁用连接按钮
    if (ui->btnConnectDevice->text() == "Disconnect")
    {
        if (camHandle != nullptr)
        {
            MV_CC_CloseDevice(camHandle);                    // 关闭设备
            MV_CC_DestroyHandle(camHandle);                  // 销毁相机句柄
            camHandle = nullptr;                             // 重置相机句柄
            ui->btnConnectDevice->setText("Connect Device"); // 更新按钮文本
            ui->comboDeviceList->setEnabled(true);           // 启用设备下拉框
            ui->leExposureTime->setEnabled(false);           // 禁用曝光时间输入框
            ui->chkAutoExposure->setEnabled(false);          // 禁用自动曝光复选
            ui->leGain->setEnabled(false);                   // 禁用增益输入框
            ui->chkAutoGain->setEnabled(false);              // 禁用自动增益复
            ui->btnSnapshot->setEnabled(false);              // 禁用开始捕获按钮
            ui->spinRedBalance_R->setEnabled(false);           // 禁用红色平衡控件
            ui->spinGreenBalance_G->setEnabled(false);         // 禁用绿色平衡控件
            ui->spinBlueBalance_B->setEnabled(false);          // 禁用蓝色平衡控件
        }
    }
    else
    {
        if (camHandle != nullptr)
        {
            MV_CC_DestroyHandle(camHandle); // 销毁之前的相机句柄
            camHandle = nullptr;            // 重置相机句柄
        }
        if (selectedDevice != nullptr)
        {
            if (MV_CC_CreateHandle(&camHandle, selectedDevice) == MV_OK)
            {
                if (MV_CC_OpenDevice(camHandle) == MV_OK)
                {
                    MV_CC_SetEnumValue(camHandle, "TriggerMode", MV_TRIGGER_MODE_OFF);      // 设置触发模式为关闭
                    MV_CC_SetEnumValue(camHandle, "PixelFormat", PixelType_Gvsp_BayerRG12); // 设置像素格式为Bayer RG12
                    MV_CC_SetIntValueEx(camHandle, "Width", 600);
                    MV_CC_SetIntValueEx(camHandle, "Height", 600); // 设置图像宽度和高度
                    MV_CC_SetIntValueEx(camHandle, "OffsetX", 400);
                    MV_CC_SetIntValueEx(camHandle, "OffsetY", 300);           // 设置图像偏移
                    MV_CC_SetBoolValue(camHandle, "BlackLevelEnable", false); // 禁用黑电平校正
                    MVCC_FLOATVALUE stFloatValue = {0};
                    MVCC_ENUMVALUE stEnumValue = {0};
                    MVCC_INTVALUE stIntValue = {0};
                    MV_CC_SetEnumValue(camHandle, "BalanceWhiteAuto", 0); // 禁用自动曝光
                    MV_CC_GetFloatValue(camHandle, "ExposureTime", &stFloatValue);
                    ui->leExposureTime->setText(QString::number(stFloatValue.fCurValue, 'f', 2)); // 设置曝光时间
                    MV_CC_GetFloatValue(camHandle, "Gain", &stFloatValue);
                    MV_CC_GetEnumValue(camHandle, "AutoExposure", &stEnumValue); // 获取自动曝光状态
                    ui->chkAutoExposure->setChecked(stEnumValue.nCurValue == 1);
                    MV_CC_GetEnumValue(camHandle, "AutoGain", &stEnumValue); // 获取自动增益状态
                    ui->chkAutoGain->setChecked(stEnumValue.nCurValue == 1);
                    ui->leGain->setText(QString::number(stFloatValue.fCurValue, 'f', 2)); // 设置增益
                    MV_CC_GetBalanceRatioBlue(camHandle, &stIntValue);
                    ui->spinBlueBalance_B->setValue(stIntValue.nCurValue);
                    MV_CC_GetBalanceRatioRed(camHandle, &stIntValue);
                    ui->spinRedBalance_R->setValue(stIntValue.nCurValue); // 设置红色平衡
                    MV_CC_GetBalanceRatioGreen(camHandle, &stIntValue);
                    ui->spinGreenBalance_G->setValue(stIntValue.nCurValue); // 设置绿色平衡
                    ui->spinRedBalance_R->setEnabled(true);                 // 启用红色平衡控件
                    ui->spinGreenBalance_G->setEnabled(true);               // 启用绿色平衡控件
                    ui->spinBlueBalance_B->setEnabled(true);                // 启用蓝色平衡控件
                    ui->leExposureTime->setEnabled(true);                 // 启用曝光时间输入框
                    ui->chkAutoExposure->setEnabled(true);                // 启用自动曝光复选框
                    ui->leGain->setEnabled(true);                         // 启用增益输入框
                    ui->chkAutoGain->setEnabled(true);
                    ui->btnSnapshot->setEnabled(true); // 启用开始捕获按钮
                    ui->btnConnectDevice->setText("Disconnect");
                    ui->comboDeviceList->setEnabled(false); // 禁用设备下拉框
                }
                else
                {
                    qDebug() << "Failed to open device";
                }
            }
            else
            {
                qDebug() << "Failed to create handle";
            }
        }
        else
        {
            qDebug() << "No device selected";
        }
    }
    ui->btnConnectDevice->setEnabled(true); // 重新启用连接按钮
}

void MainWindow::on_leGain_editingFinished()
{
    if (selectedDevice != nullptr && camHandle != nullptr)
    {
        MVCC_FLOATVALUE stGain = {0};
        MV_CC_GetFloatValue(camHandle, "Gain", &stGain);
        float gainValue = ui->leGain->text().toFloat();
        if (stGain.fMax < gainValue)
        {
            gainValue = stGain.fMax; // 如果输入值超过最大值，则设置为最大值
            qDebug() << "Gain value exceeds maximum limit:" << stGain.fMax;
            return;
        }
        if (stGain.fMin > gainValue)
        {
            gainValue = stGain.fMin; // 如果输入值低于最小值，则设置为最小值
            qDebug() << "Gain value is below minimum limit:" << stGain.fMin;
            return;
        }
        if (MV_CC_SetFloatValue(camHandle, "Gain", gainValue) == MV_OK)
        {
            MV_CC_GetFloatValue(camHandle, "Gain", &stGain);
            ui->leGain->setText(QString::number(stGain.fCurValue, 'f', 2)); // 更新增益输入框显示
            qDebug() << "Gain set successfully:" << gainValue;
        }
        else
        {
            qDebug() << "Failed to set gain value";
        }
    }
}

void MainWindow::on_leExposureTime_editingFinished()
{
    if (selectedDevice != nullptr && camHandle != nullptr)
    {
        MVCC_FLOATVALUE stExposureTime = {0};
        MV_CC_GetFloatValue(camHandle, "ExposureTime", &stExposureTime);
        float exposureTime = ui->leExposureTime->text().toFloat();
        if (stExposureTime.fMax < exposureTime)
        {
            exposureTime = stExposureTime.fMax; // 如果输入值超过最大值，则设置为最大值
            qDebug() << "Exposure time exceeds maximum limit:" << stExposureTime.fMax;
        }
        if (stExposureTime.fMin > exposureTime)
        {
            exposureTime = stExposureTime.fMin; // 如果输入值低于最小值，则设置为最小值
            qDebug() << "Exposure time is below minimum limit:" << stExposureTime.fMin;
        }
        if (MV_CC_SetFloatValue(camHandle, "ExposureTime", exposureTime) == MV_OK)
        {
            MV_CC_GetFloatValue(camHandle, "ExposureTime", &stExposureTime);
            ui->leExposureTime->setText(QString::number(stExposureTime.fCurValue, 'f', 2)); // 更新曝光时间输入框显示
            qDebug() << "Exposure time set successfully:" << exposureTime;
        }
        else
        {
            qDebug() << "Failed to set exposure time";
        }
    }
}

void MainWindow::on_chkAutoGain_toggled(bool checked)
{
    if (selectedDevice != nullptr && camHandle != nullptr)
    {
        if (MV_CC_SetEnumValue(camHandle, "GainAuto", checked ? MV_GAIN_MODE_CONTINUOUS : MV_GAIN_MODE_OFF) == MV_OK)
        {
            qDebug() << "Auto Gain set to" << (checked ? "enabled" : "disabled");
            MVCC_ENUMVALUE isAutoGainEnabled = {0};
            MV_CC_GetEnumValue(camHandle, "GainAuto", &isAutoGainEnabled);
            if (isAutoGainEnabled.nCurValue == MV_GAIN_MODE_CONTINUOUS)
            {
                ui->leGain->setEnabled(false); // 禁用增益输入框
            }
            else
            {
                ui->leGain->setEnabled(true); // 启用增益输入框
            }
        }
        else
        {
            qDebug() << "Failed to set Auto Gain";
        }
    }
}

void MainWindow::on_chkAutoExposure_toggled(bool checked)
{
    if (selectedDevice != nullptr && camHandle != nullptr)
    {
        if (MV_CC_SetEnumValue(camHandle, "ExposureAuto", checked ? MV_EXPOSURE_AUTO_MODE_OFF : MV_EXPOSURE_AUTO_MODE_CONTINUOUS) == MV_OK)
        {
            qDebug() << "Auto Exposure set to" << (checked ? "enabled" : "disabled");
            MVCC_ENUMVALUE isAutoExposureEnabled = {0};
            MV_CC_GetEnumValue(camHandle, "ExposureAuto", &isAutoExposureEnabled);
            if (isAutoExposureEnabled.nCurValue == MV_EXPOSURE_AUTO_MODE_CONTINUOUS)
            {
                ui->leExposureTime->setEnabled(false); // 禁用曝光时间输入框
            }
            else
            {
                ui->leExposureTime->setEnabled(true); // 启用曝光时间输入框
            }
        }
        else
        {
            qDebug() << "Failed to set Auto Exposure";
        }
    }
}

void MainWindow::on_spinRedBalance_R_valueChanged(int value)
{
    if (camHandle && selectedDevice)
    {
        MV_CC_SetBalanceRatioRed(camHandle, value); // 设置红色平衡比率
        qDebug() << "Red balance set to" << value;
    }
    MVCC_INTVALUE t;
    MV_CC_GetBalanceRatioRed(camHandle, &t);   // 获取当前红色平衡比率
    ui->spinRedBalance_R->setValue(t.nCurValue); // 更新UI显示
}

void MainWindow::on_spinGreenBalance_G_valueChanged(int value)
{
    if (camHandle && selectedDevice)
    {
        MV_CC_SetBalanceRatioGreen(camHandle, value); // 设置绿色平衡比率
        qDebug() << "Green balance set to" << value;
    }
    MVCC_INTVALUE t;
    MV_CC_GetBalanceRatioGreen(camHandle, &t);   // 获取当前绿色平衡比率
    ui->spinGreenBalance_G->setValue(t.nCurValue); // 更新UI显示
}

void MainWindow::on_spinBlueBalance_B_valueChanged(int value)
{
    if (camHandle && selectedDevice)
    {
        MV_CC_SetBalanceRatioBlue(camHandle, value); // 设置蓝色平衡比率
        qDebug() << "Blue balance set to" << value;
    }
    MVCC_INTVALUE t;
    MV_CC_GetBalanceRatioBlue(camHandle, &t);   // 获取当前蓝色平衡比率
    ui->spinBlueBalance_B->setValue(t.nCurValue); // 更新
}
void MainWindow::on_leSThreshold_editingFinished()
{
    float sThreshold = ui->leSThreshold->text().toFloat();
    if (sThreshold < 0.0f || sThreshold > 1.0f)
    {
        qDebug() << "S* threshold must be between 0.0 and 1.0";
        return;
    }
    imageWorker->setSThreshold(sThreshold);
    qDebug() << "S* threshold set to" << sThreshold;
}
void MainWindow::on_leVThreshold_editingFinished()
{
    float vThreshold = ui->leVThreshold->text().toFloat();
    if (vThreshold < 0.0f || vThreshold > 1.0)
    {
        qDebug() << "V* threshold must be between 0.0 and 1.0";
        return;
    }
    imageWorker->setVThreshold(vThreshold);
    qDebug() << "V* threshold set to" << vThreshold;
}
void MainWindow::on_btnSnapshot_clicked()
{
    ui->btnSnapshot->setEnabled(false); // 禁用按钮
    if (camHandle == nullptr || selectedDevice == nullptr)
    {
        qDebug() << "Camera handle or selected device is null";
        ui->btnSnapshot->setEnabled(true);
        return;
    }

    // 通过worker线程执行拍照
    QMetaObject::invokeMethod(imageWorker, "snapshot", Qt::QueuedConnection, Q_ARG(void *, camHandle));
}