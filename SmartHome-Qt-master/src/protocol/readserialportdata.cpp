#include "readserialportdata.h"
#include "myapp.h"
#include "myhelper.h"

#include "control.h"

bool gIsSendMessage;
bool gIsOpenPort;
QString cur_parlour_tempture;
QString cur_parlour_humidity;
QString cur_smoke_density;
QByteArray readData;

ReadSerialPortData::ReadSerialPortData(QObject *parent) :
    QObject(parent)
{
    this->openSerialPort();
    this->initData();
    this->init();

    m_analysis = new AnalysisData;
}

ReadSerialPortData::~ReadSerialPortData()
{
    if (m_myCom != NULL)
    {
        delete m_myCom;
        m_myCom = NULL;
    }
}

void ReadSerialPortData::init()
{
    //��ʼ���������ͼ�ʱ����ʱ���
    //    m_obo_timer_delay = OBO_TIMER_INTERVAL;

    //    //�����������ͼ�ʱ��
    //    m_obotimer = new QTimer(this);
    //    //connect(m_obotimer, SIGNAL(timeout()), this, SLOT(slotReceiveChildrenValue(quint8)));
    //    connect(m_obotimer,SIGNAL(timeout()),
    //            this,SLOT(slotSendMessage()));
}

void ReadSerialPortData::openSerialPort()
{
#ifdef Q_OS_LINUX
    //��ʼ�����ڲ�������
    //    m_myCom = new QextSerialPort("/dev/" + Myapp::linuxPortName);
    m_myCom = new QextSerialPort("/dev/ttyUSB0");
    //m_myCom = new QextSerialPort("/dev/ttySAC0");
#elif  defined (Q_OS_WIN)
    m_myCom = new QextSerialPort(Myapp::winPortName);
#endif

    //���ô��ڵ�һЩ����
    m_myCom->setBaudRate(BAUD115200);
    m_myCom->setDataBits(DATA_8);
    m_myCom->setParity(PAR_NONE);
    m_myCom->setStopBits(STOP_1);
    m_myCom->setFlowControl(FLOW_OFF);
    m_myCom->setTimeout(TIME_OUT);

    m_myCom->flush();//��ջ�����

    gIsOpenPort = m_myCom->open(QIODevice::ReadWrite);
    if (gIsOpenPort)
    {

#if QDEBUG
        qDebug()<<"\n\n==================";
        qDebug()<<"open serial port ok!";
        qDebug()<<"\n\n==================";
#endif

    }else
    {
#if QDEBUG
        qDebug()<<"\n\n==================";
        qDebug()<<"open serial port failed!"<<m_myCom->errorString();
        qDebug()<<"\n\n==================";
#endif
    }
}

void ReadSerialPortData::initConnect()
{
    connect(m_myCom,SIGNAL(readyRead()),
            this,SLOT(slotReadData()));
}

void ReadSerialPortData::packSendData(quint8 drive, quint8 drive_cmd,
                                      quint8 data_len, QString data)
{
    m_sendBegin = BGN_RESD_MSG;
    if (data_len > 0)
    {
        m_dataLen = PROTOCOL_BASIC_SIZE + data_len -1;
    }else
    {
        m_dataLen= PROTOCOL_BASIC_SIZE;
    }

    m_device = drive;
    m_deviceCmd = drive_cmd;
    m_dataLen = data_len;
    m_data = data;
    m_sendEnd = END_RESD_MSG;

    sendData();
}

void ReadSerialPortData::sendData()
{
    QByteArray str;
    str.append(m_sendBegin);
    str.append(getProtocolLen());
    str.append(getDevice());
    str.append(getDevieCmd());
    str.append(getDataLen());
    str.append(getData());
    str.append(m_sendEnd);
#if QDEBUG
    QString outData;
    outData = myHelper::ByteArrayToHexStr(str);
    qDebug()<<"==============================";
    qDebug()<<"send data begin:";
    qDebug()<<outData<<"size:"<<outData.size();
    qDebug()<<"==============================";
#endif
    m_myCom->write(str);
    myHelper::Sleep(50);
    m_myCom->write(str);
    initData();
}

void ReadSerialPortData::slotReadData()
{
    //if (m_myCom->bytesAvailable() <= 10)    return;
    if (m_myCom->bytesAvailable() >= 11)
    {
        m_temp = m_myCom->readAll();

        //����֡ͷ�򷵻�
        if (m_temp.at(0) != BGN_RESD_MSG)
        {
#if QDEBUG
            qDebug()<<"the data is not the data of head!";
#endif
            return;
        }
        else
        {
#if QDEBUG
            qDebug()<<"the data of head is ok!";
#endif
            readData = m_temp;
            execCmd(readData);
        }
        m_temp.clear();
    }
}

/**
 * @Function:       slotInitSerialPort()
 * @Description:    ���ڳ�ʼ������
 * @Calls:          �����庯������
 * @Input:          ��
 * @Output:         ��
 * @Return:         ��
 * @Others:         ͨ�����øú�������ʵ�����ô��ڲ�������ȡ��������
 */
void ReadSerialPortData::slotInitSerialPort()
{
    //init();
    initConnect();
#if QDEBUG
    qDebug()<<"thread is run!";
#endif
}

void ReadSerialPortData::slotSendMessage()
{
}

void ReadSerialPortData::slotReceiveChildrenValue(quint8 value)
{
    quint8 model = value;
    switch (model)
    {
    case CMD_BED_ROOM_LED_LEFT_ON:
        sendBedRoomCmd(CMD_BED_ROOM_LED_LEFT_ON);
        break;
    case CMD_BED_ROOM_LED_LEFT_OFF:
        sendBedRoomCmd(CMD_BED_ROOM_LED_LEFT_OFF);
        break;
    case CMD_BED_ROOM_LED_RIGHT_ON:
        sendBedRoomCmd(CMD_BED_ROOM_LED_RIGHT_ON);
        break;
    case CMD_BED_ROOM_LED_RIGHT_OFF:
        sendBedRoomCmd(CMD_BED_ROOM_LED_RIGHT_OFF);
        break;
    case CMD_PARLOUR_LED_MAIN_ON:
        sendParlourCmd(CMD_PARLOUR_LED_MAIN_ON);
        break;
    case CMD_PARLOUR_LED_MAIN_OFF:
        sendParlourCmd(CMD_PARLOUR_LED_MAIN_OFF);
        break;
    case CMD_PARLOUR_LED_TOP_ON:
        sendParlourCmd(CMD_PARLOUR_LED_TOP_ON);
        break;
    case CMD_PARLOUR_LED_TOP_OFF:
        sendParlourCmd(CMD_PARLOUR_LED_TOP_OFF);
        break;
    case CMD_PARLOUR_LED_HELP_ON:
        sendParlourCmd(CMD_PARLOUR_LED_HELP_ON);
        break;
    case CMD_PARLOUR_LED_HELP_OFF:
        sendParlourCmd(CMD_PARLOUR_LED_HELP_OFF);
        break;
    case CMD_KITCHEN_LED_ON:
        sendKitchenCmd(CMD_KITCHEN_LED_ON);
        break;
    case CMD_KITCHEN_LED_OFF:
        sendKitchenCmd(CMD_KITCHEN_LED_OFF);
        break;
    case CMD_CURTAIN_ON:
        sendCurtainCmd(CMD_CURTAIN_ON);
        break;
    case CMD_CURTAIN_STOP:
        sendCurtainCmd(CMD_CURTAIN_STOP);
        break;
    case CMD_CURTAIN_OFF:
        sendCurtainCmd(CMD_CURTAIN_OFF);
        break;
    case CMD_GO_HOME_ON:
        sendModelCmd(CMD_GO_HOME_ON);
        break;
    case CMD_GO_HOME_OFF:
        sendModelCmd(CMD_GO_HOME_OFF);
        break;
#if 0
    case CMD_LEAVE_HOME_ON:
        sendModelCmd(CMD_LEAVE_HOME_ON);
        break;
    case CMD_LEAVE_HOME_OFF:
        sendModelCmd(CMD_LEAVE_HOME_OFF);
        break;
#endif
    case CMD_TURN_ON_ALL_LED:
        sendModelCmd(CMD_TURN_ON_ALL_LED);
        break;
    case CMD_TURN_OFF_ALL_LED:
        sendModelCmd(CMD_TURN_OFF_ALL_LED);
        break;
    default:
        break;
    }
}

/*���տ������洫�ݹ�������ʪ��Ԥ��ֵ
 *������model:�¶Ȼ���ʪ��
 *     value:��Ӧ��ֵ
 **/
void ReadSerialPortData::slotReceiveParlourValue(quint8 model, const QString &value)
{
    quint8 data_len = value.length();
#if QDEBUG
    qDebug()<<"model:"<<model;
    qDebug()<<"value:"<<value;
    qDebug()<<"data_len:"<<data_len<<endl;
#endif
    switch (model)
    {
    case MODULE_DS18B20:
        packSendData(MODULE_DS18B20,PROTOCOL_FULL_DATA,data_len,value);
        break;
    case MODULE_DHT11_HUM:
        packSendData(MODULE_DHT11_HUM,PROTOCOL_FULL_DATA,data_len,value);
        break;
    case MODULE_SMOKE:
        packSendData(MODULE_SMOKE,PROTOCOL_FULL_DATA,data_len,value);
        break;
    default:
        break;
    }

}

quint8 ReadSerialPortData::getProtocolLen()
{
    return m_potocolLen;
}

quint8 ReadSerialPortData::getDevice()
{
    return m_device;
}

quint8 ReadSerialPortData::getDevieCmd()
{
    return m_deviceCmd;
}

quint8 ReadSerialPortData::getDataLen()
{
    return m_dataLen;
}

QString ReadSerialPortData::getData()
{
    return m_data;
}

/**
 * @Function:       execCmd(QByteArray buff)
 * @Description:    �������ݺ���
 * @Calls:          ���ļ�����
 * @Input:          �ֽ�����(����һ֡����)
 * @Output:         ��
 * @Return:         ��
 * @Others:         һ֡����������һ�¸�ʽ��
 *      23 0B 38 00 05 32 30 00 00 00 40
 *      0   1  2  3  4  5  6  7  8  9 10
 *�޸�˵����
 *2016-1-10 13:30:05  �����޸Ľ���������֮ǰֱ�Ӷ�ȡ�Լ���������
 *                    ��ɷ���Խ�磡(�������ݷ��͹����У����ݲ�����)
 *2016-1-10 17:30:30���ֽ���������������У����׽���˷���Խ�������!
 */
void ReadSerialPortData::execCmd(QByteArray buff)
{
#if 0
    switch (buff.at(2))
    {
    case MODULE_DS18B20:
        execDs18b20Data(buff);
        break;
    case MODULE_DHT11_TEMP:
        execDHT11_TemData(buff);
        break;
    case MODULE_DHT11_HUM:
        execDHT11_HumData(buff);
        break;
    case MODULE_SMOKE:
        execSMOKEData(buff);
        break;
    default:
        break;
    }
#endif
    initData(); //�������
#if 0
    quint8 data = 5;
    m_sendBegin = buff.at(0);
    m_dataLen = buff.at(1);
    m_device = buff.at(2);
    m_deviceCmd = buff.at(3);
    m_dataLen = buff.at(4);
    if (m_dataLen > 0)
    {
        while (buff.at(data) != END_RESD_MSG)
        {
            m_data += QString(buff.at(data));
            data++;
        }
    }
    else
    {
        m_data = "";
    }

    //m_sendEnd = buff.at(6);
    execData();
#endif

    //���ֽ��������
    QDataStream out(&buff, QIODevice::ReadWrite);
    while (!out.atEnd())
    {
        qint8 outChar = 0;
        out >> outChar; //ÿ�ֽ����һ�Σ�ֱ������
        //ʮ�����Ƶ�ת��
        QString str = QString("%1").
                arg(outChar&0xFF, 2, 16, QLatin1Char('0'));
        strHex += str;
    }

    bool ok;
    m_sendBegin = strHex.left(2).toUInt(&ok,16);
    m_potocolLen = strHex.mid(2,2).toUInt(&ok,16);
    m_device = strHex.mid(4,2).toUInt(&ok,16);
    m_deviceCmd = strHex.mid(6,2).toUInt(&ok,16);
    m_dataLen = strHex.mid(8,2).toUInt(&ok,16);

    if (m_dataLen > 0)
    {
        quint8 tens;
        quint8 unit;
        //����ֻ������2���ֽڣ���ȫ�棬������ʵ���յ������ݷ�����
        //��������������ֻ��2���ֽ�
        if (strHex.mid(10,2) != "00")
        {
            tens = strHex.mid(10,2).toUInt(&ok,16)-
                    DATA_TO_ASCII;
        }if (strHex.mid(12,2) != "00")
        {
            unit = strHex.mid(12,2).toUInt(&ok,16)-
                    DATA_TO_ASCII;
        }
        m_data = QString::number(tens).append(QString::number(unit));
    }

    m_sendEnd = strHex.right(2).toUInt(&ok,16);
#if QDEBUG
    //    qDebug()<<"m_sendBegin:"<<m_sendBegin;
    //    qDebug()<<"m_potocolLen:"<<m_potocolLen;
    //    qDebug()<<"m_device:"<<m_device;
    //    qDebug()<<"m_deviceCmd:"<<m_deviceCmd;
    //    qDebug()<<"m_dataLen:"<<m_dataLen;
    //    qDebug()<<"m_data:"<<m_data;
    //    qDebug()<<"m_sendEnd:"<<m_sendEnd;

    //���һ֡����������
    qDebug()<<strHex.toUpper();
#endif

    strHex = "";        //���
    execData();         //��������
}

void ReadSerialPortData::execData()
{
    switch (m_device)
    {
    case MODULE_DS18B20:
        emit signalParlourTempture(m_data);
        break;
    case MODULE_DHT11_TEMP:
        emit signalBedRoomTempture(m_data);
        break;
    case MODULE_DHT11_HUM:
        emit signalParlourHumidity(m_data);
        break;
    case MODULE_SMOKE:
        emit signalKitchenSmoke(m_data);
        break;
    case MODULE_BED_ROOM_LED_LEFT:
        emit signalBedRoomeLedStatus(MODULE_BED_ROOM_LED_LEFT,
                                     m_deviceCmd);
        break;
    case MODULE_BED_ROOM_LED_RIGHT:
        emit signalBedRoomeLedStatus(MODULE_BED_ROOM_LED_RIGHT,
                                     m_deviceCmd);
        break;
    case MODULE_PARLOUR_LED_MAIN:
        emit signalParlourLedStatus(MODULE_PARLOUR_LED_MAIN,
                                    m_deviceCmd);
        break;
    case MODULE_PARLOUR_LED_TOP:
        emit signalParlourLedStatus(MODULE_PARLOUR_LED_TOP,
                                    m_deviceCmd);
        break;
    case MODULE_PARLOUR_LED_HELP:
        emit signalParlourLedStatus(MODULE_PARLOUR_LED_HELP,
                                    m_deviceCmd);
        break;
    case MODULE_KITCHIN_LED:
        emit signalKitchenLedStatus(MODULE_KITCHIN_LED,
                                    m_deviceCmd);
        break;
    case MODULE_CURTAIN:
        emit signalCurtainStatus(m_deviceCmd);
        break;
    default:
        break;
    }
}

void ReadSerialPortData::initData()
{
    m_sendBegin     = BGN_RESD_MSG;
    m_dataLen       = PROTOCOL_BASIC_SIZE;
    m_device        = MSG_EMPTY_MODEL;
    m_deviceCmd     = MSG_EMPTY_MODEL_CMD;
    m_dataLen       = MSG_LEN;
    m_data          = MSG_EMPTY_DATA;
    m_sendEnd       = END_RESD_MSG;
}

//���������¶�ֵ
void ReadSerialPortData::execDs18b20Data(QByteArray buff)
{
    QString tempture;
    quint8 length = buff.at(4);
    for (int i = 5; i < 5+length ;i++)
    {
        tempture += QString(buff.at(i));
    }

    //�����¶�ֵ
    //cur_parlour_tempture = tempture;

    emit signalParlourTempture(tempture);
#if QDEBUG
    qDebug()<<"DS18B20:"<<tempture;
#endif
}

//��������ʪ��ֵ
void ReadSerialPortData::execDHT11_HumData(QByteArray buff)
{
    QString humidity;
    quint8 length = buff.at(4);
    for (int i = 5; i < 5+length ;i++)
    {
        humidity += QString(buff.at(i));
    }

    //����ʪ��ֵ
    //cur_parlour_humidity = humidity;

    emit signalParlourHumidity(humidity);
#if QDEBUG
    qDebug()<<"DHT11_HUM:"<<humidity;
#endif
}

//���������¶�ֵ
void ReadSerialPortData::execDHT11_TemData(QByteArray buff)
{
    QString tempture;
    quint8 length = buff.at(4);
    for (int i = 5; i < 5+length ;i++)
    {
        tempture += QString(buff.at(i));
    }

    emit signalBedRoomTempture(tempture);
#if QDEBUG
    qDebug()<<"DHT11_Tem:"<<tempture;
#endif
}

//��������Ũ��ֵ
void ReadSerialPortData::execSMOKEData(QByteArray buff)
{
    QString smoke;
    quint8 length = buff.at(4);
    for (int i = 5; i < 5+length ;i++)
    {
        smoke += QString(buff.at(i));
    }

    //��������ֵ
    //cur_smoke_density = smoke;

    emit signalKitchenSmoke(smoke);
#if QDEBUG
    qDebug()<<"SMOKE:"<<smoke;
#endif
}

//���ҵƿ�������ͺ���
void ReadSerialPortData::sendBedRoomCmd(quint8 device)
{
    if (CMD_BED_ROOM_LED_LEFT_ON == device)
    {
        packSendData(MODULE_BED_ROOM_LED_LEFT,
                     CMD_BED_ROOM_LED_LEFT_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_BED_ROOM_LED_LEFT_OFF == device)
    {
        packSendData(MODULE_BED_ROOM_LED_LEFT,
                     CMD_BED_ROOM_LED_LEFT_OFF,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_BED_ROOM_LED_RIGHT_ON == device)
    {
        packSendData(MODULE_BED_ROOM_LED_RIGHT,
                     CMD_BED_ROOM_LED_RIGHT_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_BED_ROOM_LED_RIGHT_OFF == device)
    {
        packSendData(MODULE_BED_ROOM_LED_RIGHT,
                     CMD_BED_ROOM_LED_RIGHT_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
}

//�����ƿ�������ͺ���
void ReadSerialPortData::sendParlourCmd(quint8 cmd)
{
    if (CMD_PARLOUR_LED_MAIN_ON == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_MAIN,
                     CMD_PARLOUR_LED_MAIN_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_PARLOUR_LED_MAIN_OFF == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_MAIN,
                     CMD_PARLOUR_LED_MAIN_OFF,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_PARLOUR_LED_TOP_ON == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_TOP,
                     CMD_PARLOUR_LED_TOP_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_PARLOUR_LED_TOP_OFF == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_TOP,
                     CMD_PARLOUR_LED_TOP_OFF,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_PARLOUR_LED_HELP_ON == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_HELP,
                     CMD_PARLOUR_LED_HELP_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_PARLOUR_LED_HELP_OFF == cmd)
    {
        packSendData(MODULE_PARLOUR_LED_HELP,
                     CMD_PARLOUR_LED_HELP_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
}

//������������ͺ���
void ReadSerialPortData::sendCurtainCmd(quint8 cmd)
{
    if (CMD_CURTAIN_ON == cmd)
    {
        packSendData(MODULE_CURTAIN,CMD_CURTAIN_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_CURTAIN_STOP == cmd)
    {
        packSendData(MODULE_CURTAIN,CMD_CURTAIN_STOP,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_CURTAIN_OFF == cmd)
    {
        packSendData(MODULE_CURTAIN,CMD_CURTAIN_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
}

//�����ƿ�������ͺ���
void ReadSerialPortData::sendKitchenCmd(quint8 cmd)
{
    if (CMD_KITCHEN_LED_ON == cmd)
    {
        packSendData(MODULE_KITCHIN_LED,
                     CMD_KITCHEN_LED_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_KITCHEN_LED_OFF == cmd)
    {
        packSendData(MODULE_KITCHIN_LED,
                     CMD_KITCHEN_LED_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
}

//����ģʽ���������
void ReadSerialPortData::sendModelCmd(quint8 cmd)
{
    if (CMD_GO_HOME_ON == cmd)
    {
        packSendData(MODULE_GO_HOME,
                     CMD_GO_HOME_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_GO_HOME_OFF == cmd)
    {
        packSendData(MODULE_GO_HOME,
                     CMD_GO_HOME_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
#if 0
    else if (CMD_LEAVE_HOME_ON == cmd)
    {
        packSendData(MODULE_LEAVE_HOME,
                     CMD_LEAVE_HOME_ON,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_LEAVE_HOME_OFF == cmd)
    {
        packSendData(MODULE_LEAVE_HOME,
                     CMD_LEAVE_HOME_OFF,
                     PROTOCOL_FULL_CMD,"");
    }
#endif
    else if (CMD_TURN_ON_ALL_LED == cmd)
    {
        packSendData(MODULE_ALL_LED,
                     CMD_TURN_ON_ALL_LED,
                     PROTOCOL_FULL_CMD,"");
    }else if (CMD_TURN_OFF_ALL_LED == cmd)
    {
        packSendData(MODULE_ALL_LED,
                     CMD_TURN_OFF_ALL_LED,
                     PROTOCOL_FULL_CMD,"");
    }
}
