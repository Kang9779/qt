#include "swingcircuitdialog.h"
#include "ui_swingcircuitdialog.h"
#include "mainwindow.h"
#include "checksensor.h"
#include "savefile.h"

SwingCircuitDialog::SwingCircuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwingCircuitDialog)
{
    ui->setupUi(this);
    // 关闭子窗口，返回主窗口
    connect(this,SIGNAL(rejected()),(MainWindow*)parentWidget(),SLOT(show()));
    // 加载油液回路动图
    movie = new QMovie(":/circuit/rsc/回转系统原理图无框.gif");
    movie->setBackgroundColor(QColor(100,100,100,100));
    ui->labelImageSwing->setMovie(movie);
    ui->labelImageSwing->setScaledContents(true);
    // 循环播放动图
    QTimer *movieTimer=new QTimer(this);
    movie->start();
    connect(movieTimer,SIGNAL(timeout()),this,SLOT(loopMovie()));
    movieTimer->start(1000);
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
    ui->pressureSensor1->setImageLabel(ui->imagePressure1);
    ui->pressureSensor1->setSensorImage(":/transducer/rsc/pressure_left.png");
    ui->pressureSensor1->setFigureList(ui->figureListWidget);
    ui->pressureSensor1->setFigureName("马达左腔压力");
    ui->pressureSensor1->setFigureLabel("P1(MPa)");
    ui->pressureSensor1->setCombox(ui->comboBox_1);

    ui->pressureSensor2->setImageLabel(ui->imagePressure2);
    ui->pressureSensor2->setSensorImage(":/transducer/rsc/pressure_right.png");
    ui->pressureSensor2->setFigureList(ui->figureListWidget);
    ui->pressureSensor2->setFigureName("马达右腔压力");
    ui->pressureSensor2->setFigureLabel("P2(MPa)");
    ui->pressureSensor2->setCombox(ui->comboBox_2);

    ui->pressureSensor3->setImageLabel(ui->imagePressure3);
    ui->pressureSensor3->setSensorImage(":/transducer/rsc/pressure_right.png");
    ui->pressureSensor3->setFigureList(ui->figureListWidget);
    ui->pressureSensor3->setFigureName("主泵1压力");
    ui->pressureSensor3->setFigureLabel("Pp1(MPa)");
    ui->pressureSensor3->setCombox(ui->comboBox_4);

    ui->pressureSensor4->setImageLabel(ui->imagePressure4);
    ui->pressureSensor4->setSensorImage(":/transducer/rsc/pressure_left.png");
    ui->pressureSensor4->setFigureList(ui->figureListWidget);
    ui->pressureSensor4->setFigureName("先导泵压力");
    ui->pressureSensor4->setFigureLabel("Pp(MPa)");
    ui->pressureSensor4->setCombox(ui->comboBox_5);

    ui->dispSensor->setImageLabel(ui->imageDisp);
    ui->dispSensor->setSensorImage(":/transducer/rsc/disp_right.png");
    ui->dispSensor->setFigureList(ui->figureListWidget);
    ui->dispSensor->setFigureName("马达转角");
    ui->dispSensor->setFigureLabel("a(rad)");
    ui->dispSensor->setCombox(ui->comboBox_3);
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

SwingCircuitDialog::~SwingCircuitDialog()
{
    delete ui;
}

void SwingCircuitDialog::loopMovie()
{
    movie->start();
}

void SwingCircuitDialog::switchPage(int index)
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

void SwingCircuitDialog::getRealtimeData(QString qstr)
{
    // 时间+2通道压力数据
    QVector<double> timeStramp;
    QVector<double> value1;
    QVector<double> value2;
    QVector<double> value3;
    QVector<double> value4;
    clientThread->dataConvert(qstr,timeStramp,value1,value2,value3,value4);
    ui->pressureSensor1->addPlotData(timeStramp,value1);
    ui->pressureSensor2->addPlotData(timeStramp,value2);
}

void SwingCircuitDialog::onRunStopChanged(int run)
{
    // 停止保存文件线程
    fileThread->quit();
    // 关闭定时器，禁止刷新曲线
    if(run)
        dateTimer->start();
    else
        dateTimer->stop();
}

void SwingCircuitDialog::updatePlot()
{
    // 2通道数据更新
    ui->pressureSensor1->updatePlot();
    ui->pressureSensor2->updatePlot();
}

void SwingCircuitDialog::updatePeriod(QString text)
{
    //调整定时器时间，改变图形刷新速率
    dateTimer->start(text.toInt());
}

void SwingCircuitDialog::startSave()
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

void SwingCircuitDialog::openHistory()
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
    ui->pressureSensor1->setPlotData(time_stramp,CylinderPressureA);
    ui->pressureSensor2->setPlotData(time_stramp,CylinderPressureB);
}

void SwingCircuitDialog::evalHealth()
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
