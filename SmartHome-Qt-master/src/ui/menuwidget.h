/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-01-28
Description:���ܼҾ�ϵͳ------�˵���ʵ��
**************************************************/
#ifndef MENUWIDGET_H
#define MENUWIDGET_H
#include <QAction>
#include <QMenu>

class MenuWidget : public QMenu
{
public:
    MenuWidget(QWidget *parent = 0);
    ~MenuWidget();

private:
    void initForm();
    void initMenu();
    void initConnect();

signals:
    void signalSetting();
    void signalQuit();

private:
    QAction *m_actionSetting;
    QAction *m_actionQuit;

};

#endif // MENUWIDGET_H
