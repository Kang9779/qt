/********************************************************************************
** Form generated from reading UI file 'boomcircuitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOMCIRCUITDIALOG_H
#define UI_BOOMCIRCUITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
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
#include "qcustomlabel.h"

QT_BEGIN_NAMESPACE

class Ui_BoomCircuitDialog
{
public:
    QCustomLabel *labelImageBoom;
    QGroupBox *groupEval;
    QTextEdit *textFault;
    RadarWidget *radar;
    QLabel *imagePressure1;
    QLabel *imagePressure2;
    QLabel *imageFlow;
    QWidget *panel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSeosor;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
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
    QPushButton *pageDown_2;
    QPushButton *pageUp_2;
    QLabel *label_12;
    QLabel *label_13;
    QListWidget *sensorList;
    QWidget *page_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnRunBoom;
    QPushButton *btnStopBoom;
    QPushButton *btnHistoryBoom;
    QPushButton *btnEvalBoom;
    QVBoxLayout *verticalLayout_3;
    QComboBox *updatePeriodBoom;
    QDateEdit *dateEdit;
    QListWidget *listWidget;
    QPushButton *pageUp_3;
    QLabel *label_14;
    QLabel *imageDisp;
    QListWidget *figureListWidget;
    QLabel *imageTiltY;
    QLabel *imagePressure3;
    QLabel *imageTiltX;
    QButtonGroup *runStopBoom;

    void setupUi(QDialog *BoomCircuitDialog)
    {
        if (BoomCircuitDialog->objectName().isEmpty())
            BoomCircuitDialog->setObjectName(QStringLiteral("BoomCircuitDialog"));
        BoomCircuitDialog->resize(1000, 750);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BoomCircuitDialog->sizePolicy().hasHeightForWidth());
        BoomCircuitDialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        BoomCircuitDialog->setFont(font);
        BoomCircuitDialog->setStyleSheet(QString::fromUtf8("QDialog#BoomCircuitDialog\n"
"{\n"
"	background-color: rgb(255,255, 255);\n"
"}\n"
"\n"
"QWidget#panel\n"
"{\n"
"	background-color:rgb(0, 170, 127)\n"
"}\n"
"\n"
"QLabel#labelImageBoom\n"
"{\n"
"	border:1px solid #999;\n"
"}\n"
"\n"
"QCustomPlot#figureBoom\n"
"{\n"
"	border:1px solid #999;\n"
"}\n"
"\n"
"QFrame#frame\n"
"{\n"
"	border:1px solid #999;\n"
"}\n"
"\n"
"QWidget#verticalWidget\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"\n"
"QCustomPlot#figureBoom\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"QGroupBox#groupBox_2\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"QGroupBox#groupEval\n"
"{\n"
"	border:1px solid #999\n"
"}\n"
"QCheckBox#pressureSensor1,QCheckBox#pressureSensor2\n"
"{\n"
"	border-image: url(:/transducer/rsc/pressure.bmp);\n"
"}\n"
"\n"
"QCheckBox#tiltSensorX,QCheckBox#tiltSensorY,QCheckBox#flowSensor\n"
"{\n"
"	border-image: url(:/transducer/rsc/displacement.png);\n"
"}\n"
"\n"
"QCheckBox#flowSensor\n"
"{\n"
"	border-image: url(:/transducer/rsc/pressure.bmp);\n"
"}\n"
"\n"
"QCheckBox#dispSensor\n"
""
                        "{\n"
"	border-image: url(:/transducer/rsc/displacement.png);\n"
"}\n"
"\n"
"QPushButton#btnRunBoom\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\274\200\345\247\213.png);\n"
"}\n"
"\n"
"QPushButton#btnStopBoom\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\201\234\346\255\242.png);\n"
"}\n"
"\n"
"QPushButton#btnHistoryBoom\n"
"{\n"
"	border-image: url(:/icons/rsc/\345\216\206\345\217\262.png);\n"
"}\n"
"\n"
"QPushButton#btnEvalBoom\n"
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
"	border-image:url(:/ico"
                        "ns/rsc/double-left-chevron.png)\n"
"}"));
        labelImageBoom = new QCustomLabel(BoomCircuitDialog);
        labelImageBoom->setObjectName(QStringLiteral("labelImageBoom"));
        labelImageBoom->setGeometry(QRect(20, 49, 461, 361));
        sizePolicy.setHeightForWidth(labelImageBoom->sizePolicy().hasHeightForWidth());
        labelImageBoom->setSizePolicy(sizePolicy);
        labelImageBoom->setMinimumSize(QSize(200, 360));
        labelImageBoom->setAutoFillBackground(false);
        labelImageBoom->setPixmap(QPixmap(QString::fromUtf8(":/circuit/rsc/\345\212\250\350\207\202\344\270\212\345\215\207\346\227\240\346\241\206.gif")));
        labelImageBoom->setScaledContents(true);
        groupEval = new QGroupBox(BoomCircuitDialog);
        groupEval->setObjectName(QStringLiteral("groupEval"));
        groupEval->setGeometry(QRect(490, 468, 491, 261));
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
        imagePressure1 = new QLabel(BoomCircuitDialog);
        imagePressure1->setObjectName(QStringLiteral("imagePressure1"));
        imagePressure1->setGeometry(QRect(217, 143, 71, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imagePressure1->sizePolicy().hasHeightForWidth());
        imagePressure1->setSizePolicy(sizePolicy1);
        imagePressure1->setStyleSheet(QStringLiteral(""));
        imagePressure2 = new QLabel(BoomCircuitDialog);
        imagePressure2->setObjectName(QStringLiteral("imagePressure2"));
        imagePressure2->setGeometry(QRect(283, 143, 61, 41));
        sizePolicy1.setHeightForWidth(imagePressure2->sizePolicy().hasHeightForWidth());
        imagePressure2->setSizePolicy(sizePolicy1);
        imageFlow = new QLabel(BoomCircuitDialog);
        imageFlow->setObjectName(QStringLiteral("imageFlow"));
        imageFlow->setGeometry(QRect(185, 350, 31, 41));
        sizePolicy1.setHeightForWidth(imageFlow->sizePolicy().hasHeightForWidth());
        imageFlow->setSizePolicy(sizePolicy1);
        panel = new QWidget(BoomCircuitDialog);
        panel->setObjectName(QStringLiteral("panel"));
        panel->setGeometry(QRect(0, 0, 1001, 41));
        sizePolicy.setHeightForWidth(panel->sizePolicy().hasHeightForWidth());
        panel->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(panel);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(panel);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        label_6->setFont(font1);

        horizontalLayout_2->addWidget(label_6);

        horizontalWidget = new QWidget(BoomCircuitDialog);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(20, 419, 461, 41));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        labelSeosor = new QLabel(horizontalWidget);
        labelSeosor->setObjectName(QStringLiteral("labelSeosor"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        labelSeosor->setFont(font2);

        horizontalLayout_3->addWidget(labelSeosor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalWidget_2 = new QWidget(BoomCircuitDialog);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setGeometry(QRect(490, 420, 491, 41));
        sizePolicy.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label = new QLabel(horizontalWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        stackedWidget = new QStackedWidget(BoomCircuitDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(19, 469, 461, 261));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
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
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(120, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_7->setFont(font3);
        label_7->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);\n"
""));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMinimumSize(QSize(120, 0));
        label_8->setFont(font3);
        label_8->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);
        label_9->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);
        label_10->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);
        label_11->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout_9);

        checkList = new QListWidget(verticalLayoutWidget);
        checkList->setObjectName(QStringLiteral("checkList"));
        sizePolicy1.setHeightForWidth(checkList->sizePolicy().hasHeightForWidth());
        checkList->setSizePolicy(sizePolicy1);
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
        sensorList = new QListWidget(page_2);
        sensorList->setObjectName(QStringLiteral("sensorList"));
        sensorList->setGeometry(QRect(10, 13, 440, 221));
        sizePolicy1.setHeightForWidth(sensorList->sizePolicy().hasHeightForWidth());
        sensorList->setSizePolicy(sizePolicy1);
        sensorList->setMinimumSize(QSize(440, 204));
        sensorList->setResizeMode(QListView::Fixed);
        sensorList->setSpacing(8);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy3);
        textBrowser->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(textBrowser);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, -1, 3, -1);
        btnRunBoom = new QPushButton(layoutWidget);
        runStopBoom = new QButtonGroup(BoomCircuitDialog);
        runStopBoom->setObjectName(QStringLiteral("runStopBoom"));
        runStopBoom->addButton(btnRunBoom);
        btnRunBoom->setObjectName(QStringLiteral("btnRunBoom"));
        sizePolicy1.setHeightForWidth(btnRunBoom->sizePolicy().hasHeightForWidth());
        btnRunBoom->setSizePolicy(sizePolicy1);
        btnRunBoom->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnRunBoom);

        btnStopBoom = new QPushButton(layoutWidget);
        runStopBoom->addButton(btnStopBoom);
        btnStopBoom->setObjectName(QStringLiteral("btnStopBoom"));
        sizePolicy1.setHeightForWidth(btnStopBoom->sizePolicy().hasHeightForWidth());
        btnStopBoom->setSizePolicy(sizePolicy1);
        btnStopBoom->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnStopBoom);

        btnHistoryBoom = new QPushButton(layoutWidget);
        btnHistoryBoom->setObjectName(QStringLiteral("btnHistoryBoom"));
        sizePolicy1.setHeightForWidth(btnHistoryBoom->sizePolicy().hasHeightForWidth());
        btnHistoryBoom->setSizePolicy(sizePolicy1);
        btnHistoryBoom->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnHistoryBoom);

        btnEvalBoom = new QPushButton(layoutWidget);
        btnEvalBoom->setObjectName(QStringLiteral("btnEvalBoom"));
        sizePolicy1.setHeightForWidth(btnEvalBoom->sizePolicy().hasHeightForWidth());
        btnEvalBoom->setSizePolicy(sizePolicy1);
        btnEvalBoom->setMinimumSize(QSize(41, 41));

        verticalLayout_2->addWidget(btnEvalBoom);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        updatePeriodBoom = new QComboBox(layoutWidget);
        updatePeriodBoom->setObjectName(QStringLiteral("updatePeriodBoom"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(updatePeriodBoom->sizePolicy().hasHeightForWidth());
        updatePeriodBoom->setSizePolicy(sizePolicy4);
        updatePeriodBoom->setModelColumn(0);

        verticalLayout_3->addWidget(updatePeriodBoom);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        sizePolicy4.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(dateEdit);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout_3);

        pageUp_3 = new QPushButton(page_3);
        pageUp_3->setObjectName(QStringLiteral("pageUp_3"));
        pageUp_3->setGeometry(QRect(435, 235, 16, 16));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 235, 40, 16));
        stackedWidget->addWidget(page_3);
        imageDisp = new QLabel(BoomCircuitDialog);
        imageDisp->setObjectName(QStringLiteral("imageDisp"));
        imageDisp->setGeometry(QRect(258, 70, 45, 15));
        sizePolicy1.setHeightForWidth(imageDisp->sizePolicy().hasHeightForWidth());
        imageDisp->setSizePolicy(sizePolicy1);
        imageDisp->setMinimumSize(QSize(40, 12));
        imageDisp->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/disp_left.png")));
        imageDisp->setScaledContents(true);
        figureListWidget = new QListWidget(BoomCircuitDialog);
        figureListWidget->setObjectName(QStringLiteral("figureListWidget"));
        figureListWidget->setGeometry(QRect(490, 50, 491, 361));
        figureListWidget->setResizeMode(QListView::Adjust);
        figureListWidget->setGridSize(QSize(480, 120));
        imageTiltY = new QLabel(BoomCircuitDialog);
        imageTiltY->setObjectName(QStringLiteral("imageTiltY"));
        imageTiltY->setGeometry(QRect(65, 365, 61, 41));
        sizePolicy1.setHeightForWidth(imageTiltY->sizePolicy().hasHeightForWidth());
        imageTiltY->setSizePolicy(sizePolicy1);
        imagePressure3 = new QLabel(BoomCircuitDialog);
        imagePressure3->setObjectName(QStringLiteral("imagePressure3"));
        imagePressure3->setGeometry(QRect(250, 190, 61, 41));
        sizePolicy1.setHeightForWidth(imagePressure3->sizePolicy().hasHeightForWidth());
        imagePressure3->setSizePolicy(sizePolicy1);
        imageTiltX = new QLabel(BoomCircuitDialog);
        imageTiltX->setObjectName(QStringLiteral("imageTiltX"));
        imageTiltX->setGeometry(QRect(368, 365, 61, 41));
        sizePolicy1.setHeightForWidth(imageTiltX->sizePolicy().hasHeightForWidth());
        imageTiltX->setSizePolicy(sizePolicy1);

        retranslateUi(BoomCircuitDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BoomCircuitDialog);
    } // setupUi

    void retranslateUi(QDialog *BoomCircuitDialog)
    {
        BoomCircuitDialog->setWindowTitle(QApplication::translate("BoomCircuitDialog", "Dialog", Q_NULLPTR));
        labelImageBoom->setText(QString());
        groupEval->setTitle(QString());
        imagePressure1->setText(QString());
        imagePressure2->setText(QString());
        imageFlow->setText(QString());
        label_6->setText(QApplication::translate("BoomCircuitDialog", "\345\212\250\350\207\202\346\266\262\345\216\213\345\233\236\350\267\257", Q_NULLPTR));
        labelSeosor->setText(QApplication::translate("BoomCircuitDialog", "\345\233\236\350\267\257\351\242\204\346\243\200", Q_NULLPTR));
        label->setText(QApplication::translate("BoomCircuitDialog", "\345\201\245\345\272\267\350\257\204\344\274\260", Q_NULLPTR));
        pageDown_1->setText(QString());
        label_7->setText(QApplication::translate("BoomCircuitDialog", "\351\241\271\347\233\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("BoomCircuitDialog", "\344\270\212\346\254\241\346\243\200\346\265\213\346\227\266\351\227\264", Q_NULLPTR));
        label_9->setText(QApplication::translate("BoomCircuitDialog", "\346\225\205\351\232\234", Q_NULLPTR));
        label_10->setText(QApplication::translate("BoomCircuitDialog", "\350\211\257\345\245\275", Q_NULLPTR));
        label_11->setText(QApplication::translate("BoomCircuitDialog", "\345\276\205\346\243\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("BoomCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        pageDown_2->setText(QString());
        pageUp_2->setText(QString());
        label_12->setText(QApplication::translate("BoomCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        label_13->setText(QApplication::translate("BoomCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        btnRunBoom->setText(QString());
        btnStopBoom->setText(QString());
        btnHistoryBoom->setText(QString());
        btnEvalBoom->setText(QString());
        pageUp_3->setText(QString());
        label_14->setText(QApplication::translate("BoomCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        imageDisp->setText(QString());
        imageTiltY->setText(QString());
        imagePressure3->setText(QString());
        imageTiltX->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BoomCircuitDialog: public Ui_BoomCircuitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOMCIRCUITDIALOG_H
