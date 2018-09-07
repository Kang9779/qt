#ifndef SETSENSOR_H
#define SETSENSOR_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>

class SetSensor: public QWidget
{
    Q_OBJECT
public:
    explicit SetSensor(QWidget *parent = 0);

public:
    QCheckBox *SensorSwitch;
    QLabel *SensorImage;
    QImage *image;
    QLabel *SensorName;
    QComboBox *SensorSignal;

    QString num_;
    int typeIndex_;
    QString name_;

public:
    void setSensorNumber(QString num);
    void setSensorType(int typeIndex);
    void setSignalName(QString name);
};

#endif // SETSENSOR_H
