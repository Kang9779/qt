/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget1;
    QLabel *labelImageSY215;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BtnBucketCircuit;
    QPushButton *BtnArmCircuit;
    QPushButton *BtnBoomCircuit;
    QPushButton *BtnSwingCircuit;
    QPushButton *BtnTravelCircuit;
    QPushButton *BtnPumpCircuit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *panel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 750);
        MainWindow->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"	border:2px solid #999\n"
"}\n"
"\n"
"#centralWidget1\n"
"{\n"
"	background:rgba(85, 170, 255,50);\n"
"}\n"
"\n"
"QWidget#panel\n"
"{\n"
"	background-color:rgb(0, 170, 127)\n"
"}\n"
"QPushButton#BtnPumpCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\346\263\265.png);\n"
"	border-radius:20px;\n"
"}\n"
"\n"
"QPushButton#BtnTravelCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\350\241\214\350\265\260.png);\n"
"	border-radius:20px;\n"
"}\n"
"\n"
"QPushButton#BtnBoomCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\212\250\350\207\202.png);\n"
"	border-radius:20px;\n"
"}\n"
"\n"
"QPushButton#BtnBucketCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\346\214\226\346\226\2271.png);\n"
"	border-radius:20px;\n"
"}\n"
"\n"
"QPushButton#BtnArmCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\346\226\227\346\235\206.png);\n"
"	border-radius:20px;\n"
"}\n"
"\n"
"QPushButton#BtnSwingCircuit\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\233\236\350\275\254.png);\n"
"	border-radius:20px;\n"
"}\n"
""));
        centralWidget1 = new QWidget(MainWindow);
        centralWidget1->setObjectName(QStringLiteral("centralWidget1"));
        centralWidget1->setEnabled(true);
        centralWidget1->setFocusPolicy(Qt::NoFocus);
        centralWidget1->setStyleSheet(QStringLiteral(""));
        labelImageSY215 = new QLabel(centralWidget1);
        labelImageSY215->setObjectName(QStringLiteral("labelImageSY215"));
        labelImageSY215->setGeometry(QRect(180, 110, 581, 351));
        labelImageSY215->setPixmap(QPixmap(QString::fromUtf8(":/images/rsc/main_sany.png")));
        labelImageSY215->setScaledContents(false);
        horizontalLayoutWidget_3 = new QWidget(centralWidget1);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(60, 520, 894, 142));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        BtnBucketCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnBucketCircuit->setObjectName(QStringLiteral("BtnBucketCircuit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BtnBucketCircuit->sizePolicy().hasHeightForWidth());
        BtnBucketCircuit->setSizePolicy(sizePolicy);
        BtnBucketCircuit->setMinimumSize(QSize(132, 140));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        BtnBucketCircuit->setFont(font);

        horizontalLayout_3->addWidget(BtnBucketCircuit);

        BtnArmCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnArmCircuit->setObjectName(QStringLiteral("BtnArmCircuit"));
        sizePolicy.setHeightForWidth(BtnArmCircuit->sizePolicy().hasHeightForWidth());
        BtnArmCircuit->setSizePolicy(sizePolicy);
        BtnArmCircuit->setMinimumSize(QSize(132, 140));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        BtnArmCircuit->setFont(font1);
        BtnArmCircuit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(BtnArmCircuit);

        BtnBoomCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnBoomCircuit->setObjectName(QStringLiteral("BtnBoomCircuit"));
        sizePolicy.setHeightForWidth(BtnBoomCircuit->sizePolicy().hasHeightForWidth());
        BtnBoomCircuit->setSizePolicy(sizePolicy);
        BtnBoomCircuit->setMinimumSize(QSize(132, 140));
        BtnBoomCircuit->setFont(font);

        horizontalLayout_3->addWidget(BtnBoomCircuit);

        BtnSwingCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnSwingCircuit->setObjectName(QStringLiteral("BtnSwingCircuit"));
        sizePolicy.setHeightForWidth(BtnSwingCircuit->sizePolicy().hasHeightForWidth());
        BtnSwingCircuit->setSizePolicy(sizePolicy);
        BtnSwingCircuit->setMinimumSize(QSize(132, 140));
        BtnSwingCircuit->setFont(font);

        horizontalLayout_3->addWidget(BtnSwingCircuit);

        BtnTravelCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnTravelCircuit->setObjectName(QStringLiteral("BtnTravelCircuit"));
        sizePolicy.setHeightForWidth(BtnTravelCircuit->sizePolicy().hasHeightForWidth());
        BtnTravelCircuit->setSizePolicy(sizePolicy);
        BtnTravelCircuit->setMinimumSize(QSize(132, 140));
        BtnTravelCircuit->setFont(font1);
        BtnTravelCircuit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(BtnTravelCircuit);

        BtnPumpCircuit = new QPushButton(horizontalLayoutWidget_3);
        BtnPumpCircuit->setObjectName(QStringLiteral("BtnPumpCircuit"));
        sizePolicy.setHeightForWidth(BtnPumpCircuit->sizePolicy().hasHeightForWidth());
        BtnPumpCircuit->setSizePolicy(sizePolicy);
        BtnPumpCircuit->setMinimumSize(QSize(132, 140));
        BtnPumpCircuit->setFont(font);

        horizontalLayout_3->addWidget(BtnPumpCircuit);

        label_2 = new QLabel(centralWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 670, 51, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 670, 51, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(centralWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 670, 51, 21));
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(570, 670, 51, 21));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(720, 670, 51, 21));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(860, 670, 71, 21));
        label_7->setFont(font2);
        panel = new QWidget(centralWidget1);
        panel->setObjectName(QStringLiteral("panel"));
        panel->setGeometry(QRect(0, 0, 1001, 61));
        horizontalLayout = new QHBoxLayout(panel);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(panel);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(36);
        label->setFont(font3);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralWidget1);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        labelImageSY215->setText(QString());
        BtnBucketCircuit->setText(QString());
        BtnArmCircuit->setText(QString());
        BtnBoomCircuit->setText(QString());
        BtnSwingCircuit->setText(QString());
        BtnTravelCircuit->setText(QString());
        BtnPumpCircuit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\351\223\262\346\226\227", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\212\250\350\207\202", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\226\227\346\235\206", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\233\236\350\275\254", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\350\241\214\350\265\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\266\262\345\216\213\346\263\265", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\214\226\346\216\230\346\234\272\346\266\262\345\216\213\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
