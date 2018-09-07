#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QVector>
#include <string>
#include <QSqlDatabase>
using namespace std;

class ClientThread: public QThread
{
    Q_OBJECT
public:
    ClientThread();
    QSqlDatabase db;
protected:
    void run();

private slots:
    void displayConnection();

    void displayError(QAbstractSocket::SocketError);

    void getTcpData();

private:
    QTcpSocket *tcpSocket;

signals:
    void dataAcquired(QString,QSqlDatabase);

// 数据分割和格式转化,2017-7-14
public:
    void dataConvert(QString qstr,QVector<double> &timeStramp,
                     QVector<double> &value1,QVector<double> &value2,
                     QVector<double> value3,QVector<double> value4);
};

#endif // CLIENTTHREAD_H
