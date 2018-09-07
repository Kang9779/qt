#include "login.h"
#include "ui_login.h"
#include <qmessagebox.h>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->pwdLineEdit->setPlaceholderText(tr("请输入密码"));
    ui->usrLineEdit->setPlaceholderText(tr("请输入用户名"));
}

login::~login()
{
    delete ui;
}

void login::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text()==tr("kangzhang")&&
            ui->pwdLineEdit->text()==tr("123")){
        accept();
    }
    else{
        QMessageBox::warning(this,tr("警告！"),
                             tr("用户名或者密码错误!"),
                             QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
