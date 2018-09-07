/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-04
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�--���������ʵ�֣����������ĵƣ���ʪ��
**************************************************/
#ifndef PARLOURWIDGET_H
#define PARLOURWIDGET_H

#include <QWidget>

class QHBoxLayout;
class LightSettings;            //�ƹ�ģ��
class TemptureSetting;          //�¶�ģ��

class ReadSerialPortData;

namespace Ui{
class Parlourwidget;
}
class Parlourwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Parlourwidget(QWidget *parent = 0);
    ~Parlourwidget();
    
signals:
    
public slots:

    void slotUpdataTemp(QString temp);

private:
    void initModule();
    void initConnect();

private:
    Ui::Parlourwidget *ui;

    LightSettings *m_moduleLight;
    TemptureSetting *m_moduleTemp;

    QHBoxLayout *m_mainLayout;

    ReadSerialPortData *m_tem;
    
};

#endif // PARLOURWIDGET_H
