#ifndef MYHELPER_H
#define MYHELPER_H

#include <QtCore>
#include <QtGui>
#include <QDesktopWidget>
#include "frmmessagebox.h"

class myHelper:public QObject
{
public:
    //���ÿ�������
    static void setAutoRunWithSystem(bool isAutoRun,const QString &appName,
                                     const QString &appPath)
    {
        QSettings *reg = new QSettings(
                    "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                    QSettings::NativeFormat);

        if (isAutoRun){
            reg->setValue(appName,appPath);
        }else{
            reg->setValue(appName,"");
        }
    }

    //���ñ��뷽ʽ
    static void setUTF8Code()
    {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
#endif
    }

    //����Ƥ����ʽ
    static void setStyle(const QString &styleName)
    {
        QFile file(QString("%1").arg(styleName));
        file.open(QFile::ReadOnly);
        QString css = QLatin1String(file.readAll());
        qApp->setStyleSheet(css);
    }

    //���������ַ�
    static void setChinese(const QString &fileName)
    {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(QString("%1").arg(fileName));
        qApp->installTranslator(translator);
    }

    //��ʾ��Ϣ�򣬽�ȷ�ϰ�ť
    static void showMessageBoxInfo(const QString &info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info,0);
        msg->exec();
    }

    //��ʾѯ�ʿ�ȷ�Ϻ�ȡ����ť
    static int showMessageBoxQusetion(const QString &info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info,1);
        return msg->exec();
    }

    //��ʾ�����,ȷ�Ϻ�ȡ����ť
    static void showMessageBoxError(const QString &info)
    {
        frmMessageBox *msg = new frmMessageBox;
        msg->SetMessage(info,2);
        msg->exec();
    }

    //��ʱ
    static void sleep(const int &sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while (QTime::currentTime() < dieTime){
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        }
    }

    //���������ʾ
    static void FormInCenter(QWidget *frm,int deskWidth,int deskHeigth)
    {
        int frmX=frm->width();
        int frmY=frm->height();
        QPoint movePoint(deskWidth/2-frmX/2,deskHeigth/2-frmY/2);
        frm->move(movePoint);
    }

    //�ļ����Ƿ����
    static bool FolderIsExist(QString strFolder)
    {
        QDir tempFolder(strFolder);
        return tempFolder.exists();
    }

    //�ļ��Ƿ����
    static bool FileIsExist(QString strFile)
    {
        QFile tempFile(strFile);
        return tempFile.exists();
    }

    //�ж��Ƿ���IP��ַ
    static bool isIpAddress(const QString &ip)
    {
        QRegExp regExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return regExp.exactMatch(ip);
    }

    //16�����ַ���ת�ֽ�����
    static QByteArray HexStrToByteArray(QString str)
    {
        QByteArray senddata;
        int hexdata,lowhexdata;
        int hexdatalen = 0;
        int len = str.length();
        senddata.resize(len/2);
        char lstr,hstr;
        for(int i=0; i<len; )
        {
            hstr=str[i].toLatin1();
            if(hstr == ' ')
            {
                i++;
                continue;
            }
            i++;
            if(i >= len)
                break;
            lstr = str[i].toLatin1();
            hexdata = ConvertHexChar(hstr);
            lowhexdata = ConvertHexChar(lstr);
            if((hexdata == 16) || (lowhexdata == 16))
                break;
            else
                hexdata = hexdata*16+lowhexdata;
            i++;
            senddata[hexdatalen] = (char)hexdata;
            hexdatalen++;
        }
        senddata.resize(hexdatalen);
        return senddata;
    }
    //Conver�ַ���
    static char ConvertHexChar(char ch)
    {
        if((ch >= '0') && (ch <= '9'))
            return ch - 0x30;
        else if((ch >= 'A') && (ch <= 'F'))
            return ch-'A'+10;
        else if((ch >= 'a') && (ch <= 'f'))
            return ch-'a'+10;
        else return (-1);
    }

    //�ֽ�����ת16�����ַ���
    static QString ByteArrayToHexStr(QByteArray data)
    {
        QString temp="";
        QString hex=data.toHex();
        for (int i=0;i<hex.length();i=i+2)
        {
            temp+=hex.mid(i,2)+" ";
        }
        return temp.trimmed().toUpper();
    }

    //16�����ַ���ת10����
    static int StrHexToDecimal(QString strHex)
    {
        bool ok;
        return strHex.toInt(&ok,16);
    }

    //10�����ַ���ת10����
    static int StrDecimalToDecimal(QString strDecimal)
    {
        bool ok;
        return strDecimal.toInt(&ok,10);
    }

    //2�����ַ���ת10����
    static int StrBinToDecimal(QString strBin)
    {
        bool ok;
        return strBin.toInt(&ok,2);
    }

    //16�����ַ���ת2�����ַ���
    static QString StrHexToStrBin(QString strHex)
    {
        uchar decimal=StrHexToDecimal(strHex);
        QString bin=QString::number(decimal,2);

        uchar len=bin.length();
        if (len<8)
        {
            for (int i=0;i<8-len;i++)
            {
                bin="0"+bin;
            }
        }

        return bin;
    }

    //10����ת2�����ַ���һ���ֽ�
    static QString DecimalToStrBin1(int decimal)
    {
        QString bin=QString::number(decimal,2);

        uchar len=bin.length();
        if (len<=8)
        {
            for (int i=0;i<8-len;i++)
            {
                bin="0"+bin;
            }
        }

        return bin;
    }

    //10����ת2�����ַ��������ֽ�
    static QString DecimalToStrBin2(int decimal)
    {
        QString bin=QString::number(decimal,2);

        uchar len=bin.length();
        if (len<=16)
        {
            for (int i=0;i<16-len;i++)
            {
                bin="0"+bin;
            }
        }

        return bin;
    }

    //����У����
    static uchar GetCheckCode(uchar data[],uchar len)
    {
        uchar temp=0;

        for (uchar i=0;i<len;i++)
        {
            temp+=data[i];
        }

        return temp%256;
    }

    //�������charתΪ��ȷ��uchar
    static uchar GetUChar(char data)
    {
        uchar temp;
        if (data>127)
        {
            temp=data+256;
        }
        else
        {
            temp=data;
        }
        return temp;
    }

    //��ʱ
    static void Sleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    //��ȡ��ǰ·��
    static QString GetCurrentPath()
    {
        return QString(QCoreApplication::applicationDirPath()+"/");
    }

    //��������
    static void PlaySound(QString soundName)
    {
        QSound::play(soundName);
    }
};

#endif
