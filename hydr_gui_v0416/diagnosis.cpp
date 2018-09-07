#include "diagnosis.h"
#include <iostream>
#include <fstream>
#include "math.h"
#include <QTime>
#include <QDateTime>
#include <string>
#include <QDebug>
#include <QString>
#include<features.h>
using namespace std;

const int N=100;
const double Pthreshod=1e-2;
const double dPthreshod=1e-3;
const double Zthreshod=1e-3;
const double Xthreshod=5;//5mm displacement error

Diagnosis::Diagnosis()
{

}

Diagnosis::Diagnosis(const vector<double> &P1, const vector<double> &P2)
                              :P1_(P1),P2_(P2)
{

}
Diagnosis::Diagnosis(const vector<double> &P1,const vector<double> &P2,const vector<double> &Xp)
    :P1_(P1),P2_(P2),Xp_(Xp)
{

}

Diagnosis::~Diagnosis()
{

}

bool Diagnosis::getSensorData(const string &fileName)
{
    ifstream infile(fileName.c_str());
    QString temp1;
    string tempStr;
    QTime tmp;
    QDateTime dt;
    double temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11;
    if(infile.is_open())
    {
        while(infile)
        {
            infile>>tempStr>>temp2>>temp3>>temp4>>temp5>>temp6>>temp7>>temp8>>temp9>>temp10>>temp11;
//            qDebug()<<"Time:"<<temp1<<"P1:"<<temp2<<"P2:"<<temp3<<endl;
            // string类型转QString类型
            temp1=QString::fromStdString(tempStr);
            // QString类型转QTime类型
            // QString类型转QTime类型
            tmp=QTime::fromString(temp1,"h:m:s.z");
            // 用QTime和QDate设置QDataTime
            dt.setTime(tmp);
            time_.push_back(dt.toMSecsSinceEpoch()/1000.0);
            P1_.push_back(temp2);
            P2_.push_back(temp3);
            Xp_.push_back(temp4);
//            qDebug()<<temp5<<endl;
            Ax_.push_back(temp5);
            Ay_.push_back(temp6);
            Ax1_.push_back(temp7);
            Ay1_.push_back(temp8);
            Ax2_.push_back(temp9);
            Ay2_.push_back(temp10);
            Qleak_.push_back(temp11);
            Dp_.push_back(temp2-temp3);
        }
    }
    else
    {
        cerr<<"Could not open the file "<<fileName<<endl;
        return false;
    }
    infile.close();

//    P1_feature=Features(P1_);
//    P2_feature=Features(P2_);
//    Dp_feature=Features(Dp_);
    P1_feature.setSignal(P1_);
    P2_feature.setSignal(P2_);
    Dp_feature.setSignal(Dp_);
    qDebug()<<"数据已存入";
    return true;
}

vector<double> Diagnosis::getTime()
{
    return time_;
}

vector<double> Diagnosis::getPressure1()
{
    return P1_;
}

vector<double> Diagnosis::getPressure2()
{
    return P2_;
}

vector<double> Diagnosis::getAx()
{
    return Ax_;
}

vector<double> Diagnosis::getAy()
{
    return Ay_;
}

vector<double> Diagnosis::getAx1()
{
    return Ax1_;
}

vector<double> Diagnosis::getAy1()
{
    return Ay1_;
}

vector<double> Diagnosis::getAx2()
{
    return Ax2_;
}

vector<double> Diagnosis::getAy2()
{
    return Ay2_;
}

vector<double> Diagnosis::getDisp()
{
    return Xp_;
}

vector<double> Diagnosis::getFlow()
{
    return Qleak_;
}

QString Diagnosis::faultRule()
{   QString fault="";
    P1_feature.FeatureExtract();
    P2_feature.FeatureExtract();
    Dp_feature.FeatureExtract();

    if(P1_feature.getUnchanged() && P2_feature.getUnchanged())
    {
        fault=fault+"液压系统正常\n";
    }else{
        fault=fault+"液压系统异常\n";
    }

    if(Dp_feature.getNearZero())
    {
        fault=fault+"液压缸内泄\n";

    }else{
        fault = fault +"液压缸无内泄\n";

    }
//    qDebug()<<"外泄判断"<<P1_feature.getLessThanZero()<<P2_feature.getLessThanZero();
    if(P1_feature.getLessThanZero()||P2_feature.getLessThanZero())
    {
        fault = fault+"液压缸外泄\n";
    }else{
        fault = fault+"液压缸无外泄\n";
    }

    return fault;

}
