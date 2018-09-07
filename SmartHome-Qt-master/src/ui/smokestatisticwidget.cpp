/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-07
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ܼҾ�--����Ũ�ȵ�ͳ��
**************************************************/
#include "smokestatisticwidget.h"
#include "control.h"
#include "statisticssetting.h"
#include <QVBoxLayout>

SmokeStatisticWidget::SmokeStatisticWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initForm();
}

SmokeStatisticWidget::~SmokeStatisticWidget()
{
}

void SmokeStatisticWidget::initForm()
{
    m_statistic = new StatisticsSetting(ENUM_SMOKE_DENSITY,this);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_statistic);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setLayout(m_mainLayout);

    m_dataList = QString("DB 30 0F 33 03 63 05 8B 09 30 65 04").split(" ");

    m_statistic->setShowData(m_dataList);
}
