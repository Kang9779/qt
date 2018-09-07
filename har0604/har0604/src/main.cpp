#include "mywidget.h"
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


QSerialPort* serialTest;

void initSerialPort();


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec=QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    initSerialPort();

    myWidget w;
    w.setWindowFlags(w.windowFlags()& (~Qt::WindowCloseButtonHint));
   //how to hint closebutton on the windows

    w.showMaximized();

    return a.exec();
}


void initSerialPort()
{

    serialTest=new QSerialPort;

    serialTest->setPortName("/dev/ttyO2");

    serialTest->open(QIODevice::ReadWrite);

    serialTest->setBaudRate(QSerialPort::Baud9600);

    serialTest->setDataBits(QSerialPort::Data8);

    serialTest->setParity(QSerialPort::NoParity);

    serialTest->setStopBits(QSerialPort::OneStop);

    serialTest->setFlowControl(QSerialPort::NoFlowControl);
}



