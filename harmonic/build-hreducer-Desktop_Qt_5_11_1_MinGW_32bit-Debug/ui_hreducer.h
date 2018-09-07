/********************************************************************************
** Form generated from reading UI file 'hreducer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HREDUCER_H
#define UI_HREDUCER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HReducer
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HReducer)
    {
        if (HReducer->objectName().isEmpty())
            HReducer->setObjectName(QStringLiteral("HReducer"));
        HReducer->resize(491, 300);
        centralWidget = new QWidget(HReducer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 70, 75, 31));
        HReducer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HReducer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 491, 23));
        HReducer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HReducer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HReducer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HReducer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HReducer->setStatusBar(statusBar);

        retranslateUi(HReducer);
        QObject::connect(pushButton, SIGNAL(clicked()), HReducer, SLOT(enSure()));

        QMetaObject::connectSlotsByName(HReducer);
    } // setupUi

    void retranslateUi(QMainWindow *HReducer)
    {
        HReducer->setWindowTitle(QApplication::translate("HReducer", "HReducer", nullptr));
        pushButton->setText(QApplication::translate("HReducer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HReducer: public Ui_HReducer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HREDUCER_H
