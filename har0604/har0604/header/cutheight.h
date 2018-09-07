#ifndef CUTHEIGHT_H
#define CUTHEIGHT_H

#define LONG1 7
#define OK1 5
#define SHORT1 3
#define MARK_BUCKET_SPACE 20

#include <QWidget>
#include <QtGui>

class cutHeight : public QWidget
{
    Q_OBJECT
public:
    explicit cutHeight(QWidget *parent = 0);

    void SetGraphColor(QColor c);

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const
    {
        return QSize(300,300);
    }

    QSize minimumSizeHint() const
    {
        return QSize(200,200);
    }

private:
    void drawMark(QPainter* painter);
    void drawBucket(QPainter* painter);
    void drawBackground(QPainter* painter);
    void drawGraph(QPainter* painter);
    void resetDrawingVariables(QPainter* painter);

private:
    qreal m_value;
    qreal m_currentValue;
    qreal m_bucketWidth;
    QTimer* updateTimer;
    bool  m_bReverse;
    qreal m_markSpace;
    qreal m_topSpace;
    QColor m_markClr;
    QColor graphcolor1;
    QColor graphcolor2;
    QColor graphcolor3;
    QRectF m_bucketRect;

private:
    void initVariables();

private slots:
    void UpdateGraph();

public slots:
    void setValue(qreal value);
    void setMarkColor(const QColor& clr);

};


#endif // CUTHEIGHT

