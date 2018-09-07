/****************************************************************************
** Meta object code from reading C++ file 'qcustomlabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qcustomlabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcustomlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCustomLabel_t {
    QByteArrayData data[9];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCustomLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCustomLabel_t qt_meta_stringdata_QCustomLabel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QCustomLabel"
QT_MOC_LITERAL(1, 13, 16), // "displayPressure1"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "displayed"
QT_MOC_LITERAL(4, 41, 16), // "displayPressure2"
QT_MOC_LITERAL(5, 58, 12), // "dislplayFlow"
QT_MOC_LITERAL(6, 71, 19), // "displayDisplacement"
QT_MOC_LITERAL(7, 91, 17), // "displayTempreture"
QT_MOC_LITERAL(8, 109, 16) // "displayVibration"

    },
    "QCustomLabel\0displayPressure1\0\0displayed\0"
    "displayPressure2\0dislplayFlow\0"
    "displayDisplacement\0displayTempreture\0"
    "displayVibration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCustomLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       8,    1,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void QCustomLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCustomLabel *_t = static_cast<QCustomLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayPressure1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->displayPressure2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->dislplayFlow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->displayDisplacement((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->displayTempreture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->displayVibration((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QCustomLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QCustomLabel.data,
      qt_meta_data_QCustomLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCustomLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCustomLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCustomLabel.stringdata0))
        return static_cast<void*>(const_cast< QCustomLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QCustomLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
