#include "clientthread.h"
#include <QDebug>
#include <QHostAddress>
#include <string>
#include <QTime>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
using namespace std;


ClientThread::ClientThread()
{
    qDebug()<<"TCP client creating thread is : "<<currentThreadId();

}

void ClientThread::run()
{
    qDebug()<<"TCP client running thread id is "<<currentThreadId();
    // Set client
  //  db= new QSqlDatabase();
    qRegisterMetaType<QSqlDatabase>("QSqlDatabase");

    db = QSqlDatabase::addDatabase("QMYSQL");
    if(!db.isOpen())
    {
//    db.setHostName("sh-cdb-oa2etw0f.sql.tencentcdb.com");
//    db.setUserName("root");
//    db.setPassword("1234qwer");
//    db.setPort(63301);
//    db.setDatabaseName("wjj");

        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("123456");
        db.setDatabaseName("58data");

    db.open();
    qDebug()<<db.lastError();
    }
    tcpSocket=new QTcpSocket();
    tcpSocket->connectToHost("127.0.0.1",63401);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(displayConnection()),Qt::DirectConnection);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)),Qt::DirectConnection);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(getTcpData()),Qt::DirectConnection);
    exec();
}

void ClientThread::displayConnection()
{
    //显示连接信息
    QHostAddress ipAddr=tcpSocket->localAddress();
    quint16 port=tcpSocket->localPort();
    qDebug()<<"Connect to address"<<ipAddr.toString()<<"and port"<<port;
//    qDebug()<<tcpSocket->bytesAvailable();
}

void ClientThread::displayError(QAbstractSocket::SocketError)
{
    //显示TCP连接错误信息
    qDebug()<<tcpSocket->errorString();
}

void ClientThread::getTcpData()
{
    // 获取TCP数据，每1s读取1次数据
    char edchar='0';
    string str="";
//    int mlgth1=0;
//    int mlgth2=0;
//    int mlgth3=0;
//    int mlgth4=0;
//    int mlgth5=0;
//    int mlgth6=0;
//    int mlgth7=0;

    while(edchar!='@')
    {
        tcpSocket->waitForReadyRead(100);
        int value=tcpSocket->bytesAvailable();
//        qDebug() << "Number is:"<<value;
        char buf2[value];
        tcpSocket->read(buf2,value);
        string bufstr(buf2);
        int len = bufstr.size();
        if (value !=0)
        {
            bufstr.erase(value,len-value);
//            decltype(bufstr.size()) punct_cnt1 = 0;
//            decltype(bufstr.size()) punct_cnt2 = 0;
//            decltype(bufstr.size()) punct_cnt3 = 0;
//            decltype(bufstr.size()) punct_cnt4 = 0;
//            decltype(bufstr.size()) punct_cnt5 = 0;
//            decltype(bufstr.size()) punct_cnt6 = 0;
//            decltype(bufstr.size()) punct_cnt7 = 0;
            for(auto c:bufstr)
            {
//                if(c=='%')
//                {
//                    ++punct_cnt1;
//                }
//                if(c==',')
//                {
//                    ++punct_cnt2;
//                }
//                if(c=='!')
//                {
//                    ++punct_cnt3;
//                }
//                if(c=='@')
//                {
//                    ++punct_cnt4;
//                }
//                if(c==';')
//                {
//                    ++punct_cnt5;
//                }
                edchar=c;
            }
//            mlgth1+=punct_cnt1;
//            mlgth2+=punct_cnt2;
//            mlgth3+=punct_cnt3;
//            mlgth4+=punct_cnt4;
//            mlgth5+=punct_cnt5;
            str=str+bufstr;
        }

    }
    int lenstr=str.size();
    char buf3[lenstr];
    int i=0;
    for(auto c:str)
    {
        buf3[i]=c;
        i++;
    }
    //将TCP缓存数据转换成字符串
    QString qstr(buf3);
//    qDebug()<<"send successfully";
    //发送数据给主线程

    emit dataAcquired(qstr,db);
}

void ClientThread::dataConvert(QString qstr, QVector<double> &timeStramp, QVector<double> &value1, QVector<double> &value2,
                               QVector<double> value3,QVector<double> value4)
{
//    string str=qstr.toStdString();
//    // 用于转换的中间变量
//        QString tmpStr;
//        QTime tmp;
//        QDateTime dt;

//        int startpoint=0;
//        int endpoint=0;
//        int num1=0;
//        int num2=0;
//        int num3=0;
//        int num4=0;
//        int num5=0;
//        int strlgth;
//        for(c:str){
//            if(c=='#')
//            {
//                startpoint = endpoint+1;
//            }
//            if(c=='%')
//            {
//                strlgth = endpoint-startpoint+1;
//                string subs=str.substr(startpoint,strlgth-1);
//                startpoint = endpoint+1;
//    //            qDebug()<<subs.c_str();
//                // string类型转QString类型
//                tmpStr=QString::fromStdString(subs);
//                // QString类型转QTime类型
//                tmp=QTime::fromString(tmpStr,"h:m:s.z");
//    //            qDebug()<<tmp;
//                // 用QTime和QDate设置QDataTime
//                dt.setTimeSpec(Qt::LocalTime);
//                dt.setTime(tmp);
//                // QDateTime类型转double类型，并存如timeStramp向量中
//                //方法一：dateTimeToKey
//                //timeStramp.push_back(QCPAxisTickerDateTime::dateTimeToKey(dt));
//                //方法二：toMSecsSinceEpoch()
//                timeStramp.push_back(dt.toMSecsSinceEpoch()/1000.0);
//    //            qDebug()<<timeStramp[num1];
//                num1+=1;
//            }
//            if(c==',')
//            {
//                strlgth = endpoint-startpoint+1;
//                string subs=str.substr(startpoint,strlgth);
//                startpoint = endpoint+1;
//                // string类型转char类型，并存入value1向量
//                value1.push_back(atof(subs.c_str()));
//    //            qDebug()<<value1[num2];
//                num2+=1;
//            }
//            if(c==';')
//            {
//                strlgth = endpoint-startpoint+1;
//                string subs=str.substr(startpoint,strlgth);
//                startpoint = endpoint+1;
//                // string类型转char类型，并存入value2向量
//                value2.push_back(atof(subs.c_str()));

//                num3+=1;
//            }
//            if(c=='@')
//            {
//                strlgth = endpoint-startpoint+1;
//                string subs=str.substr(startpoint,strlgth);
//                startpoint = endpoint+1;
//                // string类型转char类型，并存入value1向量
//                value3.push_back(atof(subs.c_str()));
//    //            qDebug()<<"value3:"<<value3[num4];
//                num4+=1;
//            }
//            if(c==';')
//            {
//                strlgth = endpoint-startpoint+1;
//                string subs=str.substr(startpoint,strlgth);
//                startpoint = endpoint+1;
//                // string类型转char类型，并存入value2向量
//                value4.push_back(atof(subs.c_str()));

//                num5+=1;
//            }
//            endpoint+=1;
//        }
//        int min_size;
//        int size1=timeStramp.size();
//        int size2=value1.size();
//        int size3=value2.size();
//        int size4=value3.size();
//        int size5=value4.size();

//        if(size1>size2)
//            min_size=size2;
//        else
//            min_size=size1;
//        if(size3<min_size)
//            min_size=size3;
//        if(size4<min_size)
//            min_size=size4;
//        if(size5<min_size)
//            min_size=size5;
//        while(size1>min_size)
//        {
//            timeStramp.pop_back();
//            size1=timeStramp.size();
//        }
//        while(size2>min_size)
//        {
//            value1.pop_back();
//            size2=value1.size();
//        }
//        while(size3>min_size)
//        {
//            value2.pop_back();
//            size3=value2.size();
//        }
//        while(size4>min_size)
//        {
//            value3.pop_back();
//            size4=value3.size();
//        }
//        while(size5>min_size)
//        {
//            value4.pop_back();
//            size5=value4.size();
//        }
}
