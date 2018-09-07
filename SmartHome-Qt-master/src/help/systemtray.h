#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QSystemTrayIcon>

class QAction;
class QMemu;
class QSystemTrayIcon;
class QWidget;
class QWidgetAction;
class QPushButton;
class QLabel;
class QHBoxLayout;
class QPainter;

class mySwitchButton;

class SystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTray(QObject *parent = 0);

    void translateActions();    //����˵�����

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    
signals:
    void signal_close();
public slots:

private:
    void initTopAction();
    void initMidAction();
    void initBottomAction();
    void initAction();
    void addActions();
    void initConnect();

private:

    QMenu* m_trayMenu;                      //ϵͳ����

    QWidget* m_topWidget;                   //�����˵�
    QWidgetAction* m_topWidgetAction;       //��������action
    QLabel* m_topLabel;                     //˵����Ϣ
    QLabel* m_homeBtn;                      //������Ϣ,���Խ�����ת���Զ����web

    QWidget* m_bottomWidget;                //�ײ��˵�
    QWidgetAction* m_bottomWidgetAction;    //�ײ�����action
    QPushButton* m_updateBtn;               //�������
    QPushButton* m_aboutBtn;                //��������
    QPushButton* m_exitBtn;                 //�˳�

    QWidget *m_midWidget;                   //�м�˵�
    QWidgetAction *m_midWidgetAction;       //�м����action
    QLabel *m_autobackupLabel;
    QLabel *m_autoStartLabel;
    mySwitchButton *m_autobackupBtn;        //�Զ�����
    mySwitchButton *m_autoStartBtn;         //��������

    QAction* m_runOnSystemBoot;             //��������
    QAction* m_helpOnline;                  //���߰���
    QAction* m_homePage;                    //��ҳ
    QAction* m_notification;                //
    QAction* m_settings;                    //����
    
};

#endif // SYSTEMTRAY_H
