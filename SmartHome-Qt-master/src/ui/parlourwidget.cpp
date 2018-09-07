/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-04
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�--���������ʵ�֣����������ĵƣ���ʪ��
**************************************************/
#include "parlourwidget.h"
#include "ui_Parlourwidget.h"

#include <QDebug>

#include "control.h"
#include "myapp.h"

//Ԥ���¶�ֵ��ʪ��ֵ
int set_parlour_tempture = Myapp::setTempValue;
int set_parlour_humidity = Myapp::setHumValue;

Parlourwidget::Parlourwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parlourwidget)
{
    ui->setupUi(this);

    this->initForm();
    this->init();
    this->initConnect();
}

Parlourwidget::~Parlourwidget()
{
    delete ui;
}

void Parlourwidget::initForm()
{
    this->setToolButtonStyle(ui->tbn_temp_add,tr("tempture_add"),
                             ":/images/module/temp_add.png");
    this->setToolButtonStyle(ui->tbn_temp_sub,tr("tempture_sub"),
                             ":/images/module/temp_sub.png");
    this->setToolButtonStyle(ui->tbn_hum_add,tr("humidity_add"),
                             ":/images/module/temp_add.png");
    this->setToolButtonStyle(ui->tbn_hum_sub,tr("humidity_sub"),
                             ":/images/module/temp_sub.png");

    m_styleOn = "QLabel{border-image:url(:/images/module/light_on.png);border:0px;}";
    m_styleOff = "QLabel{border-image:url(:/images/module/light_off.png);border:0px;}";
    //setLightStyle(m_styleOff);

    ui->pbn_light_main->setFocusPolicy(Qt::NoFocus);
    ui->pbn_light_top->setFocusPolicy(Qt::NoFocus);
    ui->pbn_light_help->setFocusPolicy(Qt::NoFocus);

    //��ʪ��Ԥ��ֵ����
    ui->label_set_hum->setText(QString::number(set_parlour_tempture));
    ui->label_set_temp->setText(QString::number(set_parlour_humidity));

    //���������ļ�״̬��Ϣ��ͬ�������Ƶ�״̬��Ϣ
    if (Myapp::parlour_led_main == true){
        ui->pbn_light_main->SetCheck(true);
        ui->label_light_main->setStyleSheet(m_styleOn);
    }else{
        ui->pbn_light_main->SetCheck(false);
        ui->label_light_main->setStyleSheet(m_styleOff);
    }
    if (Myapp::parlour_led_top == true){
        ui->pbn_light_top->SetCheck(true);
        ui->label_light_top->setStyleSheet(m_styleOn);
    }else{
        ui->pbn_light_top->SetCheck(false);
        ui->label_light_top->setStyleSheet(m_styleOff);
    }
    if (Myapp::parlour_led_help == true){
        ui->pbn_light_help->SetCheck(true);
        ui->label_light_help->setStyleSheet(m_styleOn);
    }else{
        ui->pbn_light_help->SetCheck(false);
        ui->label_light_help->setStyleSheet(m_styleOff);
    }
}

void Parlourwidget::init()
{
}

//��ʼ���źźͲ۵�����
void Parlourwidget::initConnect()
{
    //�ı�Ƶ�״̬
    connect(ui->pbn_light_main,SIGNAL(clicked()),
            this,SLOT(slot_lightMain()));
    connect(ui->pbn_light_top,SIGNAL(clicked()),
            this,SLOT(slotLighttop()));
    connect(ui->pbn_light_help,SIGNAL(clicked()),
            this,SLOT(slotLighthelp()));

    //���Ӻͼ����¶�
//    connect(ui->tbn_temp_add,SIGNAL(clicked()),
//            this,SLOT(slotAddTempture()));
//    connect(ui->tbn_temp_sub,SIGNAL(clicked()),
//            this,SLOT(slotSubTempture()));
    //���Ӻͼ���ʪ��ֵ
//    connect(ui->tbn_hum_add,SIGNAL(clicked()),
//            this,SLOT(slotAddHumidity()));
//    connect(ui->tbn_hum_sub,SIGNAL(clicked()),
//            this,SLOT(slotSubHumidity()));
}

void Parlourwidget::setToolButtonStyle(QToolButton *tbn,
                                       const QString &text,
                                       const QString iconName)
{
    //������ʾ���ı�
    tbn->setText(text);
    //tbn->setFont(QFont("��Ȫ���ź�",10,QFont::Normal));

    tbn->setAutoRaise(true);
    //���ð�ťͼ��
    tbn->setIcon(QPixmap(QString("%1").arg(iconName)));
    tbn->setIconSize(QSize(40,40));
    //�����ı���ͼ���±�
    tbn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

//���õƵ���ʽ
void Parlourwidget::setLightStyle(const QString &styleName)
{
    if (styleName == "m_styleOn")
    {
        ui->label_light_main->setStyleSheet(m_styleOn);
        ui->label_light_top->setStyleSheet(m_styleOn);
        ui->label_light_help->setStyleSheet(m_styleOn);
        ui->pbn_light_main->SetCheck(true);
        ui->pbn_light_top->SetCheck(true);
        ui->pbn_light_help->SetCheck(true);
    }else
    {
        ui->label_light_main->setStyleSheet(m_styleOff);
        ui->label_light_top->setStyleSheet(m_styleOff);
        ui->label_light_help->setStyleSheet(m_styleOff);
        ui->pbn_light_main->SetCheck(false);
        ui->pbn_light_top->SetCheck(false);
        ui->pbn_light_help->SetCheck(false);
    }

}

/**
 * @Function:       refreshSensorDefaultValue()
 * @Description:    ˢ�´�������ֵ
 * @Calls:          ������������
 * @Input:          ��
 * @Output:         ��
 * @Return:         ��
 * @Others:         ���ڸı䴫����ֵʱˢ����ʾ
 */
void Parlourwidget::refreshSensorDefaultValue()
{
    ui->label_set_temp->setText(QString::number(set_parlour_tempture,10));
    ui->label_set_hum->setText(QString::number(set_parlour_humidity,10)+
                               "%");;
}

void Parlourwidget::setLedTurnStatus(quint8 status)
{
    if (LED_ON == status)
    {
        ui->label_light_main->setStyleSheet(m_styleOn);
        ui->label_light_top->setStyleSheet(m_styleOn);
        ui->label_light_help->setStyleSheet(m_styleOn);
        ui->pbn_light_main->SetCheck(true);
        ui->pbn_light_top->SetCheck(true);
        ui->pbn_light_help->SetCheck(true);
    }else if (LED_OFF == status)
    {
        ui->label_light_main->setStyleSheet(m_styleOff);
        ui->label_light_top->setStyleSheet(m_styleOff);
        ui->label_light_help->setStyleSheet(m_styleOff);
        ui->pbn_light_main->SetCheck(false);
        ui->pbn_light_top->SetCheck(false);
        ui->pbn_light_help->SetCheck(false);
    }

}

//��������״̬�ı䷢����Ӧ���ź�
void Parlourwidget::slot_lightMain()
{
    if (ui->pbn_light_main->GetCheck())
    {
        ui->label_light_main->setStyleSheet(m_styleOn);
        emit signalLightMain(CMD_PARLOUR_LED_MAIN_ON);
    }
    else
    {
        ui->label_light_main->setStyleSheet(m_styleOff);
        emit signalLightMain(CMD_PARLOUR_LED_MAIN_OFF);
    }

    gIsSendMessage = true;
}

//��������״̬�ı䷢����Ӧ���ź�
void Parlourwidget::slotLighttop()
{
    if (ui->pbn_light_top->GetCheck())
    {
        ui->label_light_top->setStyleSheet(m_styleOn);

        emit signalLightTop(CMD_PARLOUR_LED_TOP_ON);
    }
    else
    {
        ui->label_light_top->setStyleSheet(m_styleOff);

        emit signalLightTop(CMD_PARLOUR_LED_TOP_OFF);
    }

    gIsSendMessage = true;
}

//��������״̬�����ı�ʱ������Ӧ���ź�
void Parlourwidget::slotLighthelp()
{
    if (ui->pbn_light_help->GetCheck())
    {
        ui->label_light_help->setStyleSheet(m_styleOn);

        emit signalLightHelp(CMD_PARLOUR_LED_HELP_ON);
    }
    else
    {
        ui->label_light_help->setStyleSheet(m_styleOff);

        emit signalLightHelp(CMD_PARLOUR_LED_HELP_OFF);
    }

    gIsSendMessage = true;
}

//������ʾ�¶�ֵ
void Parlourwidget::slotUpdataTemp(QString temp)
{
    ui->label_cur_temp->setText(temp);
    cur_parlour_tempture = temp;
    qDebug()<<"Cur parlour tempture:"<<temp;
}

//������ʾʪ��ֵ
void Parlourwidget::slotUpdataHum(QString hum)
{
    ui->label_cur_hum->setText(hum+"%");
    cur_parlour_humidity = hum;
#if QDEBUG
    qDebug()<<"Cur Parlout humidity:"<<hum;
#endif
}

//����LED״̬
void Parlourwidget::slotUpdataLedStatus(quint8 device, quint8 cmd)
{
    if (MODULE_PARLOUR_LED_MAIN == device)
    {
        if (CMD_PARLOUR_LED_MAIN_ON == cmd)
        {
            ui->label_light_main->setStyleSheet(m_styleOn);
            ui->pbn_light_main->SetCheck(true);
#if QDEBUG
            qDebug()<<"parlour led_main set on";
#endif
        }else
        {
            ui->label_light_main->setStyleSheet(m_styleOff);
            ui->pbn_light_main->SetCheck(false);
#if QDEBUG
            qDebug()<<"parlour led_main set off";
#endif
        }
    }else if (MODULE_PARLOUR_LED_TOP == device)
    {
        if (CMD_PARLOUR_LED_TOP_ON == cmd)
        {
            ui->label_light_top->setStyleSheet(m_styleOn);
            ui->pbn_light_top->SetCheck(true);
#if QDEBUG
            qDebug()<<"parlour led_top set on";
#endif
        }else
        {
            ui->label_light_top->setStyleSheet(m_styleOff);
            ui->pbn_light_top->SetCheck(false);
#if QDEBUG
            qDebug()<<"parlour led_top set off";
#endif
        }
    }else if (MODULE_PARLOUR_LED_HELP == device)
    {
        if (CMD_PARLOUR_LED_HELP_ON == cmd)
        {
            ui->label_light_help->setStyleSheet(m_styleOn);
            ui->pbn_light_help->SetCheck(true);
#if QDEBUG
            qDebug()<<"parlour led_help set on";
#endif
        }else
        {
            ui->label_light_help->setStyleSheet(m_styleOff);
            ui->pbn_light_help->SetCheck(false);
#if QDEBUG
            qDebug()<<"parlour led_help set off";
#endif
        }
    }
}

//��������Ƶ�״̬�������´ο���ʱͬ��
void Parlourwidget::slotSaveLedStatus()
{
    Myapp::parlour_led_main = ui->pbn_light_main->GetCheck();
    Myapp::parlour_led_top = ui->pbn_light_top->GetCheck();
    Myapp::parlour_led_help = ui->pbn_light_help->GetCheck();

    //д�������ļ�
    Myapp::WriteConfig();
}

void Parlourwidget::slotChangeLedStatus(quint8 status)
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

//add current parlour tempture
void Parlourwidget::on_tbn_temp_add_clicked()
{
    //get current tempture
    QString temp = ui->label_set_temp->text();
    QString new_temp;
    if (temp.toInt() < 100)
    {
        new_temp = QString::number(temp.toInt() + 1);
    }
    ui->label_set_temp->setText(new_temp);
#if QDEBUG
    qDebug()<<"current tempture:"<<temp;
    qDebug()<<"add tempture:"<<new_temp<<endl;
#endif
    //send temptuer
    emit signalSendTemptureValue(MODULE_DS18B20,new_temp);
}

//sub current tempture
void Parlourwidget::on_tbn_temp_sub_clicked()
{
    //get current tempture
    QString temp = ui->label_set_temp->text();
    QString new_temp;
    if (temp.toInt() > 0)
    {
        new_temp = QString::number(temp.toInt() - 1);
    }
    ui->label_set_temp->setText(new_temp);
#if QDEBUG
    qDebug()<<"current tempture:"<<temp;
    qDebug()<<"sub tempture:"<<new_temp<<endl;
#endif
    //send temptuer
    emit signalSendTemptureValue(MODULE_DS18B20,new_temp);
}

//add current humidity
void Parlourwidget::on_tbn_hum_add_clicked()
{
    //get current humidity
    QString humi = ui->label_set_hum->text();
    QString new_humi;
    if (humi.toInt() < 100)
    {
        new_humi = QString::number(humi.toInt() + 1);
    }
    ui->label_set_hum->setText(new_humi);
#if QDEBUG
    qDebug()<<"current humidity:"<<humi;
    qDebug()<<"sub humidity:"<<new_humi<<endl;
#endif
    //send humidity
    emit signalSendHumidityVlaue(MODULE_DHT11_HUM,new_humi);
}

//sub current humidity
void Parlourwidget::on_tbn_hum_sub_clicked()
{
    //get current humidity
    QString humi = ui->label_set_hum->text();
    QString new_humi;
    if (humi.toInt() > 0)
    {
        new_humi = QString::number(humi.toInt() - 1);
    }
    ui->label_set_hum->setText(new_humi);
#if QDEBUG
    qDebug()<<"current humidity:"<<humi;
    qDebug()<<"sub humidity:"<<new_humi<<endl;
#endif
    //send humidity
    emit signalSendHumidityVlaue(MODULE_DHT11_HUM,new_humi);
}


void Parlourwidget::slotChangeTempSetValue(const int &value)
{
    ui->label_set_temp->setText(QString::number(value));
}

void Parlourwidget::slotChangeHumSetValue(const int &value)
{
    ui->label_set_hum->setText(QString::number(value));
}
