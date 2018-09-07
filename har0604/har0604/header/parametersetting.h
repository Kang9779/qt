#ifndef PARAMETERSETTING_H
#define PARAMETERSETTING_H

#include <QDialog>
#include "can_recv_send.h"

extern char dataArray130[8];
extern char dataArray230[8];
extern int flag_send_setting;
extern QByteArray arr12;
//extern QByteArray arr23;

namespace Ui {
class ParameterSetting;
}

class ParameterSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ParameterSetting(QWidget *parent = 0);

    void initUI();

    ~ParameterSetting();

private:
    Ui::ParameterSetting *ui;
    void send_para_setting();

//signals:
//    void settingpara1(QByteArray bArray);
//    void settingpara2(QByteArray bArray);


private slots:
    void setvalid();
    void setinvalid();

};

#endif // PARAMETERSETTING_H
