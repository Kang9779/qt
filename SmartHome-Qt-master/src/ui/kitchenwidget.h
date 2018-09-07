/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-07
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�---�����������ܵ�ʵ�֣���Ҫ������ȼ�������⣬�ƹ����,
            ���Ӳ��֣���ӱ���Ŀ���
**************************************************/
#ifndef KITCHENWIDGET_H
#define KITCHENWIDGET_H

#include <QWidget>
#include "analysisdata.h"

class QToolButton;

namespace Ui {
class KitchenWidget;
}

class KitchenWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit KitchenWidget(QWidget *parent = 0);
    ~KitchenWidget();

private slots:
    void on_pbn_light_main_clicked();

    void slotUpdataSmokeValue(QString); //��������Ũ��ֵ
    //����LED״̬
    void slotUpdataLedStatus(quint8 device,quint8 cmd);

    void on_tbn_smoke_sub_clicked();

    void on_tbn_smoke_add_clicked();

    void slotSaveLedStatus();           //����LED״̬
    void slotChangeLedStatus(quint8 status);         //

signals:
    void signalLight(quint8 model);      //���͵Ƶ�״̬����(��/�ر�)

    //��������Ԥ��ֵ
    void signalSendSmokeValue(quint8,const QString&);

public Q_SLOTS:
    void slotChangeSmokeSetValue(const int &);

private:
    void initForm();
    void init();
    void initConnect();

    void refreshSmokeValue();

    //���õƵ���ʽ
    void setLightStyle(const QString &styleName);
    //���ð�ť��ʽ
    void setToolButtonStyle(QToolButton*tbn, const QString &text,
                            const QString iconName);

    void setLedTurnStatus(quint8 status);
    
private:
    Ui::KitchenWidget *ui;

    QString m_styleOn;                  //�ƴ�
    QString m_styleOff;                 //�ƹر�
};

#endif // KITCHENWIDGET_H
