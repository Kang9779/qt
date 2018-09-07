#include "radarwidget.h"
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QtCore/qmath.h>
#define M_PI 3.14159265358979323846

RadarWidget::RadarWidget(QWidget *parent) : QWidget(parent)
{
    hlthy[0]=0.0;
    hlthy[1]=0.0;
    hlthy[2]=0.0;
    hlthy[3]=0.0;
    resize(350, 350);
}

void RadarWidget::paintEvent(QPaintEvent *)
  { int number = 4;
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2-20);
    painter.scale(side / 350.0, side / 350.0);
    painter.setPen(Qt::NoPen);
    painter.setPen(Qt::black);
    painter.drawArc(-100,-100,200,200,0,5760);
    painter.setBrush(Qt::red);
    painter.drawEllipse(-100,-100,200,200);
    painter.drawRect(-120,140,40,15);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(-80,-80,160,160);
    painter.drawRect(-20,140,40,15);
    painter.setBrush(Qt::green);
    painter.drawEllipse(-60,-60,120,120);
    painter.drawRect(80,140,40,15);
    painter.setBrush(Qt::green);
    painter.drawEllipse(-20,-20,40,40);
    for (int i = 0; i < number; ++i) {
        if(hlthy[i]<0.6){
        painter.setBrush(Qt::green);
        }else if(hlthy[i]<0.8){
            painter.setBrush(Qt::yellow);
        }else{
            painter.setBrush(Qt::red);
        }

        painter.drawRect(-20,-130,40,20);
        painter.setPen(Qt::black);
        painter.drawLine(0, 0, 100, 0);
        painter.rotate(360/number);

    }
     painter.drawText(5,-95,"1");
     painter.drawText(5,-75,"0.8");
     painter.drawText(5,-55,"0.6");
     painter.drawText(5,-35,"0.4");
     painter.drawText(5,-15,"0.2");
     painter.drawText(5,5,"0");

     painter.setPen(Qt::NoPen);

     QFont font;
     font.setPointSize(10);
     font.setFamily("Microsoft YaHei");
     font.setBold(true);
     painter.setFont(font);
     painter.setPen(Qt::black);
     painter.drawText(-120,170,"故障区");
     painter.drawText(-20,170,"预警区");
     painter.drawText(80,170,"安全区");

     QString str="";
     int flag =0;

     for (int i = 0; i < number; ++i) {

         painter.setPen(Qt::black);
         switch (i) {
         case 0:

             str= "缸 1";
             break;
         case 1:
             str= "缸 2";
             break;
         case 2:
             str= "阀 1";
             break;
         case 3:
             str= "阀 2";
             break;
         default:
             str="";
             break;
         }

         painter.drawText(-12,-115,str);

         if(flag ==1){
                painter.translate(0,-240);
                painter.rotate(180);
         }
        painter.rotate(360/number);
         if(i>number/4-1 && i<3*number/4-1)
         {
              painter.rotate(180);
              painter.translate(0,240);
             flag = 1;

         }else{

             flag = 0;
         }
     }

     double hlthyvector[number][2]={0};
     for(int i=0;i<number;i++)
     {
            hlthyvector[i][1] = qSin(2*M_PI/number*(i))*hlthy[i]*100.0;
            hlthyvector[i][2] = -qCos(2*M_PI/number*(i))*hlthy[i]*100.0;
     }

           QPoint hlthy2[number+1] = {
               QPoint(hlthyvector[0][1],hlthyvector[0][2]),
               QPoint(hlthyvector[1][1],hlthyvector[1][2]),
               QPoint(hlthyvector[2][1],hlthyvector[2][2]),
               QPoint(hlthyvector[3][1],hlthyvector[3][2]),
               QPoint(hlthyvector[0][1],hlthyvector[0][2])
           };
     QPen pen = painter.pen();
     pen.setWidth(2);
     painter.setPen(pen);
     painter.drawPolyline(hlthy2, number+1);


}

RadarWidget::~RadarWidget()
{

}
