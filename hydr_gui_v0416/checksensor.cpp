#include "checksensor.h"
#include <QHBoxLayout>
#include <QCalendarWidget>

CheckSensor::CheckSensor(QWidget *parent) : QWidget(parent)
{
    checkBox=new QCheckBox;
    dateEdit=new QDateEdit;
    redButton=new QRadioButton;
    greenButton=new QRadioButton;
    yellowButton=new QRadioButton;

    sadLabel=new QLabel;
    smileLabel=new QLabel;
    suspiciousLabel=new QLabel;

    QHBoxLayout *layout=new QHBoxLayout(this);
    checkBox->setFixedWidth(90);
    checkBox->setFixedHeight(16);
    QFont font("楷体",12,QFont::Normal);
    checkBox->setFont(font);
    layout->addWidget(checkBox);
    layout->addStretch(1);

    QCalendarWidget *calendar=new QCalendarWidget(this);
    calendar->setGridVisible(true);
    dateEdit->setFixedHeight(16);
    dateEdit->setCalendarPopup(true);
    dateEdit->setCalendarWidget(calendar);
    dateEdit->setMinimumDate(QDate(2017, 1, 1));
    layout->addWidget(dateEdit);
    layout->addStretch(1);

    //redButton->setStyleSheet("QWidget{border-image:url(:/icons/rsc/sad.png)}");
    layout->addWidget(redButton);
    layout->addStretch(1);

    //    ui->labelImageSY215->show();
    QImage *sad=new QImage;
    sad->load(":/icons/rsc/sad.png");
    sadLabel->setFixedSize(16,16);
    sadLabel->setPixmap(QPixmap::fromImage(*sad));
    sadLabel->setScaledContents(true);
    layout->addWidget(sadLabel);
    layout->addStretch(1);

    //greenButton->setStyleSheet("QWidget{border-image:url(:/icons/rsc/smiling.png)}");
    layout->addWidget(greenButton);
    layout->addStretch(1);

    QImage *smile=new QImage;
    smile->load(":/icons/rsc/smiling.png");
    smileLabel->setFixedSize(16,16);
    smileLabel->setPixmap(QPixmap::fromImage(*smile));
    smileLabel->setScaledContents(true);
    layout->addWidget(smileLabel);
    layout->addStretch(1);

    //yellowButton->setStyleSheet("QWidget{border-image:url(:/icons/rsc/suspicious.png)}");
    layout->addWidget(yellowButton);
    layout->addStretch(1);

    QImage *suspicious=new QImage;
    suspicious->load(":/icons/rsc/suspicious.png");
    suspiciousLabel->setFixedSize(16,16);
    suspiciousLabel->setPixmap(QPixmap::fromImage(*suspicious));
    suspiciousLabel->setScaledContents(true);
    layout->addWidget(suspiciousLabel);

    layout->setContentsMargins(5,0,0,5);
}

void CheckSensor::setItemName(QString name)
{
    checkBox->setText(name);
}
