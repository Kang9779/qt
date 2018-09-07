#include "polarwidget.h"
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QGraphicsView>
PolarWidget::PolarWidget(QWidget *parent) : QWidget(parent)
{
//    QTimer *timer = new QTimer(this);
//          connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//          timer->start(1000);
    hlthy_cyld1=10;
    hlthy_cyld2=10;
    hlthy_valve1=10;
    hlthy_valve2=30;
    resize(300, 300);
}
void PolarWidget::paintEvent(QPaintEvent *event)
  {   QWidget::paintEvent(event);
      QPoint hourHand[4] = {
          QPoint(hlthy_cyld1,0),
          QPoint(0,-hlthy_cyld2),
          QPoint(-hlthy_valve1,0),
          QPoint(0, hlthy_valve2)
      };

      static const QPoint hint1[3] = {
          QPoint(0,0),
          QPoint(0,-25),
          QPoint(-25,0)
      };

      static const QPoint hint2[4] = {
          QPoint(50,0),
          QPoint(0,-50),
          QPoint(0, -75),
          QPoint(75,0),
      };

      QColor hourColor(169,219,209,70);
      QColor hourColor2(139,109,169,210);
      QColor hourColor3(1,1,1);
      int side = qMin(width(), height());


      QPainter painter(this);
      painter.setRenderHint(QPainter::Antialiasing);
      painter.translate(width() / 2, height() / 2);
      painter.scale(side / 300.0, side / 300.0);

      painter.setPen(Qt::NoPen);

      painter.save();

      painter.restore();

      painter.setPen(hourColor);

      for (int i = 0; i < 12; ++i) {
          painter.setPen(QPen(hourColor, 2, Qt::DashDotLine, Qt::RoundCap));

          painter.drawLine(0, 0, 100, 0);
          painter.drawLine(25,0,0,25);
          painter.drawLine(50,0,0,50);
          painter.drawLine(75,0,0,75);
          painter.drawLine(100,0,0,100);
          painter.setPen(hourColor);
          painter.setBrush(hourColor);
          painter.drawConvexPolygon(hint1, 3);
          painter.drawConvexPolygon(hint2, 4);


          painter.rotate(90.0);
      }
      painter.setPen(hourColor2);
      painter.setBrush(hourColor2);
      painter.drawConvexPolygon(hourHand, 4);

      painter.setPen(Qt::NoPen);

      QFont font;
      font.setPointSize(10);
      font.setFamily("Microsoft YaHei");
      font.setBold(true);
      painter.setFont(font);
      painter.setPen(hourColor3);
      painter.drawText(100,0,"缸1");
      painter.drawText(-10,-105,"缸2");
      painter.drawText(-115,0,"阀1");
      painter.drawText(-10,110,"阀2");
      painter.setPen(Qt::NoPen);

      font.setPointSize(8);
      font.setBold(true);
      painter.setFont(font);
      painter.setPen(hourColor3);
      painter.drawText(-15,-75,"优");
      painter.drawText(-15,-50,"良");
      painter.drawText(-15,-25,"中");
      painter.drawText(-15,0,"差");
      painter.setPen(Qt::NoPen);

      qDebug()<<"piantevent调用"<<hlthy_cyld1<<hlthy_cyld2;
}

PolarWidget::~PolarWidget()
{

}

