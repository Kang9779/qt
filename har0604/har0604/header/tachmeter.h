#ifndef TACHMETER_H
#define TACHMETER_H

#define LONG    5     //仪表盘中整十数的长指针的长度
#define SHORT   2     //仪表盘中其他指针的长度
#define OK      3
#define SPACE   1
#define ANGLE   5

#include <QWidget>
#include <QtGui>

class Tachmeter : public QWidget
{
    Q_OBJECT
public:
    explicit Tachmeter(QWidget *parent = 0);
    ~Tachmeter();

public slots:
    void setValue(qreal value);
    void setAnimating(bool enable)
    {
        m_bAnimating=enable;
        update();
    }

public:
    bool isAnimating() const
    {
        return m_bAnimating;
    }

protected:
    void paintEvent(QPaintEvent *);

    QSize sizeHint() const
    {
        return QSize(200,200);
    }

    QSize minimumSizeHint() const
    {
        return QSize(100,100);
    }

private:
    void drawOuterCircle(QPainter* painter);
    void drawInnerCircle(QPainter* painter);
    void drawMark(QPainter* painter);
    void drawCoverCircle(QPainter* painter);
    void drawColorPie(QPainter* painter);
    void drawIndicator(QPainter* painter);
    void drawCoverBall(QPainter* painter);
    void resetVariables(QPainter* painter);
    void drawTextRect(QPainter* painter);

private:
    qreal m_outerRadius;
    qreal m_innerRadius;
    qreal m_coverCircleRadius;
    qreal m_colorCircleRadius;
    qreal m_coverBallRadius;
    QPointF m_center;
    QRectF m_colorCircleRect;
    qreal m_value;
    QTimer* updateTimer;
    bool m_bReverse;
    qreal m_currentValue;
    QTimer* singleTimer;
    bool m_bAnimating;

private:
    void initVariables();

private slots:
    void UpdateGraph();
};

#endif // TACHMETER_H
