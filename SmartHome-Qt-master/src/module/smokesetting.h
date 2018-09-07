/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-05
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�--������ģ���ʵ��
**************************************************/
#ifndef SMOKESETTING_H
#define SMOKESETTING_H

#include <QWidget>
class QToolButton;

namespace Ui {
class SmokeSetting;
}

class SmokeSetting : public QWidget
{
    Q_OBJECT
    
public:
    explicit SmokeSetting(QWidget *parent = 0);
    ~SmokeSetting();

    void refreshSmokeValue();       //ˢ������Ũ��ֵ

private:
    void initForm();                //��ʽ��ʼ��
    void initConnect();             //��ʼ���źźͲ۵�����

    //���ð�ť��ʽ
    void setToolButtonStyle(QToolButton*tbn, const QString &text,
                            const QString iconName);

private slots:
    void slot_add_smoke();
    void slot_sub_smoke();
    
private:
    Ui::SmokeSetting *ui;

    int m_smoke_density;            //Ԥ������Ũ��ֵ
};

#endif // SMOKESETTING_H
