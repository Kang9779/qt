#ifndef CONTROLSETTING_H
#define CONTROLSETTING_H

#include <QDialog>
#include <QDebug>

#include "can_recv_send.h"

namespace Ui {
class ControlSetting;
}

class ControlSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ControlSetting(QWidget *parent = 0);
    ~ControlSetting();


private:
    Ui::ControlSetting *ui;
    void initUI();
    void send_control_setting();



private slots:
    void setvalid();
    void setinvalid();
};

#endif // CONTROLSETTING_H
