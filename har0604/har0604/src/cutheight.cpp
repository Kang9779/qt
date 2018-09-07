//显示割台高度柱状图
#include "cutheight.h"

cutHeight::cutHeight(QWidget *parent) :
    QWidget(parent)
{
    this->initVariables();
}

void cutHeight::initVariables()
{
    m_markClr=Qt::white;
    graphcolor1=Qt::darkGreen;
    graphcolor2=Qt::yellow;
    graphcolor3=Qt::red;
    m_value=0;
    m_currentValue=0;
    m_bucketWidth=width()/4;
    m_markSpace=(qreal)width()/2;
    m_topSpace=(qreal)height()/15;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));
    m_bReverse=false;
}

void cutHeight::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHints(QPainter::TextAntialiasing|QPainter::Antialiasing);
    resetDrawingVariables(&painter);
    drawBackground(&painter);
    drawMark(&painter);
    drawBucket(&painter);
    drawGraph(&painter);

    painter.end();
}

void cutHeight::drawBackground(QPainter *painter)
{
    painter->save();

    QLinearGradient bgGradient(QPointF(0,0),QPointF(0,height()));
//    bgGradient.setColorAt(0.0,QColor(200,200,200));
//    bgGradient.setColorAt(0.2,QColor(0, 0, 255));    //这两个最初是（100，100，100）
    bgGradient.setColorAt(0.9,QColor(41, 137, 254));         //背景颜色，可以改为（6, 7, 251）
//    bgGradient.setColorAt(1.0,QColor(200,200,200));

    painter->setBrush(bgGradient);
    painter->drawRect(rect());
    painter->restore();
}
void cutHeight::drawMark(QPainter *painter)
{
    painter->save();

    qreal initY=m_topSpace;
    qreal initX=m_markSpace;
    qreal length=height()-2*m_topSpace;
    qreal increment=length/100;
    painter->setPen(m_markClr);

    // draw vertical line
    QPointF topPot(m_markSpace/2+m_markSpace,m_topSpace);
    QPointF bottomPot(m_markSpace/2+m_markSpace,height()-m_topSpace);
    painter->drawLine(topPot,bottomPot);

    int vvalue=100;
    QString strValue;

    strValue=QString::fromUtf8("割台高度/cm", -1);      //设置刻度线的单位
//    qreal fontWidth=painter->fontMetrics().width(strValue);
    qreal fontHeight=painter->fontMetrics().height();


    QPointF textPot(initX/5,initY/4+fontHeight/2);
//    painter->setPen(QColor(Qt::darkGreen));       //设置"单位"字体的颜色为红色
    painter->drawText(textPot,strValue);
//    painter->setPen(QColor(Qt::black));       //设置“刻度值”字体的颜色为白色

    for(int i=0;i<=100;i++)
    {

        if(i%10==0)
        {
            QPointF leftPot(m_markSpace/2+initX+LONG1,initY);
            QPointF rightPot(m_markSpace/2+initX,initY);
            painter->drawLine(leftPot,rightPot);

            strValue=tr("%1").arg(vvalue);      //设置刻度线的值0，10，20，30....,100
            qreal fontWidth=painter->fontMetrics().width(strValue);
            qreal fontHeight=painter->fontMetrics().height();

            QPointF textPot(m_markSpace/2+initX-fontWidth-5,initY+fontHeight/2);
            painter->drawText(textPot,strValue);

            vvalue-=10;

        }
        else if(i%5==0 && i%10!=0)
        {
            QPointF leftPot(m_markSpace/2+initX+OK1,initY);
            QPointF rightPot(m_markSpace/2+initX,initY);
            painter->drawLine(leftPot,rightPot);
        }
        else
        {
            QPointF leftPot(m_markSpace/2+initX+SHORT1,initY);
            QPointF rightPot(m_markSpace/2+initX,initY);
            painter->drawLine(leftPot,rightPot);
        }
        initY+=increment;
    }
    painter->restore();
}

//void cutHeight::SetGraphColor(QColor c)
//{
//    this->graphcolor=c;
//}


void cutHeight::drawGraph(QPainter *painter)
{
    painter->save();
    qreal bucketHeight=m_bucketRect.height();
    qreal increment=(qreal)bucketHeight/100;

    QPointF bottomRightPot(m_bucketRect.bottomRight());
    qreal currentY=m_currentValue*increment;

    QPointF topLeftPot(m_bucketRect.topLeft().x(),m_bucketRect.bottomLeft().y()-currentY);
    QRectF graphRect(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);

    QLinearGradient graphGradient(graphRect.topLeft(),graphRect.topRight());
    painter->setOpacity(0.7);

    if(m_value < 50){
        graphGradient.setColorAt(0.0,this->graphcolor1);    //当值小于50时，绿色正常显示
    }else if(m_value < 80){
        graphGradient.setColorAt(0.0,this->graphcolor2);    //当值大于等于50且小于80时，黄色预警显示
    }else{
        graphGradient.setColorAt(0.0,this->graphcolor3);    //当值大于等于80且小于100时，红色报警显示
    }

    painter->setBrush(graphGradient);
    painter->drawRect(graphRect);
    painter->restore();
}

void cutHeight::drawBucket(QPainter *painter)
{
    painter->save();

    QPointF bucketTopLeftPot(m_markSpace*3/2+MARK_BUCKET_SPACE,m_topSpace);
    QPointF bucketBottomRightPot(m_markSpace*3/2+MARK_BUCKET_SPACE+m_bucketWidth,height()-m_topSpace);
    QRectF bucketRect(bucketTopLeftPot,bucketBottomRightPot);
    m_bucketRect=bucketRect;

    QLinearGradient bucketGradient(bucketRect.topLeft(),bucketRect.topRight());
    bucketGradient.setColorAt(0.0,QColor(100,100,100));
    bucketGradient.setColorAt(0.6,QColor(200,200,200));
    bucketGradient.setColorAt(1.0,QColor(150,150,150));

    painter->setPen(Qt::NoPen);
    painter->setBrush(bucketGradient);
    painter->drawRect(bucketRect);
    painter->restore();
}

void cutHeight::resetDrawingVariables(QPainter *)
{
    m_markSpace=(qreal)width()/4;
    //m_bucketWidth=(qreal)width()/5;
    m_topSpace=(qreal)height()/15;
}


void cutHeight::setValue(qreal value)
{
    if(value>m_value)
    {
        m_bReverse=false;
    }
    else if(value<m_value)
    {
        m_bReverse=true;
    }
    else
    {
        return ;
    }
     m_value=value;
    updateTimer->start();
}

void cutHeight::setMarkColor(const QColor &clr)
{
    m_markClr=clr;
    update();
}


void cutHeight::UpdateGraph()
{
    if(!m_bReverse)
    {
        m_currentValue+=0.5;
        if(m_currentValue>=m_value)
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue-=0.5;

        if(m_currentValue<=m_value)
        {
            updateTimer->stop();
        }
    }
    update();
}
