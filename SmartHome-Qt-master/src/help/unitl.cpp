#include "unitl.h"

bool Unitl::wrieteInit(QString path, QString user_key,
                       QString user_value)
{
    if (path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }else
    {
        //���������ļ���������
        QSettings *settings = new QSettings(path,QSettings::IniFormat);

        //����Ϣд�������ļ�
        settings->beginGroup("config");
        settings->setIniCodec("UTF-8");
        settings->setValue(user_key,user_value);
        settings->endGroup();

        return true;
    }
}

bool Unitl::readInit(QString path, QString user_key,
                     QString &user_value)
{
    user_value = QString("");
    if (path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }else
    {
        //���������ļ���������
        QSettings *settings = new QSettings(path,QSettings::IniFormat);
        settings->setIniCodec("UTF-8");
        user_value = settings->value(QString("config/")+user_key).toString();
        return true;
    }
}
