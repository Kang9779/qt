#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMenu>

class MainMenu : public QMenu
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);

    void translateActions();
    
signals:
   void showSettingDialog();
   void showCheckUpdateDialog();
   void showAboutUs();
   void signal_quit();
    
private:
    void createActions();
    void createConnect();

private:

    QAction *action_setting;        //����
    QAction *action_help;           //����
    QAction *action_home;           //��վ��ҳ
    QAction *action_check_update;   //�쳵����
    QAction *action_about_us;       //��������
    QAction *action_contract_author;//��ϵ����
    QAction *action_quit;           //�˳�
    
};

#endif // MAINMENU_H
