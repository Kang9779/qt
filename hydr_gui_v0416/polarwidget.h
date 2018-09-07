#ifndef POLARWIDGET_H
#define POLARWIDGET_H
#include <QWidget>
#include <QGraphicsView>
class PolarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PolarWidget(QWidget *parent = 0);
    ~PolarWidget();
//    void PaintContent();
    int hlthy_cyld1;
    int hlthy_cyld2;
    int hlthy_valve1;
    int hlthy_valve2;
//    void PaintHealthy();
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // POLARWIDGET_H
