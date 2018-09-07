#ifndef ARMCIRCUITDIALOG_H
#define ARMCIRCUITDIALOG_H

#include <QDialog>
#include <QDateTime>
#include <QTimer>
#include <QLabel>
#include "figurecontrol.h"
#include "clientthread.h"
#include "diagnosis.h"
#include "qcustomplot.h"
#include "qcustomlabel.h"
//#include "faultdiagnosis.h"
#include <QVector>
#include <string>
#include "setsensor.h"


namespace Ui {
class ArmCircuitDialog;
}

class ArmCircuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArmCircuitDialog(QWidget *parent = 0);
    ~ArmCircuitDialog();
    void addGraph(QCustomPlot *customPlot,QString title);
    void setPlot(QCustomPlot *customPlot);
    void setRealtimePlot(QCustomPlot *customPlot);
    void setCustomGraph(QCPGraph *graph);

private:
    Ui::ArmCircuitDialog *ui;
    QMovie *movie;




    FigureControl *pressCtrl1;
    FigureControl *pressCtrl2;
    FigureControl *pressCtrl3;
    FigureControl *pressCtrl4;
    FigureControl *pressCtrl5;
    FigureControl *dispCtrl;

    ClientThread *clientThread;
    QThread *fileThread;
    QTimer *dateTimer;
    QCalendarWidget *calendar;

    Diagnosis faultDetector;
    QVector<double> time_stramp;
    QVector<double> PumpPressure;
    QVector<double> CylinderPressureA;
    QVector<double> CylinderPressureB;
    QVector<double> CylinderAx;
    QVector<double> CylinderAy;
    QVector<double> ControlVoltage;
    QVector<double> CylinderDisplacement;
    //杨
    QVector<double> CylinderPressureA1;
     QCustomPlot *figure1;
     QCustomPlot *figure2;
     QCustomPlot *figure3;
     QCustomPlot *figure4;
     QCustomPlot *figure5;
     QListWidgetItem *figureItem1;
     QListWidgetItem *figureItem2;// 动臂无杆腔压力P2绘图
     QListWidgetItem *figureItem3;// 动臂液压缸位移x绘图
     QListWidgetItem *figureItem4;// X轴倾角绘图(动臂)
     QListWidgetItem *figureItem5;// Y轴倾角绘图(动臂)
      SetSensor *sensor1=new SetSensor(this);
      SetSensor *sensor2=new SetSensor(this);
      SetSensor *sensor3=new SetSensor(this);
      SetSensor *sensor4=new SetSensor(this);
      SetSensor *sensor5=new SetSensor(this);
private slots:
    void loopMovie();
    void switchPage(int index);
    void getRealtimeData(QString);
    void onRunStopChanged(int run);
    void updatePlot();
    void updatePeriod(QString);
    void startSave();
    void openHistory();
    void evalHealth();

    //杨
     void displaySensor1(bool);
     void displaySensor2(bool);
     void displaySensor3(bool);
     void displaySensor4(bool);
     void displaySensor5(bool);
};

#endif // ARMCIRCUITDIALOG_H
