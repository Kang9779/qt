/****************************************************************************
** Meta object code from reading C++ file 'cutheight.h'
**
** Created: Mon Jun 4 16:04:02 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/cutheight.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cutheight.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cutHeight[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      31,   25,   10,   10, 0x0a,
      51,   47,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cutHeight[] = {
    "cutHeight\0\0UpdateGraph()\0value\0"
    "setValue(qreal)\0clr\0setMarkColor(QColor)\0"
};

void cutHeight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cutHeight *_t = static_cast<cutHeight *>(_o);
        switch (_id) {
        case 0: _t->UpdateGraph(); break;
        case 1: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->setMarkColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData cutHeight::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cutHeight::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cutHeight,
      qt_meta_data_cutHeight, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cutHeight::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cutHeight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cutHeight::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cutHeight))
        return static_cast<void*>(const_cast< cutHeight*>(this));
    return QWidget::qt_metacast(_clname);
}

int cutHeight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
