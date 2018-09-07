#ifndef FAULTDIAGNOSIS_H
#define FAULTDIAGNOSIS_H

#include <vector>
#include <string>

using namespace std;

void calStatistic(const vector<double> &x,vector<double>::size_type start,double &mean,double &stdev);
vector<double> calDifference(const vector<double> &x,const vector<double> &y);

class FaultDiagnosis
{
public:
//    enum Fault{Normal,CylinderInterLeakage,ValveExternalLeakage,BothLeakage,NoSolution};
    FaultDiagnosis();
    FaultDiagnosis(const vector<double> &P1,const vector<double> &P2);

    bool getSensorData(const string &fileName);
    vector<double> getTime();
    vector<double> getPressure1();
    vector<double> getPressure2();
    vector<double> getAx();
    vector<double> getAy();
    vector<double> getDisp();
    vector<double> getFlow();
    int checkPressure();
    int checkPressureDiff();
    int checkPressureZero();
    virtual ~FaultDiagnosis();

private:
    vector<double> time_;
    vector<double> Pp_;
    vector<double> P1_;//有杆腔压力
    vector<double> P2_;//无杆腔压力
    vector<double> Xp_;//液压缸位移
    vector<double> Ax_;//倾角X
    vector<double> Ay_;//倾角Y
    vector<double> Qleak_;//旁路泄漏流量
    int faultID;
};

#endif // FAULTDIAGNOSIS_H
