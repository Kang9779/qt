/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_BtnArmCircuit_clicked"
QT_MOC_LITERAL(4, 59, 25), // "on_BtnBoomCircuit_clicked"
QT_MOC_LITERAL(5, 85, 29), // "on_BtnBucketCircuit_2_clicked"
QT_MOC_LITERAL(6, 115, 26), // "on_BtnSwingCircuit_clicked"
QT_MOC_LITERAL(7, 142, 29), // "on_BtnTravelCircuit_2_clicked"
QT_MOC_LITERAL(8, 172, 25), // "on_BtnPumpCircuit_clicked"
QT_MOC_LITERAL(9, 198, 27), // "on_BtnTravelCircuit_clicked"
QT_MOC_LITERAL(10, 226, 27), // "on_BtnBucketCircuit_clicked"
QT_MOC_LITERAL(11, 254, 28), // "on_BtnTravelCircuit2_clicked"
QT_MOC_LITERAL(12, 283, 26), // "on_BtnBoomCircuit2_clicked"
QT_MOC_LITERAL(13, 310, 25) // "on_BtnArmCircuit2_clicked"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_BtnArmCircuit_clicked\0"
    "on_BtnBoomCircuit_clicked\0"
    "on_BtnBucketCircuit_2_clicked\0"
    "on_BtnSwingCircuit_clicked\0"
    "on_BtnTravelCircuit_2_clicked\0"
    "on_BtnPumpCircuit_clicked\0"
    "on_BtnTravelCircuit_clicked\0"
    "on_BtnBucketCircuit_clicked\0"
    "on_BtnTravelCircuit2_clicked\0"
    "on_BtnBoomCircuit2_clicked\0"
    "on_BtnArmCircuit2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_BtnArmCircuit_clicked(); break;
        case 2: _t->on_BtnBoomCircuit_clicked(); break;
        case 3: _t->on_BtnBucketCircuit_2_clicked(); break;
        case 4: _t->on_BtnSwingCircuit_clicked(); break;
        case 5: _t->on_BtnTravelCircuit_2_clicked(); break;
        case 6: _t->on_BtnPumpCircuit_clicked(); break;
        case 7: _t->on_BtnTravelCircuit_clicked(); break;
        case 8: _t->on_BtnBucketCircuit_clicked(); break;
        case 9: _t->on_BtnTravelCircuit2_clicked(); break;
        case 10: _t->on_BtnBoomCircuit2_clicked(); break;
        case 11: _t->on_BtnArmCircuit2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
