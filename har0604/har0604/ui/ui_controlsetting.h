/********************************************************************************
** Form generated from reading UI file 'controlsetting.ui'
**
** Created: Mon Jun 4 20:55:23 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLSETTING_H
#define UI_CONTROLSETTING_H

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

class Ui_ControlSetting
{
public:
    QComboBox *cbx_1;
    QLabel *label;
    QLabel *l_chrs;
    QComboBox *cbx_3;
    QLabel *m_reset;
    QComboBox *cbx_4;
    QLabel *auto_load_regu;
    QComboBox *cbx_5;
    QLabel *auto_height;
    QComboBox *cbx_6;
    QLabel *l_rw_cl;
    QComboBox *cbx_7;
    QComboBox *cbx_9;
    QLabel *m_reset_2;
    QPushButton *Cancel_btn;
    QPushButton *OK_btn;
    SoftKeyLineEdit *reelSpeed;
    SoftKeyLineEdit *cutterHz;
    SoftKeyLineEdit *augerSpeed;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *ControlSetting)
    {
        if (ControlSetting->objectName().isEmpty())
            ControlSetting->setObjectName(QString::fromUtf8("ControlSetting"));
        ControlSetting->resize(516, 312);
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font.setPointSize(16);
        ControlSetting->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/leiwo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControlSetting->setWindowIcon(icon);
        cbx_1 = new QComboBox(ControlSetting);
        cbx_1->setObjectName(QString::fromUtf8("cbx_1"));
        cbx_1->setGeometry(QRect(60, 210, 241, 41));
        label = new QLabel(ControlSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 210, 39, 41));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/UnloaderSetting.png);"));
        label->setLineWidth(1);
        l_chrs = new QLabel(ControlSetting);
        l_chrs->setObjectName(QString::fromUtf8("l_chrs"));
        l_chrs->setGeometry(QRect(10, 260, 40, 40));
        l_chrs->setStyleSheet(QString::fromUtf8("border-image: url(:/images/parameters/CutHeightResetOn.png);"));
        cbx_3 = new QComboBox(ControlSetting);
        cbx_3->setObjectName(QString::fromUtf8("cbx_3"));
        cbx_3->setGeometry(QRect(60, 260, 241, 41));
        m_reset = new QLabel(ControlSetting);
        m_reset->setObjectName(QString::fromUtf8("m_reset"));
        m_reset->setGeometry(QRect(10, 110, 40, 40));
        m_reset->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/ZeroOn.png);"));
        cbx_4 = new QComboBox(ControlSetting);
        cbx_4->setObjectName(QString::fromUtf8("cbx_4"));
        cbx_4->setGeometry(QRect(60, 110, 241, 41));
        cbx_4->setStyleSheet(QString::fromUtf8("font: 16pt \"AR PL UKai CN\";"));
        auto_load_regu = new QLabel(ControlSetting);
        auto_load_regu->setObjectName(QString::fromUtf8("auto_load_regu"));
        auto_load_regu->setGeometry(QRect(10, 60, 40, 40));
        auto_load_regu->setStyleSheet(QString::fromUtf8("border-image: url(:/images/con_recong/LoadRegulationAutoOn.png);"));
        cbx_5 = new QComboBox(ControlSetting);
        cbx_5->setObjectName(QString::fromUtf8("cbx_5"));
        cbx_5->setGeometry(QRect(60, 60, 241, 41));
        auto_height = new QLabel(ControlSetting);
        auto_height->setObjectName(QString::fromUtf8("auto_height"));
        auto_height->setGeometry(QRect(10, 10, 40, 40));
        auto_height->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/CutHeightAutoOn.png);"));
        cbx_6 = new QComboBox(ControlSetting);
        cbx_6->setObjectName(QString::fromUtf8("cbx_6"));
        cbx_6->setGeometry(QRect(60, 10, 241, 41));
        l_rw_cl = new QLabel(ControlSetting);
        l_rw_cl->setObjectName(QString::fromUtf8("l_rw_cl"));
        l_rw_cl->setGeometry(QRect(10, 160, 40, 40));
        l_rw_cl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/setting/WeightClearOn.png);"));
        cbx_7 = new QComboBox(ControlSetting);
        cbx_7->setObjectName(QString::fromUtf8("cbx_7"));
        cbx_7->setGeometry(QRect(60, 160, 241, 41));
        cbx_9 = new QComboBox(ControlSetting);
        cbx_9->setObjectName(QString::fromUtf8("cbx_9"));
        cbx_9->setGeometry(QRect(370, 10, 91, 41));
        m_reset_2 = new QLabel(ControlSetting);
        m_reset_2->setObjectName(QString::fromUtf8("m_reset_2"));
        m_reset_2->setGeometry(QRect(320, 10, 40, 40));
        m_reset_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/warning/on.png);"));
        Cancel_btn = new QPushButton(ControlSetting);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));
        Cancel_btn->setGeometry(QRect(310, 250, 71, 51));
        Cancel_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 88, 88);"));
        OK_btn = new QPushButton(ControlSetting);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));
        OK_btn->setGeometry(QRect(400, 250, 71, 51));
        OK_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 111, 249);"));
        reelSpeed = new SoftKeyLineEdit(ControlSetting);
        reelSpeed->setObjectName(QString::fromUtf8("reelSpeed"));
        reelSpeed->setGeometry(QRect(370, 70, 91, 41));
        QFont font1;
        font1.setPointSize(20);
        reelSpeed->setFont(font1);
        cutterHz = new SoftKeyLineEdit(ControlSetting);
        cutterHz->setObjectName(QString::fromUtf8("cutterHz"));
        cutterHz->setGeometry(QRect(370, 130, 91, 41));
        cutterHz->setFont(font1);
        augerSpeed = new SoftKeyLineEdit(ControlSetting);
        augerSpeed->setObjectName(QString::fromUtf8("augerSpeed"));
        augerSpeed->setGeometry(QRect(370, 190, 91, 41));
        augerSpeed->setFont(font1);
        label_2 = new QLabel(ControlSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 70, 40, 40));
        label_2->setMinimumSize(QSize(40, 40));
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/engine/ReelSpeed.png)"));
        label_3 = new QLabel(ControlSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 130, 40, 40));
        label_3->setMinimumSize(QSize(40, 40));
        label_3->setMaximumSize(QSize(40, 40));
        label_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/engine/CutterHz.png)"));
        label_4 = new QLabel(ControlSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 190, 40, 40));
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(40, 40));
        label_4->setStyleSheet(QString::fromUtf8("border-image:url(:/images/engine/FeedAugerSpeed.png)"));
        label_5 = new QLabel(ControlSetting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 80, 66, 21));
        label_6 = new QLabel(ControlSetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 140, 66, 17));
        label_7 = new QLabel(ControlSetting);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 200, 66, 21));

        retranslateUi(ControlSetting);

        QMetaObject::connectSlotsByName(ControlSetting);
    } // setupUi

    void retranslateUi(QDialog *ControlSetting)
    {
        ControlSetting->setWindowTitle(QApplication::translate("ControlSetting", "\344\273\252\350\241\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        cbx_1->clear();
        cbx_1->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\212\250\346\200\201\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\351\235\231\346\200\201\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\224\266\345\233\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QString());
        l_chrs->setText(QString());
        cbx_3->clear();
        cbx_3->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\350\204\261\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\211\262\345\217\260\346\217\220\345\215\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\211\262\345\217\260\344\270\213\351\231\215", 0, QApplication::UnicodeUTF8)
        );
        m_reset->setText(QString());
        cbx_4->clear();
        cbx_4->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8)
        );
        auto_load_regu->setText(QString());
        cbx_5->clear();
        cbx_5->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\205\263\351\227\255\350\264\237\350\215\267\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\274\200\345\220\257\350\264\237\350\215\267\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
        );
        auto_height->setText(QString());
        cbx_6->clear();
        cbx_6->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\345\205\263\351\227\255\345\211\262\345\217\260\351\253\230\345\272\246\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\345\274\200\345\220\257\345\211\262\345\217\260\351\253\230\345\272\246\350\207\252\345\212\250\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8)
        );
        l_rw_cl->setText(QString());
        cbx_7->clear();
        cbx_7->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\270\205\351\233\266", 0, QApplication::UnicodeUTF8)
        );
        cbx_9->clear();
        cbx_9->insertItems(0, QStringList()
         << QApplication::translate("ControlSetting", "\346\227\240\345\212\250\344\275\234", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\351\235\231\351\237\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ControlSetting", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8)
        );
        m_reset_2->setText(QString());
        Cancel_btn->setText(QApplication::translate("ControlSetting", "Cancel", 0, QApplication::UnicodeUTF8));
        OK_btn->setText(QApplication::translate("ControlSetting", "OK", 0, QApplication::UnicodeUTF8));
        reelSpeed->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        cutterHz->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        augerSpeed->setText(QApplication::translate("ControlSetting", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ControlSetting", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QApplication::translate("ControlSetting", "rpm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ControlSetting", "Hz", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ControlSetting", "rpm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlSetting: public Ui_ControlSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLSETTING_H
