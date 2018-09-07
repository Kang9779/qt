#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QVBoxLayout>
#include <QBitmap>
#include <QDebug>
#include <QComboBox>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/watchdog.h>
#include <QElapsedTimer>

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariantList>

#include "mydashboard.h"
#include "mqlabel.h"
#include "can_recv_send.h"
#include "thread.h"
#include "controlsetting.h"
#include "parametersetting.h"


namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

public:
    void SensordataInit();
    void DataSave();
    void StatedataInit();
    void EngineerDataSave();


private slots:
    void updateTime();
    void show_sys();
    void hide_sys();
    void close_sys();

    void show_parameter();

    void FeedDog();

    void show_control1();
    void show_control2();

    void InsertDatabase();
    void InsertEngineerData();

    void warn_slot();
    void get_eng_ti_dis(int array[8]);
    void get_speed_data(int array[8]);
    void get_meter_distance(int array[8]);
    void get_motor_speed(int array[8]);
    void get_unload_btn(int array[8]);
    void get_valve_state(int array[8]);
    void get_redischarge_machine(int array[8]);
    void get_clean_fan(int array[8]);
    void get_reserve1(int array[8]);
    void get_water_rate(int array[8]);
    void get_weight_dry(int array[8]);
    void get_elevator_speed(int array[8]);
    void get_lose_rate(int array[8]);
    void get_gear_state(int array[8]);
    void get_throw_angle(int array[8]);
    void reserve2(int array[8]);
    void get_auto_drive_para(int array[8]);
    void get_detect_value(int array[8]);
    void get_cut_width(int array[8]);
    void get_real_speed(int array[8]);
    void get_cutter_freq(int array[8]);
    void get_feed(int array[8]);
    void get_drum_speed(int array[8]);
    void get_reserve5(int array[8]);
    void get_instrument_control(int array[8]);
    void get_setting_value(int array[8]);
    void get_alarm_setting(int array[8]);
    void get_voice_control(int array[8]);
    void get_eng_thm(int array[8]);
    void get_eng_oilpres(int array[8]);
    void get_sys_voltage(int array[8]);
    void get_eng_rev(int array[8]);



signals:
    void sendTime(QString);
    void change_flag(int);

public:


private:
    Ui::myWidget *ui;
    QTimer *timer;
    QTimer *timerwdt;       //看门狗
    QTimer *tmpara;         //定时刷新界面
    QPixmap pixmap;

    int  conflag;

    QTimer *updateTimer1;
    QTimer *updateTimerCH;
    QTimer *updateTimerTH;
    QTimer *updateTimerDL;
    QTimer *updateTimerEng;
    QTimer *updateTimerPrs;
    QTimer *updateTimerTach;
    QTimer *DataSaveTimer;//数据存储定时器
    QTimer *EngineerDataSaveTimer;

    /* 线程对象的定义*/
    Thread *xcThread;
    Thread2 * nwThread;
    ThreadBack *reThreadBack;

    /* 串口发送数据的线程 */
   // SerialThread* serialThread;

//    auto ret;
    ControlSetting *cs;
    ParameterSetting *ps;

private:
    int wdt_fd;
    int flag1;
    int flag2;
    int flag3;
    int flag4;
    int flag5;
    int flag6;
    int flag7;
    int flag8;
    int flag9;
    int flag10;
    int flag11;
    int flag12;
    int flag13;
    int flag14;
    int flag15;
    int flag16;
    int flag17;

    int flag_vol;       //是否需要报警语言标志
    int flag_aux;

    int flag_gear;      //发动机档位标志
    int flag_hb;        //手刹标志
    int flag_chg;       //充电标志
    int flag_turn;      //转向标志
    int flag_light;     //远近光灯

    int flag_preheat;   //预热
    int flag_auto;      //导航辅助驾驶

    int flag_ef;        //发动机故障
    int flag_gf;        //粮满

private:
    int Number;               //传感器数据表主键值
    int number;               //警报数据表主键值
    int number_e;
    qreal EngineerWorktime;   //发动机工作时间
    qreal TotalMileage;       //总里程
    qreal CarSpeed;           //行驶速度
    qreal Fuel;               //燃油位
    qreal SystemVoltage;      //系统电压
    qreal OilPressure;        //发动机油压
    qreal MetericMileage;     //米计里程
    qreal CheckLossrate;      //清选损失率
    qreal EntrainmentLossrate;//夹带损失率
    qreal ClearInclusionrate; //清选含杂率
    qreal BrokenRate;         //破碎率
    qreal HanZaLevel;         //含杂等级
    qreal EngineerSpeed;      //发动机转速
    qreal EngineerTemperature;//发动机水温
    qreal ChopperSpeed;       //切碎器转速
    qreal FunSpeed;           //风扇转速
    qreal CutterFrequency;    //割刀频率
    qreal BohelunSpeed;       //拨禾轮转速
    qreal AxialflowRollerSpeed;//轴流（切流）滚筒转速
    qreal Retractor;          //复脱器转速
    qreal LiftdeviceSpeed;    //升运器转速
    qreal FeedSpeed;          //喂入搅龙转速
    qreal WaterRate;          //含水率
    qreal ProductionSquaremeter;//平方米产量
    qreal GrainDryweight;     //粮食干重
    qreal GrainWetweight;     //粮食湿重
    qreal GravureGapvalue;    //凹版间隙检测值
    qreal UpsieveOpendegree;  //上筛开度
    qreal DownsieveOpendegree;//下筛开度
    qreal LastsieveOpendegree;//尾筛开度
    qreal ProfilingHeightvalue;//仿形高度检测值
    qreal CutterHeightvalue;  //割台高度检测值
    qreal CropHeightvalue;    //农作物高度检测值
    qreal BohelunHeightvalue; //拨禾轮高度
    qreal BohelunDisplacement;//拨禾轮前后位移
    qreal FormotorSpeed;      // 前马达转速
    qreal BehmotorSpeed;      //后马达转速
    qreal AxialflowRollerTorque;//轴流(切流)滚筒转矩
    qreal CutterLossrate;     //割台损失率
    qreal GrainflowQuality;   //谷物流量监测质量
    qreal PartwindBoard;      //风机分风板角度
    qreal SprinklerAngle;     //抛洒器角度
    qreal CutwidthLeftvalue;  //割宽（左）检测值
    qreal CutwidthRightvalue; //割宽（右）检测值
    qreal FeedQuantity;       //喂入量
    QString GrainWarning;     //粮满状态
    QString FormotorWarningHL;//前马达转速高/低警告
    QString FormotorWarningD; //前马达转速堵塞警告
    QString BehmotorWarningHL;//后马达转速高/低警告
    QString BehmotorWarningD; //后马达转速堵塞警告
    QString RetractorWarningHL;//复脱器转速高/低警告
    QString RetractorWarningD;//复脱器转速堵塞警告
    QString LiftdeviceWarningHL;//升运器转速高/低警告
    QString LiftdeviceWarningD;//升运器转速堵塞警告
    QString ChopperWarningHL;  //切碎器转速高/低警告
    QString ChopperWarningD;   //切碎器转速堵塞警告
    QString FunSpeedWarningHL;  //风扇转速高/低警告
    QString FunSpeedWarningD;   //风扇转速堵塞警告
    QString FeedWarningHL;     //喂入搅龙转速高/低警告
    QString FeedWarningD;      //喂入搅龙转速堵塞警告
    QString BohelunWarningHL;  //拨禾轮转速高/低警告
    QString BohelunWarningD;   //拨禾轮转速堵塞警告
    QString AxialflowWarningHL;//轴流（切流）滚筒转速高/低警告
    QString AxialflowWarningD; //轴流（切流）滚筒转速堵塞警告
    QString DataTime;
    QSqlDatabase db;

private:
    void set_watchdog();
    void variable_init();

};

#endif // MYWIDGET_H
