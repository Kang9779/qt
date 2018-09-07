#include "./header/parametersetting.h"
#include "ui_parametersetting.h"
#include <QDebug>

char dataArray130[8];
char dataArray230[8];

/*2018.6.4添加的ID为18FF5430的消息帧*/
QByteArray dataArray430;

int flag_send_setting;
QByteArray arr12;
QByteArray arr23;

ParameterSetting::ParameterSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParameterSetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    initUI();
    flag_send_setting = 0 ;
    send_para_setting();
}

ParameterSetting::~ParameterSetting()
{
    delete ui;
}

void ParameterSetting::send_para_setting(){

    connect(ui->OK_btn,SIGNAL(clicked()),this,SLOT(setvalid()));
    connect(ui->Cancel_btn,SIGNAL(clicked()),this,SLOT(setinvalid()));
}

void ParameterSetting::setvalid(){

    dataArray430.resize(8);
    for(int i = 0 ; i < 8 ; i++){

        dataArray430[i] = 0;
    }

    rsls = ui->l_rsls->text().toFloat();
    concaveclset = ui->l_concaveclset->text().toFloat();
    le = ui->lineEdit->text().toFloat();
    pfh = ui->l_pfh->text().toFloat();
    cutx = ui->l_cuth_max->text().toFloat();
    cutn = ui->l_cuth_min->text().toFloat();
    cuttermode = 0;    //Combobox
    grainkd = 0;       //Combobox

    /*18FF5430的消息帧*/
    rollerSpeed=ui->rollerSpeed->text().toFloat();
    draughtFanSpeed=ui->draughtFanSpeed->text().toFloat();
    sortingScreenUp=ui->sortingScreenUp->text().toFloat();
    sortingScreenDown=ui->sortingScreenDown->text().toFloat();
    sortingScreenTail=ui->sortingScreenTail->text().toFloat();

    dataArray130[0] = ((int)(le*100))%256;
    dataArray130[1] = (le*100)/256;
    dataArray130[2] = pfh%256;
    dataArray130[3] = pfh/256;
    dataArray130[4] = cutx%256;
    dataArray130[5] = cutx/256;
    dataArray130[6] = cutn%256;
    dataArray130[7] = cutn/256;

    arr12[0] = ((int)(le*100))%256;
    arr12[1] = (le*100)/256;
    arr12[2] = pfh%256;
    arr12[3] = pfh/256;
    arr12[4] = cutx%256;
    arr12[5] = cutx/256;
    arr12[6] = cutn%256;
    arr12[7] = cutn/256;

    dataArray230[1] = rsls % 256;
    dataArray230[2] = rsls / 256;

    dataArray430[0]=rollerSpeed%256;
    dataArray430[1]=rollerSpeed/256;
    dataArray430[2]=draughtFanSpeed%256;
    dataArray430[3]=draughtFanSpeed/256;
    dataArray430[4]=sortingScreenUp;
    dataArray430[5]=sortingScreenDown;
    dataArray430[6]=sortingScreenTail;


    if(ui->cbx_2->currentIndex() == 1)   cuttermode = 1;                //排草
    else                     cuttermode = 0;                            //切碎

    if(ui->grain_kind->currentIndex() == 0)          grainkd = 0;       //"水稻"
    else if (ui->grain_kind->currentIndex() == 1)    grainkd = 1;       //"小麦"
    else if (ui->grain_kind->currentIndex() == 2)    grainkd = 2;       //"玉米"
    else if (ui->grain_kind->currentIndex() == 3)    grainkd = 3;       //"大豆"
    else if (ui->grain_kind->currentIndex() == 4)    grainkd = 15;      //"其他"

    dataArray230[6] &= ((cuttermode << 4) | grainkd);

    arr23[1] = rsls % 256;
    arr23[2] = rsls / 256;
    arr23[3] = concaveclset;
    arr23[6] = (cuttermode << 4) | grainkd;
    arr23[0] = arr23[4] = arr23[5] = arr23[7] = 0;

    flag_send_setting = 1;

    can_send1(arr12,0x18FF5130);
    can_send1(arr23,0x18FF5230);

    /*注意can_send禾can_send1的参数不一样，一个是char []，一个是QByteArray*/
    can_send1(dataArray430,0x18FF5430);

    this->hide();
}

void ParameterSetting::setinvalid(){
    flag_send_setting = 0;
    this->hide();
}

void ParameterSetting::initUI()
{
    ui->l_rsls->setText(QString::number(rsls));
    ui->l_concaveclset->setText(QString::number(concaveclset));
    ui->lineEdit->setText(QString::number(le));
    ui->l_pfh->setText(QString::number(pfh));
    ui->l_cuth_max->setText(QString::number(cutx));
    ui->l_cuth_min->setText(QString::number(cutn));
    ui->rollerSpeed->setText(QString::number(rollerSpeed));
    ui->draughtFanSpeed->setText(QString::number(draughtFanSpeed));
    ui->sortingScreenUp->setText(QString::number(sortingScreenUp));
    ui->sortingScreenDown->setText(QString::number(sortingScreenDown));
    ui->sortingScreenTail->setText(QString::number(sortingScreenTail));


    cuttermode = 0;    //Combobox
    grainkd = 0;       //Combobox

    ui->cbx_2->setCurrentIndex(cuttermode);

    if(grainkd == 15)
        ui->grain_kind->setCurrentIndex(4);
    else
        ui->grain_kind->setCurrentIndex(grainkd);

}
