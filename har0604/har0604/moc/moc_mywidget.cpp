/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created: Mon Jun 4 16:04:12 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/mywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      28,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,    9,    9,    9, 0x08,
      58,    9,    9,    9, 0x08,
      69,    9,    9,    9, 0x08,
      80,    9,    9,    9, 0x08,
      97,   92,    9,    9, 0x08,
     111,    9,    9,    9, 0x08,
     128,    9,    9,    9, 0x08,
     138,    9,    9,    9, 0x08,
     154,    9,    9,    9, 0x08,
     170,    9,    9,    9, 0x08,
     187,    9,    9,    9, 0x08,
     208,    9,    9,    9, 0x08,
     226,  220,    9,    9, 0x08,
     249,  220,    9,    9, 0x08,
     272,  220,    9,    9, 0x08,
     299,  220,    9,    9, 0x08,
     323,  220,    9,    9, 0x08,
     346,  220,    9,    9, 0x08,
     370,  220,    9,    9, 0x08,
     402,  220,    9,    9, 0x08,
     424,  220,    9,    9, 0x08,
     445,  220,    9,    9, 0x08,
     468,  220,    9,    9, 0x08,
     491,  220,    9,    9, 0x08,
     518,  220,    9,    9, 0x08,
     540,  220,    9,    9, 0x08,
     563,  220,    9,    9, 0x08,
     587,  220,    9,    9, 0x08,
     604,  220,    9,    9, 0x08,
     632,  220,    9,    9, 0x08,
     657,  220,    9,    9, 0x08,
     679,  220,    9,    9, 0x08,
     702,  220,    9,    9, 0x08,
     726,  220,    9,    9, 0x08,
     743,  220,    9,    9, 0x08,
     766,  220,    9,    9, 0x08,
     787,  220,    9,    9, 0x08,
     818,  220,    9,    9, 0x08,
     844,  220,    9,    9, 0x08,
     870,  220,    9,    9, 0x08,
     896,  220,    9,    9, 0x08,
     916,  220,    9,    9, 0x08,
     940,  220,    9,    9, 0x08,
     964,  220,    9,    9, 0x08,
     984,    9,    9,    9, 0x08,
    1009,    9,    9,    9, 0x08,
    1034,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_myWidget[] = {
    "myWidget\0\0sendTime(QString)\0"
    "change_flag(int)\0updateTime()\0show_sys()\0"
    "hide_sys()\0close_sys()\0flag\0show_tab(int)\0"
    "show_parameter()\0FeedDog()\0show_control1()\0"
    "show_control2()\0InsertDatabase()\0"
    "InsertEngineerData()\0warn_slot()\0array\0"
    "get_eng_ti_dis(int[8])\0get_speed_data(int[8])\0"
    "get_meter_distance(int[8])\0"
    "get_motor_speed(int[8])\0get_unload_btn(int[8])\0"
    "get_valve_state(int[8])\0"
    "get_redischarge_machine(int[8])\0"
    "get_clean_fan(int[8])\0get_reserve1(int[8])\0"
    "get_water_rate(int[8])\0get_weight_dry(int[8])\0"
    "get_elevator_speed(int[8])\0"
    "get_lose_rate(int[8])\0get_gear_state(int[8])\0"
    "get_throw_angle(int[8])\0reserve2(int[8])\0"
    "get_auto_drive_para(int[8])\0"
    "get_detect_value(int[8])\0get_cut_width(int[8])\0"
    "get_real_speed(int[8])\0get_cutter_freq(int[8])\0"
    "get_feed(int[8])\0get_drum_speed(int[8])\0"
    "get_reserve5(int[8])\0"
    "get_instrument_control(int[8])\0"
    "get_setting_value(int[8])\0"
    "get_alarm_setting(int[8])\0"
    "get_voice_control(int[8])\0get_eng_thm(int[8])\0"
    "get_eng_oilpres(int[8])\0get_sys_voltage(int[8])\0"
    "get_eng_rev(int[8])\0send_settingpara1(char*)\0"
    "send_settingpara2(char*)\0"
    "send_set_arr(QByteArray)\0"
};

void myWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myWidget *_t = static_cast<myWidget *>(_o);
        switch (_id) {
        case 0: _t->sendTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->change_flag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateTime(); break;
        case 3: _t->show_sys(); break;
        case 4: _t->hide_sys(); break;
        case 5: _t->close_sys(); break;
        case 6: _t->show_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->show_parameter(); break;
        case 8: _t->FeedDog(); break;
        case 9: _t->show_control1(); break;
        case 10: _t->show_control2(); break;
        case 11: _t->InsertDatabase(); break;
        case 12: _t->InsertEngineerData(); break;
        case 13: _t->warn_slot(); break;
        case 14: _t->get_eng_ti_dis((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 15: _t->get_speed_data((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 16: _t->get_meter_distance((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 17: _t->get_motor_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 18: _t->get_unload_btn((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 19: _t->get_valve_state((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 20: _t->get_redischarge_machine((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 21: _t->get_clean_fan((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 22: _t->get_reserve1((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 23: _t->get_water_rate((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 24: _t->get_weight_dry((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 25: _t->get_elevator_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 26: _t->get_lose_rate((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 27: _t->get_gear_state((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 28: _t->get_throw_angle((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 29: _t->reserve2((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 30: _t->get_auto_drive_para((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 31: _t->get_detect_value((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 32: _t->get_cut_width((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 33: _t->get_real_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 34: _t->get_cutter_freq((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 35: _t->get_feed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 36: _t->get_drum_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 37: _t->get_reserve5((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 38: _t->get_instrument_control((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 39: _t->get_setting_value((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 40: _t->get_alarm_setting((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 41: _t->get_voice_control((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 42: _t->get_eng_thm((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 43: _t->get_eng_oilpres((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 44: _t->get_sys_voltage((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 45: _t->get_eng_rev((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 46: _t->send_settingpara1((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 47: _t->send_settingpara2((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 48: _t->send_set_arr((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myWidget,
      qt_meta_data_myWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myWidget))
        return static_cast<void*>(const_cast< myWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int myWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void myWidget::sendTime(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void myWidget::change_flag(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
