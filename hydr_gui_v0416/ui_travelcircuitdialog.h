/********************************************************************************
** Form generated from reading UI file 'travelcircuitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELCIRCUITDIALOG_H
#define UI_TRAVELCIRCUITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <radarwidget.h>

QT_BEGIN_NAMESPACE

class Ui_TravelCircuitDialog
{
public:
    QWidget *panel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QPushButton *pageDown_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QListWidget *checkList;
    QLabel *label_4;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *pressureSensor1;
    QLabel *label_2;
    QComboBox *comboBox_1;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *pressureSensor2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *dispSensor;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *pressureSensor3;
    QLabel *label_16;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *pressureSensor4;
    QLabel *label_17;
    QComboBox *comboBox_5;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *pressureSensor5;
    QLabel *label_18;
    QComboBox *comboBox_6;
    QPushButton *pageDown_2;
    QPushButton *pageUp_2;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *page_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnRun;
    QPushButton *btnStop;
    QPushButton *btnHistory;
    QPushButton *btnEval;
    QVBoxLayout *verticalLayout_3;
    QComboBox *updatePeriod;
    QDateEdit *dateEdit;
    QListWidget *listWidget;
    QPushButton *pageUp_3;
    QLabel *label_14;
    QListWidget *figureListWidget;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupEval;
    QTextEdit *textFault;
    RadarWidget *radar;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSeosor;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QLabel *labelImageTravel;

    void setupUi(QDialog *TravelCircuitDialog)
    {
        if (TravelCircuitDialog->objectName().isEmpty())
            TravelCircuitDialog->setObjectName(QStringLiteral("TravelCircuitDialog"));
        TravelCircuitDialog->resize(1000, 750);
        TravelCircuitDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#verticalWidget\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"\n"
"QGroupBox#groupEval\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"#panel\n"
"{\n"
"	background-color: rgb(0, 170, 127);\n"
"}\n"
"QFrame#frame\n"
"{\n"
"	border:1px solid #999;\n"
"}\n"
"#horizontalWidget,#horizontalWidget_2\n"
"{\n"
"	\n"
"	background-color: rgb(0, 170, 127);\n"
"}\n"
"QCheckBox#pressureSensor1,QCheckBox#pressureSensor2\n"
"{\n"
"	border-image: url(:/transducer/rsc/pressure.bmp);\n"
"}\n"
"\n"
"QCheckBox#pressureSensor3,QCheckBox#pressureSensor4,QCheckBox#pressureSensor5\n"
"{\n"
"	border-image: url(:/transducer/rsc/pressure.bmp);\n"
"}\n"
"\n"
"QCheckBox#dispSensor\n"
"{\n"
"	border-image: url(:/transducer/rsc/displacement.png);\n"
"}\n"
"\n"
"QPushButton#btnRun\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\274\200\345\247\213.png);\n"
"}\n"
"\n"
"QPushButton#btnStop\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\201\234\346\255\242.png);\n"
"}\n"
"\n"
"QPushB"
                        "utton#btnHistory\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\216\206\345\217\262.png);\n"
"}\n"
"\n"
"QPushButton#btnEval\n"
"{\n"
"	border-image: url(:/icons/rsc/\350\257\204\344\274\260.png);\n"
"}\n"
"#horizontalWidget,#horizontalWidget_2\n"
"{\n"
"	\n"
"	background-color: rgb(0, 170, 127);\n"
"}\n"
"QStackedWidget\n"
"{\n"
"	border:1px solid #999;\n"
"}\n"
"QPushButton#pageDown_1\n"
"{\n"
"	border-image:url(:/icons/rsc/double-right-chevron.png)\n"
"}\n"
"QPushButton#pageUp_2\n"
"{\n"
"	border-image:url(:/icons/rsc/double-left-chevron.png)\n"
"}\n"
"QPushButton#pageDown_2\n"
"{\n"
"	border-image:url(:/icons/rsc/double-right-chevron.png)\n"
"}\n"
"QPushButton#pageUp_3\n"
"{\n"
"	border-image:url(:/icons/rsc/double-left-chevron.png)\n"
"}"));
        panel = new QWidget(TravelCircuitDialog);
        panel->setObjectName(QStringLiteral("panel"));
        panel->setGeometry(QRect(0, 0, 1001, 41));
        panel->setStyleSheet(QLatin1String("#panel\n"
"{\n"
"background-color: rgb(0, 170, 127);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(panel);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(panel);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        stackedWidget = new QStackedWidget(TravelCircuitDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 470, 461, 261));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        pageDown_1 = new QPushButton(page_1);
        pageDown_1->setObjectName(QStringLiteral("pageDown_1"));
        pageDown_1->setGeometry(QRect(435, 235, 16, 16));
        verticalLayoutWidget = new QWidget(page_1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 442, 224));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, 2, -1);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(120, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        label_7->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);\n"
""));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(120, 0));
        label_8->setFont(font1);
        label_8->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout_9);

        checkList = new QListWidget(verticalLayoutWidget);
        checkList->setObjectName(QStringLiteral("checkList"));
        sizePolicy.setHeightForWidth(checkList->sizePolicy().hasHeightForWidth());
        checkList->setSizePolicy(sizePolicy);
        checkList->setMinimumSize(QSize(440, 204));
        checkList->setResizeMode(QListView::Fixed);
        checkList->setSpacing(15);

        verticalLayout->addWidget(checkList);

        label_4 = new QLabel(page_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 235, 40, 16));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 221));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 10, 0, 10);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, -1, 5, -1);
        pressureSensor1 = new QCheckBox(layoutWidget);
        pressureSensor1->setObjectName(QStringLiteral("pressureSensor1"));
        sizePolicy.setHeightForWidth(pressureSensor1->sizePolicy().hasHeightForWidth());
        pressureSensor1->setSizePolicy(sizePolicy);
        pressureSensor1->setMinimumSize(QSize(72, 16));
        pressureSensor1->setStyleSheet(QStringLiteral(""));

        horizontalLayout_5->addWidget(pressureSensor1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(50, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        label_2->setFont(font2);

        horizontalLayout_5->addWidget(label_2);

        comboBox_1 = new QComboBox(layoutWidget);
        comboBox_1->setObjectName(QStringLiteral("comboBox_1"));
        sizePolicy.setHeightForWidth(comboBox_1->sizePolicy().hasHeightForWidth());
        comboBox_1->setSizePolicy(sizePolicy);
        comboBox_1->setMinimumSize(QSize(120, 20));

        horizontalLayout_5->addWidget(comboBox_1);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, -1, 5, -1);
        pressureSensor2 = new QCheckBox(layoutWidget);
        pressureSensor2->setObjectName(QStringLiteral("pressureSensor2"));
        sizePolicy.setHeightForWidth(pressureSensor2->sizePolicy().hasHeightForWidth());
        pressureSensor2->setSizePolicy(sizePolicy);
        pressureSensor2->setMinimumSize(QSize(72, 16));

        horizontalLayout_6->addWidget(pressureSensor2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(50, 20));
        label_3->setFont(font2);

        horizontalLayout_6->addWidget(label_3);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(120, 20));

        horizontalLayout_6->addWidget(comboBox_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, -1, 5, -1);
        dispSensor = new QCheckBox(layoutWidget);
        dispSensor->setObjectName(QStringLiteral("dispSensor"));
        sizePolicy.setHeightForWidth(dispSensor->sizePolicy().hasHeightForWidth());
        dispSensor->setSizePolicy(sizePolicy);
        dispSensor->setMinimumSize(QSize(72, 16));

        horizontalLayout_8->addWidget(dispSensor);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(50, 20));
        label_5->setFont(font2);

        horizontalLayout_8->addWidget(label_5);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);
        comboBox_3->setMinimumSize(QSize(120, 20));

        horizontalLayout_8->addWidget(comboBox_3);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, -1, 5, -1);
        pressureSensor3 = new QCheckBox(layoutWidget);
        pressureSensor3->setObjectName(QStringLiteral("pressureSensor3"));
        sizePolicy.setHeightForWidth(pressureSensor3->sizePolicy().hasHeightForWidth());
        pressureSensor3->setSizePolicy(sizePolicy);
        pressureSensor3->setMinimumSize(QSize(72, 16));

        horizontalLayout_10->addWidget(pressureSensor3);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setMinimumSize(QSize(50, 20));
        label_16->setFont(font2);

        horizontalLayout_10->addWidget(label_16);

        comboBox_4 = new QComboBox(layoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        sizePolicy.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy);
        comboBox_4->setMinimumSize(QSize(120, 20));

        horizontalLayout_10->addWidget(comboBox_4);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, -1, 5, -1);
        pressureSensor4 = new QCheckBox(layoutWidget);
        pressureSensor4->setObjectName(QStringLiteral("pressureSensor4"));
        sizePolicy.setHeightForWidth(pressureSensor4->sizePolicy().hasHeightForWidth());
        pressureSensor4->setSizePolicy(sizePolicy);
        pressureSensor4->setMinimumSize(QSize(72, 16));

        horizontalLayout_11->addWidget(pressureSensor4);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(50, 20));
        label_17->setFont(font2);

        horizontalLayout_11->addWidget(label_17);

        comboBox_5 = new QComboBox(layoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        sizePolicy.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy);
        comboBox_5->setMinimumSize(QSize(120, 20));

        horizontalLayout_11->addWidget(comboBox_5);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(5, -1, 5, -1);
        pressureSensor5 = new QCheckBox(layoutWidget);
        pressureSensor5->setObjectName(QStringLiteral("pressureSensor5"));
        sizePolicy.setHeightForWidth(pressureSensor5->sizePolicy().hasHeightForWidth());
        pressureSensor5->setSizePolicy(sizePolicy);
        pressureSensor5->setMinimumSize(QSize(72, 16));

        horizontalLayout_12->addWidget(pressureSensor5);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(50, 20));
        label_18->setFont(font2);

        horizontalLayout_12->addWidget(label_18);

        comboBox_6 = new QComboBox(layoutWidget);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        sizePolicy.setHeightForWidth(comboBox_6->sizePolicy().hasHeightForWidth());
        comboBox_6->setSizePolicy(sizePolicy);
        comboBox_6->setMinimumSize(QSize(120, 20));

        horizontalLayout_12->addWidget(comboBox_6);


        verticalLayout_4->addLayout(horizontalLayout_12);

        pageDown_2 = new QPushButton(page_2);
        pageDown_2->setObjectName(QStringLiteral("pageDown_2"));
        pageDown_2->setGeometry(QRect(435, 235, 16, 16));
        pageUp_2 = new QPushButton(page_2);
        pageUp_2->setObjectName(QStringLiteral("pageUp_2"));
        pageUp_2->setGeometry(QRect(10, 235, 16, 16));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(35, 235, 40, 16));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(390, 235, 40, 16));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        layoutWidget_2 = new QWidget(page_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 441, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        textBrowser = new QTextBrowser(layoutWidget_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(textBrowser);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, -1, 3, -1);
        btnRun = new QPushButton(layoutWidget_2);
        btnRun->setObjectName(QStringLiteral("btnRun"));
        sizePolicy.setHeightForWidth(btnRun->sizePolicy().hasHeightForWidth());
        btnRun->setSizePolicy(sizePolicy);
        btnRun->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnRun);

        btnStop = new QPushButton(layoutWidget_2);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        sizePolicy.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy);
        btnStop->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnStop);

        btnHistory = new QPushButton(layoutWidget_2);
        btnHistory->setObjectName(QStringLiteral("btnHistory"));
        sizePolicy.setHeightForWidth(btnHistory->sizePolicy().hasHeightForWidth());
        btnHistory->setSizePolicy(sizePolicy);
        btnHistory->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnHistory);

        btnEval = new QPushButton(layoutWidget_2);
        btnEval->setObjectName(QStringLiteral("btnEval"));
        sizePolicy.setHeightForWidth(btnEval->sizePolicy().hasHeightForWidth());
        btnEval->setSizePolicy(sizePolicy);
        btnEval->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnEval);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        updatePeriod = new QComboBox(layoutWidget_2);
        updatePeriod->setObjectName(QStringLiteral("updatePeriod"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(updatePeriod->sizePolicy().hasHeightForWidth());
        updatePeriod->setSizePolicy(sizePolicy3);
        updatePeriod->setModelColumn(0);

        verticalLayout_3->addWidget(updatePeriod);

        dateEdit = new QDateEdit(layoutWidget_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        sizePolicy3.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(dateEdit);

        listWidget = new QListWidget(layoutWidget_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout_3);

        pageUp_3 = new QPushButton(page_3);
        pageUp_3->setObjectName(QStringLiteral("pageUp_3"));
        pageUp_3->setGeometry(QRect(435, 235, 16, 16));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 235, 40, 16));
        stackedWidget->addWidget(page_3);
        figureListWidget = new QListWidget(TravelCircuitDialog);
        figureListWidget->setObjectName(QStringLiteral("figureListWidget"));
        figureListWidget->setGeometry(QRect(490, 50, 491, 361));
        figureListWidget->setResizeMode(QListView::Adjust);
        figureListWidget->setGridSize(QSize(480, 120));
        horizontalWidget_2 = new QWidget(TravelCircuitDialog);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setGeometry(QRect(490, 420, 491, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label = new QLabel(horizontalWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        label->setFont(font3);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        groupEval = new QGroupBox(TravelCircuitDialog);
        groupEval->setObjectName(QStringLiteral("groupEval"));
        groupEval->setGeometry(QRect(490, 470, 491, 261));
        sizePolicy.setHeightForWidth(groupEval->sizePolicy().hasHeightForWidth());
        groupEval->setSizePolicy(sizePolicy);
        groupEval->setMinimumSize(QSize(400, 250));
        groupEval->setAutoFillBackground(false);
        textFault = new QTextEdit(groupEval);
        textFault->setObjectName(QStringLiteral("textFault"));
        textFault->setGeometry(QRect(280, 10, 201, 241));
        radar = new RadarWidget(groupEval);
        radar->setObjectName(QStringLiteral("radar"));
        radar->setGeometry(QRect(10, 10, 261, 241));
        horizontalWidget = new QWidget(TravelCircuitDialog);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(20, 420, 461, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        labelSeosor = new QLabel(horizontalWidget);
        labelSeosor->setObjectName(QStringLiteral("labelSeosor"));
        labelSeosor->setFont(font3);

        horizontalLayout_3->addWidget(labelSeosor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        frame = new QFrame(TravelCircuitDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(19, 50, 461, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelImageTravel = new QLabel(frame);
        labelImageTravel->setObjectName(QStringLiteral("labelImageTravel"));
        labelImageTravel->setGeometry(QRect(-20, 20, 511, 326));
        sizePolicy.setHeightForWidth(labelImageTravel->sizePolicy().hasHeightForWidth());
        labelImageTravel->setSizePolicy(sizePolicy);
        labelImageTravel->setMinimumSize(QSize(458, 326));
        labelImageTravel->setPixmap(QPixmap(QString::fromUtf8(":/circuit/rsc/\345\267\246\345\217\263\350\241\214\350\265\260_\345\212\250\347\224\273\346\227\240\346\241\206.gif")));
        labelImageTravel->setScaledContents(true);

        retranslateUi(TravelCircuitDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TravelCircuitDialog);
    } // setupUi

    void retranslateUi(QDialog *TravelCircuitDialog)
    {
        TravelCircuitDialog->setWindowTitle(QApplication::translate("TravelCircuitDialog", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("TravelCircuitDialog", "\350\241\214\350\265\260\346\266\262\345\216\213\345\233\236\350\267\257", Q_NULLPTR));
        pageDown_1->setText(QString());
        label_7->setText(QApplication::translate("TravelCircuitDialog", "\351\241\271\347\233\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("TravelCircuitDialog", "\344\270\212\346\254\241\346\243\200\346\265\213\346\227\266\351\227\264", Q_NULLPTR));
        label_9->setText(QApplication::translate("TravelCircuitDialog", "\346\225\205\351\232\234", Q_NULLPTR));
        label_10->setText(QApplication::translate("TravelCircuitDialog", "\350\211\257\345\245\275", Q_NULLPTR));
        label_11->setText(QApplication::translate("TravelCircuitDialog", "\345\276\205\346\243\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("TravelCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        pressureSensor1->setText(QString());
        label_2->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232 ", Q_NULLPTR));
        pressureSensor2->setText(QString());
        label_3->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        dispSensor->setText(QString());
        label_5->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pressureSensor3->setText(QString());
        label_16->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pressureSensor4->setText(QString());
        label_17->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pressureSensor5->setText(QString());
        label_18->setText(QApplication::translate("TravelCircuitDialog", "\344\274\240\346\204\237\345\231\250\344\277\241\345\217\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pageDown_2->setText(QString());
        pageUp_2->setText(QString());
        label_12->setText(QApplication::translate("TravelCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        label_13->setText(QApplication::translate("TravelCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        btnRun->setText(QString());
        btnStop->setText(QString());
        btnHistory->setText(QString());
        btnEval->setText(QString());
        pageUp_3->setText(QString());
        label_14->setText(QApplication::translate("TravelCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        label->setText(QApplication::translate("TravelCircuitDialog", "\345\201\245\345\272\267\350\257\204\344\274\260", Q_NULLPTR));
        groupEval->setTitle(QString());
        labelSeosor->setText(QApplication::translate("TravelCircuitDialog", "\345\233\236\350\267\257\351\242\204\346\243\200", Q_NULLPTR));
        labelImageTravel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TravelCircuitDialog: public Ui_TravelCircuitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELCIRCUITDIALOG_H
