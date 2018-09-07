#include "faultdiagnosis.h"
#include <iostream>
#include <fstream>
#include "math.h"
#include <QTime>
#include <QDateTime>

#include <QDebug>

using namespace std;

const int N=100;
const double Pthreshod=1e4;
const double dPthreshod=1e5;
const double Zthreshod=1e3;


FaultDiagnosis::FaultDiagnosis()
{

}

FaultDiagnosis::FaultDiagnosis(const vector<double> &P1, const vector<double> &P2)
                              :P1_(P1),P2_(P2)
{

}

bool FaultDiagnosis::getSensorData(const string &fileName)
{
    ifstream infile(fileName.c_str());
    QString temp1;
    string tempStr;
    QTime tmp;
    QDateTime dt;
    double temp2,temp3,temp4,temp5,temp6,temp7;
    if(infile.is_open())
    {
        while(infile)
        {
            infile>>tempStr>>temp2>>temp3>>temp4>>temp5>>temp6>>temp7;
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
            Ax_.push_back(temp5);
            Ay_.push_back(temp6);
            Qleak_.push_back(temp7);
        }
    }
    else
    {
        cerr<<"Could not open the file "<<fileName<<endl;
        return false;
    }
    infile.close();
    return true;
}

vector<double> FaultDiagnosis::getTime()
{
    return time_;
}

vector<double> FaultDiagnosis::getPressure1()
{
    return P1_;
}

vector<double> FaultDiagnosis::getPressure2()
{
    return P2_;
}

vector<double> FaultDiagnosis::getAx()
{
    return Ax_;
}

vector<double> FaultDiagnosis::getAy()
{
    return Ay_;
}

vector<double> FaultDiagnosis::getDisp()
{
    return Xp_;
}

vector<double> FaultDiagnosis::getFlow()
{
    return Qleak_;
}

FaultDiagnosis::~FaultDiagnosis()
{

}

int FaultDiagnosis::checkPressure()
{
    int flag=1;
    vector<double>::size_type start=100;
    double mean1,mean2,stdev1,stdev2;
    calStatistic(P1_,start,mean1,stdev1);
    while(start<P1_.size()-N)
    {
        calStatistic(P1_,start,mean2,stdev2);
        if(abs(mean1-mean2)<Pthreshod&&abs(stdev1-stdev2)<Pthreshod)
        {
            mean1=mean2;
            stdev1=stdev2;
        }
        else
        {
            cout<<"Fault detected! Go and check the pressure difference."<<endl;
            return 0;
        }
        start+=N;
    }
    cout<<"The cylinder and the valve is normal"<<endl;
    return flag;
}

int FaultDiagnosis::checkPressureDiff()
{
    int flag=2;
    vector<double> dP=calDifference(P1_,P2_);
    vector<double>::size_type start=100;
    double mean1,mean2,stdev1,stdev2;
    calStatistic(dP,start,mean1,stdev1);
    while(start<dP.size()-N)
    {
        calStatistic(dP,start,mean2,stdev2);
        if(mean1>=mean2)
        {
            mean1=mean2;
        }
        else
        {
            if(mean2>dPthreshod)
            {
                cout<<"Fault detected! Go and check the pressure P2."<<endl;
                return 0;
            }
        }
        start+=N;
    }
    cout<<"The cylinder has internal leakage"<<endl;
    return flag;
}

int FaultDiagnosis::checkPressureZero()
{
    int flag=3;
    vector<double>::size_type start=100;
    double mean1,mean2,stdev1,stdev2;
    calStatistic(P2_,start,mean1,stdev1);
    while(start<P2_.size()-N)
    {
        calStatistic(P2_,start,mean2,stdev2);
        if(mean1>=mean2)
        {
            mean1=mean2;
        }
        else
        {
            if(mean2>Zthreshod)
            {
                cout<<"The cylinder and the valve both have internal leakage"<<endl;
                return 4;
            }
        }
        start+=N;
    }
    cout<<"The valve has internal leakage"<<endl;
    return flag;
}

vector<double> calDifference(const vector<double> &x, const vector<double> &y)
{
    vector<double> delta;
    if(x.size()==y.size())
        for(vector<double>::size_type i=0;i!=x.size();++i)
            delta.push_back(x[i]-y[i]);
    else
        cerr<<"The size of the two array is not equal"<<endl;
    return delta;
}

void calStatistic(const vector<double> &x,vector<double>::size_type start,double &mean, double &stdev)
{
    double sum=0.0;
    for(vector<double>::size_type i=start;i!=start+N;++i)
        sum+=x[i];
    mean=sum/N;
    double accum=0.0;
    for(vector<double>::size_type i=start;i!=start+N;++i)
        accum+=(x[i]-mean)*(x[i]-mean);
    stdev=sqrt(accum/(N-1));
//    qDebug()<<"mean:"<<mean<<"Standard deveration:"<<stdev<<endl;
}
