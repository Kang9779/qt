/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-08-25
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�---������ʵ��
**************************************************/
#ifndef CURTAINSETTING_H
#define CURTAINSETTING_H

#include <QWidget>

namespace Ui {
class CurtainSetting;
}

class CurtainSetting : public QWidget
{
    Q_OBJECT
    
public:
    explicit CurtainSetting(QWidget *parent = 0);
    ~CurtainSetting();

private:
    void initForm();            //��ʼ����ʽ
    void initConnect();         //��ʼ���źźͲ۵�����
    
private:
    Ui::CurtainSetting *ui;
};

#endif // CURTAINSETTING_H
