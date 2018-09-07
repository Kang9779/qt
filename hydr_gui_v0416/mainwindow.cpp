#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include "login.h"
#include <QMovie>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->BtnArmCircuit->setText("斗\n杆\n1");
//    ui->BtnBoomCircuit->setText("动\n臂\n2");
//    ui->BtnBucketCircuit->setText("铲\n斗");
//    ui->BtnSwingCircuit->setText("回\n转");
//    ui->BtnTravelCircuit->setText("左\n行\n走");
//    ui->BtnArmCircuit2->setText("斗\n杆\n2");
//    ui->BtnBoomCircuit2->setText("动\n臂\n1");
//    ui->BtnTravelCircuit2->setText("右\n行\n走");
//    ui->BackupCircuit->setText("备\n用");


    connect(this,SIGNAL(destroyed(QObject*)),this->parent()/*(Login*)parentWidget()*/,SLOT(show()));

//    QImage *image=new QImage;
//    image->load(":/new/src/image/SY215.jpg");
//    ui->labelImageSY215->setPixmap(QPixmap::fromImage(*image));
//    ui->labelImageSY215->setScaledContents(true);
//    ui->labelImageSY215->show();

    ui->BtnBucketCircuit->installEventFilter(this);
    ui->BtnBoomCircuit->installEventFilter(this);
    ui->BtnSwingCircuit->installEventFilter(this);
    ui->BtnTravelCircuit->installEventFilter(this);
    ui->BtnArmCircuit->installEventFilter(this);
    ui->BtnPumpCircuit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_BtnArmCircuit_clicked()
{
    this->hide();
//    ui->labelStatus->setText("当前选择挖掘机斗杆液压回路");
    ArmWindow=new ArmCircuitDialog(this);
    ArmWindow->setWindowTitle("斗杆液压回路");
    ArmWindow->show();
}

void MainWindow::on_BtnBoomCircuit_clicked()
{
    this->hide();
//    ui->labelStatus->setText("当前选择挖掘机动臂液压回路");
    BoomWindow=new BoomCircuitDialog(this);
    BoomWindow->setWindowTitle("动臂液压回路");
    BoomWindow->show();
}

void MainWindow::on_BtnBucketCircuit_2_clicked()
{

}



void MainWindow::on_BtnSwingCircuit_clicked()
{
    this->hide();
//    ui->labelStatus->setText("当前选择挖掘机回转液压回路");
    SwingWindow=new SwingCircuitDialog(this);
    SwingWindow->setWindowTitle("回转液压回路");
    SwingWindow->show();
}

void MainWindow::on_BtnTravelCircuit_2_clicked()
{

}

void MainWindow::on_BtnPumpCircuit_clicked()
{
    this->hide();
//    ui->labelStatus->setText("当前选择挖掘机液压泵源回路");
    PumpWindow=new PumpCircuitDialog(this);
    PumpWindow->setWindowTitle("液压泵回路");
    PumpWindow->show();
}

void MainWindow::on_BtnTravelCircuit_clicked()
{
    this->hide();
    //    ui->labelStatus->setText("当前选择挖掘机行走液压回路");
    TravelWindow=new TravelCircuitDialog(this);
    TravelWindow->setWindowTitle("行走液压回路");
    TravelWindow->show();
}

void MainWindow::on_BtnBucketCircuit_clicked()
{
    this->hide();
    //    ui->labelStatus->setText("当前选择挖掘机铲斗液压回路");
    BucketWindow=new BucketCircuitDialog(this);
    BucketWindow->setWindowTitle("铲斗液压回路");
    BucketWindow->show();
}

void MainWindow::on_BtnTravelCircuit2_clicked()
{
    ui->BtnTravelCircuit->click();
}

void MainWindow::on_BtnBoomCircuit2_clicked()
{
    ui->BtnBoomCircuit->click();
}

void MainWindow::on_BtnArmCircuit2_clicked()
{
    ui->BtnArmCircuit->click();
}
//void MainWindow::enterEvent(QEvent *e)
//{
//    qDebug()<<"鼠标进来";
//}

//void MainWindow::leaveEvent(QEvent *e)
//{
//    qDebug()<<"鼠标出来";
//}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{

    if(watched == ui->BtnBucketCircuit)
    {
       if(event->type() == QEvent::Enter)
       {
           QMovie *movie =new QMovie(":/images/rsc/main_sany_bucket.gif");
           ui->labelImageSY215->setMovie(movie);
           movie->start();
           return true;
       }
       if(event->type() == QEvent::Leave)
       {
           ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
           return true;
       }
    }else if(watched == ui->BtnArmCircuit)
    {
       if(event->type() == QEvent::Enter)
       {
           QMovie *movie =new QMovie(":/images/rsc/main_sany_arm.gif");
           ui->labelImageSY215->setMovie(movie);
           movie->start();
           return true;
       }
       if(event->type() == QEvent::Leave)
       {
           ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
//           qDebug()<<"从斗杆出来";
           return true;
       }
    }
    else if(watched == ui->BtnBoomCircuit)
        {
           if(event->type() == QEvent::Enter)
           {
               QMovie *movie =new QMovie(":/images/rsc/main_sany_boom.gif");
               ui->labelImageSY215->setMovie(movie);
               movie->start();

//               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany_boom.png"));
//               qDebug()<<"进入动臂";
               return true;
           }
           if(event->type() == QEvent::Leave)
           {
               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
//               qDebug()<<"从动臂出来";
               return true;
           }
        }
    else if(watched == ui->BtnSwingCircuit)
        {
           if(event->type() == QEvent::Enter)
           {
               QMovie *movie =new QMovie(":/images/rsc/main_sany_swing.gif");
               ui->labelImageSY215->setMovie(movie);
               movie->start();
//               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany_swing.png"));
//               qDebug()<<"进入回转";
               return true;
           }
           if(event->type() == QEvent::Leave)
           {
               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
//               qDebug()<<"从回转出来";
               return true;
           }
        }
    else if(watched == ui->BtnPumpCircuit)
        {
           if(event->type() == QEvent::Enter)
           {
               QMovie *movie =new QMovie(":/images/rsc/main_sany_pump.gif");
               ui->labelImageSY215->setMovie(movie);
               movie->start();
//               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany_pump.png"));
//               qDebug()<<"进入泵";
               return true;
           }
           if(event->type() == QEvent::Leave)
           {
               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
//               qDebug()<<"从泵出来";
               return true;
           }
        }
    else if(watched == ui->BtnTravelCircuit)
        {
           if(event->type() == QEvent::Enter)
           {

               QMovie *movie =new QMovie(":/images/rsc/main_sany_travel.gif");
               ui->labelImageSY215->setMovie(movie);
               movie->start();
//               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany_travel.png"));
//               qDebug()<<"进入行走";
               return true;
           }
           if(event->type() == QEvent::Leave)
           {
               ui->labelImageSY215->setPixmap(QPixmap(":/images/rsc/main_sany.png"));
//               qDebug()<<"从斗杆行走";
               return true;
           }
        }
    else
    {
        return true;
    }
}
