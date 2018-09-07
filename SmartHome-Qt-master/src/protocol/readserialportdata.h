#ifndef READSERIALPORTDATA_H
#define READSERIALPORTDATA_H
#include <QObject>
#include "qextserialport.h"

#include "analysisdata.h"

//��ʱ��TIME_OUT�Ǵ��ڶ�д����ʱ
#define TIME_OUT 100
//�������Ͷ�ʱ����ʱ���,200ms
#define OBO_TIMER_INTERVAL 200

#include <QTimer>

class ReadSerialPortData : public QObject
{
    Q_OBJECT
public:
    explicit ReadSerialPortData(QObject *parent = 0);
    ~ReadSerialPortData();

    void execCmd(QByteArray buff);

private:
    void initData();
    void init();
    void openSerialPort();      //open
    void initConnect();

    void packSendData(quint8 drive, quint8 drive_cmd,
                      quint8 data_len, QString data);
    void sendData();

    quint8 getProtocolLen();
    quint8 getDevice();
    quint8 getDevieCmd();
    quint8 getDataLen();
    QString getData();

    void execData();
    void execDs18b20Data(QByteArray buff);
    void execDHT11_HumData(QByteArray buff);
    void execDHT11_TemData(QByteArray buff);
    void execSMOKEData(QByteArray buff);

    void sendBedRoomCmd(quint8 cmd);              //����������ؿ�������
    void sendParlourCmd(quint8 cmd);              //���Ϳ�����ؿ�������
    void sendCurtainCmd(quint8 cmd);              //���ʹ�����ؿ�������
    void sendKitchenCmd(quint8 cmd);              //���ͳ�����ؿ�������
    void sendModelCmd(quint8 cmd);                //����ģʽ���ƽ���

    //��λ����λ���͵�LED״̬�����������
//    void execBedRoomeLedStatus(quint8 device);     //���ҵ�״̬
//    void execParlourLedStatus(quint8 device);      //������״̬
//    void execKitchenLedStatus(quint8 device);      //������״̬
//    void execCurtainStatus(quint8 device);         //����״̬
    
signals:
    void singnalReceiveData(QByteArray buff);      //��������
    void signalBedRoomTempture(QString);           //�����¶�
    void signalParlourTempture(QString);           //�����¶�
    void signalParlourHumidity(QString);           //����ʪ��
    void signalKitchenSmoke(QString);              //��������Ũ��

    //��λ����λ���͵�LED״̬����
    void signalBedRoomeLedStatus(quint8 device,quint8 cmd);
    void signalParlourLedStatus(quint8 device,quint8 cmd);
    void signalKitchenLedStatus(quint8 device,quint8 cmd);
    //����״̬
    void signalCurtainStatus(quint8 cmd);

    //״̬��Ϣ
    void signalFinished();
    void signalError(QString err);
    
public slots:
    void slotReadData();                           //��ȡ���ݲۺ���
    void slotInitSerialPort();                     //���ڳ�ʼ��

    //�������ݲۺ���
    //void sendData(AnalysisData *);

    void slotSendMessage();
    //���ո����ӽ��洫�ݹ�����Ϣ,��������λ������
    void slotReceiveChildrenValue(quint8 value);

    //���տ������ݹ�������ʪ��Ԥ��ֵ
    void slotReceiveParlourValue(quint8,const QString &);

private:
    quint8 m_sendBegin;			//��ʼ��־  �ԡ�#����ʼ
    quint8 m_potocolLen;		//��Ϣ����  �ɱ䳤
    quint8 m_device;            //�豸��
    quint8 m_deviceCmd;         //�豸����
    quint8 m_dataLen;			//���ݳ���   	û��Ϊ0
    QString m_data;             //����		û��ָ���
    quint8 m_sendEnd;			//������־	�ԡ�@������

    QextSerialPort *m_myCom;
    QByteArray m_temp;          //���ڽ���������ʱ����
    QString strHex;
    AnalysisData *m_analysis;   

    QTimer *m_obotimer;
    unsigned int m_timer_delay;
    unsigned int m_obo_timer_delay;
};

#endif // READSERIALPORTDATA_H
