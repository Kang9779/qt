#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "armcircuitdialog.h"
#include "boomcircuitdialog.h"
#include "bucketcircuitdialog.h"
#include "swingcircuitdialog.h"
#include "travelcircuitdialog.h"
#include "pumpcircuitdialog.h"
#include <QSqlDatabase>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_BtnArmCircuit_clicked();

    void on_BtnBoomCircuit_clicked();

    void on_BtnBucketCircuit_2_clicked();

    void on_BtnSwingCircuit_clicked();

    void on_BtnTravelCircuit_2_clicked();

    void on_BtnPumpCircuit_clicked();

    void on_BtnTravelCircuit_clicked();

    void on_BtnBucketCircuit_clicked();

    void on_BtnTravelCircuit2_clicked();

    void on_BtnBoomCircuit2_clicked();

    void on_BtnArmCircuit2_clicked();

private:
    Ui::MainWindow *ui;
    ArmCircuitDialog *ArmWindow;
    BoomCircuitDialog *BoomWindow;
    BucketCircuitDialog *BucketWindow;
    SwingCircuitDialog *SwingWindow;
    TravelCircuitDialog *TravelWindow;
    PumpCircuitDialog *PumpWindow;
};

#endif // MAINWINDOW_H
