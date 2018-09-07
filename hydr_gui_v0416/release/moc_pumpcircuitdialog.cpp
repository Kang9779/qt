/****************************************************************************
** Meta object code from reading C++ file 'pumpcircuitdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pumpcircuitdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pumpcircuitdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PumpCircuitDialog_t {
    QByteArrayData data[13];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PumpCircuitDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PumpCircuitDialog_t qt_meta_stringdata_PumpCircuitDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PumpCircuitDialog"
QT_MOC_LITERAL(1, 18, 10), // "switchPage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "index"
QT_MOC_LITERAL(4, 36, 15), // "getRealtimeData"
QT_MOC_LITERAL(5, 52, 16), // "onRunStopChanged"
QT_MOC_LITERAL(6, 69, 3), // "run"
QT_MOC_LITERAL(7, 73, 10), // "updatePlot"
QT_MOC_LITERAL(8, 84, 12), // "updatePeriod"
QT_MOC_LITERAL(9, 97, 4), // "text"
QT_MOC_LITERAL(10, 102, 9), // "startSave"
QT_MOC_LITERAL(11, 112, 11), // "openHistory"
QT_MOC_LITERAL(12, 124, 10) // "evalHealth"

    },
    "PumpCircuitDialog\0switchPage\0\0index\0"
    "getRealtimeData\0onRunStopChanged\0run\0"
    "updatePlot\0updatePeriod\0text\0startSave\0"
    "openHistory\0evalHealth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PumpCircuitDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    1,   60,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PumpCircuitDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PumpCircuitDialog *_t = static_cast<PumpCircuitDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getRealtimeData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onRunStopChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updatePlot(); break;
        case 4: _t->updatePeriod((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->startSave(); break;
        case 6: _t->openHistory(); break;
        case 7: _t->evalHealth(); break;
        default: ;
        }
    }
}

const QMetaObject PumpCircuitDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PumpCircuitDialog.data,
      qt_meta_data_PumpCircuitDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PumpCircuitDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PumpCircuitDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PumpCircuitDialog.stringdata0))
        return static_cast<void*>(const_cast< PumpCircuitDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PumpCircuitDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
