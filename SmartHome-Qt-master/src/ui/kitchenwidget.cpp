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
#include "kitchenwidget.h"
#include "ui_kitchenwidget.h"
#include <QToolButton>
#include "myapp.h"
#include "control.h"
#include <QDebug>

int set_smoke_density = Myapp::setSmokeValue;

KitchenWidget::KitchenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KitchenWidget)
{
    ui->setupUi(this);

    this->initForm();
    this->init();
    this->initConnect();
    this->refreshSmokeValue();
}

KitchenWidget::~KitchenWidget()
{
    delete ui;
}

void KitchenWidget::initForm()
{
    m_styleOn = "QLabel{border-image:url(:/images/module/light_on.png);border:0px;}";
    m_styleOff = "QLabel{border-image:url(:/images/module/light_off.png);border:0px;}";
    //setLightStyle(m_styleOff);
    ui->pbn_light_main->setFocusPolicy(Qt::NoFocus);

    setToolButtonStyle(ui->tbn_smoke_add,tr("add_smoke"),
                       ":/images/module/temp_add.png");
    setToolButtonStyle(ui->tbn_smoke_sub,tr("sub_smoke"),
                       ":/images/module/temp_sub.png");

    //���������ļ���Ϣͬ��LED��״̬
    if (Myapp::kitchen_led == true){
        ui->pbn_light_main->SetCheck(true);
        ui->label_light_main->setStyleSheet(m_styleOn);
    }else{
        ui->pbn_light_main->SetCheck(false);
        ui->label_light_main->setStyleSheet(m_styleOff);
    }
}

void KitchenWidget::init()
{
}

void KitchenWidget::initConnect()
{
}

void KitchenWidget::refreshSmokeValue()
{
    ui->label_set_smoke->setText(QString::number(set_smoke_density,10));
}

void KitchenWidget::setLightStyle(const QString &styleName)
{
    if  ("m_styleOn" == styleName)
    {
        ui->label_light_main->setStyleSheet(m_styleOn);
        ui->pbn_light_main->SetCheck(true);
    }else
    {
        ui->label_light_main->setStyleSheet(m_styleOff);
        ui->pbn_light_main->SetCheck(false);
    }
}

void KitchenWidget::setToolButtonStyle(QToolButton *tbn,
                                       const QString &text, const QString iconName)
{
    //������ʾ���ı�
    tbn->setText(text);
    tbn->setFont(QFont("��Ȫ���ź�",10,QFont::Normal));

    tbn->setAutoRaise(true);
    //���ð�ťͼ��
    tbn->setIcon(QPixmap(QString("%1").arg(iconName)));
    tbn->setIconSize(QSize(40,40));
    //�����ı���ͼ���±�
    tbn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void KitchenWidget::setLedTurnStatus(quint8 status)
{
    if (LED_ON == status)
    {
        ui->label_light_main->setStyleSheet(m_styleOn);
        ui->pbn_light_main->SetCheck(true);
    }else if (LED_OFF == status)
    {
        ui->label_light_main->setStyleSheet(m_styleOff);
        ui->pbn_light_main->SetCheck(false);
    }
}

//�ı�Ƶ�״̬��ʾ��������Ӧ�������ź�
void KitchenWidget::on_pbn_light_main_clicked()
{
    if (ui->pbn_light_main->GetCheck())
    {
        ui->label_light_main->setStyleSheet(m_styleOn);

        emit signalLight(CMD_KITCHEN_LED_ON);
    }
    else
    {
        ui->label_light_main->setStyleSheet(m_styleOff);

        emit signalLight(CMD_KITCHEN_LED_OFF);
    }

    gIsSendMessage = true;
}

//��������ֵ
void KitchenWidget::slotUpdataSmokeValue(QString smoke)
{
    int temp = 100 - smoke.toInt();
    ui->label_cur_smoke->setText(QString::number(temp)+"%");
    cur_smoke_density = QString::number(temp,10);
#if QDEBUG
    qDebug() <<"kitchen smoke:"<<smoke;
#endif
}

void KitchenWidget::slotUpdataLedStatus(quint8 device, quint8 cmd)
{
    if (MODULE_KITCHIN_LED == device)
    {
        if (CMD_KITCHEN_LED_ON == cmd)
        {
            ui->label_light_main->setStyleSheet(m_styleOn);
            ui->pbn_light_main->SetCheck(true);
#if QDEBUG
            qDebug()<<"kitchen led set on";
#endif
        }else
        {
            ui->label_light_main->setStyleSheet(m_styleOn);
            ui->pbn_light_main->SetCheck(true);
#if QDEBUG
            qDebug()<<"kitchen led set off";
#endif
        }
    }
}

/*
 *��������Ԥ��ֵ
*/
void KitchenWidget::on_tbn_smoke_sub_clicked()
{
    if (set_smoke_density > 0)
        set_smoke_density--;
    emit signalSendSmokeValue(MODULE_SMOKE,QString::number(set_smoke_density));

    refreshSmokeValue();
}

/*
 *��������Ԥ��ֵ
*/
void KitchenWidget::on_tbn_smoke_add_clicked()
{
    if (set_smoke_density <  80)
        set_smoke_density++;
    emit signalSendSmokeValue(MODULE_SMOKE,QString::number(set_smoke_density));
    refreshSmokeValue();
}

//����LED״̬����������ϵͳ������ͬ��
void KitchenWidget::slotSaveLedStatus()
{
    Myapp::kitchen_led = ui->pbn_light_main->GetCheck();
}

void KitchenWidget::slotChangeLedStatus(quint8 status)
{
    switch (status)
    {
    case CMD_TURN_ON_ALL_LED:
        setLedTurnStatus(LED_ON);
        break;
    case CMD_TURN_OFF_ALL_LED:
        setLedTurnStatus(LED_OFF);
        break;
    default:
        break;
    }
}


void KitchenWidget::slotChangeSmokeSetValue(const int &value)
{
    ui->label_set_smoke->setText(QString::number(value));
}
