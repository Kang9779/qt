/****************************************************************************
** Meta object code from reading C++ file 'numkeyboard.h'
**
** Created: Mon Jun 4 16:04:14 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/numkeyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NumKeyboard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      61,   12,   12,   12, 0x08,
      85,   12,   12,   12, 0x08,
     109,   12,   12,   12, 0x08,
     133,   12,   12,   12, 0x08,
     157,   12,   12,   12, 0x08,
     181,   12,   12,   12, 0x08,
     205,   12,   12,   12, 0x08,
     229,   12,   12,   12, 0x08,
     252,   12,   12,   12, 0x08,
     276,   12,   12,   12, 0x08,
     300,   12,   12,   12, 0x08,
     324,   12,   12,   12, 0x08,
     349,   12,   12,   12, 0x08,
     378,   12,   12,   12, 0x08,
     404,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NumKeyboard[] = {
    "NumKeyboard\0\0on_num1Button_clicked()\0"
    "on_num2Button_clicked()\0on_num3Button_clicked()\0"
    "on_num4Button_clicked()\0on_num5Button_clicked()\0"
    "on_num6Button_clicked()\0on_num7Button_clicked()\0"
    "on_num8Button_clicked()\0on_num9Button_clicked()\0"
    "on_dotButton_clicked()\0on_num0Button_clicked()\0"
    "on_signButton_clicked()\0on_leftButton_clicked()\0"
    "on_rightButton_clicked()\0"
    "on_backspaceButton_clicked()\0"
    "on_cancelButton_clicked()\0"
    "on_okButton_clicked()\0"
};

void NumKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NumKeyboard *_t = static_cast<NumKeyboard *>(_o);
        switch (_id) {
        case 0: _t->on_num1Button_clicked(); break;
        case 1: _t->on_num2Button_clicked(); break;
        case 2: _t->on_num3Button_clicked(); break;
        case 3: _t->on_num4Button_clicked(); break;
        case 4: _t->on_num5Button_clicked(); break;
        case 5: _t->on_num6Button_clicked(); break;
        case 6: _t->on_num7Button_clicked(); break;
        case 7: _t->on_num8Button_clicked(); break;
        case 8: _t->on_num9Button_clicked(); break;
        case 9: _t->on_dotButton_clicked(); break;
        case 10: _t->on_num0Button_clicked(); break;
        case 11: _t->on_signButton_clicked(); break;
        case 12: _t->on_leftButton_clicked(); break;
        case 13: _t->on_rightButton_clicked(); break;
        case 14: _t->on_backspaceButton_clicked(); break;
        case 15: _t->on_cancelButton_clicked(); break;
        case 16: _t->on_okButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NumKeyboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NumKeyboard::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NumKeyboard,
      qt_meta_data_NumKeyboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NumKeyboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NumKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NumKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NumKeyboard))
        return static_cast<void*>(const_cast< NumKeyboard*>(this));
    return QDialog::qt_metacast(_clname);
}

int NumKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
