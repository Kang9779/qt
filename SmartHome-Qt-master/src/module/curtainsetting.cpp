/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-08-25
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�---������ʵ��
**************************************************/
#include "curtainsetting.h"
#include "ui_curtainsetting.h"

CurtainSetting::CurtainSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurtainSetting)
{
    ui->setupUi(this);

    this->initForm();
}

CurtainSetting::~CurtainSetting()
{
    delete ui;
}

void CurtainSetting::initForm()
{
}

void CurtainSetting::initConnect()
{
}
