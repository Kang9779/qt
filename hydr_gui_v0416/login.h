#ifndef Login_H
#define Login_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_loginButon_clicked();

    void on_shutdownButton_clicked();

    void updateTime();

private:
    Ui::Login *ui;
    MainWindow *mainWindow;
    QSqlDatabase db;
    QTimer *timer;
};

#endif // Login_H
