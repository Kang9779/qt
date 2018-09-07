/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-06
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�--���ҽ����ʵ�֣��������Ҵ�ͷ�ĵ�
**************************************************/
#include "bedroomwidget.h"
#include "ui_BedRoomWidget.h"
#include <QToolButton>

#include <QDebug>
#include "myapp.h"
#include "control.h"

BedRoomWidget::BedRoomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BedRoomWidget)
{
    ui->setupUi(this);


    this->initForm();
    this->init();
    this->initConnect();
}

BedRoomWidget::~BedRoomWidget()
{
    delete ui;
}

void BedRoomWidget::initForm()
{
    ui->label_device->setVisible(false);
    //������ʽ
    m_styleOn = "QLabel{border-image:url(:/images/module/light_on.png);border:0px;}";
    m_styleOff = "QLabel{border-image:url(:/images/module/light_off.png);border:0px;}";
    //setLightStyle(m_styleOff);

    ui->pbn_light_right->setFocusPolicy(Qt::NoFocus);
    ui->pbn_light_left->setFocusPolicy(Qt::NoFocus);

    //���������ļ���ʼ��LED��״̬
    if (Myapp::bed_room_led_left == true)
    {
        ui->label_light_top->setStyleSheet(m_styleOn);
        ui->pbn_light_left->SetCheck(true);
    }
    else
    {
        ui->label_light_top->setStyleSheet(m_styleOff);
        ui->pbn_light_left->SetCheck(false);
    }
    if (Myapp::bed_room_led_right == true)
    {
        ui->pbn_light_right->SetCheck(true);
        ui->label_light_help->setStyleSheet(m_styleOn);
    }
    else
    {
        ui->pbn_light_right->SetCheck(false);
        ui->label_light_help->setStyleSheet(m_styleOff);
    }
}

void BedRoomWidget::init()
{
}

//�źźͲ۳�ʼ��
void BedRoomWidget::initConnect()
{
    connect(ui->pbn_light_left,SIGNAL(clicked()),
            this,SLOT(slotLightLeft()));
    connect(ui->pbn_light_right,SIGNAL(clicked()),
            this,SLOT(slotLightRight()));
}

void BedRoomWidget::setLightStyle(const QString styleName)
{
    if (styleName == "m_styleOn")
    {
        ui->label_light_top->setStyleSheet(m_styleOn);
        ui->label_light_help->setStyleSheet(m_styleOn);
        ui->pbn_light_left->SetCheck(true);
        ui->pbn_light_right->SetCheck(true);
    }else
    {
        ui->label_light_top->setStyleSheet(m_styleOff);
        ui->label_light_help->setStyleSheet(m_styleOff);
        ui->pbn_light_left->SetCheck(false);
        ui->pbn_light_right->SetCheck(false);
    }
}

void BedRoomWidget::setLedTurnStatus(quint8 status)
{
    if (LED_ON == status)
    {
        ui->label_light_top->setStyleSheet(m_styleOn);
        ui->label_light_help->setStyleSheet(m_styleOn);
        ui->pbn_light_left->SetCheck(true);
        ui->pbn_light_right->SetCheck(true);
    }else if (LED_OFF == status)
    {
        ui->label_light_top->setStyleSheet(m_styleOff);
        ui->label_light_help->setStyleSheet(m_styleOff);
        ui->pbn_light_left->SetCheck(false);
        ui->pbn_light_right->SetCheck(false);
    }

}

//������ͷ��״̬�ı��Լ�����״̬�ź�
void BedRoomWidget::slotLightLeft()
{
    if (ui->pbn_light_left->GetCheck())
    {
        ui->label_light_top->setStyleSheet(m_styleOn);

        emit signalLightLeft(CMD_BED_ROOM_LED_LEFT_ON);
    }
    else
    {
        ui->label_light_top->setStyleSheet(m_styleOff);

        emit signalLightLeft(CMD_BED_ROOM_LED_LEFT_OFF);
    }

    gIsSendMessage = true;
}

//�����Ҵ�ͷ��״̬�ı��Լ�����״̬�ź�
void BedRoomWidget::slotLightRight()
{
    if (ui->pbn_light_right->GetCheck())
    {
        ui->label_light_help->setStyleSheet(m_styleOn);

        emit signalLightRight(CMD_BED_ROOM_LED_RIGHT_ON);
    }
    else
    {
        ui->label_light_help->setStyleSheet(m_styleOff);

        emit signalLightRight(CMD_BED_ROOM_LED_RIGHT_OFF);
    }
    gIsSendMessage = true;
}

//������ʾ�¶�ֵ
void BedRoomWidget::slotUpdataTemp(QString temp)
{
    ui->label_cur_temp->setText(temp);
#if QDEBUG
    qDebug()<<"Cur parlour tempture:"<<temp;
#endif
}

//����LED�Ƶ�״̬
void BedRoomWidget::slotUpdataLedStatus(quint8 device, quint8 cmd)
{
    if ( MODULE_BED_ROOM_LED_LEFT == device)
    {
        if (CMD_BED_ROOM_LED_LEFT_ON == cmd){
            ui->pbn_light_left->SetCheck(true);
            ui->label_light_top->setStyleSheet(m_styleOn);
#if QDEBUG
             qDebug()<<"bed_room led_left set on";
#endif
        }else{
            ui->pbn_light_left->SetCheck(false);
            ui->label_light_top->setStyleSheet(m_styleOff);
#if QDEBUG
            qDebug()<<"bed_room led_left set off";
#endif
        }
    }else if ( MODULE_BED_ROOM_LED_RIGHT == device)
    {
        if (CMD_BED_ROOM_LED_RIGHT_ON == cmd){
            ui->pbn_light_right->SetCheck(true);
            ui->label_light_help->setStyleSheet(m_styleOn);
#if QDEBUG
            qDebug()<<"bed_room led_right set on";
#endif
        }else{
            ui->pbn_light_right->SetCheck(false);
            ui->label_light_help->setStyleSheet(m_styleOff);
#if QDEBUG
            qDebug()<<"bed_room led_right set off";
#endif
        }
    }
}

//����Ƶ�״̬��д�������ļ�
void BedRoomWidget::slotSaveLedStatus()
{
    Myapp::bed_room_led_left = ui->pbn_light_left->GetCheck();
    Myapp::bed_room_led_right = ui->pbn_light_right->GetCheck();

    Myapp::WriteConfig();
}

//�����ı�LED��״̬
void BedRoomWidget::slotChangeLedStatus(quint8 status)
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
