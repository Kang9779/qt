/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout;
    QLabel *currentDateTime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *restartButton;
    QPushButton *shutdownButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelLogo;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *loginForm;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_4;
    QPushButton *loginButon;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1000, 750);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Login->setFont(font);
        Login->setStyleSheet(QLatin1String("QLineEdit { border-radius: 3px;}\n"
"\n"
"QLabel { color: black; }\n"
"\n"
"QPushButton#loginButon,#restartButton,#shutdownButton\n"
"{\n"
"	color: white;\n"
"	background-color: #27a9e3;\n"
"	border-width: 0px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QPushButton:hover { background-color: #66c011; }\n"
"\n"
"QWidget#centralWidget\n"
"{\n"
"	background:rgba(85, 170, 255,50)\n"
"\n"
"}\n"
"\n"
"QWidget#loginForm\n"
"{\n"
"	border-radius:20;\n"
"	border:3px solid rgba(0, 85, 255,30);\n"
"}\n"
"QStatusBar\n"
"{\n"
"	\n"
"	background-color: rgb(0, 170, 127);\n"
"}"));
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topPanel = new QWidget(centralWidget);
        topPanel->setObjectName(QStringLiteral("topPanel"));
        topPanel->setStyleSheet(QLatin1String("#topPanel { background-color:\n"
"rgb(0, 170, 127); }"));
        horizontalLayout = new QHBoxLayout(topPanel);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 5, 5, 5);
        currentDateTime = new QLabel(topPanel);
        currentDateTime->setObjectName(QStringLiteral("currentDateTime"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(currentDateTime->sizePolicy().hasHeightForWidth());
        currentDateTime->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        currentDateTime->setFont(font1);

        horizontalLayout->addWidget(currentDateTime);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(topPanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(24);
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        restartButton = new QPushButton(topPanel);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(restartButton->sizePolicy().hasHeightForWidth());
        restartButton->setSizePolicy(sizePolicy1);
        restartButton->setMinimumSize(QSize(55, 55));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/rsc/restart_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        restartButton->setIcon(icon);
        restartButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(restartButton);

        shutdownButton = new QPushButton(topPanel);
        shutdownButton->setObjectName(QStringLiteral("shutdownButton"));
        sizePolicy1.setHeightForWidth(shutdownButton->sizePolicy().hasHeightForWidth());
        shutdownButton->setSizePolicy(sizePolicy1);
        shutdownButton->setMinimumSize(QSize(55, 55));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/rsc/shutdown_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        shutdownButton->setIcon(icon1);
        shutdownButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(shutdownButton);


        verticalLayout->addWidget(topPanel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, 0);
        labelLogo = new QLabel(centralWidget);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        sizePolicy1.setHeightForWidth(labelLogo->sizePolicy().hasHeightForWidth());
        labelLogo->setSizePolicy(sizePolicy1);
        labelLogo->setMinimumSize(QSize(120, 120));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/rsc/\345\277\203\347\213\227.png")));

        horizontalLayout_5->addWidget(labelLogo);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        sizePolicy1.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy1);
        logo->setMinimumSize(QSize(172, 150));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/rsc/\346\214\226\346\234\272.png")));
        logo->setScaledContents(true);

        horizontalLayout_2->addWidget(logo);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        loginForm = new QWidget(centralWidget);
        loginForm->setObjectName(QStringLiteral("loginForm"));
        sizePolicy1.setHeightForWidth(loginForm->sizePolicy().hasHeightForWidth());
        loginForm->setSizePolicy(sizePolicy1);
        loginForm->setMinimumSize(QSize(350, 150));
        loginForm->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(loginForm);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(35, 35, 35, 25);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(loginForm);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(24, 24));
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/rsc/\347\224\250\346\210\267.png")));
        label->setScaledContents(false);

        horizontalLayout_6->addWidget(label);

        username = new QLineEdit(loginForm);
        username->setObjectName(QStringLiteral("username"));
        username->setMinimumSize(QSize(0, 25));

        horizontalLayout_6->addWidget(username);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(loginForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(24, 24));
        label_2->setFont(font);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/rsc/\345\257\206\347\240\201.png")));

        horizontalLayout_4->addWidget(label_2);

        password = new QLineEdit(loginForm);
        password->setObjectName(QStringLiteral("password"));
        password->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(password);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        loginButon = new QPushButton(loginForm);
        loginButon->setObjectName(QStringLiteral("loginButon"));
        loginButon->setMinimumSize(QSize(0, 30));
        loginButon->setFont(font);

        verticalLayout_2->addWidget(loginButon);


        horizontalLayout_3->addWidget(loginForm);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Login->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Login->setStatusBar(statusBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        currentDateTime->setText(QApplication::translate("Login", "Monday, 26-10-2015 3:14 PM", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "\346\266\262\345\216\213\345\277\203\347\213\227-SY215\346\214\226\346\216\230\346\234\272", Q_NULLPTR));
        restartButton->setText(QString());
        shutdownButton->setText(QString());
        labelLogo->setText(QString());
        logo->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        loginButon->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
