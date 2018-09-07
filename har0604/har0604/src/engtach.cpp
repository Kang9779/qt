//发动机转速表,0-3000rpm
#include "../header/engtach.h"

Engtach::Engtach(QWidget *parent) : QWidget(parent)
{
    this->initVariables();
}

Engtach::~Engtach()
{

}

void Engtach::initVariables()
{
    m_outerRadius=width()>height() ? height()/2: width()/2;
    m_innerRadius=m_outerRadius/8*5;
    m_coverCircleRadius=m_outerRadius/8*4;
    m_colorCircleRadius=m_outerRadius/8*5;
    m_center=rect().center();
    m_value=0;
    m_currentValue=0;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));
    singleTimer=new QTimer(this);
    singleTimer->setInterval(100);
    connect(singleTimer,SIGNAL(timeout()),this,SLOT(update()));
    singleTimer->start();
}

void Engtach::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    resetVariables(&painter);
    drawOuterCircle(&painter);
    drawInnerCircle(&painter);
    drawColorPie(&painter);
    drawCoverCircle(&painter);
    drawMark(&painter);
    drawIndicator(&painter);
    drawCoverBall(&painter);
    drawTextRect(&painter);
    painter.end();
}

void Engtach::drawOuterCircle(QPainter *painter)
{
    painter->save();
    QRadialGradient outerGradient(m_center,m_outerRadius,m_center);
    outerGradient.setColorAt(0.0,QColor(200,200,200));
    outerGradient.setColorAt(0.9,QColor(80,80,80));
    outerGradient.setColorAt(0.95,QColor(180,180,180));
    outerGradient.setColorAt(1.0,QColor(80,80,80));

    painter->setPen(Qt::NoPen);
    painter->setBrush(outerGradient);
    painter->drawEllipse(m_center,m_outerRadius,m_outerRadius);
    //画半圆
//    painter->drawChord(m_center.x()-m_outerRadius,m_center.y()-m_outerRadius,m_outerRadius*2,m_outerRadius*2,0,180*16);
    //画扇形
//    painter->drawPie(m_center.x()-m_outerRadius,m_center.y()-m_outerRadius,2*m_outerRadius,2*m_outerRadius,45*16,135*16);
    painter->restore();
}

void Engtach::drawInnerCircle(QPainter *painter)
{
    painter->save();
    QRadialGradient innerGradient(m_center,m_innerRadius,m_center);
    innerGradient.setColorAt(0.0,QColor(130,130,130));
    innerGradient.setColorAt(0.7,QColor(130,130,130));
    innerGradient.setColorAt(1.0,QColor(80,80,80));
    painter->setPen(Qt::NoPen);
    painter->setBrush(innerGradient);
    painter->drawEllipse(m_center,m_innerRadius,m_innerRadius);
//    painter->drawChord(m_center.x()-m_innerRadius,m_center.y()-m_innerRadius,m_innerRadius*2,m_innerRadius*2,0,180*16);
    painter->restore();
}

//画刻度线和刻度线的值
void Engtach::drawMark(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::white);
    painter->translate(m_center);

    qreal dAngle=(qreal)180/6;
    qreal startAngle=90;
    int value=0;
    QString strValue;

    strValue=tr("x100rpm");      //设置刻度线的单位
    qreal textWidth=fontMetrics().width(strValue);
    qreal textHeight=fontMetrics().height()/3*2;
    QFont font;                 //设置字体的大小
    font.setPointSize(textHeight*3/8);
//    font.setPointSize(12);
    painter->setFont(font);
    QPointF textPot(0-textWidth/28*5,0-m_colorCircleRadius/7*2);
//    QPointF textPot(0-textWidth/7*3,0-m_colorCircleRadius/7*3);

//    painter->setPen(QColor(50,50,150));       //设置刻度线的颜色
    painter->drawText(textPot,strValue);

    painter->setPen(QColor(255, 217, 102));
    for(int i=0;i<=6;i++)
    {
        painter->save();
        painter->rotate(startAngle);


        strValue=tr("%1").arg(value);
        qreal textWidth=fontMetrics().width(strValue);
        qreal textHeight=fontMetrics().height()/2;
        QPointF bottomPot(0,m_colorCircleRadius+SPACE);
        QPointF topPot(0,m_colorCircleRadius+SPACE+SHORT);
        painter->drawLine(bottomPot,topPot);
        value+=5;

        //画刻度线的值
        painter->save();
//        QPointF textPot(0-textWidth/2,m_colorCircleRadius+textHeight);
        QPointF textPot(0-textWidth*4/5,m_colorCircleRadius+textHeight*2/3+2);
        painter->translate(textPot);
        painter->rotate(180);
        painter->drawText(QPointF(-textWidth,textHeight/2),strValue);
        painter->restore();

        painter->restore();
        startAngle+=dAngle;
    }
    painter->restore();
}

void Engtach::drawCoverBall(QPainter *painter)
{
    painter->save();

//    painter->translate(m_center);
    qreal ballRadius=m_outerRadius/7;
    m_coverBallRadius=ballRadius;
    QRadialGradient ballGradient(m_center,ballRadius,m_center);
    ballGradient.setColorAt(0.0,QColor(140,140,140));
    ballGradient.setColorAt(0.7,QColor(140,140,140));
    ballGradient.setColorAt(1.0,QColor(60,60,60));
    painter->setBrush(ballGradient);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(m_center,ballRadius,ballRadius);
//    painter->drawChord(m_center.x()-ballRadius,m_center.y()-ballRadius,ballRadius*2,ballRadius*2,0,180*16);
//    painter->drawPie(m_center.x()-ballRadius,m_center.y()-ballRadius,2*ballRadius,2*ballRadius,45*16,135*16);

    painter->restore();
}

void Engtach::drawTextRect(QPainter *painter)
{
    painter->save();
    qreal rectWidth=m_coverCircleRadius/5;

    QPointF topLeftPot(m_center.x()-rectWidth*4,m_center.y()+rectWidth*2);
//    QPointF topLeftPot(m_center.x()-3*rectWidth,m_center.y());
    QPointF bottomRightPot(topLeftPot.x()+8*rectWidth,topLeftPot.y()+rectWidth*4);
    QRectF textRect(topLeftPot,bottomRightPot);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,170,255));
    painter->setOpacity(0.6);
    painter->drawRoundRect(textRect,ANGLE,ANGLE);

    qreal fontSize=textRect.height()/2;
    QFont font;
    font.setPointSize(fontSize);
    painter->setFont(font);

    painter->setOpacity(1.0);
    painter->setPen(Qt::black);
    QString strValue;
    strValue=tr("%1").arg(m_value);
    painter->drawText(textRect,Qt::AlignHCenter|Qt::AlignVCenter,strValue);     //设置中心文本数值
    painter->restore();
}

void Engtach::drawCoverCircle(QPainter *painter)
{
    painter->save();
    painter->setBrush(QColor(130,130,130));
    painter->setPen(Qt::NoPen);

    //显示绿黄红条的宽度,画圆覆盖绿黄红条的圆，让它只显示一小部分
//    painter->drawEllipse(m_center,m_coverCircleRadius,m_coverCircleRadius);
    painter->drawChord(m_center.x()-m_coverCircleRadius,m_center.y()-m_coverCircleRadius,m_coverCircleRadius*2,m_coverCircleRadius*2,-5*16,185*16);
//    painter->drawPie(m_center.x()-m_coverCircleRadius,m_center.y()-m_coverCircleRadius,2*m_coverCircleRadius,2*m_coverCircleRadius,45*16,135*16);
    painter->restore();
}

void Engtach::drawColorPie(QPainter *painter)
{
    painter->save();

    QPointF topLeftPot(m_center.x()-m_colorCircleRadius,m_center.y()-m_colorCircleRadius);
    QPointF bottomRightPot(m_center.x()+m_colorCircleRadius,m_center.y()+m_colorCircleRadius);
    m_colorCircleRect=QRectF(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);

    QConicalGradient greenGradient(m_center,m_innerRadius);
    greenGradient.setColorAt(0.0,QColor(0,30,0));
    greenGradient.setColorAt(0.25,QColor(0,230,0));
    greenGradient.setColorAt(1.0,QColor(0,230,0));

    painter->setBrush(Qt::green);
//    painter->drawPie(m_colorCircleRect,45*16,135*16);
    painter->drawPie(m_colorCircleRect,0*16,180*16);

    painter->setBrush(QColor(218,218,0));
//    painter->drawPie(m_colorCircleRect,45*16,45*16);
    painter->drawPie(m_colorCircleRect,0*16,60*16);

    painter->setBrush(QColor(240,50,50));
//    painter->drawPie(m_colorCircleRect,45*16,15*16);
    painter->drawPie(m_colorCircleRect,0*16,30*16);

    painter->restore();
}

void Engtach::drawIndicator(QPainter *painter)
{
    painter->save();

    painter->translate(m_center);
//    qreal increment=(qreal)135/100;         //设置指针的旋转角度增量
    qreal increment=(qreal)180/300;
    qreal changedAngle=90+increment*m_currentValue/10;     //设置指针起始角度和旋转角度
    painter->rotate(changedAngle);

    QPointF topPot(0,m_colorCircleRadius+LONG);
//    QPointF bottomLeftPot(-m_coverBallRadius/3,0);
    QPointF bottomLeftPot(-m_coverBallRadius/5,m_coverBallRadius);     //仪表盘上指针在最宽处（圆的中心）的宽度，第二个参数为指针底部距离圆心的位置
    QPointF bottomRightPot(m_coverBallRadius/5,m_coverBallRadius);
    painter->setPen(Qt::NoPen);

    QLinearGradient indicatorGradient(topPot,bottomLeftPot);
    indicatorGradient.setColorAt(0.0,QColor(236,187,62));
    indicatorGradient.setColorAt(0.5,QColor(220,147,0));
    indicatorGradient.setColorAt(1.0,QColor(236,187,62));
//    indicatorGradient.setColorAt(0.0,QColor(0,0,255));
//    indicatorGradient.setColorAt(1.0,QColor(0,0,255));

    painter->setBrush(indicatorGradient);
    QVector<QPointF> potVec;
    potVec.push_back(topPot);
    potVec.push_back(bottomLeftPot);
    potVec.push_back(bottomRightPot);

    painter->drawPolygon(potVec);
    painter->restore();
}

void Engtach::resetVariables(QPainter *)
{
    m_outerRadius=width()>height() ? height()/2: width()/2;
    m_innerRadius=m_outerRadius/8*7;
    m_coverCircleRadius=m_outerRadius/8*4;
    m_colorCircleRadius=m_outerRadius/8*5;

    m_center=rect().center();
}

void Engtach::setValue(qreal value)
{
    if(value>m_value)
    {
        m_bReverse=false;
        m_value=value;

        if(!m_bAnimating)
        {
            m_currentValue=m_value;
        }
    }
    else if(value<m_value)
    {
        m_bReverse=true;
        m_value=value;
        if(!m_bAnimating)
        {
            m_currentValue=m_value;
        }
    }
    else
    {
        return ;
    }
    updateTimer->start();
}

void Engtach::UpdateGraph()
{
    if(!m_bReverse)
    {
        m_currentValue+=1;

        if(m_currentValue>=m_value)
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue-=1;
        if(m_currentValue<=m_value)
        {
            updateTimer->stop();
        }
    }
    update();
}
