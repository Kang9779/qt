#ifndef TRAVELCIRCUITDIALOG_H
#define TRAVELCIRCUITDIALOG_H

#include <QDialog>

namespace Ui {
class TravelCircuitDialog;
}

class TravelCircuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TravelCircuitDialog(QWidget *parent = 0);
    ~TravelCircuitDialog();

private:
    Ui::TravelCircuitDialog *ui;
    QMovie *movie;

private slots:
    void loopMovie();
};

#endif // TRAVELCIRCUITDIALOG_H
