#include "login.h"
#include "ui_Login.h"
#include <QDateTime>
#include <QTime>
#include <QDate>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("zlxiong");
    db.setPassword("123456");
    db.setDatabaseName("sjtu");

    if(db.open())
    {
        qDebug()<<"Connect to database successfully.";
    }
    else
    {
        qDebug()<<"Failed to connect to database.";
    }
}

Login::~Login()
{
    delete ui;
    db.close();
}

void Login::on_loginButon_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    QSqlQuery query;
//    if(query.exec("SELECT userID from user WHERE username='"+username+"'AND password='"+password+"'"))
//    {
//        if(query.size()>0)
//        {
//            while(query.next())
//            {
//                QString userID=query.value(0).toString();
//                qDebug()<<"The user "<<userID<<"can login";
//            }
            this->hide();
            mainWindow=new MainWindow(this);
            mainWindow->setWindowTitle("挖掘机液压系统");
            mainWindow->show();
//        }
//        else
//        {
//            QMessageBox::warning(this, "Login failed","Invalid username or password.");
//        }
//    }
//    else
//    {
//        qDebug() << query.lastError().text();
//    }
}

void Login::on_shutdownButton_clicked()
{
    this->close();
}

void Login::updateTime()
{
    QDateTime dt;
    QTime currTime;
//    QTime currTime=QTime::currentTime();
    QDate currDate;
    dt.setTime(currTime.currentTime());
    dt.setDate(currDate.currentDate());
    QString current=dt.toString("yyyy/MM/dd,hh:mm:ss");
//    QString current=currTime.toString("hh:mm:ss");
    ui->currentDateTime->setText(current);
}
