#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include "logindialog.h"
#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog:public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent=0);
    ~LoginDialog();
private slots:
    void login();
    void close();

private:
   QLabel *usrLabel;
   QLabel *pwdLabel;
   QLineEdit *usrLineEdit;
   QLineEdit *pwdLineEdit;
   QPushButton *loginBtn;
   QPushButton *exitBtn;
};
#endif
