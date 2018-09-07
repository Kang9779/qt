#include "analysisdata.h"
#include <QDebug>
#include "control.h"

AnalysisData::AnalysisData(QObject *parent) :
    QObject(parent)
{
    initData();
}

//��ʼ�����ݰ�
void AnalysisData::initData()
{
    m_sendBegin = BGN_RESD_MSG;
    m_dataLen = PROTOCOL_BASIC_SIZE;
    m_device = MSG_EMPTY_MODEL;
    m_deviceCmd = MSG_EMPTY_MODEL_CMD;
    m_dataLen = MSG_LEN;
    m_data = MSG_EMPTY_DATA;
    m_sendEnd = END_RESD_MSG;
}

void AnalysisData::packSendData(quint8 drive, quint8 drive_cmd,
                            quint8 data_len, QString data)
{
    m_sendBegin = BGN_RESD_MSG;
    m_dataLen = PROTOCOL_BASIC_SIZE + data_len;
    m_device = drive;
    m_deviceCmd = drive_cmd;
    m_dataLen = data_len;
    m_data = data;
    m_sendEnd = END_RESD_MSG;

    //sendData();
}


/**
 * @Function:       receiveData(Protocol *pro)
 * @Description:    �������ݺ���
 * @Calls:          �ⲿ����
 * @Input:          ���������ݵĽṹ��
 * @Output:         ��
 * @Return:         ��
 * @Others:         ����˵��
 */
void AnalysisData::receiveData(AnalysisData *pro)
{
    switch (pro->m_device) {
    case MODULE_BEEP:
        execModuleBeep(pro);
        break;
    default:
        break;
    }
}

void AnalysisData::execModuleBeep(AnalysisData *pro)
{
    switch (pro->m_deviceCmd) {
        case CMD_BEEP_ON:
            qDebug()<<"beep on!";
            break;
        case CMD_BEEP_OFF:
            qDebug()<<"beep off!";
            break;
        default:
            break;
    }
}

void AnalysisData::printData()
{
#ifdef  QDEBUG
    qDebug()<<"============================";
    qDebug()<<"m_sendBegin:"<<m_sendBegin;
    qDebug()<<"m_potocolLen:"<<m_potocolLen;
    qDebug()<<"m_device:"<<m_device;
    qDebug()<<"m_deviceCmd:"<<m_deviceCmd;
    qDebug()<<"m_dataLen:"<<m_dataLen;
    qDebug()<<"m_data:"<<m_data;
    qDebug()<<"m_sendEnd:"<<m_sendEnd;
    qDebug()<<"============================";

#endif
}
