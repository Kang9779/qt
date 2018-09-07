#ifndef ANALYSISDATA_H
#define ANALYSISDATA_H

#include <QObject>

#define   BGN_RESD_MSG		     0x23	 //"#":��ʼ��(0x23)
#define   END_RESD_MSG           0x2A  	 //"*":������(0x2A)

/*���ݷ��ͽ���ʽ�ĺ궨��*/
#define PROTOCOL_BASIC_SIZE 	 0x07

#define PROTOCOL_FULL_CMD   	 0x00
#define PROTOCOL_ZERO_LEN        0x00
#define PROTOCOL_FULL_DATA       0x00
#define DATA_TO_ASCII            0x30   //��������ʱ���ֵ�ASCII��Ļ���0

/*Ĭ���������ͺ궨��*/
#define MSG_EMPTY_DATA           ""    //������
#define MSG_LEN                  5     //Ĭ�����ݳ���
#define MSG_EMPTY_MODEL          0x00  //Ĭ���豸��
#define MSG_EMPTY_MODEL_CMD      0x00  //Ĭ���豸����

typedef enum MODEL{
    MODULE_BED_ROOM_LED_LEFT  = 0x30,     //�������    30
    MODULE_BED_ROOM_LED_RIGHT       ,     //�����ҵ�    31
    MODULE_PARLOUR_LED_MAIN         ,     //��������    32
    MODULE_PARLOUR_LED_TOP          ,     //��������    33
    MODULE_PARLOUR_LED_HELP         ,     //��������    34
    MODULE_KITCHIN_LED              ,     //������      35
    MODULE_CURTAIN		  			,     //����(�����������)36
    MODULE_DS18B20			    	,     //�¶�(�����¶�)    37
    MODULE_DHT11_TEMP				,     //ʪ��(�����¶�)    38
    MODULE_DHT11_HUM                ,     //DHT11ʪ��        39
    MODULE_SMOKE					,     //����Ũ��        0x3A
    MODULE_BEEP 					,     //������          0x3B
    MODULE_GO_HOME                  ,     //�ؼ�ģʽ
    MODULE_LEAVE_HOME               ,     //���ģʽ
    MODULE_ALL_LED                  ,     //����LED��

    CMD_BED_ROOM_LED_LEFT_ON        ,     //���������        3C
    CMD_BED_ROOM_LED_LEFT_OFF       ,     //���������        3D
    CMD_BED_ROOM_LED_RIGHT_ON       ,     //�����ҵ���        3E
    CMD_BED_ROOM_LED_RIGHT_OFF      ,     //�����ҵ���        3F
    CMD_PARLOUR_LED_MAIN_ON         ,     //����������        40
    CMD_PARLOUR_LED_MAIN_OFF        ,     //����������        41
    CMD_PARLOUR_LED_TOP_ON          ,     //����������        42
    CMD_PARLOUR_LED_TOP_OFF         ,     //����������        43
    CMD_PARLOUR_LED_HELP_ON         ,     //����������        44
    CMD_PARLOUR_LED_HELP_OFF        ,     //����������        45
    CMD_KITCHEN_LED_ON              ,     //��������          46
    CMD_KITCHEN_LED_OFF             ,     //��������          47
    CMD_BEEP_ON						,     //��������          48
    CMD_BEEP_OFF      				,	  //��������          49
    CMD_CURTAIN_ON 					,	  //������(���������ת)4A
    CMD_CURTAIN_STOP                ,     //����ֹͣ          4B
    CMD_CURTAIN_OFF                 ,     //������(���������ת)4C
    CMD_LEAVE_HOME_ON               ,     //���ģʽ����
    CMD_LEAVE_HOME_OFF              ,     //���ģʽ�ر�
    CMD_GO_HOME_ON                  ,     //�ؼ�ģʽ����
    CMD_GO_HOME_OFF                 ,     //�ؼ�ģʽ�ر�
    CMD_TURN_ON_ALL_LED             ,     //һ������
    CMD_TURN_OFF_ALL_LED                  //һ���ص�
}MODEL;


class AnalysisData : public QObject
{
    Q_OBJECT
public:
    explicit AnalysisData(QObject *parent = 0);

    void initData(void);
    
public slots:

public:

    void packSendData(quint8 drive, quint8 drive_cmd,
                  quint8 data_len, QString data);
    void  sendData(AnalysisData *);                    //�����������

    void updataPack();

    void receiveData(AnalysisData *pro);

    void execModuleBeep(AnalysisData *pro);

    //�������ݺ���
    void requestData(MODEL deviceName);

    void printData();

private:
    quint8 m_sendBegin;			//��ʼ��־  �ԡ�*����ʼ
    quint8 m_potocolLen;		//��Ϣ����  �ɱ䳤
    quint8 m_device;            //�豸��
    quint8 m_deviceCmd;         //�豸����
    quint8 m_dataLen;			//���ݳ���   	û��Ϊ0
    QString m_data;             //����		û��ָ���
    quint8 m_sendEnd;			//������־	�ԡ�#������
    
};

#endif // ANALYSISDATA_H
