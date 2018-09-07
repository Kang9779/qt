#include "savefile.h"
#include <iostream>
#include <QTextStream>
#include <QThread>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
using namespace std;

SaveFile::SaveFile(QObject *parent) : QObject(parent)
{

}

SaveFile::SaveFile(QString fileName)
{
    fileName_=fileName;
    file=new QFile(fileName,this);
    if(!file->open(QIODevice::WriteOnly))
    {
        cerr<<"Can not open file "<<fileName_.toStdString().c_str()<<" for writing"<<endl;
    }
}

SaveFile::~SaveFile()
{
    file->close();
}

void SaveFile::saveRealtimeData(QString dataStr,QSqlDatabase db)
{
    qDebug()<<"Saving file thread is : "<<QThread::currentThreadId();
    //保存所有数据
    string str=dataStr.toStdString();
    QTextStream out(file);

    QSqlQuery query;
    QString strfordb;
    int startpoint=0;
    int endpoint=0;
    int strlgth;
    string subs1,subs2,subs3,subs4,subs5,subs6,subs7,subs8,
            subs9,subs10,subs11,subs12,subs13,subs14,subs15,subs16;

    for(auto c:str)
    {

        if(c=='@'){
            strlgth = endpoint-startpoint;
            int chnlNumber=atoi(str.substr(startpoint,2).c_str())-10;
            string subs=str.substr(startpoint+3,strlgth-3);
            startpoint=endpoint+1;
            switch (chnlNumber) {
            case 1:
//                subs1.push_back(atof(subs.c_str()));
                subs1=subs;
                break;
             case 2:
//                subs2.push_back(atof(subs.c_str()));
                subs2=subs;
                 break;
            case 3:
                  subs3=subs;
//               subs3.push_back(atof(subs.c_str()));
                break;
            case 4:
                  subs4=subs;
//               subs4.push_back(atof(subs.c_str()));
                break;
            case 5:
                  subs5=subs;
//               subs5.push_back(atof(subs.c_str()));
                break;
            case 6:
                  subs6=subs;
//               subs6.push_back(atof(subs.c_str()));
                break;
            case 7:
                  subs7=subs;
//               subs6.push_back(atof(subs.c_str()));
                break;
            case 8:
                  subs8=subs;
//               subs6.push_back(atof(subs.c_str()));
                break;
            case 9:
                  subs9=subs;
//               subs6.push_back(atof(subs.c_str()));
                break;
            case 10:
                  subs10=subs;
//               subs6.push_back(atof(subs.c_str()));
                break;
            case 11:
                  subs11=subs;
                break;
            case 12:
                  subs12=subs;
                break;
            case 13:
                subs13=subs;
              break;
            case 14:
                subs14=subs;
              break;
            case 15:
                  subs15=subs;
                break;
            case 16:
                  subs16=subs;
//               subs7.push_back(atof(subs.c_str()));
               if(subs1.c_str()!="" && subs1.length()>5)
               {
                   qDebug()<<db.isOpen();
             strfordb=QString("insert into testdb (mytime,p1,p2,X1,"
                               "p3,p4,X2,p5,p6,X3) values(now(),%1,%2,%3,%4,%5,%6,%7,%8,%9)").arg(QString::fromStdString(subs2)).arg(QString::fromStdString(subs3))
                      .arg(QString::fromStdString(subs4)).arg(QString::fromStdString(subs4)).arg(QString::fromStdString(subs5)).arg(QString::fromStdString(subs9))
                     .arg(QString::fromStdString(subs7)).arg(QString::fromStdString(subs8)).arg(QString::fromStdString(subs14));
//              //  qDebug()<< query.exec(" insert into student (tine,id,score) values(now(),,11)");
               // strfordb = QString("insert into ")
 //                   QString strfordb = QString("INSERT INTO `sensorforytc`(`sid`, `mid`, `dgwp`, `dgwy`, `dgyp`, `date`, `dbyp`, `dbwp`, `dbwy`, `dgY`, `dgX`, `cdyP`, `dbY`, `dbX`, `cdX`, `cdY`, `location`, `cdwy`, `cdwp`) VALUES (1,2,3,4,5,now(),7,8,9,0,1,2,3,4,5,6,7,8,9)");
                   qDebug()<< query.exec(strfordb);
                //   qDebug()<< strfordb;

                //   out<<subs1.c_str()<<" "<<subs2.c_str()<<" "<<subs3.c_str()<<" "<<subs4.c_str()<<" "<<subs5.c_str()<<" "<<subs6.c_str()<<" "<<subs7.c_str()<<" "<<subs8.c_str()<<" "<<subs9.c_str()<<" "<<subs10.c_str()<<" "<<subs11.c_str()<<"\n";
               }
                   break;
            default:
                break;
            }

            }
            endpoint+=1;
    }
//    for(auto c:str)
//    {
//        if(c=='#')
//        {
//            startpoint = endpoint+1;
//        }

//        if(c=='@')
//        {
//            strlgth = endpoint-startpoint;
//            subs1=str.substr(startpoint,strlgth);
//            startpoint = endpoint+1;
//        //    out<<subs1.c_str()<<" ";
//        }
//        if(c==',')
//        {
//            strlgth = endpoint-startpoint+1;
//            subs2=str.substr(startpoint,strlgth-1);
//            startpoint = endpoint+1;
//          //  out<<subs2.c_str()<<" ";
//        }
//        if(c=='!')
//        {
//            strlgth = endpoint-startpoint+1;
//            subs3=str.substr(startpoint,strlgth-1);
//            startpoint = endpoint+1;
//          //  out<<subs2.c_str()<<" ";
//        }
//        if(c=='@')
//        {
//            strlgth = endpoint-startpoint+1;
//            subs4=str.substr(startpoint,strlgth-1);
//            startpoint = endpoint+1;
//          //  out<<subs2.c_str()<<" ";
//        }

//        if(c==';')
//        {
//            strlgth = endpoint-startpoint+1;
//            subs5=str.substr(startpoint,strlgth-1);
//            startpoint = endpoint+1;
//            out<<subs1.c_str()<<" "<<subs2.c_str()<<" "<<subs3.c_str()<<" "<<subs4.c_str()<<" "<<subs5.c_str()<<"\n";
//        }


//        endpoint+=1;
//    }
//    QTextStream out(file);
//    QString temStr,temPer,temComa;
//    QString time,data1,data2;
//    while(dataStr.s)
//    {
//        QTextStream(&dataStr)<<temStr;
//        if(temStr==";")
//        {
//            QTextStream(&dataStr)<<time<<temPer<<data1<<temComa<<data2;
//            out<<time<<data1<<data2;
//        }
//        if(temStr=="")
//            break;
//    }
}
