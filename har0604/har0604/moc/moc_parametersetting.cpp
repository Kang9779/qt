/****************************************************************************
** Meta object code from reading C++ file 'parametersetting.h'
**
** Created: Mon Jun 4 16:04:15 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/parametersetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametersetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ParameterSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      29,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ParameterSetting[] = {
    "ParameterSetting\0\0setvalid()\0setinvalid()\0"
};

void ParameterSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ParameterSetting *_t = static_cast<ParameterSetting *>(_o);
        switch (_id) {
        case 0: _t->setvalid(); break;
        case 1: _t->setinvalid(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ParameterSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ParameterSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParameterSetting,
      qt_meta_data_ParameterSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ParameterSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ParameterSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ParameterSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterSetting))
        return static_cast<void*>(const_cast< ParameterSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int ParameterSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
