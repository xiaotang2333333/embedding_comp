/********************************************************************************
** Form generated from reading UI file 'qtccm.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCCM_H
#define UI_QTCCM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *mainLayout;
    QWidget *controlPanel;
    QVBoxLayout *verticalLayout;
    QGroupBox *grpDeviceControl;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnFindDevice;
    QWidget *deviceControls;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboDeviceList;
    QPushButton *btnConnectDevice;
    QGroupBox *grpMotorControl;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabMotorControl;
    QWidget *motorX;
    QVBoxLayout *verticalLayout_X;
    QCheckBox *chkMotorEnable_X;
    QLabel *lblPeriod_X;
    QSpinBox *spinPeriod_X;
    QLabel *lblPulseCount_X;
    QSpinBox *spinPulseCount_X;
    QPushButton *btnStartMotor_X;
    QLabel *lblTotalPulses_X;
    QSpinBox *spinTotalPulses_X;
    QLabel *lblStepPulses_X;
    QSpinBox *spinStepPulses_X;
    QWidget *motorY;
    QVBoxLayout *verticalLayout_Y;
    QCheckBox *chkMotorEnable_Y;
    QLabel *lblPeriod_Y;
    QSpinBox *spinPeriod_Y;
    QLabel *lblPulseCount_Y;
    QSpinBox *spinPulseCount_Y;
    QPushButton *btnStartMotor_Y;
    QLabel *lblTotalPulses_Y;
    QSpinBox *spinTotalPulses_Y;
    QLabel *lblStepPulses_Y;
    QSpinBox *spinStepPulses_Y;
    QWidget *motorZ;
    QVBoxLayout *verticalLayout_Z;
    QCheckBox *chkMotorEnable_Z;
    QLabel *lblPeriod_Z;
    QSpinBox *spinPeriod_Z;
    QLabel *lblPulseCount_Z;
    QSpinBox *spinPulseCount_Z;
    QPushButton *btnStartMotor_Z;
    QLabel *lblTotalPulses_Z;
    QSpinBox *spinTotalPulses_Z;
    QLabel *lblStepPulses_Z;
    QSpinBox *spinStepPulses_Z;
    QGroupBox *grpCameraSettings;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblExposureTime;
    QLineEdit *leExposureTime;
    QCheckBox *chkAutoExposure;
    QLabel *lblGain;
    QLineEdit *leGain;
    QCheckBox *chkAutoGain;
    QLabel *lblSThreshold;
    QLineEdit *leSThreshold;
    QLabel *lblVThreshold;
    QLineEdit *leVThreshold;
    QTabWidget *tabColorBalance;
    QWidget *tabRBalance;
    QVBoxLayout *verticalLayout_R;
    QLabel *lblRedBalance_R;
    QSpinBox *spinRedBalance_R;
    QWidget *tabGBalance;
    QVBoxLayout *verticalLayout_G;
    QLabel *lblGreenBalance_G;
    QSpinBox *spinGreenBalance_G;
    QWidget *tabBBalance;
    QVBoxLayout *verticalLayout_B;
    QLabel *lblBlueBalance_B;
    QSpinBox *spinBlueBalance_B;
    QGroupBox *grpActions;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnSnapshot;
    QPushButton *btnAutoRun;
    QPushButton *btnReset;
    QLabel *lblDistance;
    QLabel *lblShowMax;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QWidget *Q3dContainerWidget;
    QVBoxLayout *verticalLayout_Q3D;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1283, 881);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        mainLayout = new QHBoxLayout(MainWindow);
        mainLayout->setSpacing(6);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(6, 6, 6, 6);
        controlPanel = new QWidget(MainWindow);
        controlPanel->setObjectName("controlPanel");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(controlPanel->sizePolicy().hasHeightForWidth());
        controlPanel->setSizePolicy(sizePolicy1);
        controlPanel->setMinimumSize(QSize(220, 0));
        controlPanel->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(controlPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        grpDeviceControl = new QGroupBox(controlPanel);
        grpDeviceControl->setObjectName("grpDeviceControl");
        verticalLayout_3 = new QVBoxLayout(grpDeviceControl);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        btnFindDevice = new QPushButton(grpDeviceControl);
        btnFindDevice->setObjectName("btnFindDevice");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnFindDevice->sizePolicy().hasHeightForWidth());
        btnFindDevice->setSizePolicy(sizePolicy2);
        btnFindDevice->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(btnFindDevice);

        deviceControls = new QWidget(grpDeviceControl);
        deviceControls->setObjectName("deviceControls");
        sizePolicy2.setHeightForWidth(deviceControls->sizePolicy().hasHeightForWidth());
        deviceControls->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(deviceControls);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboDeviceList = new QComboBox(deviceControls);
        comboDeviceList->setObjectName("comboDeviceList");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboDeviceList->sizePolicy().hasHeightForWidth());
        comboDeviceList->setSizePolicy(sizePolicy3);
        comboDeviceList->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(comboDeviceList);

        btnConnectDevice = new QPushButton(deviceControls);
        btnConnectDevice->setObjectName("btnConnectDevice");
        btnConnectDevice->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnConnectDevice->sizePolicy().hasHeightForWidth());
        btnConnectDevice->setSizePolicy(sizePolicy4);
        btnConnectDevice->setMinimumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(btnConnectDevice);


        verticalLayout_3->addWidget(deviceControls);


        verticalLayout->addWidget(grpDeviceControl);

        grpMotorControl = new QGroupBox(controlPanel);
        grpMotorControl->setObjectName("grpMotorControl");
        verticalLayout_5 = new QVBoxLayout(grpMotorControl);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabMotorControl = new QTabWidget(grpMotorControl);
        tabMotorControl->setObjectName("tabMotorControl");
        tabMotorControl->setAutoFillBackground(false);
        motorX = new QWidget();
        motorX->setObjectName("motorX");
        verticalLayout_X = new QVBoxLayout(motorX);
        verticalLayout_X->setSpacing(0);
        verticalLayout_X->setObjectName("verticalLayout_X");
        verticalLayout_X->setContentsMargins(0, 0, 0, 0);
        chkMotorEnable_X = new QCheckBox(motorX);
        chkMotorEnable_X->setObjectName("chkMotorEnable_X");

        verticalLayout_X->addWidget(chkMotorEnable_X);

        lblPeriod_X = new QLabel(motorX);
        lblPeriod_X->setObjectName("lblPeriod_X");

        verticalLayout_X->addWidget(lblPeriod_X);

        spinPeriod_X = new QSpinBox(motorX);
        spinPeriod_X->setObjectName("spinPeriod_X");
        spinPeriod_X->setEnabled(false);
        spinPeriod_X->setMaximumSize(QSize(16777215, 16777215));
        spinPeriod_X->setMinimum(1);
        spinPeriod_X->setMaximum(16777215);
        spinPeriod_X->setValue(1000);

        verticalLayout_X->addWidget(spinPeriod_X);

        lblPulseCount_X = new QLabel(motorX);
        lblPulseCount_X->setObjectName("lblPulseCount_X");

        verticalLayout_X->addWidget(lblPulseCount_X);

        spinPulseCount_X = new QSpinBox(motorX);
        spinPulseCount_X->setObjectName("spinPulseCount_X");
        spinPulseCount_X->setEnabled(false);
        spinPulseCount_X->setMinimum(-16777215);
        spinPulseCount_X->setMaximum(16777215);
        spinPulseCount_X->setValue(1000);

        verticalLayout_X->addWidget(spinPulseCount_X);

        btnStartMotor_X = new QPushButton(motorX);
        btnStartMotor_X->setObjectName("btnStartMotor_X");
        btnStartMotor_X->setEnabled(false);

        verticalLayout_X->addWidget(btnStartMotor_X);

        lblTotalPulses_X = new QLabel(motorX);
        lblTotalPulses_X->setObjectName("lblTotalPulses_X");

        verticalLayout_X->addWidget(lblTotalPulses_X);

        spinTotalPulses_X = new QSpinBox(motorX);
        spinTotalPulses_X->setObjectName("spinTotalPulses_X");
        spinTotalPulses_X->setEnabled(false);
        spinTotalPulses_X->setMinimum(-1000000);
        spinTotalPulses_X->setMaximum(1000000);
        spinTotalPulses_X->setValue(50000);

        verticalLayout_X->addWidget(spinTotalPulses_X);

        lblStepPulses_X = new QLabel(motorX);
        lblStepPulses_X->setObjectName("lblStepPulses_X");

        verticalLayout_X->addWidget(lblStepPulses_X);

        spinStepPulses_X = new QSpinBox(motorX);
        spinStepPulses_X->setObjectName("spinStepPulses_X");
        spinStepPulses_X->setEnabled(false);
        spinStepPulses_X->setMinimum(-1000000);
        spinStepPulses_X->setMaximum(1000000);
        spinStepPulses_X->setValue(-1000000);

        verticalLayout_X->addWidget(spinStepPulses_X);

        tabMotorControl->addTab(motorX, QString());
        motorY = new QWidget();
        motorY->setObjectName("motorY");
        verticalLayout_Y = new QVBoxLayout(motorY);
        verticalLayout_Y->setSpacing(0);
        verticalLayout_Y->setObjectName("verticalLayout_Y");
        verticalLayout_Y->setContentsMargins(0, 0, 0, 0);
        chkMotorEnable_Y = new QCheckBox(motorY);
        chkMotorEnable_Y->setObjectName("chkMotorEnable_Y");

        verticalLayout_Y->addWidget(chkMotorEnable_Y);

        lblPeriod_Y = new QLabel(motorY);
        lblPeriod_Y->setObjectName("lblPeriod_Y");

        verticalLayout_Y->addWidget(lblPeriod_Y);

        spinPeriod_Y = new QSpinBox(motorY);
        spinPeriod_Y->setObjectName("spinPeriod_Y");
        spinPeriod_Y->setEnabled(false);
        spinPeriod_Y->setMaximumSize(QSize(16777215, 16777215));
        spinPeriod_Y->setMinimum(1);
        spinPeriod_Y->setMaximum(16777215);
        spinPeriod_Y->setValue(1000);

        verticalLayout_Y->addWidget(spinPeriod_Y);

        lblPulseCount_Y = new QLabel(motorY);
        lblPulseCount_Y->setObjectName("lblPulseCount_Y");

        verticalLayout_Y->addWidget(lblPulseCount_Y);

        spinPulseCount_Y = new QSpinBox(motorY);
        spinPulseCount_Y->setObjectName("spinPulseCount_Y");
        spinPulseCount_Y->setEnabled(false);
        spinPulseCount_Y->setMinimum(-16777215);
        spinPulseCount_Y->setMaximum(16777215);
        spinPulseCount_Y->setValue(1000);

        verticalLayout_Y->addWidget(spinPulseCount_Y);

        btnStartMotor_Y = new QPushButton(motorY);
        btnStartMotor_Y->setObjectName("btnStartMotor_Y");
        btnStartMotor_Y->setEnabled(false);

        verticalLayout_Y->addWidget(btnStartMotor_Y);

        lblTotalPulses_Y = new QLabel(motorY);
        lblTotalPulses_Y->setObjectName("lblTotalPulses_Y");

        verticalLayout_Y->addWidget(lblTotalPulses_Y);

        spinTotalPulses_Y = new QSpinBox(motorY);
        spinTotalPulses_Y->setObjectName("spinTotalPulses_Y");
        spinTotalPulses_Y->setEnabled(false);
        spinTotalPulses_Y->setMinimum(-1000000);
        spinTotalPulses_Y->setMaximum(1000000);
        spinTotalPulses_Y->setValue(50000);

        verticalLayout_Y->addWidget(spinTotalPulses_Y);

        lblStepPulses_Y = new QLabel(motorY);
        lblStepPulses_Y->setObjectName("lblStepPulses_Y");

        verticalLayout_Y->addWidget(lblStepPulses_Y);

        spinStepPulses_Y = new QSpinBox(motorY);
        spinStepPulses_Y->setObjectName("spinStepPulses_Y");
        spinStepPulses_Y->setEnabled(false);
        spinStepPulses_Y->setMinimum(-1000000);
        spinStepPulses_Y->setMaximum(1000000);
        spinStepPulses_Y->setValue(-1000000);

        verticalLayout_Y->addWidget(spinStepPulses_Y);

        tabMotorControl->addTab(motorY, QString());
        motorZ = new QWidget();
        motorZ->setObjectName("motorZ");
        verticalLayout_Z = new QVBoxLayout(motorZ);
        verticalLayout_Z->setSpacing(0);
        verticalLayout_Z->setObjectName("verticalLayout_Z");
        verticalLayout_Z->setContentsMargins(0, 0, 0, 0);
        chkMotorEnable_Z = new QCheckBox(motorZ);
        chkMotorEnable_Z->setObjectName("chkMotorEnable_Z");

        verticalLayout_Z->addWidget(chkMotorEnable_Z);

        lblPeriod_Z = new QLabel(motorZ);
        lblPeriod_Z->setObjectName("lblPeriod_Z");

        verticalLayout_Z->addWidget(lblPeriod_Z);

        spinPeriod_Z = new QSpinBox(motorZ);
        spinPeriod_Z->setObjectName("spinPeriod_Z");
        spinPeriod_Z->setEnabled(false);
        spinPeriod_Z->setMaximumSize(QSize(16777215, 16777215));
        spinPeriod_Z->setMinimum(1);
        spinPeriod_Z->setMaximum(16777215);
        spinPeriod_Z->setValue(1000);

        verticalLayout_Z->addWidget(spinPeriod_Z);

        lblPulseCount_Z = new QLabel(motorZ);
        lblPulseCount_Z->setObjectName("lblPulseCount_Z");

        verticalLayout_Z->addWidget(lblPulseCount_Z);

        spinPulseCount_Z = new QSpinBox(motorZ);
        spinPulseCount_Z->setObjectName("spinPulseCount_Z");
        spinPulseCount_Z->setEnabled(false);
        spinPulseCount_Z->setMinimum(-16777215);
        spinPulseCount_Z->setMaximum(16777215);
        spinPulseCount_Z->setValue(1000);

        verticalLayout_Z->addWidget(spinPulseCount_Z);

        btnStartMotor_Z = new QPushButton(motorZ);
        btnStartMotor_Z->setObjectName("btnStartMotor_Z");
        btnStartMotor_Z->setEnabled(false);

        verticalLayout_Z->addWidget(btnStartMotor_Z);

        lblTotalPulses_Z = new QLabel(motorZ);
        lblTotalPulses_Z->setObjectName("lblTotalPulses_Z");

        verticalLayout_Z->addWidget(lblTotalPulses_Z);

        spinTotalPulses_Z = new QSpinBox(motorZ);
        spinTotalPulses_Z->setObjectName("spinTotalPulses_Z");
        spinTotalPulses_Z->setEnabled(false);
        spinTotalPulses_Z->setMinimum(-1000000);
        spinTotalPulses_Z->setMaximum(1000000);
        spinTotalPulses_Z->setValue(50000);

        verticalLayout_Z->addWidget(spinTotalPulses_Z);

        lblStepPulses_Z = new QLabel(motorZ);
        lblStepPulses_Z->setObjectName("lblStepPulses_Z");

        verticalLayout_Z->addWidget(lblStepPulses_Z);

        spinStepPulses_Z = new QSpinBox(motorZ);
        spinStepPulses_Z->setObjectName("spinStepPulses_Z");
        spinStepPulses_Z->setEnabled(false);
        spinStepPulses_Z->setMinimum(-1000000);
        spinStepPulses_Z->setMaximum(1000000);
        spinStepPulses_Z->setValue(-1000000);

        verticalLayout_Z->addWidget(spinStepPulses_Z);

        tabMotorControl->addTab(motorZ, QString());

        verticalLayout_5->addWidget(tabMotorControl);


        verticalLayout->addWidget(grpMotorControl);

        grpCameraSettings = new QGroupBox(controlPanel);
        grpCameraSettings->setObjectName("grpCameraSettings");
        verticalLayout_2 = new QVBoxLayout(grpCameraSettings);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 6, 0, 0);
        lblExposureTime = new QLabel(grpCameraSettings);
        lblExposureTime->setObjectName("lblExposureTime");

        verticalLayout_2->addWidget(lblExposureTime);

        leExposureTime = new QLineEdit(grpCameraSettings);
        leExposureTime->setObjectName("leExposureTime");
        leExposureTime->setEnabled(false);
        sizePolicy2.setHeightForWidth(leExposureTime->sizePolicy().hasHeightForWidth());
        leExposureTime->setSizePolicy(sizePolicy2);
        leExposureTime->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(leExposureTime);

        chkAutoExposure = new QCheckBox(grpCameraSettings);
        chkAutoExposure->setObjectName("chkAutoExposure");
        chkAutoExposure->setEnabled(false);

        verticalLayout_2->addWidget(chkAutoExposure);

        lblGain = new QLabel(grpCameraSettings);
        lblGain->setObjectName("lblGain");

        verticalLayout_2->addWidget(lblGain);

        leGain = new QLineEdit(grpCameraSettings);
        leGain->setObjectName("leGain");
        leGain->setEnabled(false);
        leGain->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(leGain);

        chkAutoGain = new QCheckBox(grpCameraSettings);
        chkAutoGain->setObjectName("chkAutoGain");
        chkAutoGain->setEnabled(false);

        verticalLayout_2->addWidget(chkAutoGain);

        lblSThreshold = new QLabel(grpCameraSettings);
        lblSThreshold->setObjectName("lblSThreshold");

        verticalLayout_2->addWidget(lblSThreshold);

        leSThreshold = new QLineEdit(grpCameraSettings);
        leSThreshold->setObjectName("leSThreshold");

        verticalLayout_2->addWidget(leSThreshold);

        lblVThreshold = new QLabel(grpCameraSettings);
        lblVThreshold->setObjectName("lblVThreshold");

        verticalLayout_2->addWidget(lblVThreshold);

        leVThreshold = new QLineEdit(grpCameraSettings);
        leVThreshold->setObjectName("leVThreshold");

        verticalLayout_2->addWidget(leVThreshold);

        tabColorBalance = new QTabWidget(grpCameraSettings);
        tabColorBalance->setObjectName("tabColorBalance");
        tabRBalance = new QWidget();
        tabRBalance->setObjectName("tabRBalance");
        verticalLayout_R = new QVBoxLayout(tabRBalance);
        verticalLayout_R->setSpacing(0);
        verticalLayout_R->setObjectName("verticalLayout_R");
        verticalLayout_R->setContentsMargins(0, 0, 0, 0);
        lblRedBalance_R = new QLabel(tabRBalance);
        lblRedBalance_R->setObjectName("lblRedBalance_R");

        verticalLayout_R->addWidget(lblRedBalance_R);

        spinRedBalance_R = new QSpinBox(tabRBalance);
        spinRedBalance_R->setObjectName("spinRedBalance_R");
        spinRedBalance_R->setMinimum(0);
        spinRedBalance_R->setMaximum(65536);
        spinRedBalance_R->setValue(100);

        verticalLayout_R->addWidget(spinRedBalance_R);

        tabColorBalance->addTab(tabRBalance, QString());
        tabGBalance = new QWidget();
        tabGBalance->setObjectName("tabGBalance");
        verticalLayout_G = new QVBoxLayout(tabGBalance);
        verticalLayout_G->setSpacing(0);
        verticalLayout_G->setObjectName("verticalLayout_G");
        verticalLayout_G->setContentsMargins(0, 0, 0, 0);
        lblGreenBalance_G = new QLabel(tabGBalance);
        lblGreenBalance_G->setObjectName("lblGreenBalance_G");

        verticalLayout_G->addWidget(lblGreenBalance_G);

        spinGreenBalance_G = new QSpinBox(tabGBalance);
        spinGreenBalance_G->setObjectName("spinGreenBalance_G");
        spinGreenBalance_G->setMinimum(0);
        spinGreenBalance_G->setMaximum(65536);
        spinGreenBalance_G->setValue(100);

        verticalLayout_G->addWidget(spinGreenBalance_G);

        tabColorBalance->addTab(tabGBalance, QString());
        tabBBalance = new QWidget();
        tabBBalance->setObjectName("tabBBalance");
        verticalLayout_B = new QVBoxLayout(tabBBalance);
        verticalLayout_B->setSpacing(0);
        verticalLayout_B->setObjectName("verticalLayout_B");
        verticalLayout_B->setContentsMargins(0, 0, 0, 0);
        lblBlueBalance_B = new QLabel(tabBBalance);
        lblBlueBalance_B->setObjectName("lblBlueBalance_B");

        verticalLayout_B->addWidget(lblBlueBalance_B);

        spinBlueBalance_B = new QSpinBox(tabBBalance);
        spinBlueBalance_B->setObjectName("spinBlueBalance_B");
        spinBlueBalance_B->setMinimum(0);
        spinBlueBalance_B->setMaximum(65536);
        spinBlueBalance_B->setValue(100);

        verticalLayout_B->addWidget(spinBlueBalance_B);

        tabColorBalance->addTab(tabBBalance, QString());

        verticalLayout_2->addWidget(tabColorBalance);


        verticalLayout->addWidget(grpCameraSettings);

        grpActions = new QGroupBox(controlPanel);
        grpActions->setObjectName("grpActions");
        verticalLayout_4 = new QVBoxLayout(grpActions);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        btnSnapshot = new QPushButton(grpActions);
        btnSnapshot->setObjectName("btnSnapshot");
        btnSnapshot->setEnabled(false);
        sizePolicy2.setHeightForWidth(btnSnapshot->sizePolicy().hasHeightForWidth());
        btnSnapshot->setSizePolicy(sizePolicy2);
        btnSnapshot->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnSnapshot);

        btnAutoRun = new QPushButton(grpActions);
        btnAutoRun->setObjectName("btnAutoRun");
        btnAutoRun->setEnabled(false);

        verticalLayout_4->addWidget(btnAutoRun);

        btnReset = new QPushButton(grpActions);
        btnReset->setObjectName("btnReset");

        verticalLayout_4->addWidget(btnReset);

        lblDistance = new QLabel(grpActions);
        lblDistance->setObjectName("lblDistance");

        verticalLayout_4->addWidget(lblDistance);


        verticalLayout->addWidget(grpActions);

        lblShowMax = new QLabel(controlPanel);
        lblShowMax->setObjectName("lblShowMax");

        verticalLayout->addWidget(lblShowMax);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        mainLayout->addWidget(controlPanel);

        graphicsView = new QGraphicsView(MainWindow);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy5);
        graphicsView->setMinimumSize(QSize(600, 500));
        graphicsView->setMaximumSize(QSize(1920, 1080));
        graphicsView->setFocusPolicy(Qt::StrongFocus);
        graphicsView->setAcceptDrops(true);

        mainLayout->addWidget(graphicsView);

        Q3dContainerWidget = new QWidget(MainWindow);
        Q3dContainerWidget->setObjectName("Q3dContainerWidget");
        sizePolicy5.setHeightForWidth(Q3dContainerWidget->sizePolicy().hasHeightForWidth());
        Q3dContainerWidget->setSizePolicy(sizePolicy5);
        Q3dContainerWidget->setMinimumSize(QSize(600, 500));
        Q3dContainerWidget->setMaximumSize(QSize(1920, 1080));
        verticalLayout_Q3D = new QVBoxLayout(Q3dContainerWidget);
        verticalLayout_Q3D->setSpacing(0);
        verticalLayout_Q3D->setObjectName("verticalLayout_Q3D");
        verticalLayout_Q3D->setContentsMargins(0, 0, 0, 0);

        mainLayout->addWidget(Q3dContainerWidget);


        retranslateUi(MainWindow);

        tabMotorControl->setCurrentIndex(2);
        tabColorBalance->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QT Chromatic Confocal Measurement", nullptr));
        grpDeviceControl->setTitle(QCoreApplication::translate("MainWindow", "Device Control", nullptr));
        btnFindDevice->setText(QCoreApplication::translate("MainWindow", "Find Device", nullptr));
        btnConnectDevice->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        grpMotorControl->setTitle(QCoreApplication::translate("MainWindow", "Motor Control", nullptr));
        chkMotorEnable_X->setText(QCoreApplication::translate("MainWindow", "Motor Enable", nullptr));
        lblPeriod_X->setText(QCoreApplication::translate("MainWindow", "Period (ns):", nullptr));
        lblPulseCount_X->setText(QCoreApplication::translate("MainWindow", "Pulse Count:", nullptr));
        btnStartMotor_X->setText(QCoreApplication::translate("MainWindow", "Start Motor", nullptr));
        lblTotalPulses_X->setText(QCoreApplication::translate("MainWindow", "Total Pulses:", nullptr));
        lblStepPulses_X->setText(QCoreApplication::translate("MainWindow", "Step Pulses:", nullptr));
        tabMotorControl->setTabText(tabMotorControl->indexOf(motorX), QCoreApplication::translate("MainWindow", "X", nullptr));
        chkMotorEnable_Y->setText(QCoreApplication::translate("MainWindow", "Motor Enable", nullptr));
        lblPeriod_Y->setText(QCoreApplication::translate("MainWindow", "Period (ns):", nullptr));
        lblPulseCount_Y->setText(QCoreApplication::translate("MainWindow", "Pulse Count:", nullptr));
        btnStartMotor_Y->setText(QCoreApplication::translate("MainWindow", "Start Motor", nullptr));
        lblTotalPulses_Y->setText(QCoreApplication::translate("MainWindow", "Total Pulses:", nullptr));
        lblStepPulses_Y->setText(QCoreApplication::translate("MainWindow", "Step Pulses:", nullptr));
        tabMotorControl->setTabText(tabMotorControl->indexOf(motorY), QCoreApplication::translate("MainWindow", "Y", nullptr));
        chkMotorEnable_Z->setText(QCoreApplication::translate("MainWindow", "Motor Enable", nullptr));
        lblPeriod_Z->setText(QCoreApplication::translate("MainWindow", "Period (ns):", nullptr));
        lblPulseCount_Z->setText(QCoreApplication::translate("MainWindow", "Pulse Count:", nullptr));
        btnStartMotor_Z->setText(QCoreApplication::translate("MainWindow", "Start Motor", nullptr));
        lblTotalPulses_Z->setText(QCoreApplication::translate("MainWindow", "Total Pulses:", nullptr));
        lblStepPulses_Z->setText(QCoreApplication::translate("MainWindow", "Step Pulses:", nullptr));
        tabMotorControl->setTabText(tabMotorControl->indexOf(motorZ), QCoreApplication::translate("MainWindow", "Z", nullptr));
        grpCameraSettings->setTitle(QCoreApplication::translate("MainWindow", "Camera Settings", nullptr));
        lblExposureTime->setText(QCoreApplication::translate("MainWindow", "Exposure Time (ms):", nullptr));
        chkAutoExposure->setText(QCoreApplication::translate("MainWindow", "Auto Exposure", nullptr));
        lblGain->setText(QCoreApplication::translate("MainWindow", "Gain (db):", nullptr));
        chkAutoGain->setText(QCoreApplication::translate("MainWindow", "Auto Gain", nullptr));
        lblSThreshold->setText(QCoreApplication::translate("MainWindow", "S Threshold:", nullptr));
        leSThreshold->setText(QCoreApplication::translate("MainWindow", "0.2", nullptr));
        lblVThreshold->setText(QCoreApplication::translate("MainWindow", "V Threshold:", nullptr));
        leVThreshold->setText(QCoreApplication::translate("MainWindow", "0.2", nullptr));
        lblRedBalance_R->setText(QCoreApplication::translate("MainWindow", "Red Balance:", nullptr));
        tabColorBalance->setTabText(tabColorBalance->indexOf(tabRBalance), QCoreApplication::translate("MainWindow", "R", nullptr));
        lblGreenBalance_G->setText(QCoreApplication::translate("MainWindow", "Green Balance:", nullptr));
        tabColorBalance->setTabText(tabColorBalance->indexOf(tabGBalance), QCoreApplication::translate("MainWindow", "G", nullptr));
        lblBlueBalance_B->setText(QCoreApplication::translate("MainWindow", "Blue Balance:", nullptr));
        tabColorBalance->setTabText(tabColorBalance->indexOf(tabBBalance), QCoreApplication::translate("MainWindow", "B", nullptr));
        grpActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        btnSnapshot->setText(QCoreApplication::translate("MainWindow", "Snapshot", nullptr));
        btnAutoRun->setText(QCoreApplication::translate("MainWindow", "Auto Run", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        lblDistance->setText(QString());
        lblShowMax->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCCM_H
