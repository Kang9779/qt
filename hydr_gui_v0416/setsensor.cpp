#include "setsensor.h"
#include <QHBoxLayout>

SetSensor::SetSensor(QWidget *parent) : QWidget(parent),num_("#0"),typeIndex_(1),name_("")
{
    SensorSwitch=new QCheckBox;
    SensorImage=new QLabel;
    SensorName=new QLabel;
    SensorSignal=new QComboBox;

    QHBoxLayout *SensorLayout=new QHBoxLayout(this);

    // Switch
    SensorSwitch->setFixedHeight(20);
    SensorSwitch->setFixedWidth(40);
    QFont font("楷体",12,QFont::Normal);
    SensorSwitch->setFont(font);
    SensorLayout->addWidget(SensorSwitch);
//    SensorLayout->addStretch(1);

    // Image
    image=new QImage;
//    switch(typeIndex_)
//    {
//    case 1:/*压力传感器*/
//        image->load(":/transducer/rsc/pressure.bmp");
//        break;
//    case 2:/*位移传感器*/
//        image->load(":/transducer/rsc/displacement.png");
//        break;
//    case 3:/*倾角传感器*/
//        image->load(":/transducer/rsc/displacement.png");
//        break;
//    case 4:/*流量传感器*/
//        image->load(":/transducer/rsc/pressure.bmp");
//        break;
//    }
    SensorImage->setFixedSize(72,20);
//    SensorImage->setPixmap(QPixmap::fromImage(*image));
//    SensorImage->setScaledContents(true);
    SensorLayout->addWidget(SensorImage);
    SensorLayout->addStretch(1);

    // Name
    SensorName->setFixedSize(140,20);
    SensorName->setFont(font);
    SensorLayout->addWidget(SensorName);
    SensorLayout->addStretch(1);

    // Signal
    SensorSignal->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
    SensorSignal->setFixedSize(100,20);
    SensorLayout->addWidget(SensorSignal);
    SensorLayout->setContentsMargins(5,0,0,5);
}

void SetSensor::setSensorNumber(QString num)
{
    num_=num;
    SensorSwitch->setText(num_);
}

void SetSensor::setSensorType(int typeIndex)
{
    typeIndex_=typeIndex;
    switch(typeIndex_)
    {
    case 1:/*压力传感器*/
        image->load(":/transducer/rsc/pressure.bmp");
        break;
    case 2:/*位移传感器*/
        image->load(":/transducer/rsc/displacement.png");
        break;
    case 3:/*倾角传感器*/
        image->load(":/transducer/rsc/displacement.png");
        break;
    case 4:/*流量传感器*/
        image->load(":/transducer/rsc/pressure.bmp");
        break;
    }
    SensorImage->setPixmap(QPixmap::fromImage(*image));
    SensorImage->setScaledContents(true);
}

void SetSensor::setSignalName(QString name)
{
    name_=name;
    SensorName->setText(name_);
}
