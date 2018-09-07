/********************************************************************************
** Form generated from reading UI file 'parametersetting.ui'
**
** Created: Mon Jun 4 21:49:20 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTING_H
#define UI_PARAMETERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include "softkeylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ParameterSetting
{
public:
    SoftKeyLineEdit *lineEdit;
    QLabel *label_23;
    QLabel *label_103;
    QLabel *label_22;
    QLabel *label_102;
    QLabel *label_10;
    SoftKeyLineEdit *l_concaveclset;
    QLabel *label_19;
    SoftKeyLineEdit *l_rsls;
    SoftKeyLineEdit *l_cuth_max;
    SoftKeyLineEdit *l_pfh;
    SoftKeyLineEdit *l_cuth_min;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *OK_btn;
    QPushButton *Cancel_btn;
    QComboBox *grain_kind;
    QLabel *label_7;
    QLabel *label_105;
    QComboBox *cbx_2;
    SoftKeyLineEdit *rollerSpeed;
    SoftKeyLineEdit *draughtFanSpeed;
    SoftKeyLineEdit *sortingScreenUp;
    SoftKeyLineEdit *sortingScreenDown;
    SoftKeyLineEdit *sortingScreenTail;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QDialog *ParameterSetting)
    {
        if (ParameterSetting->objectName().isEmpty())
            ParameterSetting->setObjectName(QString::fromUtf8("ParameterSetting"));
        ParameterSetting->resize(670, 216);
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font.setPointSize(17);
        ParameterSetting->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/leiwo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ParameterSetting->setWindowIcon(icon);
        lineEdit = new SoftKeyLineEdit(ParameterSetting);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 10, 70, 40));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_23 = new QLabel(ParameterSetting);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 160, 39, 40));
        label_23->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/cut_height_min.png);"));
        label_103 = new QLabel(ParameterSetting);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        label_103->setGeometry(QRect(10, 59, 39, 40));
        label_103->setStyleSheet(QString::fromUtf8("border-image: url(:/images/con_recong/ProfilingHeightSet.png);"));
        label_22 = new QLabel(ParameterSetting);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 114, 39, 40));
        label_22->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/cut_height_max.png);"));
        label_102 = new QLabel(ParameterSetting);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        label_102->setGeometry(QRect(10, 10, 39, 39));
        label_102->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/Weight1000.png);"));
        label_10 = new QLabel(ParameterSetting);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 10, 39, 40));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/RollerSpeedLowSetting.png);"));
        l_concaveclset = new SoftKeyLineEdit(ParameterSetting);
        l_concaveclset->setObjectName(QString::fromUtf8("l_concaveclset"));
        l_concaveclset->setGeometry(QRect(220, 60, 70, 40));
        l_concaveclset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(ParameterSetting);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(170, 60, 39, 40));
        label_19->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/ConcaveClearanceSetting.png);"));
        l_rsls = new SoftKeyLineEdit(ParameterSetting);
        l_rsls->setObjectName(QString::fromUtf8("l_rsls"));
        l_rsls->setGeometry(QRect(220, 10, 70, 40));
        l_rsls->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_cuth_max = new SoftKeyLineEdit(ParameterSetting);
        l_cuth_max->setObjectName(QString::fromUtf8("l_cuth_max"));
        l_cuth_max->setGeometry(QRect(60, 115, 70, 40));
        l_cuth_max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_pfh = new SoftKeyLineEdit(ParameterSetting);
        l_pfh->setObjectName(QString::fromUtf8("l_pfh"));
        l_pfh->setGeometry(QRect(60, 60, 70, 40));
        l_pfh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_cuth_min = new SoftKeyLineEdit(ParameterSetting);
        l_cuth_min->setObjectName(QString::fromUtf8("l_cuth_min"));
        l_cuth_min->setGeometry(QRect(60, 161, 70, 39));
        l_cuth_min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(ParameterSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 40, 30));
        label_2 = new QLabel(ParameterSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 70, 40, 30));
        label_3 = new QLabel(ParameterSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 20, 40, 30));
        label_4 = new QLabel(ParameterSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 60, 40, 30));
        label_5 = new QLabel(ParameterSetting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 125, 40, 30));
        label_6 = new QLabel(ParameterSetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 170, 40, 30));
        OK_btn = new QPushButton(ParameterSetting);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));
        OK_btn->setGeometry(QRect(550, 150, 91, 31));
        OK_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 111, 249);"));
        Cancel_btn = new QPushButton(ParameterSetting);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));
        Cancel_btn->setGeometry(QRect(550, 100, 91, 31));
        Cancel_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 88, 88);"));
        grain_kind = new QComboBox(ParameterSetting);
        grain_kind->setObjectName(QString::fromUtf8("grain_kind"));
        grain_kind->setGeometry(QRect(220, 160, 91, 41));
        label_7 = new QLabel(ParameterSetting);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(172, 110, 39, 41));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/CutMachineMode.png);"));
        label_105 = new QLabel(ParameterSetting);
        label_105->setObjectName(QString::fromUtf8("label_105"));
        label_105->setGeometry(QRect(175, 166, 30, 30));
        label_105->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/RiceKind.png);"));
        cbx_2 = new QComboBox(ParameterSetting);
        cbx_2->setObjectName(QString::fromUtf8("cbx_2"));
        cbx_2->setGeometry(QRect(220, 110, 91, 41));
        rollerSpeed = new SoftKeyLineEdit(ParameterSetting);
        rollerSpeed->setObjectName(QString::fromUtf8("rollerSpeed"));
        rollerSpeed->setGeometry(QRect(390, 10, 71, 41));
        QFont font1;
        font1.setPointSize(17);
        rollerSpeed->setFont(font1);
        draughtFanSpeed = new SoftKeyLineEdit(ParameterSetting);
        draughtFanSpeed->setObjectName(QString::fromUtf8("draughtFanSpeed"));
        draughtFanSpeed->setGeometry(QRect(560, 10, 71, 41));
        draughtFanSpeed->setFont(font1);
        sortingScreenUp = new SoftKeyLineEdit(ParameterSetting);
        sortingScreenUp->setObjectName(QString::fromUtf8("sortingScreenUp"));
        sortingScreenUp->setGeometry(QRect(390, 60, 71, 41));
        sortingScreenDown = new SoftKeyLineEdit(ParameterSetting);
        sortingScreenDown->setObjectName(QString::fromUtf8("sortingScreenDown"));
        sortingScreenDown->setGeometry(QRect(390, 110, 71, 41));
        sortingScreenTail = new SoftKeyLineEdit(ParameterSetting);
        sortingScreenTail->setObjectName(QString::fromUtf8("sortingScreenTail"));
        sortingScreenTail->setGeometry(QRect(390, 160, 71, 41));
        label_8 = new QLabel(ParameterSetting);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(340, 10, 40, 40));
        label_8->setMinimumSize(QSize(40, 40));
        label_8->setMaximumSize(QSize(40, 40));
        label_8->setStyleSheet(QString::fromUtf8("border-image:url(:/images/engine/RollerSpeed.png)"));
        label_9 = new QLabel(ParameterSetting);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(510, 10, 40, 40));
        label_9->setMinimumSize(QSize(40, 40));
        label_9->setMaximumSize(QSize(40, 40));
        label_9->setStyleSheet(QString::fromUtf8("border-image:url(:/images/engine/draught_fanimpurity_rate.png)"));
        label_11 = new QLabel(ParameterSetting);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(340, 60, 40, 40));
        label_11->setMinimumSize(QSize(40, 40));
        label_11->setMaximumSize(QSize(40, 40));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/images/parameters/sorting_screen_up.png)"));
        label_12 = new QLabel(ParameterSetting);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(340, 120, 40, 31));
        label_12->setMinimumSize(QSize(40, 31));
        label_12->setMaximumSize(QSize(40, 40));
        label_12->setStyleSheet(QString::fromUtf8("border-image: url(:/images/parameters/sorting_screen_down.png)"));
        label_13 = new QLabel(ParameterSetting);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(340, 160, 40, 40));
        label_13->setMinimumSize(QSize(40, 40));
        label_13->setMaximumSize(QSize(40, 40));
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/images/parameters/sorting_screen_tail.png)"));
        label_14 = new QLabel(ParameterSetting);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(460, 20, 40, 30));
        label_15 = new QLabel(ParameterSetting);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(630, 20, 40, 30));
        label_16 = new QLabel(ParameterSetting);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(470, 110, 40, 30));
        label_17 = new QLabel(ParameterSetting);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(470, 160, 31, 31));

        retranslateUi(ParameterSetting);

        QMetaObject::connectSlotsByName(ParameterSetting);
    } // setupUi

    void retranslateUi(QDialog *ParameterSetting)
    {
        ParameterSetting->setWindowTitle(QApplication::translate("ParameterSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ParameterSetting", "0.00", 0, QApplication::UnicodeUTF8));
        label_23->setText(QString());
        label_103->setText(QString());
        label_22->setText(QString());
        label_102->setText(QString());
        label_10->setText(QString());
        l_concaveclset->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_19->setText(QString());
        l_rsls->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_cuth_max->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_pfh->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        l_cuth_min->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ParameterSetting", "g", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
        OK_btn->setText(QApplication::translate("ParameterSetting", "OK", 0, QApplication::UnicodeUTF8));
        Cancel_btn->setText(QApplication::translate("ParameterSetting", "Cancel", 0, QApplication::UnicodeUTF8));
        grain_kind->clear();
        grain_kind->insertItems(0, QStringList()
         << QApplication::translate("ParameterSetting", "\346\260\264\347\250\273", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ParameterSetting", "\345\260\217\351\272\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ParameterSetting", "\347\216\211\347\261\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ParameterSetting", "\345\244\247\350\261\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ParameterSetting", "\345\205\266\344\273\226", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QString());
        label_105->setText(QString());
        cbx_2->clear();
        cbx_2->insertItems(0, QStringList()
         << QApplication::translate("ParameterSetting", "\345\210\207\347\242\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ParameterSetting", "\346\216\222\350\215\211", 0, QApplication::UnicodeUTF8)
        );
        rollerSpeed->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        draughtFanSpeed->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        sortingScreenUp->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        sortingScreenDown->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        sortingScreenTail->setText(QApplication::translate("ParameterSetting", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ParameterSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("ParameterSetting", "mm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParameterSetting: public Ui_ParameterSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTING_H
