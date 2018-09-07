/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-05
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�--������ģ���ʵ��
**************************************************/
#include "smokesetting.h"
#include "ui_smokesetting.h"
#include <QToolButton>

SmokeSetting::SmokeSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmokeSetting)
{
    ui->setupUi(this);

    this->initForm();
    this->initConnect();
}

SmokeSetting::~SmokeSetting()
{
    delete ui;
}

void SmokeSetting::refreshSmokeValue()
{
    ui->label_set_smoke->setText(QString::number(m_smoke_density,10) + "%");
}

void SmokeSetting::initForm()
{
    setToolButtonStyle(ui->tbn_smoke_add,tr("add_smoke"),
                       ":/images/module/temp_add.png");
    setToolButtonStyle(ui->tbn_smoke_sub,tr("sub_smoke"),
                       ":/images/module/temp_sub.png");

    m_smoke_density = 10;           //Ԥ������Ũ��ֵ��ʼ��Ϊ10
    refreshSmokeValue();
}


void SmokeSetting::initConnect()
{
    connect(ui->tbn_smoke_add,SIGNAL(clicked()),
            this,SLOT(slot_add_smoke()));
    connect(ui->tbn_smoke_sub,SIGNAL(clicked()),
            this,SLOT(slot_sub_smoke()));
}

void SmokeSetting::setToolButtonStyle(QToolButton *tbn, const QString &text,
                                      const QString iconName)
{
    //������ʾ���ı�
    tbn->setText(text);
    tbn->setFont(QFont("��Ȫ���ź�",10,QFont::Normal));

    tbn->setAutoRaise(true);
    //���ð�ťͼ��
    tbn->setIcon(QPixmap(QString("%1").arg(iconName)));
    tbn->setIconSize(QSize(40,40));
    //�����ı���ͼ���±�
    tbn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void SmokeSetting::slot_add_smoke()
{
    m_smoke_density++;
    refreshSmokeValue();
}

void SmokeSetting::slot_sub_smoke()
{
    m_smoke_density--;
    refreshSmokeValue();
}
