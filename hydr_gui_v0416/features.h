#ifndef FEATURES_H
#define FEATURES_H

#include <vector>
#include <string>
#include<QString>


using namespace std;

void calStat(const vector<double> &x,vector<double>::size_type start,double &mean,double &stdev);
vector<double> calDiff(const vector<double> &x,const vector<double> &y);
vector<double> calabs(const vector<double> &x);

class Features
{
public:
    Features();
    Features(const vector<double> &P);

    void FeatureExtract();

    void setChangeThreshold(double t);
    void setZeroThrethold(double t);
    void setSignal(const vector<double> &P);
    bool getUnchanged();
    bool getIncrease();
    bool getDecrease();
    bool getNearZero();
    bool getAbsIncrs();
    bool getAbsDecrs();
    bool getLessThanZero();
    virtual ~Features();

private:
    int N=100;
    double changeThreshold=1e-2;
    double Zthreshold=2e-2;
    double Xthreshold=5;//5mm displacement error

    vector<double> testSignal;

    bool unchanged=false;
    bool increase=false;
    bool decrease=false;
    void Check_change();//unchanged,increase,decrease

    bool nearZero=false;
    void Check_nearzero();

    bool absincrease=false;
    bool absdecrease=false;
    void Check_abschange();

    bool lessThanZero=false;
    void Check_lessThanZero();

};

#endif // FEATURES_H
