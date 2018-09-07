#include "pumpcircuitdialog.h"
#include "ui_pumpcircuitdialog.h"
#include "mainwindow.h"
#include "checksensor.h"
#include "savefile.h"

#include <QListWidgetItem>
#include "string.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <QDebug>
#include <QPen>
#include <QString>
#include <QFileDialog>
#include "clientthread.h"
#include <QPen>
#include<diagnosis.h>

PumpCircuitDialog::PumpCircuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PumpCircuitDialog)
{
    ui->setupUi(this);
    // 关闭子窗口，返回主窗口
    connect(this,SIGNAL(rejected()),(MainWindow*)parentWidget(),SLOT(show()));
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
        // 初始化传感器控制checkbox
        //传感器初始化
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
        QListWidgetItem *sensorItem1=new  QListWidgetItem(ui->sensorList);
        QListWidgetItem *sensorItem2=new  QListWidgetItem(ui->sensorList);
        QListWidgetItem *sensorItem3=new  QListWidgetItem(ui->sensorList);
        QListWidgetItem *sensorItem4=new  QListWidgetItem(ui->sensorList);
        QListWidgetItem *sensorItem5=new  QListWidgetItem(ui->sensorList);
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
        connect(sensor1->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor1(bool)));
        connect(sensor2->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor2(bool)));// 有杆腔压力传感器
        connect(sensor3->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor3(bool)));// 液压缸位移传感器
        connect(sensor4->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor4(bool)));// 动臂X轴倾角传感器
        connect(sensor5->SensorSwitch,SIGNAL(toggled(bool)),this,SLOT(displaySensor5(bool)));// 动臂Y轴倾角传感器
        // 绘图区横轴滚轮条取消
        ui->figureListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        // 子页面3：数据采集栏
        // 测试流程
        ui->textBrowser->setStyleSheet("border: none;");
        QFont font("楷体",12,QFont::Normal);
        ui->textBrowser->setFont(font);
        ui->textBrowser->setText("\n 测试流程：\n\n铲斗满载，开启动臂液压缸多路换向阀，运动到最大行程处。");
        // TCP数据采集线程
        clientThread=new ClientThread();
        // 子线程和主线程数据传输
        connect(clientThread,SIGNAL(dataAcquired(QString)),this,SLOT(getRealtimeData(QString)));
        clientThread->start(QThread::HighestPriority);//clientThread->start();
        // 数据采集启动与停止
        QButtonGroup *runStop=new QButtonGroup(this);
        runStop->setId(ui->btnRun,1);
        runStop->setId(ui->btnStop,0);
        connect(runStop,SIGNAL(buttonPressed(int)),this,SLOT(onRunStopChanged(int)));
        // Set timer用于控制曲线刷新
        dateTimer=new QTimer(this);
        dateTimer->start(0);// 周期为0时界面启动即运行
        connect(dateTimer,SIGNAL(timeout()),this,SLOT(updatePlot()));
        // Set update period combox，更新周期选择
        ui->updatePeriod->addItems(QStringList() << "0"<<"20" << "50" << "100" << "200");
        connect(ui->updatePeriod,SIGNAL(currentIndexChanged(QString)),this,SLOT(updatePeriod(QString)));
        // 文件日历选择
        calendar=new QCalendarWidget(this);
        calendar->setGridVisible(true);
        ui->dateEdit->setCalendarPopup(true);
        ui->dateEdit->setCalendarWidget(calendar);
        ui->dateEdit->setMinimumDate(QDate(2017, 1, 1));
        // 创建文件读、写线程
        fileThread=new QThread();
        connect(ui->btnRun,SIGNAL(clicked(bool)),this,SLOT(startSave()));
        // 历史数据
        connect(ui->btnHistory,SIGNAL(clicked(bool)),this,SLOT(openHistory()));
        // 评估
        connect(ui->btnEval,SIGNAL(clicked(bool)),this,SLOT(evalHealth()));
}

PumpCircuitDialog::~PumpCircuitDialog()
{
    delete ui;
}

void PumpCircuitDialog::switchPage(int index)
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

void PumpCircuitDialog::getRealtimeData(QString qstr)
{

    // QString类型转string类型
    string str=qstr.toStdString();
    // 用于QCustomPlot绘图数据类型
    QVector<double> timeStramp;//时间
    QVector<double> value1;//压力1
    QVector<double> value2;//压力2
    QVector<double> value3;//激光传感器位移
    QVector<double> value4;//动臂X轴倾角
    QVector<double> value5;//动臂Y轴倾角
    // 用于转换的中间变量
    QString tmpStr;
    QTime tmp;
    QDateTime dt;
    int startpoint=0;
    int endpoint=0;
    int strlgth;
    for(auto c:str)
    {
        if(c=='@'){
            strlgth = endpoint-startpoint;
            int chnlNumber=atoi(str.substr(startpoint,2).c_str())-10;
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
                break;
             case 2:
                value1.push_back(atof(subs.c_str()));
                 break;
            case 3:
               value2.push_back(atof(subs.c_str()));
                break;
            case 4:
               value3.push_back(atof(subs.c_str()));
                break;
            case 5:
               value4.push_back(atof(subs.c_str()));
                break;
            case 6:
               value5.push_back(atof(subs.c_str()));
                break;
            default:
                break;
            }
            }
            endpoint+=1;
    }
    int min_size;
    int size1=timeStramp.size();
    int size2=value1.size();
    int size3=value2.size();
    int size4=value3.size();
    int size5=value4.size();
    int size6=value5.size();
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
}

void PumpCircuitDialog::onRunStopChanged(int run)
{
    // 停止保存文件线程
    fileThread->quit();
    // 关闭定时器，禁止刷新曲线
    if(run)
        dateTimer->start();
    else
        dateTimer->stop();
}

void PumpCircuitDialog::updatePlot()
{
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
}

void PumpCircuitDialog::updatePeriod(QString text)
{
    //调整定时器时间，改变图形刷新速率
    dateTimer->start(text.toInt());
}

void PumpCircuitDialog::startSave()
{
    // 创建并运行保存文件子线程
    QDateTime dt;
    QTime currTime;
    QDate currDate;
    dt.setTime(currTime.currentTime());
    dt.setDate(currDate.currentDate());
    QString fileName=dt.toString("yyyy-MM-dd-hh-mm-ss");
    SaveFile *saveFile=new SaveFile("E:\\"+fileName+".txt");
    // 添加到ListWidget
    int row=ui->listWidget->count();
    QListWidgetItem *newFile = new QListWidgetItem;
    newFile->setText(fileName);
    ui->listWidget->insertItem(row+1, newFile);
    // 写采集到的数据到文件
    saveFile->moveToThread(fileThread);
    connect(clientThread,SIGNAL(dataAcquired(QString)),saveFile,SLOT(saveRealtimeData(QString)),Qt::QueuedConnection);
    fileThread->start();
    // 文件子线程ID，用于调试
    //qDebug()<<"fileThread id is "<<fileThread->currentThreadId();
}

void PumpCircuitDialog::openHistory()
{
    // 创建打开文件对话框，在windows系统下会出现log4cplus error,但不影响文件打开
    QString qfileName=QFileDialog::getOpenFileName(this,tr("Open"),"./",tr("*.txt;;*.dat;;*.bin;;*.csv"));
    faultDetector.getSensorData(qfileName.toStdString());//问题重新打开另一文件，即使清除了之前的图形，仍会出现问题
    vector<double> t=faultDetector.getTime();
    vector<double> P1=faultDetector.getPressure1();
    vector<double> P2=faultDetector.getPressure2();
    //    qDebug()<<t[1]<<P1[1]<<P2[1]<<endl;
    time_stramp=QVector<double>::fromStdVector(t);
    CylinderPressureA=QVector<double>::fromStdVector(P1);
    CylinderPressureB=QVector<double>::fromStdVector(P2);
    //    qDebug()<<time_stramp[1]<<CylinderPressureA[1]<<CylinderPressureB[1]<<endl;
    // 添加数据，重新绘图
   // ui->pressureSensor1->setPlotData(time_stramp,CylinderPressureA);
   // ui->pressureSensor2->setPlotData(time_stramp,CylinderPressureB);
}

void PumpCircuitDialog::evalHealth()
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
    ui->textFault->setText(faultstring.toStdString().c_str());
}
void PumpCircuitDialog::displaySensor1(bool displayed)
{
    QImage *image=new QImage;
  //  image->load(":/transducer/rsc/pressure_left.png");
    ui->imagePressure1->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器1
   //     ui->imagePressure1->show();
        // 无杆腔压力绘图
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
void PumpCircuitDialog::displaySensor2(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
   // ui->imagePressure2->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
  //      ui->imagePressure2->show();
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

void PumpCircuitDialog::displaySensor3(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/disp_left.png");
 //   ui->imageDisp->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器3
     //   ui->imageDisp->show();
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
      //  ui->imageDisp->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem3);
        delete figureItem3;
    }
}

void PumpCircuitDialog::displaySensor4(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
   // ui->imageTiltX->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
     //   ui->imageTiltX->show();
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
       // ui->imageTiltX->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem4);
        delete figureItem4;
    }
}

void PumpCircuitDialog::displaySensor5(bool displayed)
{
    QImage *image=new QImage;
    image->load(":/transducer/rsc/pressure_right.png");
   // ui->imageTiltY->setPixmap(QPixmap::fromImage(*image));
    if(displayed)
    {
        // 液压回路图中显示压力传感器2
     //   ui->imageTiltY->show();
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
      //  ui->imageTiltY->hide();
        // 删除绘图
        ui->figureListWidget->removeItemWidget(figureItem5);
        delete figureItem5;
    }
}


void PumpCircuitDialog::addGraph(QCustomPlot *figure,QString title)
{
    figure->addGraph();
//    // 设置标题
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

void PumpCircuitDialog::setPlot(QCustomPlot *figure)
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

    // 设置曲线画笔
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    figure->graph(0)->setPen(pen);

    // Set ranges
    figure->yAxis->setRange(0,10);

    // Set label
    figure->xAxis->setLabel("时间 (s)");
    // 清除当前绘图
    figure->graph(0)->data()->clear();
    // 时间轴
    figure->setLocale(QLocale(QLocale::Chinese, QLocale::China));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    figure->xAxis->setTicker(timeTicker);
    figure->replot();
}

void PumpCircuitDialog::setRealtimePlot(QCustomPlot *figureBoom)
{
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    figureBoom->xAxis->setTicker(timeTicker);
    figureBoom->axisRect()->setupFullAxesBox();
}

// 布局子图设置
void PumpCircuitDialog::setCustomGraph(QCPGraph *graph)
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
