/****************************************************************************
** Meta object code from reading C++ file 'ion-wundergroundpws.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/ion-wundergroundpws.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ion-wundergroundpws.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WundergroundPWSIon_t {
    QByteArrayData data[13];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
            qptrdiff(offsetof(qt_meta_stringdata_WundergroundPWSIon_t, stringdata0) + ofs \
                     - idx * sizeof(QByteArrayData)) \
            )
static const qt_meta_stringdata_WundergroundPWSIon_t qt_meta_stringdata_WundergroundPWSIon = {
    {
        QT_MOC_LITERAL(0, 0, 18), // "WundergroundPWSIon"
        QT_MOC_LITERAL(1, 19, 22), // "search_slotDataArrived"
        QT_MOC_LITERAL(2, 42, 0), // ""
        QT_MOC_LITERAL(3, 43, 9), // "KIO::Job*"
        QT_MOC_LITERAL(4, 53, 22), // "search_slotJobFinished"
        QT_MOC_LITERAL(5, 76, 5), // "KJob*"
        QT_MOC_LITERAL(6, 82, 3), // "job"
        QT_MOC_LITERAL(7, 86, 27), // "observation_slotDataArrived"
        QT_MOC_LITERAL(8, 114, 27), // "observation_slotJobFinished"
        QT_MOC_LITERAL(9, 142, 22), // "demand_slotDataArrived"
        QT_MOC_LITERAL(10, 165, 22), // "demand_slotJobFinished"
        QT_MOC_LITERAL(11, 188, 24), // "forecast_slotDataArrived"
        QT_MOC_LITERAL(12, 213, 24) // "forecast_slotJobFinished"

    },
    "WundergroundPWSIon\0search_slotDataArrived\0"
    "\0KIO::Job*\0search_slotJobFinished\0"
    "KJob*\0job\0observation_slotDataArrived\0"
    "observation_slotJobFinished\0"
    "demand_slotDataArrived\0demand_slotJobFinished\0"
    "forecast_slotDataArrived\0"
    "forecast_slotJobFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WundergroundPWSIon[] = {

// content:
    8,       // revision
    0,       // classname
    0,    0, // classinfo
    8,   14, // methods
    0,    0, // properties
    0,    0, // enums/sets
    0,    0, // constructors
    0,       // flags
    0,       // signalCount

// slots: name, argc, parameters, tag, flags
    1,    2,   54,    2, 0x08 /* Private */,
    4,    1,   59,    2, 0x08 /* Private */,
    7,    2,   62,    2, 0x08 /* Private */,
    8,    1,   67,    2, 0x08 /* Private */,
    9,    2,   70,    2, 0x08 /* Private */,
    10,    1,   75,    2, 0x08 /* Private */,
    11,    2,   78,    2, 0x08 /* Private */,
    12,    1,   83,    2, 0x08 /* Private */,

// slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    6,

    0        // eod
};

void WundergroundPWSIon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WundergroundPWSIon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->search_slotDataArrived((*reinterpret_cast< KIO::Job*(*)>(_a[1])), (*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 1: _t->search_slotJobFinished((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        case 2: _t->observation_slotDataArrived((*reinterpret_cast< KIO::Job*(*)>(_a[1])), (*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 3: _t->observation_slotJobFinished((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        case 4: _t->demand_slotDataArrived((*reinterpret_cast< KIO::Job*(*)>(_a[1])), (*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 5: _t->demand_slotJobFinished((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        case 6: _t->forecast_slotDataArrived((*reinterpret_cast< KIO::Job*(*)>(_a[1])), (*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 7: _t->forecast_slotJobFinished((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KIO::Job* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KJob* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KIO::Job* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KJob* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KIO::Job* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KJob* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KIO::Job* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KJob* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WundergroundPWSIon::staticMetaObject = { {
        QMetaObject::SuperData::link<IonInterface::staticMetaObject>(),
        qt_meta_stringdata_WundergroundPWSIon.data,
        qt_meta_data_WundergroundPWSIon,
        qt_static_metacall,
        nullptr,
        nullptr
    }
};


const QMetaObject *WundergroundPWSIon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WundergroundPWSIon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WundergroundPWSIon.stringdata0))
        return static_cast<void*>(this);
    return IonInterface::qt_metacast(_clname);
}

int WundergroundPWSIon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IonInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
