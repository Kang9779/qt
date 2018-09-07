/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-08
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�---���ݴ涨ʱ���̵߳�ʵ��
**************************************************/
#include "savedatathread.h"
#include <QDebug>
#include "sqlhelp.h"
#include "control.h"
#include "myhelper.h"
#include <QSqlQuery>
#include <QSqlError>

SaveDataThread::SaveDataThread(QObject *parent) :
    QThread(parent)
{
    this->initForm();
}

SaveDataThread::~SaveDataThread()
{
    if (m_sqlHelp != NULL)
    {
        delete m_sqlHelp;
        m_sqlHelp = NULL;
    }
}

void SaveDataThread::run()
{
#if QDEBUG
    qDebug()<<"=======================\n";
    qDebug()<<"start save sensor data!";
    qDebug()<<"=======================\n";
#endif
    while (m_isStop)
    {
        msleep(1000);
        m_count++;

        if ( SAVE_DATA_INTERVAL ==  m_count)
        {
            //�������ݣ��������ݣ��������ݲ������ݿ���
#if QDEBUG
            qDebug()<<"\n\n================================";
            qDebug() << SAVE_DATA_INTERVAL<<" come!";
#endif
#if 0
            //��������ֵ
            this->insertData(DEVICE_SMOKE,cur_smoke_density);
            //�����¶�ֵ
            this->insertData(DEVICE_TEMP,cur_parlour_tempture);
            //����ʪ��ֵ
            this->insertData(DEVICE_HUM,cur_parlour_humidity);
#endif
            //��������
            this->insertData();

            emit signalUpdataData();
            m_count = 0;
        }
    }
}

void SaveDataThread::stopSaveThread()
{
    if (1 == m_isStop)
        m_isStop = 0;
}

void SaveDataThread::initForm()
{
    m_isStop = 1;
    m_count = 0;
}

void SaveDataThread::setStartTime(QTime time)
{
    m_time = time;

    m_sqlHelp = new SqlHelp;
}

/**
 * @Function:       insertData(enumDeviceName deviceName,
                                const QString &value)
 * @Description:    �����ݲ��뵽���ݿ���
 * @Calls:          ���ص���
 * @Input:          ��
 * @Output:         ��
 * @Return:         ��
 * @Others:         ����˵��
 * �޸�˵����
 * ʱ�䣺2016��1��20��16:45:02
 * �޸����ݣ�����ʵ�����ݱ���ķ�ʽ��������������ķ�ʽ��
 *          ֮ǰ�������������и������������������������棡
 */
void SaveDataThread::insertData()
{
#if 0
    QString currentDataTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString sql = "INSERT INTO device_info(device_id,";
    sql += "device_value,device_data,remark) VALUES('";
    sql += deviceName +"','" + value+"','" + currentDataTime + "','" + "')";

#if QDEBUG
    qDebug()<<"insert data:"<<sql;
#endif
    m_sqlHelp->ExecuteSql(sql);
#endif

    QString currentDataTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QSqlQuery query;
    query.exec("INSERT INTO[device_info] (device_id,device_value,device_data,remark) VALUES(?,?,?,?)");

    QVariantList sensor_id;
    sensor_id <<DEVICE_TEMP << DEVICE_HUM <<DEVICE_SMOKE;
    query.addBindValue(sensor_id);
    QVariantList sensor_value;
    sensor_value << cur_parlour_tempture <<cur_parlour_humidity
                    <<cur_smoke_density;
    query.addBindValue(sensor_value);
    QVariantList sensor_data;
    sensor_data << currentDataTime
                << QString::number(currentDataTime.toLongLong() +1)
                << QString::number(currentDataTime.toLongLong() +2);
    query.addBindValue(sensor_data);
    QVariantList sensor_remark;
    sensor_remark <<"" <<"" <<"";
    query.addBindValue(sensor_remark);

    try {
        if (!query.execBatch())
        {
#if QDEBUG
            qDebug()<<query.lastQuery();
            qDebug()<<query.lastError();
            return;
#endif
        }else
        {
#if     QDEBUG
            qDebug()<<"\n=================\n";
            qDebug()<<"save data ok!\n";
            qDebug()<<"\n=================\n";
#endif
        }

    } catch (...) {
        qDebug()<<"Add New Sensor Data error!\nUnable to add \
                  a new Data!/n/n";
    }

}
