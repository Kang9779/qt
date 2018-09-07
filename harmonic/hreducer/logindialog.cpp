#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>

LoginDialog::LoginDialog(QWidget *parent):
    QDialog(parent)
{
    usrLabel = new QLabel(this);
    usrLabel->setText(tr("用户名"));
    usrLabel->move(70,80);
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->setPlaceholderText(tr("请输入用户名"));
    usrLineEdit->move(140,80);

    pwdLabel = new QLabel(this);
    pwdLabel->setText(tr("密码"));
    pwdLabel->move(70,130);
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->setPlaceholderText(tr("请输入密码"));
    pwdLineEdit->move(140,130);

    loginBtn = new QPushButton(this);
    loginBtn->setText(tr("登陆"));
    loginBtn->move(140,150);

    exitBtn = new QPushButton(this);
    exitBtn->setText(tr("退出"));
    exitBtn->move(180,150);

    connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::login);
    connect(exitBtn,&QPushButton::clicked,this,&LoginDialog::close);

}
LoginDialog::~LoginDialog()
{

}
void LoginDialog::login()
{
    if(usrLineEdit->text()==tr("kangzhang")&&
            pwdLineEdit->text()==tr("123")){
        accept();
    }
    else{
        QMessageBox::warning(this,tr("警告！"),
                             tr("用户名或者密码错误!"),
                             QMessageBox::Yes);
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}
void LoginDialog::close()
{
    QWidget::close();
}
