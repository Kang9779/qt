/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-07
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�--ͳ��ģ���ʵ��
**************************************************/

#include "statisticssetting.h"
#include "ui_statisticssetting.h"
#include "control.h"


StatisticsSetting::StatisticsSetting(enum_statistic_title title, QWidget *parent) :
    QWidget(parent),ui(new Ui::StatisticsSetting),m_title_name(title)
{
    ui->setupUi(this);

    initForm();
    initPlotForm();
    initConnect();
}

StatisticsSetting::~StatisticsSetting()
{
    delete ui;
}

/**
 * @Function:       setShowData(const QStringList &data)
 * @Description:    ������ʾ�����ݣ����ڻ�ͼ���������
 * @Calls:          �ⲿ����
 * @Input:          ����
 * @Output:         ��
 * @Return:         ��
 * @Others:         ����˵��
 */
void StatisticsSetting::setShowData(const QStringList &data)
{
    plot_data = data;
    currentCount = plot_data.length();
    ui->labInfo->setText(tr("total ")+QString("%1").arg(currentCount)+tr(" data"));
    LoadPlot();
}

void StatisticsSetting::initForm()
{
    if (m_title_name == ENUM_TEMPTURE)
        ui->label_title->setText(tr("temp_statistic"));
    else if (m_title_name == ENUM_SMOKE_DENSITY)
        ui->label_title->setText(tr("smoke_statistic"));
    else if (m_title_name == ENUM_HUMIDITY_DENSITY)
        ui->label_title->setText(tr("humidity_statistic"));
}

void StatisticsSetting::initConnect()
{
    //�����ƶ�
    connect(ui->ckMove,SIGNAL(stateChanged(int)),
            this,SLOT(slot_movePlot(int)));
    //���Y������
    connect(ui->ckXGrid,SIGNAL(stateChanged(int)),
            this,SLOT(slot_addXGrid(int)));
    //���X������
    connect(ui->ckYGrid,SIGNAL(stateChanged(int)),
            this,SLOT(slot_addYGrid(int)));
    //������Ӱ
    connect(ui->ckBackground,SIGNAL(stateChanged(int)),
            this,SLOT(slot_startBackground(int)));
    //ͼ��
    connect(ui->ckText,SIGNAL(stateChanged(int)),
            this,SLOT(slot_showLegend(int)));
}

void StatisticsSetting::initPlotForm()
{
    xTickCount = 5;
    yTickCount = 5;
    currentCount = 10;   //���������ֵ
    currentColor = 0;

    Plot_DotColor.append(QColor(5, 189, 251));
    Plot_LineColor.append(QColor(41, 138, 220));    //�ߵ���ɫ--��ɫ
    Plot_BGColor.append(QColor(41, 138, 220, 80));

    Plot_DotColor.append(QColor(236, 110, 0));
    Plot_LineColor.append(QColor(246, 98, 0));      //�ߵ���ɫ--�ٻ�ɫ
    Plot_BGColor.append(QColor(246, 98, 0, 80));

    Plot_DotColor.append(QColor(255, 127, 0));
    Plot_LineColor.append(QColor(255, 139, 0));     //�ߵ���ɫ--�ٻ�ɫ-ǳ
    Plot_BGColor.append(QColor(255, 139, 0, 80));

    Plot_DotColor.append(QColor(255, 0, 254));
    Plot_LineColor.append(QColor(255, 52, 178));
    Plot_BGColor.append(QColor(255, 52, 178, 80));

    Plot_DotColor.append(QColor(254, 0, 0));
    Plot_LineColor.append(QColor(255, 48, 48));
    Plot_BGColor.append(QColor(255, 48, 48, 80));

    Plot_DotColor.append(QColor(229, 230, 250));
    Plot_LineColor.append(QColor(237, 237, 237));
    Plot_BGColor.append(QColor(237, 237, 237, 80));

    Plot_DotColor.append(QColor(106, 139, 34));
    Plot_LineColor.append(QColor(106, 142, 34));
    Plot_BGColor.append(QColor(106, 142, 34, 80));

    //��������������
    if (m_title_name == ENUM_TEMPTURE)
        ui->plot->yAxis->setLabel(tr("unit_temp"));
    else if (m_title_name == ENUM_SMOKE_DENSITY)
        ui->plot->yAxis->setLabel(tr("unit_smoke"));
    else if (m_title_name == ENUM_HUMIDITY_DENSITY)
        ui->plot->yAxis->setLabel(tr("unit_hum"));

    ui->plot->xAxis->setLabel(tr("week"));

    //����������ɫ/����������ɫ
    ui->plot->yAxis->setLabelColor(TextColor);          //Y������Ϊ��ɫ
    ui->plot->xAxis->setLabelColor(TextColor);          //X������Ϊ��ɫ
    ui->plot->xAxis->setTickLabelColor(TextColor);      //X����Ϊ��ɫ
    ui->plot->yAxis->setTickLabelColor(TextColor);
    ui->plot->xAxis->setBasePen(QPen(TextColor, TextWidth));
    ui->plot->yAxis->setBasePen(QPen(TextColor, TextWidth));
    ui->plot->xAxis->setTickPen(QPen(TextColor, TextWidth));
    ui->plot->yAxis->setTickPen(QPen(TextColor, TextWidth));
    ui->plot->xAxis->setSubTickPen(QPen(TextColor, TextWidth));
    ui->plot->yAxis->setSubTickPen(QPen(TextColor, TextWidth));

    //���û�������ɫ
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));//��ɫ
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->plot->setBackground(plotGradient);

    //�������걳��ɫ
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->plot->axisRect()->setBackground(axisRectGradient);

    //����ͼ����ʾλ�ü�����ɫ
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    ui->plot->legend->setBrush(QColor(255, 255, 255, 200));

    ui->plot->addGraph();

    if (m_title_name == ENUM_TEMPTURE)
        ui->plot->graph(0)->setName(tr("graph_temp"));
    else if (m_title_name == ENUM_SMOKE_DENSITY)
        ui->plot->graph(0)->setName(tr("graph_smoke"));
    else if (m_title_name == ENUM_HUMIDITY_DENSITY)
        ui->plot->graph(0)->setName(tr("graph_hum"));

    //���þ�̬���ߵĺ����귶Χ������Ӧ������
    ui->plot->xAxis->setRange(0, currentCount + 1, Qt::AlignLeft);
    ui->plot->yAxis->setRange(0,100);
    ui->plot->xAxis->setAutoTickCount(xTickCount);
    ui->plot->yAxis->setAutoTickCount(yTickCount);
    ui->plot->graph(0)->rescaleAxes();              //����Ӧ��ʾ��Χ
    ui->plot->replot();                             //�ػ�
}

qint16 StatisticsSetting::StrHexToShort(QString strHex)
{
    bool ok;
    return strHex.toUShort(&ok, 16);
}

void StatisticsSetting::LoadPlot()
{
    plot_keys.clear();
    plot_values.clear();

    //����ǻ��������򳤶�Ҫ-1
    if (currentCount % 2 != 0)
    {
        currentCount--;
    }

    for (int i = 0; i < currentCount / 2; i++)
    {
        plot_keys.append(i);
    }
    for (int i = 0; i < currentCount; i = i + 2)
    {
        qint16 value = StrHexToShort(QString("%1%2").arg(plot_data[i]).arg(plot_data[i + 1]));
#if QDEBUG
        qDebug() << plot_data[i] << plot_data[i + 1] << value << i << currentCount;
#endif
        plot_values.append(value);
    }
    //�����������
    ui->plot->graph(0)->setData(plot_keys, plot_values);

    ui->plot->xAxis->setAutoTickCount(xTickCount);
    ui->plot->yAxis->setAutoTickCount(yTickCount);
    ui->plot->graph(0)->rescaleAxes();
    ui->plot->replot();
}

//�����ƶ�
void StatisticsSetting::slot_movePlot(int arg)
{
    bool value = (arg == 0 ? false : true);
    if (value) {
        ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    } else {
        ui->plot->setInteractions(QCP::iSelectOther);
    }
    ui->plot->replot();
}

//���X������
void StatisticsSetting::slot_addXGrid(int arg)
{
    bool value = (arg == 0 ? false : true);
    ui->plot->xAxis->grid()->setSubGridVisible(value);
    ui->plot->replot();
}

//���Y������
void StatisticsSetting::slot_addYGrid(int arg)
{
    bool value = (arg == 0 ? false : true);
    ui->plot->yAxis->grid()->setSubGridVisible(value);
    ui->plot->replot();
}

//����������Ӱ
void StatisticsSetting::slot_startBackground(int arg)
{
    bool value = (arg == 0 ? false : true);
    if (value) {
        ui->plot->graph(0)->setBrush(QBrush(Plot_BGColor[currentColor]));
    } else {
        ui->plot->graph(0)->setBrush(QBrush(Plot_NoColor));
    }
    ui->plot->replot();
}

//ͼ����ʾ
void StatisticsSetting::slot_showLegend(int arg)
{
    bool value = (arg == 0 ? false : true);
    ui->plot->legend->setVisible(value);
    ui->plot->replot();
}
