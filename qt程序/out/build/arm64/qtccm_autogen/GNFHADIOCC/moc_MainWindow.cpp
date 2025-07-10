/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/inc/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/qsurface3dseries.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[76];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[5];
    char stringdata6[8];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[17];
    char stringdata10[11];
    char stringdata11[25];
    char stringdata12[28];
    char stringdata13[39];
    char stringdata14[6];
    char stringdata15[26];
    char stringdata16[34];
    char stringdata17[32];
    char stringdata18[32];
    char stringdata19[27];
    char stringdata20[8];
    char stringdata21[33];
    char stringdata22[6];
    char stringdata23[35];
    char stringdata24[34];
    char stringdata25[23];
    char stringdata26[23];
    char stringdata27[20];
    char stringdata28[28];
    char stringdata29[28];
    char stringdata30[28];
    char stringdata31[29];
    char stringdata32[29];
    char stringdata33[29];
    char stringdata34[27];
    char stringdata35[27];
    char stringdata36[27];
    char stringdata37[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 11),  // "updateImage"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5),  // "image"
        QT_MOC_LITERAL(30, 13),  // "onPwmComplete"
        QT_MOC_LITERAL(44, 4),  // "AXIS"
        QT_MOC_LITERAL(49, 7),  // "whatAmI"
        QT_MOC_LITERAL(57, 9),  // "onPwmTrig"
        QT_MOC_LITERAL(67, 8),  // "trigStat"
        QT_MOC_LITERAL(76, 16),  // "updateChartImage"
        QT_MOC_LITERAL(93, 10),  // "dataPoints"
        QT_MOC_LITERAL(104, 24),  // "on_btnFindDevice_clicked"
        QT_MOC_LITERAL(129, 27),  // "on_btnConnectDevice_clicked"
        QT_MOC_LITERAL(157, 38),  // "on_comboDeviceList_currentInd..."
        QT_MOC_LITERAL(196, 5),  // "index"
        QT_MOC_LITERAL(202, 25),  // "on_leGain_editingFinished"
        QT_MOC_LITERAL(228, 33),  // "on_leExposureTime_editingFini..."
        QT_MOC_LITERAL(262, 31),  // "on_leSThreshold_editingFinished"
        QT_MOC_LITERAL(294, 31),  // "on_leVThreshold_editingFinished"
        QT_MOC_LITERAL(326, 26),  // "on_chkAutoExposure_toggled"
        QT_MOC_LITERAL(353, 7),  // "checked"
        QT_MOC_LITERAL(361, 32),  // "on_spinRedBalance_R_valueChanged"
        QT_MOC_LITERAL(394, 5),  // "value"
        QT_MOC_LITERAL(400, 34),  // "on_spinGreenBalance_G_valueCh..."
        QT_MOC_LITERAL(435, 33),  // "on_spinBlueBalance_B_valueCha..."
        QT_MOC_LITERAL(469, 22),  // "on_chkAutoGain_toggled"
        QT_MOC_LITERAL(492, 22),  // "on_btnSnapshot_clicked"
        QT_MOC_LITERAL(515, 19),  // "on_btnReset_clicked"
        QT_MOC_LITERAL(535, 27),  // "on_chkMotorEnable_X_toggled"
        QT_MOC_LITERAL(563, 27),  // "on_chkMotorEnable_Y_toggled"
        QT_MOC_LITERAL(591, 27),  // "on_chkMotorEnable_Z_toggled"
        QT_MOC_LITERAL(619, 28),  // "on_spinPeriod_X_valueChanged"
        QT_MOC_LITERAL(648, 28),  // "on_spinPeriod_Y_valueChanged"
        QT_MOC_LITERAL(677, 28),  // "on_spinPeriod_Z_valueChanged"
        QT_MOC_LITERAL(706, 26),  // "on_btnStartMotor_X_clicked"
        QT_MOC_LITERAL(733, 26),  // "on_btnStartMotor_Y_clicked"
        QT_MOC_LITERAL(760, 26),  // "on_btnStartMotor_Z_clicked"
        QT_MOC_LITERAL(787, 21)   // "on_btnAutoRun_clicked"
    },
    "MainWindow",
    "updateImage",
    "",
    "image",
    "onPwmComplete",
    "AXIS",
    "whatAmI",
    "onPwmTrig",
    "trigStat",
    "updateChartImage",
    "dataPoints",
    "on_btnFindDevice_clicked",
    "on_btnConnectDevice_clicked",
    "on_comboDeviceList_currentIndexChanged",
    "index",
    "on_leGain_editingFinished",
    "on_leExposureTime_editingFinished",
    "on_leSThreshold_editingFinished",
    "on_leVThreshold_editingFinished",
    "on_chkAutoExposure_toggled",
    "checked",
    "on_spinRedBalance_R_valueChanged",
    "value",
    "on_spinGreenBalance_G_valueChanged",
    "on_spinBlueBalance_B_valueChanged",
    "on_chkAutoGain_toggled",
    "on_btnSnapshot_clicked",
    "on_btnReset_clicked",
    "on_chkMotorEnable_X_toggled",
    "on_chkMotorEnable_Y_toggled",
    "on_chkMotorEnable_Z_toggled",
    "on_spinPeriod_X_valueChanged",
    "on_spinPeriod_Y_valueChanged",
    "on_spinPeriod_Z_valueChanged",
    "on_btnStartMotor_X_clicked",
    "on_btnStartMotor_Y_clicked",
    "on_btnStartMotor_Z_clicked",
    "on_btnAutoRun_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  182,    2, 0x08,    1 /* Private */,
       4,    1,  185,    2, 0x08,    3 /* Private */,
       7,    2,  188,    2, 0x08,    5 /* Private */,
       9,    1,  193,    2, 0x08,    8 /* Private */,
      11,    0,  196,    2, 0x08,   10 /* Private */,
      12,    0,  197,    2, 0x08,   11 /* Private */,
      13,    1,  198,    2, 0x08,   12 /* Private */,
      15,    0,  201,    2, 0x08,   14 /* Private */,
      16,    0,  202,    2, 0x08,   15 /* Private */,
      17,    0,  203,    2, 0x08,   16 /* Private */,
      18,    0,  204,    2, 0x08,   17 /* Private */,
      19,    1,  205,    2, 0x08,   18 /* Private */,
      21,    1,  208,    2, 0x08,   20 /* Private */,
      23,    1,  211,    2, 0x08,   22 /* Private */,
      24,    1,  214,    2, 0x08,   24 /* Private */,
      25,    1,  217,    2, 0x08,   26 /* Private */,
      26,    0,  220,    2, 0x08,   28 /* Private */,
      27,    0,  221,    2, 0x08,   29 /* Private */,
      28,    1,  222,    2, 0x08,   30 /* Private */,
      29,    1,  225,    2, 0x08,   32 /* Private */,
      30,    1,  228,    2, 0x08,   34 /* Private */,
      31,    1,  231,    2, 0x08,   36 /* Private */,
      32,    1,  234,    2, 0x08,   38 /* Private */,
      33,    1,  237,    2, 0x08,   40 /* Private */,
      34,    0,  240,    2, 0x08,   42 /* Private */,
      35,    0,  241,    2, 0x08,   43 /* Private */,
      36,    0,  242,    2, 0x08,   44 /* Private */,
      37,    0,  243,    2, 0x08,   45 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    8,    6,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'updateImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'onPwmComplete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const AXIS &, std::false_type>,
        // method 'onPwmTrig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const AXIS &, std::false_type>,
        // method 'updateChartImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const double, std::false_type>,
        // method 'on_btnFindDevice_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnConnectDevice_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboDeviceList_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_leGain_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leExposureTime_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leSThreshold_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leVThreshold_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chkAutoExposure_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_spinRedBalance_R_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinGreenBalance_G_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBlueBalance_B_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_chkAutoGain_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_btnSnapshot_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnReset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_chkMotorEnable_X_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkMotorEnable_Y_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_chkMotorEnable_Z_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_spinPeriod_X_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinPeriod_Y_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinPeriod_Z_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_btnStartMotor_X_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnStartMotor_Y_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnStartMotor_Z_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAutoRun_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->onPwmComplete((*reinterpret_cast< std::add_pointer_t<AXIS>>(_a[1]))); break;
        case 2: _t->onPwmTrig((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<AXIS>>(_a[2]))); break;
        case 3: _t->updateChartImage((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->on_btnFindDevice_clicked(); break;
        case 5: _t->on_btnConnectDevice_clicked(); break;
        case 6: _t->on_comboDeviceList_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_leGain_editingFinished(); break;
        case 8: _t->on_leExposureTime_editingFinished(); break;
        case 9: _t->on_leSThreshold_editingFinished(); break;
        case 10: _t->on_leVThreshold_editingFinished(); break;
        case 11: _t->on_chkAutoExposure_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_spinRedBalance_R_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_spinGreenBalance_G_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_spinBlueBalance_B_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_chkAutoGain_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_btnSnapshot_clicked(); break;
        case 17: _t->on_btnReset_clicked(); break;
        case 18: _t->on_chkMotorEnable_X_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_chkMotorEnable_Y_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_chkMotorEnable_Z_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_spinPeriod_X_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_spinPeriod_Y_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_spinPeriod_Z_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_btnStartMotor_X_clicked(); break;
        case 25: _t->on_btnStartMotor_Y_clicked(); break;
        case 26: _t->on_btnStartMotor_Z_clicked(); break;
        case 27: _t->on_btnAutoRun_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 28;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
