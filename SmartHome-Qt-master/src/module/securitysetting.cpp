/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-18
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�--�������ģ���ʵ��
**************************************************/
#include "securitysetting.h"
#include "ui_securitysetting.h"

SecuritySetting::SecuritySetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecuritySetting)
{
    ui->setupUi(this);

    this->initForm();
}

SecuritySetting::~SecuritySetting()
{
    delete ui;
}

void SecuritySetting::initForm()
{
       this->setMaximumSize(480,350);
}
