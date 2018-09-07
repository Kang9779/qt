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
#include <QToolButton>
#include "analysisdata.h"

namespace Ui {
class Parlourwidget;
}

class Parlourwidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Parlourwidget(QWidget *parent = 0);
    ~Parlourwidget();

private:

    void initForm();
    void init();
    void initConnect();
    //���ð�ť��ʽ
    void setToolButtonStyle(QToolButton*tbn, const QString &text,
                            const QString iconName);
    //���õƵ���ʽ
    void setLightStyle(const QString &styleName);

    void refreshSensorDefaultValue();       //ˢ�´�������Ĭ��ֵ
    void setLedTurnStatus(quint8 status);

private slots:
    void slot_lightMain();
    void slotLighttop();
    void slotLighthelp();

//    void slotAddTempture();
//    void slotSubTempture();
//    void slotAddHumidity();
//    void slotSubHumidity();

    void slotUpdataTemp(QString);       //�����¶�
    void slotUpdataHum(QString);        //����ʪ��

    //����LED��״̬
    void slotUpdataLedStatus(quint8 device,quint8 cmd);

    void slotSaveLedStatus();           //����LED�Ƶ�״̬
    void slotChangeLedStatus(quint8 status);         //

    void on_tbn_temp_add_clicked();

    void on_tbn_temp_sub_clicked();

    void on_tbn_hum_add_clicked();

    void on_tbn_hum_sub_clicked();

signals:
    //���ҵ�״̬�ź�(MODEL cmd ��/�ر�)
    void signalLightMain(quint8 cmd);
    void signalLightTop(quint8 cmd);
    void signalLightHelp(quint8 cmd);

    //send tempture value
    void signalSendTemptureValue(quint8, const QString&);
    //send humidity value
    void signalSendHumidityVlaue(quint8,const QString&);

public Q_SLOTS:
    void slotChangeTempSetValue(const int &);
    void slotChangeHumSetValue(const int &);
    
private:
    Ui::Parlourwidget *ui;

    QString m_styleOn;                  //�ƴ�
    QString m_styleOff;                 //�ƹر�
};

#endif // PARLOURWIDGET_H
