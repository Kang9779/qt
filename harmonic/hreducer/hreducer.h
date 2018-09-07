#ifndef HREDUCER_H
#define HREDUCER_H

#include <QMainWindow>

namespace Ui {
class HReducer;
}

class HReducer : public QMainWindow
{
    Q_OBJECT

public:
    explicit HReducer(QWidget *parent = 0);
    ~HReducer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HReducer *ui;
};

#endif // HREDUCER_H
