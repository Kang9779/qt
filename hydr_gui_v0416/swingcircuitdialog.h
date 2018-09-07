#ifndef SWINGCIRCUITDIALOG_H
#define SWINGCIRCUITDIALOG_H

#include <QDialog>

#include <QDateTime>
#include <QTimer>
#include <QLabel>

#include "figurecontrol.h"
#include "clientthread.h"
#include "diagnosis.h"

namespace Ui {
class SwingCircuitDialog;
}

class SwingCircuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwingCircuitDialog(QWidget *parent = 0);
    ~SwingCircuitDialog();

private:
    Ui::SwingCircuitDialog *ui;
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
    QVector<double> ControlVoltage;
    QVector<double> CylinderDisplacement;

private slots:
    void loopMovie();
    void switchPage(int index);
    void getRealtimeData(QString qstr);
    void onRunStopChanged(int run);
    void updatePlot();
    void updatePeriod(QString);
    void startSave();
    void openHistory();
    void evalHealth();
};

#endif // SWINGCIRCUITDIALOG_H
