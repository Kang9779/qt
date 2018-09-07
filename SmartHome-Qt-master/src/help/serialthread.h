/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-1-19
Email:kevinlq0912@163.com
QQ:936563422
Description:���ö��߳̽��մ���������ķ�װ
*************************************************/
#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QString>
#include "qextserialport.h"

//��ʱ��TIME_OUT�Ǵ��ڶ�д����ʱ
#define TIME_OUT 100

//�������Ͷ�ʱ����ʱ���,200ms
#define OBO_TIMER_INTERVAL 200

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = 0);

    void run();
    void stopThread();
    void startThread();
    
signals:
    void serialFinished(QByteArray temp);
    
public slots:

private:
    QextSerialPort *m_myCom;     //
    bool m_isStopped;
    bool m_isOpenPort;
};

#endif // SERIALTHREAD_H
