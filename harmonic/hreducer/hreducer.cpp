#include "hreducer.h"
#include "ui_hreducer.h"
#include <QLabel>
#include <QDialog>
HReducer::HReducer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HReducer)
{
    ui->setupUi(this);
    this->setWindowTitle("谐波减速器状态监测平台");
    ui->pushButton->setText(tr("新窗口"));

}

HReducer::~HReducer()
{
    delete ui;
}

void HReducer::on_pushButton_clicked()
{
    QDialog* dlg = new QDialog(this);
    dlg->show();
}
