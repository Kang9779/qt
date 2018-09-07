#include "./header/controlsetting.h"
#include "ui_controlsetting.h"

ControlSetting::ControlSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlSetting)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    initUI();

    send_control_setting();
}

ControlSetting::~ControlSetting()
{
    delete ui;
}

void ControlSetting::send_control_setting(){
    connect(ui->OK_btn,SIGNAL(clicked()),this,SLOT(setvalid()));
    connect(ui->Cancel_btn,SIGNAL(clicked()),this,SLOT(setinvalid()));
}

void ControlSetting::setvalid(){

    QByteArray arrctl1;
    QByteArray arrctl2;

    arrctl1.resize(8);
    arrctl2.resize(8);


    for(int i = 0 ; i < 8 ; i++){
        arrctl1[i] = 0;
        arrctl2[i] = 0;
    }


    if(ui->cbx_4->currentIndex() == 1)          clear_meter = 1;           //清零
    else                                        clear_meter = 0;           //无动作

    if(ui->cbx_3->currentIndex() == 0)          reset_cutheight = 0;       //脱开
    else if (ui->cbx_3->currentIndex() == 1)    reset_cutheight = 1;       //割台提升
    else if (ui->cbx_3->currentIndex() == 2)    reset_cutheight = 2;       //割台下降
    else                                        reset_cutheight = 3;       //未定义

    if(ui->cbx_1->currentIndex() == 0)          control_unloader = 4;       //停止
    else if (ui->cbx_1->currentIndex() == 1)    control_unloader = 5;       //动态展开
    else if (ui->cbx_1->currentIndex() == 2)    control_unloader = 6;       //静态展开
    else if (ui->cbx_1->currentIndex() == 3)    control_unloader = 7;       //收回
    else                                        control_unloader = 0;       //无动作

    if(ui->cbx_5->currentIndex() == 0)          auto_loader = 0;       //关闭负荷自动调节
    else if (ui->cbx_5->currentIndex() == 1)    auto_loader = 1;       //开启负荷自动调节
    else                                        auto_loader = 2;       //无动作

    if(ui->cbx_6->currentIndex() == 0)          auto_cutheight = 0;       //关闭割台高度自动调节
    else if (ui->cbx_6->currentIndex() == 1)    auto_cutheight = 1;       //开启割台高度自动调节
    else                                        auto_cutheight = 2;       //无动作

    if(ui->cbx_7->currentIndex() == 0)          reset_weight = 0;       //无动作
    else if (ui->cbx_7->currentIndex() == 1)    reset_weight = 1;       //清零
    else                                        reset_weight = 2;       //未定义

    if(ui->cbx_9->currentIndex() == 1)          set_alarm = 1;       //静音
    else if (ui->cbx_9->currentIndex() == 2)    set_alarm = 2;       //播放
    else                                        set_alarm = 0;       //无动作

     reelSpeed = ui->reelSpeed->text().toFloat();          //拨禾轮转速
     cutterHz=ui->cutterHz->text().toFloat();              //割刀频率
     feedAugerSpeed=ui->augerSpeed->text().toFloat();      //搅龙转速

     arrctl2[0]=set_alarm;

     if(reelSpeed>65536) reelSpeed=0;
     arrctl2[1]=reelSpeed;

     arrctl2[2]=cutterHz%256;
     arrctl2[3]=cutterHz/256;

     arrctl2[4]=feedAugerSpeed%256;
     arrctl2[5]=feedAugerSpeed/256;


    arrctl1[0] = (clear_meter << 2) | (reset_cutheight << 4);
    arrctl1[1] = control_unloader | (auto_loader << 3) | (auto_cutheight << 5);
    arrctl1[2] = reset_weight;

    can_send1(arrctl1,0x18FF5030);
    can_send1(arrctl2,0x18FF5330);

    this->hide();
}

void ControlSetting::setinvalid()
{
    this->hide();
}

void ControlSetting::initUI()
{
     ui->cbx_4->setCurrentIndex(clear_meter);
     ui->cbx_3->setCurrentIndex(reset_cutheight);

     if(control_unloader == 0) // No action
        ui->cbx_1->setCurrentIndex(4);
     else
        ui->cbx_1->setCurrentIndex(control_unloader-4);

     ui->cbx_5->setCurrentIndex(auto_loader);

     ui->cbx_6->setCurrentIndex(auto_cutheight);

     ui->cbx_7->setCurrentIndex(reset_weight);

     ui->cbx_9->setCurrentIndex(set_alarm);

     ui->reelSpeed->setText(QString::number(reelSpeed));

     ui->cutterHz->setText(QString::number(cutterHz));

     ui->augerSpeed->setText(QString::number(feedAugerSpeed));


}
