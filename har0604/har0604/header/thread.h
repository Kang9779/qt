#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMetaType>
#include <QVariant>
#include <iostream>
#include <QTimer>
#include <QMessageBox>
#include "parametersetting.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>

extern int get_flag;
extern QSerialPort* serialTest;

extern "C"{
//#include "led_header.h"			//Led的头文件
}

extern int num_mon[32][8];          //所有id接收的数据综合


/* 接收数据的线程 */
class Thread: public QThread
{
	Q_OBJECT
public:
	Thread();
	
	void stop();
		
public slots:
	
signals:
	void warn_signal();
    void serialSendSignal(QByteArray msg);


protected:
	void run();
	
private:
	volatile bool stopped;
	QTimer *warn_timer;


private slots:
	void warnFun_slot();
    void serialSendPlot(QByteArray);


private:
    QByteArray getSerialSendData(struct can_frame* frame_temp);

	
};



class Thread2: public QThread
{
    Q_OBJECT

public:
    Thread2();

    void stop();

public slots:

signals:
    void warn_signal();
    void serialSendSignal(QByteArray);

protected:
    void run();

private:
    volatile bool stopped;
    QTimer *warn_timer;

private slots:
    void warnFun_slot();
    void serialSendPlot(QByteArray);

private:
    QByteArray getSerialSendData(struct can_frame* frame_temp);

};



/* 返回数据的线程 */
class ThreadBack: public QThread
{
	Q_OBJECT
public:
	ThreadBack();
	void stop();
			
public slots:
	
		
signals:
    void settingpara1(char *);
    void settingpara2(char *);
    void set_arr(QByteArray array);

protected:
	virtual void run();
	
private:
	QTimer *send_timer;
	volatile bool stopped;

private slots:
	void can_return();
	void canTest(QByteArray bArray);

};


///* 串口发送数据的线程 */
//class SerialThread: public QThread
//{
//    Q_OBJECT
//public:
//    SerialThread();

//public slots:

//signals:

//protected:
//    void run();

//private:
//    QSerialPort* serialTest;


//private slots:
//    void serialSendPlot(QByteArray msg);
//};




static QByteArray ba;	//静态变量


#endif //THREAD_H
