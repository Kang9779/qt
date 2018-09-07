#include "../header/mqlabel.h"

MQlabel::MQlabel(QWidget *parent) : QLabel(parent)
{
    timer_g=new QTimer();
    connect(timer_g,SIGNAL(timeout()),this,SLOT(timerout_glitter()));
}

//闪烁
void MQlabel::glitter()
{
    timer_g->start(500);
}

MQlabel::~MQlabel()
{

}

void MQlabel::timerout_glitter()
{
    if(this->isHidden())
        this->show();
    else
        this->hide();
}

void MQlabel::setValue(int val){
    if(val == 0){
        this->setStyleSheet("border-image: url(:/images/warning/normal.png);");
    }else{
        this->setStyleSheet("border-image: url(:/images/warning/alarm.png);");
    }
}
