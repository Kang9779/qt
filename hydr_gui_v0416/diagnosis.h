#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <vector>
#include <string>
#include<QString>
#include <features.h>

using namespace std;
vector<double> calDiff(const vector<double> &x,const vector<double> &y);

class Diagnosis
{
public:
    Diagnosis();
    Diagnosis(const vector<double> &P1,const vector<double> &P2);
    Diagnosis(const vector<double> &P1,const vector<double> &P2,const vector<double> &Xp);
    bool getSensorData(const string &fileName);
    vector<double> getTime();
    vector<double> getPressure1();
    vector<double> getPressure2();
    vector<double> getAx();
    vector<double> getAy();
    vector<double> getAx1();
    vector<double> getAy1();
    vector<double> getAx2();
    vector<double> getAy2();
    vector<double> getDisp();
    vector<double> getFlow();
    QString faultRule();
    virtual ~Diagnosis();


private:
    vector<double> time_;
    vector<double> Pp_;
    vector<double> P1_;//有杆腔压力
    vector<double> P2_;//无杆腔压力
    vector<double> Xp_;//液压缸位移
    vector<double> Ax_;//倾角X
    vector<double> Ay_;//倾角Y
    vector<double> Qleak_;//旁路泄漏流量
    vector<double> Dp_;
    vector<double> Ax1_;//斗杆倾角X
    vector<double> Ay1_;//斗杆倾角Y
    vector<double> Ax2_;//斗杆倾角X
    vector<double> Ay2_;//斗杆倾角Y

    Features P1_feature=Features();
    Features P2_feature=Features();
    Features Dp_feature=Features();

};

#endif // DIAGNOSIS_H
