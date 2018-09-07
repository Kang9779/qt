#ifndef MQLABEL_H
#define MQLABEL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>


class MQlabel : public QLabel
{
    Q_OBJECT
public:
    explicit MQlabel(QWidget *parent = 0);
    void glitter();
    void setValue(int);

    ~MQlabel();

signals:

private slots:
    void timerout_glitter();

private:
    QTimer *timer_g;
};

#endif // MQLABEL_H
