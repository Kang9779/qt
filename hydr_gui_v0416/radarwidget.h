#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QWidget>

class RadarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadarWidget(QWidget *parent = 0);
    ~RadarWidget();
    double hlthy[4];
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // RADARWIDGET_H
