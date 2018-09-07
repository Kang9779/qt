/********************************************************************************
** Form generated from reading UI file 'bucketcircuitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCKETCIRCUITDIALOG_H
#define UI_BUCKETCIRCUITDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_BucketCircuitDialog
{
public:
    QLabel *labelImageBucket;
    QWidget *panel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QListWidget *figureListWidget;
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QListWidget *sensorList;
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
    QGroupBox *groupEval;
    QTextEdit *textFault;
    RadarWidget *radar;
    QLabel *imageDisp;
    QLabel *imagePressure1;
    QLabel *imagePressure4;
    QLabel *imagePressure2;
    QLabel *imagePressure3;

    void setupUi(QDialog *BucketCircuitDialog)
    {
        if (BucketCircuitDialog->objectName().isEmpty())
            BucketCircuitDialog->setObjectName(QStringLiteral("BucketCircuitDialog"));
        BucketCircuitDialog->resize(1000, 750);
        BucketCircuitDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
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
"QLabel#labelImageBucket\n"
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
""
                        "\n"
"QPushButton#btnHistory\n"
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
        labelImageBucket = new QLabel(BucketCircuitDialog);
        labelImageBucket->setObjectName(QStringLiteral("labelImageBucket"));
        labelImageBucket->setGeometry(QRect(20, 50, 461, 361));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelImageBucket->sizePolicy().hasHeightForWidth());
        labelImageBucket->setSizePolicy(sizePolicy);
        labelImageBucket->setMinimumSize(QSize(360, 360));
        labelImageBucket->setPixmap(QPixmap(QString::fromUtf8(":/circuit/rsc/\351\223\262\346\226\227v2wukuang.gif")));
        labelImageBucket->setScaledContents(true);
        panel = new QWidget(BucketCircuitDialog);
        panel->setObjectName(QStringLiteral("panel"));
        panel->setGeometry(QRect(0, 0, 1001, 41));
        horizontalLayout_2 = new QHBoxLayout(panel);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(panel);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        figureListWidget = new QListWidget(BucketCircuitDialog);
        figureListWidget->setObjectName(QStringLiteral("figureListWidget"));
        figureListWidget->setGeometry(QRect(490, 50, 491, 361));
        figureListWidget->setResizeMode(QListView::Adjust);
        figureListWidget->setGridSize(QSize(480, 120));
        horizontalWidget = new QWidget(BucketCircuitDialog);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(20, 420, 461, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        labelSeosor = new QLabel(horizontalWidget);
        labelSeosor->setObjectName(QStringLiteral("labelSeosor"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        labelSeosor->setFont(font1);

        horizontalLayout_3->addWidget(labelSeosor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalWidget_2 = new QWidget(BucketCircuitDialog);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setGeometry(QRect(490, 420, 491, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label = new QLabel(horizontalWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        stackedWidget = new QStackedWidget(BucketCircuitDialog);
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_7->setFont(font2);
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
        label_8->setFont(font2);
        label_8->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);
        label_10->setStyleSheet(QLatin1String("background-color: rgb(192, 192, 192);\n"
"border-right-color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);
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
        sensorList = new QListWidget(layoutWidget);
        sensorList->setObjectName(QStringLiteral("sensorList"));

        verticalLayout_4->addWidget(sensorList);

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
        groupEval = new QGroupBox(BucketCircuitDialog);
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
        imageDisp = new QLabel(BucketCircuitDialog);
        imageDisp->setObjectName(QStringLiteral("imageDisp"));
        imageDisp->setGeometry(QRect(302, 90, 45, 15));
        sizePolicy.setHeightForWidth(imageDisp->sizePolicy().hasHeightForWidth());
        imageDisp->setSizePolicy(sizePolicy);
        imageDisp->setMinimumSize(QSize(40, 12));
        imageDisp->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/disp_left.png")));
        imageDisp->setScaledContents(true);
        imagePressure1 = new QLabel(BucketCircuitDialog);
        imagePressure1->setObjectName(QStringLiteral("imagePressure1"));
        imagePressure1->setGeometry(QRect(202, 152, 71, 41));
        sizePolicy.setHeightForWidth(imagePressure1->sizePolicy().hasHeightForWidth());
        imagePressure1->setSizePolicy(sizePolicy);
        imagePressure1->setStyleSheet(QStringLiteral(""));
        imagePressure1->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/pressure_left.png")));
        imagePressure4 = new QLabel(BucketCircuitDialog);
        imagePressure4->setObjectName(QStringLiteral("imagePressure4"));
        imagePressure4->setGeometry(QRect(86, 330, 61, 41));
        sizePolicy.setHeightForWidth(imagePressure4->sizePolicy().hasHeightForWidth());
        imagePressure4->setSizePolicy(sizePolicy);
        imagePressure4->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/pressure_left.png")));
        imagePressure2 = new QLabel(BucketCircuitDialog);
        imagePressure2->setObjectName(QStringLiteral("imagePressure2"));
        imagePressure2->setGeometry(QRect(272, 152, 61, 41));
        sizePolicy.setHeightForWidth(imagePressure2->sizePolicy().hasHeightForWidth());
        imagePressure2->setSizePolicy(sizePolicy);
        imagePressure2->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/pressure_right.png")));
        imagePressure3 = new QLabel(BucketCircuitDialog);
        imagePressure3->setObjectName(QStringLiteral("imagePressure3"));
        imagePressure3->setGeometry(QRect(212, 330, 61, 41));
        sizePolicy.setHeightForWidth(imagePressure3->sizePolicy().hasHeightForWidth());
        imagePressure3->setSizePolicy(sizePolicy);
        imagePressure3->setPixmap(QPixmap(QString::fromUtf8(":/transducer/rsc/pressure_left.png")));

        retranslateUi(BucketCircuitDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BucketCircuitDialog);
    } // setupUi

    void retranslateUi(QDialog *BucketCircuitDialog)
    {
        BucketCircuitDialog->setWindowTitle(QApplication::translate("BucketCircuitDialog", "Dialog", Q_NULLPTR));
        labelImageBucket->setText(QString());
        label_6->setText(QApplication::translate("BucketCircuitDialog", "\351\223\262\346\226\227\346\266\262\345\216\213\345\233\236\350\267\257", Q_NULLPTR));
        labelSeosor->setText(QApplication::translate("BucketCircuitDialog", "\345\233\236\350\267\257\351\242\204\346\243\200", Q_NULLPTR));
        label->setText(QApplication::translate("BucketCircuitDialog", "\345\201\245\345\272\267\350\257\204\344\274\260", Q_NULLPTR));
        pageDown_1->setText(QString());
        label_7->setText(QApplication::translate("BucketCircuitDialog", "\351\241\271\347\233\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("BucketCircuitDialog", "\344\270\212\346\254\241\346\243\200\346\265\213\346\227\266\351\227\264", Q_NULLPTR));
        label_9->setText(QApplication::translate("BucketCircuitDialog", "\346\225\205\351\232\234", Q_NULLPTR));
        label_10->setText(QApplication::translate("BucketCircuitDialog", "\350\211\257\345\245\275", Q_NULLPTR));
        label_11->setText(QApplication::translate("BucketCircuitDialog", "\345\276\205\346\243\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("BucketCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        pageDown_2->setText(QString());
        pageUp_2->setText(QString());
        label_12->setText(QApplication::translate("BucketCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        label_13->setText(QApplication::translate("BucketCircuitDialog", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        btnRun->setText(QString());
        btnStop->setText(QString());
        btnHistory->setText(QString());
        btnEval->setText(QString());
        pageUp_3->setText(QString());
        label_14->setText(QApplication::translate("BucketCircuitDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        groupEval->setTitle(QString());
        imageDisp->setText(QString());
        imagePressure1->setText(QString());
        imagePressure4->setText(QString());
        imagePressure2->setText(QString());
        imagePressure3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BucketCircuitDialog: public Ui_BucketCircuitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCKETCIRCUITDIALOG_H
