/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-06
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�---ϵͳ���賣��������������
**************************************************/
#ifndef CONTROL_H
#define CONTROL_H

#include <QString>

#define SHADOW_WIDTH            5
#define WINDOW_WIDTH            680
#define WINDOW_HEIGHT           372
#define WINDOW_START_X          0
#define WINDOW_START_Y          0
#define WINDOW_PAGE_COUNT       4
#define WINDOW_BUTTON_COUNT     4
#define WINDOW_PAGE_MOVE        20
#define WINDOW_ONEBUTTON_WIDTH  170
#define DEFALUT_SKIN    "images/login/skin"

#define _ARM_        0

//������Ϣ������ƣ�1�������Ϣ��0���������Ϣ
#define QDEBUG  1

//��������ʱ���� ����λ���룩(5����Կ�����)
#define SAVE_DATA_INTERVAL  60

//�Ƿ���ʾͼ��(1����ʾ��0������ʾ;Ĭ����ʾ)
#define SHOW_LEGEND     1

//�豸����,���ڲ�������ʱʹ��
#define DEVICE_TEMP         "01"    //�¶�
#define DEVICE_HUM          "02"    //ʪ��
#define DEVICE_SMOKE        "03"    //����

#define LED_ON      1
#define LED_OFF     0


extern bool gIsSendMessage;

//Ԥ���¶�ֵ
extern int set_parlour_tempture;
extern int set_bedroom_tempture;
extern int set_parlour_humidity;        //Ԥ��ʪ��ֵ
extern int set_smoke_density;           //Ԥ������Ũ��

//����������ʵʱֵ
extern QString cur_parlour_tempture;    //ֻͳ�ƿ����¶�(DS18B20�¶�ֵ)
extern QString cur_parlour_humidity;    //(DHT11ֵ)
extern QString cur_smoke_density;       //(MQ_2ֵ)

extern bool gIsOpenPort;                //���ڴ򿪱�־λ
extern bool gIsOpenCurtain;             //�����Ƿ��

//�Ƶ�����ö��
enum enum_light_name{
    E_BED_ROOM = 0,             //����
    E_PARLOUR,                  //����
    E_KITCHEN                   //����
};
//�Ƶ�����ö��
enum enum_ligt_num{
    ENUM_ONE = 1,
    ENUM_TWO ,
    ENUM_THREE
};
//ͳ�ƽ������
enum enum_statistic_title
{
    ENUM_TEMPTURE,                  //�¶�ͳ��
    ENUM_HUMIDITY_DENSITY,          //ʪ��Ũ��ͳ��
    ENUM_SMOKE_DENSITY              //����Ũ��ͳ��
};

#endif // CONTROL_H
