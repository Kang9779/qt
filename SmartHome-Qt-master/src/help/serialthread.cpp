#include "serialthread.h"
#include <QDebug>
#include "control.h"
#include "myhelper.h"
#include "myapp.h"

#include <QDebug>

SerialThread::SerialThread(QObject *parent):
    QThread(parent)
{
#ifdef Q_OS_LINUX
    //��ʼ�����ڲ�������
    m_myCom = new QextSerialPort("/dev/" + Myapp::linuxPortName);
#elif  defined (Q_OS_WIN)
    m_myCom = new QextSerialPort(Myapp::winPortName);
#endif

    m_isStopped = 0;

    //���ô��ڵ�һЩ����
    m_myCom->setBaudRate(BAUD9600);
    m_myCom->setDataBits(DATA_8);
    m_myCom->setParity(PAR_NONE);
    m_myCom->setStopBits(STOP_1);
    m_myCom->setFlowControl(FLOW_OFF);
    m_myCom->setTimeout(TIME_OUT);

    m_isOpenPort = m_myCom->open(QIODevice::ReadWrite);
    if (m_isOpenPort)
    {
        m_myCom->flush();//��ջ�����
        m_isStopped = true;

#if QDEBUG
        qDebug()<<"open serial ok!";
#endif

    }else
    {
        m_isStopped = false;
#if QDEBUG
        qDebug()<<"open serial failed!";
#endif
    }
}

//�����̣߳�������������
void SerialThread::run()
{
    QByteArray temp;
    while(m_isStopped)
    {
        msleep(1000);                       //delay 1000ms
        if (m_myCom->bytesAvailable() <= 10){return;};
        temp = m_myCom->readAll();

        emit serialFinished(temp);
    }
}

//ֹͣ�߳�
void SerialThread::stopThread()
{
    if (1 == m_isStopped)
        m_isStopped = 0;
}

//�����߳�
void SerialThread::startThread()
{
    if (!m_isOpenPort)
    {
        myHelper::showMessageBoxError(tr("open Serialport fail,please open !"));
        return;
    }else
    {
        if (0 == m_isStopped)
        {
            m_isStopped = 1;
            this->start();
        }
    }
}
