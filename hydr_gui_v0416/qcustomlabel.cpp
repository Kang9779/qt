#include "qcustomlabel.h"

#include <QPainter>
#include <QDebug>

const int NUM=4;

QCustomLabel::QCustomLabel(QWidget *parent) :QLabel(parent)
{
//    ID=0;
//    for(int i=0;i<NUM;i++)
//    {
//        displayed.push_back(false);
//        location.push_back(QPoint(0,0));
//        transducer.push_back("");
//    }
    displayedPressure1=false;
    displayedPressure2=false;
    displayedFlow=false;
    displayedDisplacement=false;
    displayedTempreture=false;
    displayedVibration=false;
}

void QCustomLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter imagePainter(this);
    QImage imagePressure1;
    imagePressure1.load(":/icons/rsc/pressure_left.png");
    QImage imagePressure2;
    imagePressure2.load(":/icons/rsc/pressure_right.png");
    QImage imageDisplacement;
    imageDisplacement.load(":/icons/rsc/tempreture.png");
    QImage imageFlow;
    imageFlow.load(":/icons/rsc/flow.png");
    imagePainter.setCompositionMode(QPainter::CompositionMode_Difference);
    if(displayedPressure1)
    {
        imagePainter.drawImage(QPoint(100,100),imagePressure1);
        imagePainter.drawText(QPoint(100,100),"OK");
    }
    if(displayedPressure2)
        imagePainter.drawImage(QPoint(200,100),imagePressure2);
    if(displayedDisplacement)
        imagePainter.drawImage(QPoint(200,50),imageDisplacement);
    if(displayedFlow)
        imagePainter.drawImage(QPoint(150,150),imageFlow);
//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
//    for(int ti=0;ti<NUM;ti++)
//    {
//        if(displayed[ti])
//        {
//            painter.drawText(location[ti],transducer[ti]);
//            painter.drawEllipse(location[ti].x(),location[ti].y(),10,10);
//        }
    //    }
}

void QCustomLabel::displayPressure1(bool displayed)
{
    this->displayedPressure1=displayed;
    qDebug()<<"OK";
    update();
}

void QCustomLabel::displayPressure2(bool displayed)
{
    this->displayedPressure2=displayed;
    update();
}

void QCustomLabel::dislplayFlow(bool displayed)
{
    this->displayedFlow=displayed;
    update();
}

void QCustomLabel::displayDisplacement(bool displayed)
{
    this->displayedDisplacement=displayed;
    update();
}

void QCustomLabel::displayTempreture(bool displayed)
{
    this->displayedTempreture=displayed;
    update();
}

void QCustomLabel::displayVibration(bool displayed)
{
    this->displayedVibration=displayed;
    update();
}

//void QCustomLabel::setID(int id)
//{
//    this->ID=id;
//}

//void QCustomLabel::setTransducer(QString transducer)
//{
//    this->transducer[ID]=transducer;
//}

//void QCustomLabel::setLocation(QPoint location)
//{
//    this->location[ID]=location;
//    update();
//}

//void QCustomLabel::displayTransducer(bool displayed)
//{
//    this->displayed[ID]=displayed;
//    update();
//}



