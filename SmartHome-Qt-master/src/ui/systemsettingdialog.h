/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-11-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ϵͳ���ù���
            1.��Ҫ��������ZigBee�Ĵ��ںš������ʵȴ�����Ϣ������
            2.ϵͳ����Ĭ�ϲ�������(���翪��������������ơ���)
            2.ϵͳ����
**************************************************/
#ifndef SYSTEMSETTINGDIALOG_H
#define SYSTEMSETTINGDIALOG_H

#include <QDialog>


namespace Ui {
class SystemSettingDialog;
}

class SystemSettingDialog : public QDialog
{
    Q_OBJECT
    enum baudNum{
        E_BAUD9600 = 0,
        E_BAUD115200,
        E_BAUDNUMNULL
    };
    enum baudName{
        E_BAUDCOM0 = 0,
        E_BAUDCOM1,
        E_BAUDCOM2,
        E_BAUDCOM3,
        E_BAUDCOM4,
        E_BAUDCOM5,
        E_BAUDCOM6,
        E_BAUDCOM7,
        E_BAUDCOM8,
        E_BAUDCOMNULL
    };
    
public:
    explicit SystemSettingDialog(QWidget *parent = 0);
    ~SystemSettingDialog();

private:
    void initForm();
    void initData();
    void initWidget();
    void initConnect();

    int getBaudNum(const int baud);
    int getBaudName(const QString &baud);

Q_SIGNALS:
    void signalSendSetTempValue(const int &);
    void signalSendSetHumValue(const int &);
    void signalSendSetSmokeValue(const int &);
    void signalSendSetSaveDataTime(const int &);
    
private slots:
    void on_pbnOk_clicked();

    void on_pbnClosePort_clicked();

    void on_tbnMenuClose_clicked();

    void on_spinBox_temp_valueChanged(int arg1);

    void on_spinBox_hum_valueChanged(int arg1);

    void on_spinBox_smoke_valueChanged(int arg1);

    void on_spinBox_save_time_valueChanged(int arg1);

public slots:
    //void slotReadInfo(QByteArray byte);

private:
    Ui::SystemSettingDialog *ui;

    bool m_isopenPort;
    QStringList m_portName;
    QStringList m_portBaud;
};

#endif // SYSTEMSETTINGDIALOG_H
