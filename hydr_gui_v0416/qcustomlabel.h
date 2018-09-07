#ifndef QCUSTOMLABEL_H
#define QCUSTOMLABEL_H

#include <QLabel>
#include <QImage>

class QCustomLabel : public QLabel
{
    Q_OBJECT
public:
//    enum Transducer {PressureTransducer,TempretureTransducer,FlowTransducer,DisplacementTransducer,VibrationTransducer};
    explicit QCustomLabel(QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *event);

public slots:
//    void setID(int);
//    void setTransducer(QString);
//    void setLocation(QPoint);
//    void displayTransducer(bool);
    void displayPressure1(bool displayed);
    void displayPressure2(bool displayed);
    void dislplayFlow(bool displayed);
    void displayDisplacement(bool displayed);
    void displayTempreture(bool displayed);
    void displayVibration(bool displayed);

private:
//    QImage *labelIcon;
//    int ID;
//    QVector<QPoint> location;
//    QVector<bool> displayed;
//    QVector<QString> transducer;
    bool displayedPressure1,displayedPressure2;
    bool displayedFlow;
    bool displayedDisplacement;
    bool displayedTempreture;
    bool displayedVibration;
};

#endif // QCUSTOMLABEL_H
