#ifndef SKINMENU_H
#define SKINMENU_H

#include <QMenu>

class SkinMenu : public QMenu
{
    Q_OBJECT
public:
    explicit SkinMenu(QWidget *parent = 0);
    
     void translateActions();
signals:
    
public slots:
     void setWidgetSkin();     //���ý���Ƥ��

private:
    void initActions();
    void initConnect();
private:
    QAction *m_action_blue;     //��ɫƤ��
    QAction *m_action_navy;     //����ɫ
    QAction *m_action_black;    //��ɫƤ��
    QAction *m_action_gray;     //��ɫƤ��
    
};

#endif // SKINMENU_H
