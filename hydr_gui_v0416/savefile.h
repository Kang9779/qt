#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QObject>
#include <QFile>
#include <QSqlDatabase>
class SaveFile : public QObject
{
    Q_OBJECT
public:
    explicit SaveFile(QObject *parent = 0);
    SaveFile(QString fileName);
    virtual ~SaveFile();
  //  QSqlDatabase db;
signals:

private slots:
    void saveRealtimeData(QString,QSqlDatabase);

private:
    QFile *file;
    QString fileName_;
};

#endif // SAVEFILE_H
