/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *loginBtn;
    QPushButton *exitBtn;
    QLineEdit *usrLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(400, 300);
        loginBtn = new QPushButton(login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(90, 240, 75, 23));
        exitBtn = new QPushButton(login);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(200, 240, 75, 23));
        usrLineEdit = new QLineEdit(login);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(140, 110, 113, 20));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 110, 54, 12));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 150, 54, 12));
        pwdLineEdit = new QLineEdit(login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(140, 150, 113, 20));
        pwdLineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(login);
        QObject::connect(exitBtn, SIGNAL(clicked()), login, SLOT(close()));

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", nullptr));
        loginBtn->setText(QApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        exitBtn->setText(QApplication::translate("login", "\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("login", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
