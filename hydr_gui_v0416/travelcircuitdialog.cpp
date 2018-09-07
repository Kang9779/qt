#include "travelcircuitdialog.h"
#include "ui_travelcircuitdialog.h"
#include "mainwindow.h"

TravelCircuitDialog::TravelCircuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TravelCircuitDialog)
{
    ui->setupUi(this);
    // 关闭子窗口，返回主窗口
    connect(this,SIGNAL(rejected()),(MainWindow*)parentWidget(),SLOT(show()));
    // 加载油液回路动图
    movie = new QMovie(":/circuit/rsc/左右行走_动画无框.gif");
    movie->setBackgroundColor(QColor(100,100,100,100));
    ui->labelImageTravel->setMovie(movie);
    ui->labelImageTravel->setScaledContents(true);
    // 循环播放动图
    QTimer *movieTimer=new QTimer(this);
    movie->start();
    connect(movieTimer,SIGNAL(timeout()),this,SLOT(loopMovie()));
    movieTimer->start(1000);
}

TravelCircuitDialog::~TravelCircuitDialog()
{
    delete ui;
}

void TravelCircuitDialog::loopMovie()
{
    movie->start();
}
