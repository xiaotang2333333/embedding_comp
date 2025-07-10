/****************************************************************************
** Meta object code from reading C++ file 'ImageAcquisitionWorker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../hardware/hkcam/inc/ImageAcquisitionWorker.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageAcquisitionWorker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ImageAcquisitionWorker_t {
    uint offsetsAndSizes[22];
    char stringdata0[23];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[19];
    char stringdata5[4];
    char stringdata6[14];
    char stringdata7[6];
    char stringdata8[17];
    char stringdata9[9];
    char stringdata10[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ImageAcquisitionWorker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ImageAcquisitionWorker_t qt_meta_stringdata_ImageAcquisitionWorker = {
    {
        QT_MOC_LITERAL(0, 22),  // "ImageAcquisitionWorker"
        QT_MOC_LITERAL(23, 13),  // "snapshotImage"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 5),  // "image"
        QT_MOC_LITERAL(44, 18),  // "snapshotColorChart"
        QT_MOC_LITERAL(63, 3),  // "hue"
        QT_MOC_LITERAL(67, 13),  // "snapshotError"
        QT_MOC_LITERAL(81, 5),  // "error"
        QT_MOC_LITERAL(87, 16),  // "snapshotFinished"
        QT_MOC_LITERAL(104, 8),  // "snapshot"
        QT_MOC_LITERAL(113, 6)   // "handle"
    },
    "ImageAcquisitionWorker",
    "snapshotImage",
    "",
    "image",
    "snapshotColorChart",
    "hue",
    "snapshotError",
    "error",
    "snapshotFinished",
    "snapshot",
    "handle"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ImageAcquisitionWorker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    1,   47,    2, 0x06,    3 /* Public */,
       6,    1,   50,    2, 0x06,    5 /* Public */,
       8,    0,   53,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   54,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject ImageAcquisitionWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ImageAcquisitionWorker.offsetsAndSizes,
    qt_meta_data_ImageAcquisitionWorker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ImageAcquisitionWorker_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImageAcquisitionWorker, std::true_type>,
        // method 'snapshotImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'snapshotColorChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const double, std::false_type>,
        // method 'snapshotError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'snapshotFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'snapshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<void *, std::false_type>
    >,
    nullptr
} };

void ImageAcquisitionWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageAcquisitionWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->snapshotImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->snapshotColorChart((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->snapshotError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->snapshotFinished(); break;
        case 4: _t->snapshot((*reinterpret_cast< std::add_pointer_t<void*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageAcquisitionWorker::*)(QImage );
            if (_t _q_method = &ImageAcquisitionWorker::snapshotImage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageAcquisitionWorker::*)(const double );
            if (_t _q_method = &ImageAcquisitionWorker::snapshotColorChart; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImageAcquisitionWorker::*)(const QString & );
            if (_t _q_method = &ImageAcquisitionWorker::snapshotError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImageAcquisitionWorker::*)();
            if (_t _q_method = &ImageAcquisitionWorker::snapshotFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *ImageAcquisitionWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageAcquisitionWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageAcquisitionWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageAcquisitionWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ImageAcquisitionWorker::snapshotImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageAcquisitionWorker::snapshotColorChart(const double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageAcquisitionWorker::snapshotError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageAcquisitionWorker::snapshotFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
