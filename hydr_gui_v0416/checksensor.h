#ifndef CHECKSENSOR_H
#define CHECKSENSOR_H

#include <QWidget>
#include <QCheckBox>
#include <QDateEdit>
#include <QRadioButton>
#include <QLabel>

class CheckSensor : public QWidget
{
    Q_OBJECT
public:
    explicit CheckSensor(QWidget *parent = 0);

signals:

public slots:

private:
    QCheckBox *checkBox;
    QDateEdit *dateEdit;
    QRadioButton *redButton;
    QRadioButton *greenButton;
    QRadioButton *yellowButton;
    QLabel *sadLabel;
    QLabel *smileLabel;
    QLabel *suspiciousLabel;

public:
    void setItemName(QString name);
};

#endif // CHECKSENSOR_H
