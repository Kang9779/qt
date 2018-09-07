/****************************************************************************
** Meta object code from reading C++ file 'bucketcircuitdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bucketcircuitdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bucketcircuitdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BucketCircuitDialog_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BucketCircuitDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BucketCircuitDialog_t qt_meta_stringdata_BucketCircuitDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "BucketCircuitDialog"
QT_MOC_LITERAL(1, 20, 9), // "loopMovie"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "switchPage"
QT_MOC_LITERAL(4, 42, 5), // "index"
QT_MOC_LITERAL(5, 48, 15), // "getRealtimeData"
QT_MOC_LITERAL(6, 64, 16), // "onRunStopChanged"
QT_MOC_LITERAL(7, 81, 3), // "run"
QT_MOC_LITERAL(8, 85, 10), // "updatePlot"
QT_MOC_LITERAL(9, 96, 12), // "updatePeriod"
QT_MOC_LITERAL(10, 109, 9), // "startSave"
QT_MOC_LITERAL(11, 119, 11), // "openHistory"
QT_MOC_LITERAL(12, 131, 10) // "evalHealth"

    },
    "BucketCircuitDialog\0loopMovie\0\0"
    "switchPage\0index\0getRealtimeData\0"
    "onRunStopChanged\0run\0updatePlot\0"
    "updatePeriod\0startSave\0openHistory\0"
    "evalHealth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BucketCircuitDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       8,    0,   69,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BucketCircuitDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BucketCircuitDialog *_t = static_cast<BucketCircuitDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loopMovie(); break;
        case 1: _t->switchPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getRealtimeData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onRunStopChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updatePlot(); break;
        case 5: _t->updatePeriod((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->startSave(); break;
        case 7: _t->openHistory(); break;
        case 8: _t->evalHealth(); break;
        default: ;
        }
    }
}

const QMetaObject BucketCircuitDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BucketCircuitDialog.data,
      qt_meta_data_BucketCircuitDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BucketCircuitDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BucketCircuitDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BucketCircuitDialog.stringdata0))
        return static_cast<void*>(const_cast< BucketCircuitDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BucketCircuitDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
