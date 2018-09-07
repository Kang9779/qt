#include "boomcircuitdialog.h"
#include "ui_boomcircuitdialog.h"

#include "string.h"
#include <iostream>
#include <fstream>

#include <vector>

#include <QDebug>

#include "mainwindow.h"
#include <QPen>
#include <QString>
#include <QFileDialog>
#include "clientthread.h"
#include "savefile.h"
#include <QPen>
#include<diagnosis.h>
#include "checksensor.h"

using namespace std;

BoomCircuitDialog::BoomCircuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoomCircuitDialog)
{
    // 主线程ID号，用于调试
    //qDebug()<<"Boom circuit main window thread is : "<<QThread::currentThreadId();
    // UI设置
    ui->setupUi(this);
    // 关闭子窗口，返回主窗口
    connect(this,SIGNAL(rejected()),(MainWindow*)parentWidget(),SLOT(show()));
    // 加载油液回路动图
    movie = new QMovie(":/circuit/rsc/动臂上升无框.gif");
    movie->setBackgroundColor(QColor(100,100,100,100));
    ui->labelImageBoom->setMovie(movie);
    ui->labelImageBoom->setScaledContents(true);
    // 循环播放动图
    QTimer *movieTimer=new QTimer(this);
    movie->start();
    connect(movieTimer,SIGNAL(timeout()),this,SLOT(loopMovie()));
    movieTimer->start(1000);
    // 数据采集启动与停止
    ui->runStopBoom->setId(ui->btnRunBoom,1);
    ui->runStopBoom->setId(ui->btnStopBoom,0);
    connect(ui->runStopBoom,SIGNAL(buttonPressed(int)),this,SLOT(onRunStopChanged(int)));
    // Set timer用于控制曲线刷新
    dateTimer=new QTimer(this);
    dateTimer->start(0);// 周期为0时界面启动即运行
    connect(dateTimer,SIGNAL(timeout()),this,SLOT(updataPlot()));
    // Set update period combox，更新周期选择
    ui->updatePeriodBoom->addItems(QStringList() << "0"<<"20" << "50" << "100" << "200");
    connect(ui->updatePeriodBoom,SIGNAL(currentIndexChanged(QString)),this,SLOT(onUpdatePeriod(QString)));
    // 创建TCP子线程
    clientThread=new ClientThread();
//    connect(clientThread,SIGNAL(dataAcquired(char buf3[])),
//            this,SLOT(getRealtimeData(char buf2[])),Qt::QueuedConnection);
    // 子线程和主线程数据传输
    connect(clientThread,SIGNAL(dataAcquired(QString)),this,SLOT(getRealtimeData(QString)));
    clientThread->start(QThread::HighestPriority);//clientThread->start();
    // 创建文件读、写线程
    fileThread=new QThread();
    // 文件选择日历控件
    calendar=new QCalendarWidget(this);
    calendar->setGridVisible(true);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setCalendarWidget(calendar);
    ui->dateEdit->setMinimumDate(QDate(2017, 1, 1));
//    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(on_btnHistoryBoom_clicked(QDate)));
    // 列表
    connect(ui->listWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(showHistory(QModelIndex)));
    // 堆栈窗体，3个子页面切换控制
    QButtonGroup *groupPage=new QButtonGroup(this);
    groupPage->addButton(ui->pageDown_1);
    groupPage->addButton(ui->pageUp_2);
    groupPage->addButton(ui->pageDown_2);
    groupPage->addButton(ui->pageUp_3);
    groupPage->setId(ui->pageDown_1,1);
    groupPage->setId(ui->pageUp_2,2);
    groupPage->setId(ui->pageDown_2,3);
    groupPage->setId(ui->pageUp_3,4);
    connect(groupPage,SIGNAL(buttonClicked(int)),this,SLOT(switchPage(int)));
    // 子页面1：预检栏
    CheckSensor *check1=new CheckSensor(this);
    check1->setItemName("油液  ");
    check1->resize(431,30);
    CheckSensor *check2=new CheckSensor(this);
    check2->setItemName("先导阀1");
    check2->resize(431,30);
    CheckSensor *check3=new CheckSensor(this);
    check3->setItemName("先导阀2");
    check3->resize(431,30);
    CheckSensor *check4=new CheckSensor(this);
    check4->setItemName("节流阀 ");
    check4->resize(431,30);
    CheckSensor *check5=new CheckSensor(this);
    check5->setItemName("单向阀 ");
    check5->resize(431,30);
    QListWidgetItem *checkItem1=new  QListWidgetItem(ui->checkList);
    QListWidgetItem *checkItem2=new  QListWidgetItem(ui->checkList);
    QListWidgetItem *checkItem3=new  QListWidgetItem(ui->checkList);
    QListWidgetItem *checkItem4=new  QListWidgetItem(ui->checkList);
    QListWidgetItem *checkItem5=new  QListWidgetItem(ui->checkList);

    ui->checkList->setItemWidget(checkItem1,check1);
    ui->checkList->addItem(checkItem1);

    ui->checkList->setItemWidget(checkItem2,check2);
    ui->checkList->addItem(checkItem2);

    ui->checkList->setItemWidget(checkItem3,check3);
    ui->checkList->addItem(checkItem3);

    ui->checkList->setItemWidget(checkItem4,check4);
    ui->checkList->addItem(checkItem4);

    ui->checkList->setItemWidget(checkItem5,check5);
    ui->checkList->addItem(checkItem5);
    //子页面2：传感器布置栏
//    ui->comboBox_1->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
//    ui->comboBox_2->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
//    ui->comboBox_3->addItems(QStringList() << "0~10V (电压)"<<"4~20mA (电流)" << "AB (脉冲)");
//    ui->comboBox_4->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
//    ui->comboBox_5->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
//    ui->comboBox_6->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
//    //绘图区域纵坐标设置
//    connect(ui->comboBox_1,SIGNAL(currentIndexChanged(int)),this,SLOT(setPlotRange1(int)));
//    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(setPlotRange2(int)));
//    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(setPlotRange3(int)));
    sensor1=new SetSensor(this);
    sensor1->setSensorNumber("#1");
    sensor1->setSignalName("动臂有杆腔压力");
    sensor1->setSensorType(1);
    sensor1->resize(431,30);
    sensor2=new SetSensor(this);
    sensor2->setSensorNumber("#2");
    sensor2->setSignalName("动臂无杆腔压力");
    sensor2->setSensorType(1);
    sensor2->resize(431,30);
    sensor3=new SetSensor(this);
    sensor3->setSensorNumber("#3");
    sensor3->setSignalName("动臂位移");
    sensor3->setSensorType(2);
    sensor3->resize(431,30);
    sensor4=new SetSensor(this);
    sensor4->setSensorNumber("#4");
    sensor4->setSignalName("动臂X轴倾角");
    sensor4->setSensorType(3);
    sensor4->resize(431,30);
    sensor5=new SetSensor(this);
    sensor5->setSensorNumber("#5");
    sensor5->setSignalName("动臂Y轴倾角");
    sensor5->setSensorType(3);
    sensor5->resize(431,30);

    sensor6=new SetSensor(this);
    sensor6->setSensorNumber("#6");
    sensor6->setSignalName("斗杆有杆腔压力");
    sensor6->setSensorType(1);
    sensor6->resize(431,30);
    sensor7=new SetSensor(this);
    sensor7->setSensorNumber("#7");
    sensor7->setSignalName("斗杆无杆腔压力");
    sensor7->setSensorType(1);
    sensor7->resize(431,30);
    sensor8=new SetSensor(this);
    sensor8->setSensorNumber("#8");
    sensor8->setSignalName("斗杆位移");
    sensor8->setSensorType(2);
    sensor8->resize(431,30);
    sensor9=new SetSensor(this);
    sensor9->setSensorNumber("#9");
    sensor9->setSignalName("斗杆X轴倾角");
    sensor9->setSensorType(3);
    sensor9->resize(431,30);
    sensor10=new SetSensor(this);
    sensor10->setSensorNumber("#10");
    sensor10->setSignalName("斗杆Y轴倾角");
    sensor10->setSensorType(3);
    sensor10->resize(431,30);

    //杨泰春测试用
    sensor11=new SetSensor(this);
    sensor11->setSensorNumber("#11");
    sensor11->setSignalName("铲斗有杆腔压力");
    sensor11->setSensorType(1);
    sensor11->resize(431,30);

    sensor12=new SetSensor(this);
    sensor12->setSensorNumber("#12");
    sensor12->setSignalName("铲斗无杆腔压力");
    sensor12->setSensorType(1);
    sensor12->resize(431,30);

    sensor13=new SetSensor(this);
    sensor13->setSensorNumber("#13");
    sensor13->setSignalName("铲斗位移");
    sensor13->setSensorType(2);
    sensor13->resize(431,30);

    sensor14=new SetSensor(this);
    sensor14->setSensorNumber("#14");
    sensor14->setSignalName("铲斗X轴倾角");
    sensor14->setSensorType(3);
    sensor14->resize(431,30);

    sensor15=new SetSensor(this);
    sensor15->setSensorNumber("#15");
    sensor15->setSignalName("铲斗Y轴倾角");
    sensor15->setSensorType(3);
    sensor15->resize(431,30);

    QListWidgetItem *sensorItem1=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem2=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem3=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem4=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem5=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem6=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem7=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem8=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem9=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem10=new  QListWidgetItem(ui->sensorList);

    //杨泰春测试用
    QListWidgetItem *sensorItem11=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem12=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem13=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem14=new  QListWidgetItem(ui->sensorList);
    QListWidgetItem *sensorItem15=new  QListWidgetItem(ui->sensorList);

    ui->sensorList->setItemWidget(sensorItem1,sensor1);
    ui->sensorList->addItem(sensorItem1);
    ui->sensorList->setItemWidget(sensorItem2,sensor2);
    ui->sensorList->addItem(sensorItem2);
    ui->sensorList->setItemWidget(sensorItem3,sensor3);
    ui->sensorList->addItem(sensorItem3);
    ui->sensorList->setItemWidget(sensorItem4,sensor4);
    ui->sensorList->addItem(sensorItem4);
    ui->sensorList->setItemWidget(sensorItem5,sensor5);
    ui->sensorList->addItem(sensorItem5);
    ui->sensorList->setItemWidget(sensorItem6,sensor6);
    ui->sensorList->addItem(sensorItem6);
    ui->sensorList->setItemWidget(sensorItem7,sensor7);
    ui->sensorList->addItem(sensorItem7);
    ui->sensorList->setItemWidget(sensorItem8,sensor8);
    ui->sensorList->addItem(sensorItem8);
    ui->sensorList->setItemWidget(sensorItem9,sensor9);
    ui->sensorList->addItem(sensorItem9);
    ui->sensorList->setItemWidget(sensorItem10,sensor10);
    ui->sensorList->addItem(sensorItem10);
//杨泰春测试用
    ui->sensorList->setItemWidget(sensorItem11,sensor11);
    ui->sensorList->addItem(sensorItem11);
    ui->sensorList->setItemWidget(sensorItem12,sensor12);
    ui->sensorList->addItem(sensorItem12);
    ui->sensorList->setItemWidget(sensorItem13,sensor13);
    ui->sensorList->addItem(sensorItem13);
    ui->sensorList->setItemWidget(sensorItem14,sensor14);
    ui->sensorList->addItem(sensorItem14);
    ui->sensorList->setItemWidget(sensorItem15,sensor15);
    ui->sensorList->addItem(sensorItem15);

    //这一段注释是熊志林师兄做的，我来不及改了
    connect(sensor1->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor1(bool)));// 无杆腔压力传感器
    connect(sensor2->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor2(bool)));// 有杆腔压力传感器
    connect(sensor3->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor3(bool)));// 液压缸位移传感器
    connect(sensor4->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor4(bool)));// 动臂X轴倾角传感器
    connect(sensor5->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor5(bool)));// 动臂Y轴倾角传感器
    connect(sensor6->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor6(bool)));// 流量传感器
    connect(sensor7->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor7(bool)));// 斗杆X轴倾角传感器
    connect(sensor8->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor8(bool)));// 斗杆Y轴倾角传感器
    connect(sensor9->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor9(bool)));// 铲斗X轴倾角传感器
    connect(sensor10->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor10(bool)));// 铲斗Y轴倾角传感器
   //杨泰春测试用
    connect(sensor11->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor11(bool)));
    connect(sensor12->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor12(bool)));
    connect(sensor13->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor13(bool)));
    connect(sensor14->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor14(bool)));
    connect(sensor15->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor15(bool)));

    // 子页面3：数据采集栏
    ui->textBrowser->setStyleSheet("border: none;");
    QFont font("楷体",12,QFont::Normal);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText("\n 测试流程：\n\n铲斗满载，开启动臂液压缸多路换向阀，运动到最大行程处。");
    // 绘图区横轴滚轮条取消
    ui->figureListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

BoomCircuitDialog::~BoomCircuitDialog()
{
    delete ui;
}

void BoomCircuitDialog::addGraph(QCustomPlot *figure,QString title)
{
    figure->addGraph();
//    // 设置标题
//    figure->plotLayout()->insertRow(0);
//    figure->plotLayout()->addElement(0, 0, new QCPTextElement(figure, title, QFont("sans", 10, QFont::Bold)));
    // 标题空白区域太大，采用legend方式
    QPen borderPen;
    borderPen.setColor(QColor(0,0,0,0));
    QBrush brush;
    brush.setColor(QColor(0,0,0,0));
    figure->legend->setVisible(true);
    figure->legend->setBorderPen(borderPen);
    figure->legend->setBrush(brush);
    figure->graph(0)->setName(title);
    // 减小空白区域面积
    figure->plotLayout()->setOuterRect(QRect(0,0,0,0));
    figure->plotLayout()->setMargins(QMargins(0,0,0,0));
    //figure->plotLayout()->setRowStretchFactor(1, 0.001);
}

void BoomCircuitDialog::setPlot(QCustomPlot *figure)
{
    // 图形交互操作：缩放、平移等
    figure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);
    //设置网格
    figure->xAxis->setBasePen(QPen(Qt::red,1));
    figure->yAxis->setBasePen(QPen(Qt::red,1));
    figure->xAxis->setTickPen(QPen(Qt::red,1));
    figure->yAxis->setTickPen(QPen(Qt::red,1));
    figure->xAxis->setTickLabelColor(Qt::black);
    figure->yAxis->setTickLabelColor(Qt::black);
    figure->xAxis->grid()->setPen(QPen(Qt::red, 1, Qt::DotLine));
    figure->yAxis->grid()->setPen(QPen(Qt::red, 1, Qt::DotLine));
    figure->xAxis->grid()->setSubGridPen(QPen(QColor(255,0,0,128),1,Qt::DotLine));
    figure->yAxis->grid()->setSubGridPen(QPen(QColor(255,0,0,128),1,Qt::DotLine));
    figure->xAxis->grid()->setSubGridVisible(true);
    figure->yAxis->grid()->setSubGridVisible(true);
    figure->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    figure->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    // Set legend
//    figureBoom->legend->setVisible(true);
//    QFont legendFont = font();  // start out with MainWindow's font..
//    legendFont.setPointSize(9); // and make a bit smaller for legend
//    figureBoom->legend->setFont(legendFont);
//    figureBoom->legend->setBrush(QBrush(QColor(255,255,255,230)));
//    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
//    figure->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    // Set graph 0
    // 设置曲线画笔
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    figure->graph(0)->setPen(pen);
    //figureBoom->graph(0)->setLineStyle(QCPGraph::lsLine);
    //figure->graph(0)->setName("压力 P1");
    // Set ranges
    figure->yAxis->setRange(0,10);
//    figureBoom->graph(0)->rescaleValueAxis();
    // Set label
    figure->xAxis->setLabel("时间 (s)");
    //figure->yAxis->setLabel("压力 (MPa)");
    // 清除当前绘图
    figure->graph(0)->data()->clear();
    // 时间轴
    figure->setLocale(QLocale(QLocale::Chinese, QLocale::China));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    figure->xAxis->setTicker(timeTicker);
    figure->replot();
}

void BoomCircuitDialog::setRealtimePlot(QCustomPlot *figureBoom)
{
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    figureBoom->xAxis->setTicker(timeTicker);
    figureBoom->axisRect()->setupFullAxesBox();
}

// 布局子图设置
void BoomCircuitDialog::setCustomGraph(QCPGraph *graph)
{
    // 设置画笔
    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    graph->setPen(pen);
    // 设置名字
    //graph->setName("压力 P1");// 在函数外设置
    //方式2
    // 设置时间轴
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    graph->keyAxis()->setTicker(timeTicker);
    // 设置范围
    graph->valueAxis()->setRange(0,10);
    // Set label
    graph->keyAxis()->setLabel("时间 (s)");
    graph->valueAxis()->setLabel("压力 P1(MPa)");
}

void BoomCircuitDialog::getRealtimeData(QString qstr)
{
//    qDebug()<<"Get";

    // QString类型转string类型
    string str=qstr.toStdString();

//    qDebug()<<str.c_str()<<endl;
    // 用于QCustomPlot绘图数据类型
    QVector<double> timeStramp;//时间

    //以下一段的注释是熊志林师兄做的，我来不及改了
    QVector<double> value1;//压力1
    QVector<double> value2;//压力2
    QVector<double> value3;//激光传感器位移
    QVector<double> value4;//动臂X轴倾角
    QVector<double> value5;//动臂Y轴倾角
    QVector<double> value6;//斗杆X轴倾角
    QVector<double> value7;//斗杆Y轴倾角
    QVector<double> value8;//铲斗X轴倾角
    QVector<double> value9;//铲斗Y轴倾角
    QVector<double> value10;//流量值
    //杨泰春测试
    QVector<double> value11;//测试用
    QVector<double> value12;
    QVector<double> value13;
    QVector<double> value14;
    QVector<double> value15;
    // 用于转换的中间变量
    QString tmpStr;
    QTime tmp;
    QDateTime dt;

    int startpoint=0;
    int endpoint=0;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    int num5=0;
    int num6=0;
    int num7=0;
    int num8=0;
    int num9=0;
    int num10=0;
    int num11=0;
    //杨泰春测试
    int num12=0;
    int num13=0;
    int num14=0;
    int num15=0;
    int num16=0;
    int strlgth;
    for(auto c:str)
    {

        if(c=='@'){
            strlgth = endpoint-startpoint;

            int chnlNumber=atoi(str.substr(startpoint,2).c_str())-10;
//            qDebug()<<str.substr(startpoint,2).c_str()<<endl;

            string subs=str.substr(startpoint+3,strlgth-3);
            startpoint=endpoint+1;
//             qDebug()<<chnlNumber<<endl;
            switch (chnlNumber) {
            case 1:
                tmpStr=QString::fromStdString(subs);

                tmp=QTime::fromString(tmpStr,"h:m:s.z");
                dt.setTimeSpec(Qt::LocalTime);
                dt.setTime(tmp);
                timeStramp.push_back(QCPAxisTickerDateTime::dateTimeToKey(dt));
                num1+=1;
//                qDebug()<<tmp;
                break;
             case 2:
                value1.push_back(atof(subs.c_str()));
//                qDebug()<<subs.c_str()<<endl;
                num2+=1;
                 break;
            case 3:
               value2.push_back(atof(subs.c_str()));
               num3+=1;
                break;
            case 4:
               value3.push_back(atof(subs.c_str()));
               num4+=1;
                break;
            case 5:
               value4.push_back(atof(subs.c_str()));
               num5+=1;
                break;
            case 6:
               value5.push_back(atof(subs.c_str()));
               num6+=1;
                break;
            case 7:
               value6.push_back(atof(subs.c_str()));
               num7+=1;
                break;
            case 8:
               value7.push_back(atof(subs.c_str()));
               num8+=1;
                break;
            case 9:
               value8.push_back(atof(subs.c_str()));
               num9+=1;
                break;
            case 10:
               value9.push_back(atof(subs.c_str()));
               num10+=1;
//               qDebug()<<subs.c_str()<<endl;
                break;
            case 11:
               value10.push_back(atof(subs.c_str()));
               num11+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;
               //杨泰春测试
            case 12:
               value11.push_back(atof(subs.c_str()));
               num12+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;

            case 13:
               value12.push_back(atof(subs.c_str()));
               num13+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;
            case 14:
               value13.push_back(atof(subs.c_str()));
               num14+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;
            case 15:
               value14.push_back(atof(subs.c_str()));
               num15+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;
            case 16:
               value15.push_back(atof(subs.c_str()));
               num16+=1;
//               qDebug()<<subs.c_str()<<endl;/
                break;
            default:
                break;
            }

            }
            endpoint+=1;
    }
//        if(c=='#')
//        {
//            startpoint = endpoint+1;
//        }
//        if(c=='%')
//        {
//            strlgth = endpoint-startpoint+1;
//            string subs=str.substr(startpoint,strlgth-1);
//            startpoint = endpoint+1;
////            qDebug()<<subs.c_str();
//            // string类型转QString类型
//            tmpStr=QString::fromStdString(subs);
//            // QString类型转QTime类型
//            tmp=QTime::fromString(tmpStr,"h:m:s.z");
////            qDebug()<<tmp;
//            // 用QTime和QDate设置QDataTime
//            dt.setTimeSpec(Qt::LocalTime);
//            dt.setTime(tmp);
//            // QDateTime类型转double类型，并存如timeStramp向量中
//            //方法一：dateTimeToKey
//            timeStramp.push_back(QCPAxisTickerDateTime::dateTimeToKey(dt));
//            //方法二：toMSecsSinceEpoch()
//            //timeStramp.push_back(dt.toMSecsSinceEpoch()/1000.0);
//            qDebug()<<timeStramp[num1];
//            num1+=1;
//        }
//        if(c==',')
//        {
//            strlgth = endpoint-startpoint+1;
//            string subs=str.substr(startpoint,strlgth);
//            startpoint = endpoint+1;
//            // string类型转char类型，并存入value1向量
//            value1.push_back(atof(subs.c_str()));
////            qDebug()<<value1[num2];
//            num2+=1;
//        }
//        if(c=='!')
//        {
//            strlgth = endpoint-startpoint+1;
//            string subs=str.substr(startpoint,strlgth);
//            startpoint = endpoint+1;
//            // string类型转char类型，并存入value1向量
//            value2.push_back(atof(subs.c_str()));
////            qDebug()<<value1[num2];
//            num3+=1;
//        }
//        if(c=='@')
//        {
//            strlgth = endpoint-startpoint+1;
//            string subs=str.substr(startpoint,strlgth);
//            startpoint = endpoint+1;
//            // string类型转char类型，并存入value1向量
//            value3.push_back(atof(subs.c_str()));
////            qDebug()<<"value3:"<<value3[num4];
//            num4+=1;
//        }
//        if(c==';')
//        {
//            strlgth = endpoint-startpoint+1;
//            string subs=str.substr(startpoint,strlgth);
//            startpoint = endpoint+1;
//            // string类型转char类型，并存入value2向量
//            value4.push_back(atof(subs.c_str()));

//            num5+=1;
//        }
//        endpoint+=1;
//    }
    int min_size;
    int size1=timeStramp.size();
    int size2=value1.size();
    int size3=value2.size();
    int size4=value3.size();
    int size5=value4.size();
    int size6=value5.size();
    int size7=value6.size();
    int size8=value7.size();
    int size9=value8.size();
    int size10=value9.size();
    int size11=value10.size();

    //杨泰春测试用

    int size12=value11.size();
    int size13=value11.size();
    int size14=value11.size();
    int size15=value11.size();
    int size16=value11.size();

    if(size1>size2)
        min_size=size2;
    else
        min_size=size1;
    if(size3<min_size)
        min_size=size3;
    if(size4<min_size)
        min_size=size4;
    if(size5<min_size)
        min_size=size5;
    if(size6<min_size)
        min_size=size6;
    if(size7<min_size)
        min_size=size7;
    if(size8<min_size)
        min_size=size8;
    if(size9<min_size)
        min_size=size9;
    if(size10<min_size)
        min_size=size10;
    if(size11<min_size)
        min_size=size11;

    //杨泰春测试用
    if(size12<min_size)
        min_size=size12;
    if(size13<min_size)
        min_size=size13;
    if(size14<min_size)
        min_size=size14;
    if(size15<min_size)
        min_size=size15;
    if(size16<min_size)
        min_size=size16;

    while(size1>min_size)
    {
        timeStramp.pop_back();
        size1=timeStramp.size();
    }
    while(size2>min_size)
    {
        value1.pop_back();
        size2=value1.size();
    }
    while(size3>min_size)
    {
        value2.pop_back();
        size3=value2.size();
    }
    while(size4>min_size)
    {
        value3.pop_back();
        size4=value3.size();
    }
    while(size5>min_size)
    {
        value4.pop_back();
        size5=value4.size();
    }
    while(size6>min_size)
    {
        value5.pop_back();
        size6=value5.size();
    }
    while(size7>min_size)
    {
        value6.pop_back();
        size7=value6.size();
    }
    while(size8>min_size)
    {
        value7.pop_back();
        size8=value7.size();
    }
    while(size9>min_size)
    {
        value8.pop_back();
        size9=value8.size();
    }
    while(size10>min_size)
    {
        value9.pop_back();
        size10=value9.size();
    }
    while(size11>min_size)
    {
        value10.pop_back();
        size11=value10.size();
    }

    //杨泰春测试用
    while(size12>min_size)
    {
        value11.pop_back();
        size12=value11.size();
    }

    while(size13>min_size)
    {
        value12.pop_back();
        size13=value11.size();
    }
    while(size14>min_size)
    {
        value13.pop_back();
        size14=value11.size();
    }
    while(size15>min_size)
    {
        value14.pop_back();
        size15=value11.size();
    }
    while(size16>min_size)
    {
        value15.pop_back();
        size16=value11.size();
    }
    // 加入绘图区数据,每次显示5s钟的数据
    if(sensor1->SensorSwitch->isChecked())
    {
        // 液压缸有杆腔压力显示
        figure1->graph(0)->addData(timeStramp,value1);
        figure1->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor2->SensorSwitch->isChecked())
    {
        // 液压缸无杆腔压力显示
        figure2->graph(0)->addData(timeStramp,value2);
        figure2->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor3->SensorSwitch->isChecked())
    {
        // 液压缸位移显示
        figure3->graph(0)->addData(timeStramp,value3);
        figure3->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor4->SensorSwitch->isChecked())
    {
        // 倾角传感器X轴x显示
        figure4->graph(0)->addData(timeStramp,value4);
        figure4->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor5->SensorSwitch->isChecked())
    {
        // 倾角传感器Y轴显示
        figure5->graph(0)->addData(timeStramp,value5);
        figure5->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor6->SensorSwitch->isChecked())
    {
        // 流量传感器显示
        figure6->graph(0)->addData(timeStramp,value6);
        figure6->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor7->SensorSwitch->isChecked())
    {
        // 斗杆倾角X
        figure7->graph(0)->addData(timeStramp,value7);
        figure7->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor8->SensorSwitch->isChecked())
    {
        // 斗杆倾角Y
        figure8->graph(0)->addData(timeStramp,value8);
        figure8->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor9->SensorSwitch->isChecked())
    {
        // 铲斗倾角X
        figure9->graph(0)->addData(timeStramp,value9);
        figure9->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }
    if(sensor10->SensorSwitch->isChecked())
    {
        // 铲斗倾角Y
        figure10->graph(0)->addData(timeStramp,value10);
        figure10->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }


    //杨泰春测试用
    if(sensor11->SensorSwitch->isChecked())
    {

        figure11->graph(0)->addData(timeStramp,value11);
        figure11->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }

    if(sensor12->SensorSwitch->isChecked())
    {
        // 铲斗倾角Y
        figure12->graph(0)->addData(timeStramp,value12);
        figure12->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }

    if(sensor13->SensorSwitch->isChecked())
    {
        // 铲斗倾角Y
        figure13->graph(0)->addData(timeStramp,value13);
        figure13->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }

    if(sensor14->SensorSwitch->isChecked())
    {
        // 铲斗倾角Y
        figure14->graph(0)->addData(timeStramp,value14);
        figure14->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }

    if(sensor15->SensorSwitch->isChecked())
    {
        // 铲斗倾角Y
        figure15->graph(0)->addData(timeStramp,value15);
        figure15->graph(0)->data()->removeBefore(timeStramp[0]-5);
    }

}

// 实时动态曲线更新
void BoomCircuitDialog::updataPlot()
{
    // 坐标自适应
    if(sensor1->SensorSwitch->isChecked())
    {
        figure1->graph(0)->rescaleKeyAxis();
        figure1->replot();
    }
    if(sensor2->SensorSwitch->isChecked())
    {
        figure2->graph(0)->rescaleKeyAxis();
        figure2->replot();
    }
    if(sensor3->SensorSwitch->isChecked())
    {
        figure3->graph(0)->rescaleKeyAxis();
        figure3->replot();
    }
    if(sensor4->SensorSwitch->isChecked())
    {
        figure4->graph(0)->rescaleKeyAxis();
        figure4->replot();
    }
    if(sensor5->SensorSwitch->isChecked())
    {
        figure5->graph(0)->rescaleKeyAxis();
        figure5->replot();
    }
    if(sensor6->SensorSwitch->isChecked())
    {
        figure6->graph(0)->rescaleKeyAxis();
        figure6->replot();
    }
    if(sensor7->SensorSwitch->isChecked())
    {
        figure7->graph(0)->rescaleKeyAxis();
        figure7->replot();
    }
    if(sensor8->SensorSwitch->isChecked())
    {
        figure8->graph(0)->rescaleKeyAxis();
        figure8->replot();
    }
    if(sensor9->SensorSwitch->isChecked())
    {
        figure9->graph(0)->rescaleKeyAxis();
        figure9->replot();
    }
    if(sensor10->SensorSwitch->isChecked())
    {
        figure10->graph(0)->rescaleKeyAxis();
        figure10->replot();
    }



    //杨泰春测试用

    if(sensor11->SensorSwitch->isChecked())
    {
        figure11->graph(0)->rescaleKeyAxis();
        figure11->replot();
    }
    if(sensor12->SensorSwitch->isChecked())
    {
        figure12->graph(0)->rescaleKeyAxis();
        figure12->replot();
    }
    if(sensor13->SensorSwitch->isChecked())
    {
        figure13->graph(0)->rescaleKeyAxis();
        figure13->replot();
    }
    if(sensor14->SensorSwitch->isChecked())
    {
        figure14->graph(0)->rescaleKeyAxis();
        figure14->replot();
    }
    if(sensor15->SensorSwitch->isChecked())
    {
        figure15->graph(0)->rescaleKeyAxis();
        figure15->replot();
    }
}

void BoomCircuitDialog::onRunStopChanged(int run)
{
    // 停止保存文件线程
    fileThread->quit();
    // 关闭定时器，禁止刷新曲线
    if(run)
        dateTimer->start();
    else
        dateTimer->stop();
}

void BoomCircuitDialog::onUpdatePeriod(QString text)
{
    //调整定时器时间，改变图形刷新速率
    dateTimer->start(text.toInt());
}

void BoomCircuitDialog::on_btnRunBoom_clicked()
{
    // 创建并运行保存文件子线程
    QDateTime dt;
    QTime currTime;
    QDate currDate;
    dt.setTime(currTime.currentTime());
    dt.setDate(currDate.currentDate());
    QString fileName=dt.toString("yyyy-MM-dd-hh-mm");
    SaveFile *saveFile=new SaveFile("C:\\Users\\ytc\\Desktop\\Software\\history\\"+fileName+"boom.txt");
    // 添加到ListWidget
    int row=ui->listWidget->count();
    QListWidgetItem *newFile = new QListWidgetItem;
    newFile->setText(fileName);
    ui->listWidget->insertItem(row+1, newFile);


    // 写采集到的数据到文件
    saveFile->moveToThread(fileThread);
    connect(clientThread,SIGNAL(dataAcquired(QString,QSqlDatabase)),saveFile,SLOT(saveRealtimeData(QString,QSqlDatabase)),Qt::QueuedConnection);
    fileThread->start();
    // 文件子线程ID，用于调试
    //qDebug()<<"fileThread id is "<<fileThread->currentThreadId();
}

void BoomCircuitDialog::on_btnHistoryBoom_clicked(/*QDate date*/)
{
    // 重置绘图

    // 创建打开文件对话框，在windows系统下会出现log4cplus error,但不影响文件打开
    QString qfileName=QFileDialog::getOpenFileName(this,tr("Open"),"./",tr("*.txt;;*.dat;;*.bin;;*.csv"));
    faultDetector.getSensorData(qfileName.toStdString());//问题重新打开另一文件，即使清除了之前的图形，仍会出现问题
    vector<double> t=faultDetector.getTime();
    vector<double> P1=faultDetector.getPressure1();
    vector<double> P2=faultDetector.getPressure2();
    vector<double> Ax=faultDetector.getAx();
    vector<double> Ay=faultDetector.getAy();
    vector<double> Ax1=faultDetector.getAx1();
    vector<double> Ay1=faultDetector.getAy1();
    vector<double> Ax2=faultDetector.getAx2();
    vector<double> Ay2=faultDetector.getAy2();
    vector<double> Xp=faultDetector.getDisp();
    vector<double> Qleak=faultDetector.getFlow();
//    qDebug()<<t[1]<<P1[1]<<P2[1]<<endl;
    time_stramp=QVector<double>::fromStdVector(t);
    CylinderPressureA=QVector<double>::fromStdVector(P1);
    CylinderPressureB=QVector<double>::fromStdVector(P2);
    CylinderAx=QVector<double>::fromStdVector(Ax);
    CylinderAy=QVector<double>::fromStdVector(Ay);
    CylinderAx1=QVector<double>::fromStdVector(Ax1);
    CylinderAy1=QVector<double>::fromStdVector(Ay1);
    CylinderAx2=QVector<double>::fromStdVector(Ax2);
    CylinderAy2=QVector<double>::fromStdVector(Ay2);
    CylinderDisp=QVector<double>::fromStdVector(Xp);
    LeakFlow=QVector<double>::fromStdVector(Qleak);
//    qDebug()<<time_stramp[1]<<CylinderAx[1]<<CylinderAy[1]<<endl;
    // 添加数据，重新绘图
    if(sensor1->SensorSwitch->isChecked())
    {
        figure1->graph(0)->setData(time_stramp,CylinderPressureA);
        figure1->replot();
    }
    if(sensor2->SensorSwitch->isChecked())
    {
        figure2->graph(0)->setData(time_stramp,CylinderPressureB);
        figure2->replot();
    }
    if(sensor3->SensorSwitch->isChecked())
    {
        figure3->graph(0)->setData(time_stramp,CylinderDisp);
        figure3->replot();
    }
    if(sensor4->SensorSwitch->isChecked())
    {
        figure4->graph(0)->setData(time_stramp,CylinderAx);
//        int i=0;
//        for(i=0;i<CylinderAx.size();i++)
//        {
//            qDebug()<<"测试数据"<<CylinderAx[i]<<endl;
//        }
//        qDebug()<<i<<endl;
        figure4->replot();
    }
    if(sensor5->SensorSwitch->isChecked())
    {
        figure5->graph(0)->setData(time_stramp,CylinderAy);
        figure5->replot();
    }
    if(sensor6->SensorSwitch->isChecked())
    {
        figure6->graph(0)->setData(time_stramp,LeakFlow);
        figure6->replot();
    }
    if(sensor7->SensorSwitch->isChecked())
    {
        figure7->graph(0)->setData(time_stramp,CylinderAx1);
        figure7->replot();
    }
    if(sensor8->SensorSwitch->isChecked())
    {
        figure8->graph(0)->setData(time_stramp,CylinderAy1);
        figure8->replot();
    }
    if(sensor9->SensorSwitch->isChecked())
    {
        figure9->graph(0)->setData(time_stramp,CylinderAx2);
        figure9->replot();
    }
    if(sensor10->SensorSwitch->isChecked())
    {
        figure10->graph(0)->setData(time_stramp,CylinderAy2);
        figure10->replot();
    }


    //杨泰春测试用
    if(sensor11->SensorSwitch->isChecked())
    {
        figure11->graph(0)->setData(time_stramp,CylinderAy2);
        figure11->replot();
    }

}

void BoomCircuitDialog::displaySensor1(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_left.png");
    ui->imagePressure1->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器1
        ui->imagePressure1->show();
        // 无杆腔压力绘图
//        int n=ui->figureListWidget->count();
//        QSize size(480,360/(n+1));
//        ui->figureListWidget->setGridSize(size);
        figure1=new QCustomPlot(this);
        addGraph(figure1,"动臂有杆腔压力");
        figure1->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure1);
        figure1->yAxis->setLabel("P1(V)");
        //
        figureItem1=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem1,figure1);
        ui->figureListWidget->addItem(figureItem1);

    }
    else
    {
        ui->imagePressure1->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem1);
        delete figureItem1;
    }
}

void BoomCircuitDialog::displaySensor2(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
    ui->imagePressure2->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
        ui->imagePressure2->show();
        // 有杆腔压力绘图
//        int n=ui->figureListWidget->count();
//        QSize size(480,360/(n+1));
//        ui->figureListWidget->setGridSize(size);
        figure2=new QCustomPlot(this);
        addGraph(figure2,"动臂无杆腔压力");
        figure2->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure2);
        figure2->yAxis->setLabel("P2(V)");
        //
        figureItem2=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem2,figure2);
        ui->figureListWidget->addItem(figureItem2);
    }
    else
    {
        ui->imagePressure2->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem2);
        delete figureItem2;
    }
}

void BoomCircuitDialog::displaySensor4(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
    ui->imageTiltX->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
        ui->imageTiltX->show();
        // 主泵1压力绘图
        figure4=new QCustomPlot(this);
//        addGraph(figure3,"主泵1压力");
        addGraph(figure4,"动臂X轴倾角");
        figure4->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure4);
//        figure3->yAxis->setLabel("Pp1(MPa)");
        figure4->yAxis->setLabel("Ax1(V)");
        //
        figureItem4=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem4,figure4);
        ui->figureListWidget->addItem(figureItem4);
    }
    else
    {
        ui->imageTiltX->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem4);
        delete figureItem4;
    }
}

void BoomCircuitDialog::displaySensor5(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
    ui->imageTiltY->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
        ui->imageTiltY->show();
        // 主泵1压力绘图
        figure5=new QCustomPlot(this);
//        addGraph(figure4,"主泵2压力");
        addGraph(figure5,"动臂Y轴倾角");
        figure5->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure5);
//        figure4->yAxis->setLabel("Pp2(MPa)");
        figure5->yAxis->setLabel("Ay1(V)");
        //
        figureItem5=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem5,figure5);
        ui->figureListWidget->addItem(figureItem5);
    }
    else
    {
        ui->imageTiltY->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem5);
        delete figureItem5;
    }
}

void BoomCircuitDialog::displaySensor6(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
    ui->imageFlow->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示
        ui->imageFlow->show();
        // 旁路泄漏流量
        figure6=new QCustomPlot(this);
        addGraph(figure6,"斗杆有杆腔压力");
        figure6->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure6);
        figure6->yAxis->setLabel("P3(V)");
        //
        figureItem6=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem6,figure6);
        ui->figureListWidget->addItem(figureItem6);
    }
    else
    {
        ui->imageFlow->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem6);
        delete figureItem6;
    }
}

void BoomCircuitDialog::displaySensor3(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/disp_left.png");
    ui->imageDisp->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器3
        ui->imageDisp->show();
        // 液压缸位移绘图
//        int n=ui->figureListWidget->count();
//        QSize size(480,360/(n+1));
//        ui->figureListWidget->setGridSize(size);
        figure3=new QCustomPlot(this);
        addGraph(figure3,"动臂位移");
        figure3->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure3);
        figure3->yAxis->setLabel("x1(m)");
        //
        figureItem3=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem3,figure3);
        ui->figureListWidget->addItem(figureItem3);

    }
    else
    {
        ui->imageDisp->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem3);
        delete figureItem3;
    }
}

void BoomCircuitDialog::displaySensor7(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角X
        figure7=new QCustomPlot(this);
        addGraph(figure7,"斗杆无杆腔压力");
        figure7->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure7);
        figure7->yAxis->setLabel("P4(V)");
        //
        figureItem7=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem7,figure7);
        ui->figureListWidget->addItem(figureItem7);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem7);
        delete figureItem7;
    }
}

void BoomCircuitDialog::displaySensor8(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure8=new QCustomPlot(this);
        addGraph(figure8,"斗杆位移");
        figure8->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure8);
        figure8->yAxis->setLabel("x2(m)");
        //
        figureItem8=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem8,figure8);
        ui->figureListWidget->addItem(figureItem8);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem8);
        delete figureItem8;
    }
}

void BoomCircuitDialog::displaySensor9(bool displayed)
{
    if(displayed)
    {
        // 铲斗倾角X
        figure9=new QCustomPlot(this);
        addGraph(figure9,"斗杆X轴倾角");
        figure9->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure9);
        figure9->yAxis->setLabel("Ax2(V)");
        //
        figureItem9=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem9,figure9);
        ui->figureListWidget->addItem(figureItem9);
    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem9);
        delete figureItem9;
    }
}

void BoomCircuitDialog::displaySensor10(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure10=new QCustomPlot(this);
        addGraph(figure10,"斗杆Y轴倾角)");
        figure10->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure10);
        figure10->yAxis->setLabel("Ay2(V)");
        //
        figureItem10=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem10,figure10);
        ui->figureListWidget->addItem(figureItem10);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem10);
        delete figureItem10;
    }
}


//杨泰春测试用
void BoomCircuitDialog::displaySensor11(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure11=new QCustomPlot(this);
        addGraph(figure11,"铲斗有杆腔压力");
        figure11->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure11);
        figure11->yAxis->setLabel("P5(V)");
        //
        figureItem11=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem11,figure11);
        ui->figureListWidget->addItem(figureItem11);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem11);
        delete figureItem11;
    }
}



void BoomCircuitDialog::displaySensor12(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure12=new QCustomPlot(this);
        addGraph(figure12,"铲斗无杆腔压力");
        figure12->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure12);
        figure12->yAxis->setLabel("P6(Y)");
        //
        figureItem12=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem12,figure12);
        ui->figureListWidget->addItem(figureItem12);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem12);
        delete figureItem12;
    }
}

void BoomCircuitDialog::displaySensor13(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure13=new QCustomPlot(this);
        addGraph(figure13,"铲斗位移");
        figure13->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure13);
        figure13->yAxis->setLabel("x3(m)");
        //
        figureItem13=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem13,figure13);
        ui->figureListWidget->addItem(figureItem13);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem13);
        delete figureItem13;
    }
}

void BoomCircuitDialog::displaySensor14(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure14=new QCustomPlot(this);
        addGraph(figure14,"铲斗X轴倾角");
        figure14->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure14);
        figure14->yAxis->setLabel("Ax3(V)");
        //
        figureItem14=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem14,figure14);
        ui->figureListWidget->addItem(figureItem14);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem14);
        delete figureItem14;
    }
}

void BoomCircuitDialog::displaySensor15(bool displayed)
{
    if(displayed)
    {
        // 斗杆倾角Y
        figure15=new QCustomPlot(this);
        addGraph(figure15,"铲斗Y轴倾角");
        figure15->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure15);
        figure15->yAxis->setLabel("Ay3(V)");
        //
        figureItem15=new QListWidgetItem(ui->figureListWidget);
        ui->figureListWidget->setItemWidget(figureItem15,figure15);
        ui->figureListWidget->addItem(figureItem15);

    }
    else
    {
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem15);
        delete figureItem15;
    }
}
void BoomCircuitDialog::showHistory(QModelIndex index)
{
    qDebug()<<"clicked";
    int row=index.row();
    QListWidgetItem *currentFile=ui->listWidget->item(row);
    QString fileName=currentFile->text();
    // 加上路径和后缀
    QString qfielName="C:\\Users\\ytc\\Desktop\\Software\\history\\"+fileName+"boom.txt";
    //setPlot(ui->figureBoom);
    // 打开文件
    faultDetector.getSensorData(qfielName.toStdString());//问题重新打开另一文件，即使清除了之前的图形，仍会出现问题
    vector<double> t=faultDetector.getTime();
    vector<double> P1=faultDetector.getPressure1();
    vector<double> P2=faultDetector.getPressure2();
    // 类型转化
    time_stramp=QVector<double>::fromStdVector(t);
    CylinderPressureA=QVector<double>::fromStdVector(P1);
    CylinderPressureB=QVector<double>::fromStdVector(P2);

//    qDebug()<<time_stramp[1]<<CylinderPressureA[1]<<CylinderPressureB[1]<<endl;
    // 添加数据，重新绘图

}

void BoomCircuitDialog::loopMovie()
{
    movie->start();
}

void BoomCircuitDialog::switchPage(int index)
{
    switch(index)
    {
    case 1:
        ui->stackedWidget->setCurrentIndex(1);
        ui->labelSeosor->setText("传感器设置");
        break;
    case 2:
        ui->stackedWidget->setCurrentIndex(0);
        ui->labelSeosor->setText("回路预检");
        break;
    case 3:
        ui->stackedWidget->setCurrentIndex(2);
        ui->labelSeosor->setText("信号采集与存储");
        break;
    case 4:
        ui->stackedWidget->setCurrentIndex(1);
        ui->labelSeosor->setText("传感器设置");
        break;

    }
}

void BoomCircuitDialog::setPlotRange1(int index)
{
    if(sensor1->SensorSwitch->isChecked())
    {
        switch(index)
        {
        case 0/*"0~10V (电压)"*/:
            figure1->graph(0)->valueAxis()->setRange(0,10);
            break;
        case 1/*"-5~5V (电压)"*/:
            figure1->graph(0)->valueAxis()->setRange(-5,5);
            break;
        case 2/*"4~20mA (电流)"*/:
            figure1->graph(0)->valueAxis()->setRange(4,20);
            break;
        }
        figure1->replot();
    }
}

void BoomCircuitDialog::setPlotRange2(int index)
{
    if(sensor2->SensorSwitch->isChecked())
    {
        switch(index)
        {
        case 0/*"0~10V (电压)"*/:
            figure2->graph(0)->valueAxis()->setRange(0,10);
            break;
        case 1/*"-5~5V (电压)"*/:
            figure2->graph(0)->valueAxis()->setRange(-5,5);
            break;
        case 2/*"4~20mA (电流)"*/:
            figure2->graph(0)->valueAxis()->setRange(4,20);
            break;
        }
        figure2->replot();
    }
}

void BoomCircuitDialog::setPlotRange3(int index)
{
    if(sensor3->SensorSwitch->isChecked())
    {
        switch(index)
        {
        case 0/*"0~10V (电压)"*/:
            figure6->graph(0)->valueAxis()->setRange(0,10);
            break;
        case 1/*"4~20mA (电流)"*/:
            figure6->graph(0)->valueAxis()->setRange(4,20);
            break;
        case 2/*"AB (脉冲)"*/:
            figure6->graph(0)->valueAxis()->setRange(0,1.2);
            break;
        }
        figure6->replot();
    }
}

//void BoomCircuitDialog::mousePressEvent(QMouseEvent *event)
//{
//    //获取鼠标点击位置
//    if(event->button()==Qt::LeftButton)
//    {
//        lastPoint=event->pos();
//        ui->labelImageBoom->setLocation(lastPoint-controlPoint);
////        qDebug()<<lastPoint<<lastPoint-controlPoint<<endl;
//    }
//}

void BoomCircuitDialog::on_btnEvalBoom_clicked()
{
    QString faultstring=faultDetector.faultRule();
    ui->radar->hlthy[0]=0.87;
    ui->radar->hlthy[1]=0.55;
    ui->radar->hlthy[2]=0.35;
    ui->radar->hlthy[3]=0.76;
    ui->radar->repaint();
    ui->textFault->setDocumentTitle("元件健康");
    QFont font("楷体",12,QFont::Normal);
    ui->textFault->setFont(font);
//    ui->textFault->setText("液压缸1故障程度87%\n");
//    ui->textFault->setText("液压缸1故障程度87%\n \n液压缸2故障程度55%\n \n多路换向阀1故障程度35%\n \n多路换向阀2故障程度76%\n");
    ui->textFault->setText(faultstring.toStdString().c_str());
//    ui->textFault->setText("多路换向阀1故障程度35%\n");
//    ui->textFault->setText("多路换向阀2故障程度76%\n");
//    int faultID=faultDetector.checkPressure();
//    if(faultID==0)
//    {
//        faultID=faultDetector.checkPressureDiff();
//        if(faultID==0)
//        {
//            faultID=faultDetector.checkPressureZero();
//            cout<<"fault ID is "<<faultID<<endl;
//        }
//    }
//    switch(faultID)
//    {
//    case 0:
//        ui->textFault->setText("无法判断故障");
//        break;
//    case 1:
//        ui->textFault->setText("液压缸正常，阀正常");
//        break;
//    case 2:
//        ui->textFault->setText("液压缸内泄漏，阀正常");
//        break;
//    case 3:
//        ui->textFault->setText("液压缸正常，阀内泄漏");
//        break;
//    case 4:
//        ui->textFault->setText("液压缸内泄漏，阀内泄漏");
//        break;
//    }
}

void BoomCircuitDialog::on_P1Boom_clicked()
{
//    if(ui->P1Boom->isChecked())
//    {
//        ui->figureBoom->graph(0)->setVisible(true);
//    }
//    else
//    {
//        ui->figureBoom->graph(0)->setVisible(false);
//    }
//    ui->figureBoom->replot();
}

void BoomCircuitDialog::on_P2Boom_clicked()
{
//    if(ui->P2Boom->isChecked())
//    {
//        ui->figureBoom->graph(1)->setVisible(true);
//    }
//    else
//    {
//        ui->figureBoom->graph(1)->setVisible(false);
//    }
//    ui->figureBoom->replot();
}
