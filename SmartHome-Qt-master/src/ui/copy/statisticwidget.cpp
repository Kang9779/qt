/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-07
Email:kevinlq0912@163.com
QQ:936563422
Description:���ܼҾ�--ͳ��ģ���ʵ��
            �¶�ͳ�ơ�ʪ��ͳ�ơ�����Ũ��ͳ��
**************************************************/
#include "statisticwidget.h"
#include "ui_statisticwidget.h"
#include  "control.h"
#include "sqlhelp.h"
#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>

//������Ҫ���Ƶĵ���
#define MAX_POINT_NUM   18

//���������ֵ
#define PLOT_TEMPTURE_MAX_Y         100     //�¶�ֵ
#define PLOT_HUMIDITY_MAX_Y         100     //ʪ��ֵ
#define PLOT_SMOKE_MAX_Y            100   //����Ũ��ֵ

#define TextColor QColor(255,255,0)         //��ɫ
#define Plot_NoColor QColor(0,0,0,0)        //��ɫ

#define Plot1_DotColor QColor(5,189,251)
#define Plot1_LineColor QColor(41,138,220)
#define Plot1_BGColor QColor(41,138,220,80)

#define Plot2_DotColor QColor(236,110,0)
#define Plot2_LineColor QColor(246,98,0)
#define Plot2_BGColor QColor(246,98,0,80)

#define Plot3_DotColor QColor(204,0,0)
#define Plot3_LineColor QColor(246,0,0,200)
#define Plot3_BGColor QColor(246,98,0,80)

#define Plot1_Count 12
#define Plot2_Count 10

#define Plot1_MaxY 50
#define Plot2_MaxY 100
#define Plot3_MaxY 500
#define Plot4_MaxY 100

#define TextWidth 1
#define LineWidth 2
#define DotWidth  10

#define Plot2_LineWidth 1
#define Plot2_DotWidth  2

#ifdef _ARM_
#define Plot5_MaxY 20
#else
#define Plot5_MaxY 50
#endif


StatisticWidget::StatisticWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticWidget)
{
    ui->setupUi(this);

    initForm();
    initStyle();
    initPlot();

    initPlotTempture();
    initPlotHumidity();
    initPlotSmoke();

    loadPlotTempture();
    loadPlotHumidity();
    loadPlotSmoke();

//    initData();

    initConnect();
}

StatisticWidget::~StatisticWidget()
{
    delete ui;
    if (m_sqlhelp != NULL)
    {
        delete m_sqlhelp;
        m_sqlhelp = NULL;
    }
}

void StatisticWidget::loadPlotTempture()
{
    //ÿ���ӻ���һ������
    QStringList value_list,data_list;
    QString sql = "SELECT [device_value],[device_data]  FROM [device_info] WHERE [device_id]='01'";
    QString currrent_time = "20160401174000";
    QString start_time;
    quint8 hour,minute;
    hour = currrent_time.mid(8,2).toUInt();
    minute = currrent_time.mid(10,2).toUInt();
    //��Ϊ������Ҫ����12���㣬���������ȡ���ʱ����ڣ�12���������
    if (minute < MAX_POINT_NUM)
    {
        //Сʱ-1�����Ӽ�60��Ȼ��������
        hour -= 1;
        minute +=60;
        start_time = currrent_time.replace(
                    8,4,QString::number(hour).append(QString::number(minute - MAX_POINT_NUM)));
    }else if (minute >= MAX_POINT_NUM)
    {
        start_time = QString::number(currrent_time.toLongLong() - MAX_POINT_NUM*100);
    }

    sql += " AND [device_data] > '" +start_time + "'";
    sql += " AND [device_data] < '" +currrent_time + "'";
    QSqlQuery query;
    if (query.exec(sql))
    {
        while (query.next())
        {
            value_list << query.value(0).toString();
            data_list << query.value(1).toString();
        }
    }else
    {
        qDebug()<<query.lastError();
    }

    if (value_list.isEmpty())
    {
        m_plots_list.at(0)->xAxis->setRange(0,MAX_POINT_NUM*20,Qt::AlignLeft);
        return;
    }
    m_plot_tempture_keys.clear();
    m_plot_tempture_values.clear();

    foreach (QString str, value_list) {
        m_plot_tempture_values << str.toDouble();
    }

    foreach (QString str, data_list) {
        //��ʱ��ת��Ϊ�룬����������ʾ����������
        m_plot_tempture_keys << (QDateTime::fromString(str,"yyyyMMddhhmmss").toMSecsSinceEpoch()/1000);
    }
#if QDEBUG
    //qDebug()<<"temp_value_count:"<<m_plot_tempture_values.count();
    qDebug()<<"temp_value:"<<m_plot_tempture_values;
    qDebug()<<"temp_data:"<<m_plot_tempture_keys;
#endif

    m_plots_list.at(0)->graph(0)->addData(m_plot_tempture_keys,
                                          m_plot_tempture_values);
    //    m_plots_list.at(0)->graph(0)->removeDataBefore(m_plot_tempture_keys.at(MAX_POINT_NUM-1) -MAX_POINT_NUM -1);
    //    m_plots_list.at(0)->xAxis->setRange(m_plot_tempture_keys.at(MAX_POINT_NUM-1),MAX_POINT_NUM,Qt::AlignLeft);
    //�Զ�������������ʾ��Χ
    m_plots_list.at(0)->rescaleAxes();
    m_plots_list.at(0)->yAxis->setRange(0,50);
    m_plots_list.at(0)->replot();
}

/*�޸�˵��:
 * 2016-03-25 22:45:53:
 * �޸�����ͳ����ʾ��ʽ��һ��(Ҳ����ÿ��ֻ��ʾ10�����ݣ���������ʾ)
 * ��ȡ˼·����ȡ��ǰʱ�䣬Ȼ���ȥ1���ӣ��������ݿ��в�����������ڵ�ʪ����Ϣ
 *         ��ʾ�ڻ�ͼ�����
 *2016��4��2��21:30:47
 *�����޸�
 *��ȡ��ǰʱ���ǰ12����¼��������ʾ����
*/
void StatisticWidget::loadPlotHumidity()
{
    /*
    //��ȡ��ǰϵͳʱ�䣬���ڼ���������������
    QString curTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString befTime = QString::number(curTime.toLongLong() - 100);

    qDebug()<<"current time:"<<curTime;
    qDebug()<<"before time:"<<befTime;

    QString sql = "SELECT [device_value] FROM [device_info] WHERE ";
    sql += "[device_id] = '02' AND [device_data] >= '"+befTime;
    sql +="' AND [device_data] <= '"+curTime +"'";

    qDebug()<<"select sql:\n"<<sql<<endl;

    plot2_key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    plot2_value = qrand() % Plot2_MaxY;
    m_plots_list.at(1)->graph(0)->addData(plot2_key, plot2_value);
    m_plots_list.at(1)->graph(0)->removeDataBefore(plot2_key - Plot2_Count - 1);
    m_plots_list.at(1)->xAxis->setRange(plot2_key, Plot2_Count , Qt::AlignRight);
    m_plots_list.at(1)->replot();
    */
#if 0
    /*
     *�ڶ����޸�
    */
    //ÿ���ӻ���һ������
    QStringList value_list,data_list;
    QString sql = "SELECT [device_value],[device_data]  FROM [device_info] WHERE [device_id]='02'";
    //QString currrent_time = "20160401174000";
    QString currrent_time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString start_time;
    quint8 hour,minute;
    hour = currrent_time.mid(8,2).toUInt();
    minute = currrent_time.mid(10,2).toUInt();
    //��Ϊ������Ҫ����12���㣬���������ȡ���ʱ����ڣ�12���������
    if (minute < MAX_POINT_NUM)
    {
        //Сʱ-1�����Ӽ�60��Ȼ��������
        hour -= 1;
        minute +=60;
        start_time = currrent_time.replace(
                    8,4,QString::number(hour).append(QString::number(minute - MAX_POINT_NUM)));
    }else if (minute >= MAX_POINT_NUM)
    {
        start_time = QString::number(currrent_time.toLongLong() - MAX_POINT_NUM*100);
    }

    sql += " AND [device_data] > '" +start_time + "'";
    sql += " AND [device_data] < '" +currrent_time + "'";
    QSqlQuery query;
    if (query.exec(sql))
    {
        while (query.next())
        {
            value_list << query.value(0).toString();
            data_list << query.value(1).toString();
        }
    }else
    {
        qDebug()<<query.lastError();
    }

    //�������Ϊ�գ������������
    if (value_list.isEmpty())
    {
        m_plots_list.at(1)->xAxis->setRange(0,MAX_POINT_NUM*20,Qt::AlignLeft);
        m_plot_hum_values <<0;
    }else
    {
        m_plot_hum_keys.clear();
        m_plot_hum_values.clear();

        foreach (QString str, value_list) {
            m_plot_hum_values << str.toDouble();
        }

        foreach (QString str, data_list) {
            //��ʱ��ת��Ϊ�룬����������ʾ����������
            m_plot_hum_keys << (QDateTime::fromString(str,"yyyyMMddhhmmss").toMSecsSinceEpoch()/1000);
        }
#if QDEBUG
        //qDebug()<<"temp_value_count:"<<m_plot_tempture_values.count();
        qDebug()<<"temp_value:"<<m_plot_hum_values;
        qDebug()<<"temp_data:"<<m_plot_hum_keys;
#endif
    }
    m_plots_list.at(1)->graph(0)->addData(m_plot_hum_keys,
                                          m_plot_hum_values);

    //�Զ�������������ʾ��Χ
    m_plots_list.at(1)->rescaleAxes();
    m_plots_list.at(1)->yAxis->setRange(0,m_plot_hum_values.last()+20);
    m_plots_list.at(1)->replot();
#endif
    //�������޸�
    /*
     *ֻ��ȡ��ǰʱ���ǰһ�������ݣ�������ʾ��ÿһ����ˢ��һ�εġ�
    */
    QStringList value_list,data_list;
    quint8 hour,minute;
    QString sql = "SELECT [device_value],[device_data]  FROM [device_info] WHERE [device_id]='02'";
    QString currrent_time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
//    QString currrent_time = "20160401174000";
    QString start_time = currrent_time.left(8).append("000000");

    sql += " AND [device_data]>='" +start_time+"' AND [device_data]<='"+currrent_time+"'";
    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        value_list <<query.value(0).toString();
        data_list <<query.value(1).toString();
    }

    foreach (QString str,value_list)
    {
        m_plot_hum_values <<str.toDouble();
    }

    foreach (QString str,data_list)
    {
        hour = str.mid(8,2).toUInt();
        minute = str.mid(10,2).toUInt();
        m_plot_hum_keys <<(hour*60 +minute);
    }

    //�ж������Ƿ�Ϊ��
    if (!value_list.isEmpty())
    {
        m_plots_list.at(1)->graph(0)->addData(m_plot_hum_keys,
                                              m_plot_hum_values);
        m_plots_list.at(1)->graph(0)->removeDataBefore(m_plot_hum_keys.first() - 60);
        //�Զ�������������ʾ��Χ
        m_plots_list.at(1)->rescaleAxes();
        m_plots_list.at(1)->xAxis->setRange(0,24*60,Qt::AlignLeft);
                m_plots_list.at(1)->yAxis->setRange(0,60);
        m_plots_list.at(1)->replot();
    }else
    {
        qDebug()<<"\ndata is empty!\n";
    }

}

void StatisticWidget::loadPlotSmoke()
{
    /*
    QStringList value,key;
    QString cur_time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

    QString sql_value = "SELECT device_value FROM device_info WHERE";
    sql_value += " device_id = '03' AND device_data >= "+cur_time.left(8).append("000000");
    sql_value += " AND device_data <=" + cur_time;

    QString sql_key = "SELECT device_data FROM device_info WHERE";
    sql_key += " device_id = '03' AND device_data >= "+ cur_time.left(8).append("000000");
    sql_key += " AND device_data <=" + cur_time;
#if QDEBUG
    qDebug()<<"seach data from database:";
    qDebug()<< sql_value;
#endif
    value = m_sqlhelp->getColumnData(sql_value);
    key = m_sqlhelp->getColumnData(sql_key);
#if QDEBUG
    qDebug("\n\n");
    qDebug()<<"size:"<<value.count();
    qDebug() <<"value:"<<value;
    qDebug() <<"key:"<<key;
    qDebug("\n\n");
#endif

    m_smoke_count = value.count();
    m_plot_smoke_values.clear();
    m_plot_smoke_key.clear();

    foreach (QString str,value)
    {
        m_plot_smoke_values << str.toDouble();
    }
    foreach (QString str,key)
    {
        m_plot_smoke_key <<str.mid(8,4).toDouble();
    }

    qDebug()<<"m_plot_smoke_values:\n"<<m_plot_smoke_values;
    qDebug()<<"m_plot_smoke_key:\n"<<m_plot_smoke_key;


    m_plots_list.at(2)->graph(0)->setData(m_plot_smoke_key, m_plot_smoke_values);
    m_plots_list.at(2)->xAxis->setAutoTickCount(12);
    m_plots_list.at(2)->yAxis->setAutoTickCount(10);
    m_plots_list.at(2)->graph(0)->rescaleAxes();
    m_plots_list.at(2)->replot();
    */

    /*
     *2016��4��2��21:36:08  �ٴ��޸�
    */
    //ÿ���ӻ���һ������
    QStringList value_list,data_list;
    QString sql = "SELECT [device_value],[device_data]  FROM [device_info] WHERE [device_id]='03'";
    QString currrent_time = "20160401174000";
    QString start_time;
    quint8 hour,minute;
    hour = currrent_time.mid(8,2).toUInt();
    minute = currrent_time.mid(10,2).toUInt();
    //��Ϊ������Ҫ����12���㣬���������ȡ���ʱ����ڣ�12���������
    if (minute < MAX_POINT_NUM)
    {
        //Сʱ-1�����Ӽ�60��Ȼ��������
        hour -= 1;
        minute +=60;
        start_time = currrent_time.replace(
                    8,4,QString::number(hour).append(QString::number(minute - MAX_POINT_NUM)));
    }else if (minute >= MAX_POINT_NUM)
    {
        start_time = QString::number(currrent_time.toLongLong() - MAX_POINT_NUM*100);
    }

    sql += " AND [device_data] > '" +start_time + "'";
    sql += " AND [device_data] < '" +currrent_time + "'";
    QSqlQuery query;
    if (query.exec(sql))
    {
        while (query.next())
        {
            value_list << query.value(0).toString();
            data_list << query.value(1).toString();
        }
    }else
    {
        qDebug()<<query.lastError();
    }

    if (value_list.isEmpty())
    {
        m_plots_list.at(2)->xAxis->setRange(0,MAX_POINT_NUM*20,Qt::AlignLeft);
        return;
    }
    m_plot_smoke_keys.clear();
    m_plot_smoke_values.clear();

    foreach (QString str, value_list) {
        m_plot_smoke_values << str.toDouble();
    }

    foreach (QString str, data_list) {
        //��ʱ��ת��Ϊ�룬����������ʾ����������
        m_plot_smoke_keys << (QDateTime::fromString(str,"yyyyMMddhhmmss").toMSecsSinceEpoch()/1000);
    }
#if QDEBUG
    //qDebug()<<"temp_value_count:"<<m_plot_tempture_values.count();
    qDebug()<<"temp_value:"<<m_plot_smoke_values;
    qDebug()<<"temp_data:"<<m_plot_smoke_keys;
#endif

    m_plots_list.at(2)->graph(0)->addData(m_plot_smoke_keys,
                                          m_plot_smoke_values);

    //�Զ�������������ʾ��Χ
    m_plots_list.at(2)->rescaleAxes();

    m_plots_list.at(2)->yAxis->setRange(0,m_plot_smoke_values.last()+20);
    m_plots_list.at(2)->replot();
}

void StatisticWidget::initStyle()
{
    m_sqlhelp = new SqlHelp;
}

void StatisticWidget::initForm()
{
    m_currentIndex = 0;

    m_plots_list.append(ui->plot_tempture);
    m_plots_list.append(ui->plot_humidity);
    m_plots_list.append(ui->plot_smoke);

    //Ĭ����ʾͼ��
#if SHOW_LEGEND
    m_plots_list.at(0)->legend->setVisible(true);
    m_plots_list.at(1)->legend->setVisible(true);
    m_plots_list.at(2)->legend->setVisible(true);
    ui->ckText->setChecked(true);
#endif

    ui->label_dateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
}

//��ʼ����ͼ�豸
void StatisticWidget::initPlot()
{
    //���ø���ͼ������������
    m_plots_list.at(0)->yAxis->setLabel(tr("�¶�ֵ(��λ:��)"));
    m_plots_list.at(1)->yAxis->setLabel(tr("ʪ��ֵ(��λ:%)"));
    m_plots_list.at(2)->yAxis->setLabel(tr("Ũ��ֵ(��λ:%)"));

    m_plots_list.at(0)->xAxis->setLabel(tr("ʱ��"));
    m_plots_list.at(1)->xAxis->setLabel(tr("ʱ��"));
    m_plots_list.at(2)->xAxis->setLabel(tr("ʱ��"));

    //���������귶Χ
    m_plots_list.at(0)->yAxis->setRange(0,PLOT_TEMPTURE_MAX_Y);
    m_plots_list.at(1)->yAxis->setRange(0,PLOT_HUMIDITY_MAX_Y);
    m_plots_list.at(2)->yAxis->setRange(0,PLOT_SMOKE_MAX_Y);

    foreach (QCustomPlot *plot, m_plots_list) {
        //����������ɫ������
        plot->yAxis->setLabelColor(TextColor);
        plot->xAxis->setLabelColor(TextColor);

        plot->yAxis->setTickLabelColor(TextColor);  //Y���ǩ��ɫ
        plot->xAxis->setTickLabelColor(TextColor);

        //���ñȱ�ǩ����
        plot->xAxis->setTickLabelFont(QFont(QFont().family(),10));

        plot->xAxis->setBasePen(QPen(TextColor,TextWidth));
        plot->yAxis->setBasePen(QPen(TextColor,TextWidth));

        plot->xAxis->setTickPen(QPen(TextColor,TextWidth));
        plot->yAxis->setTickPen(QPen(TextColor,TextWidth));

        plot->xAxis->setSubTickPen(QPen(TextColor,TextWidth));
        plot->yAxis->setSubTickPen(QPen(TextColor,TextWidth));

        //���û�������
        QLinearGradient plotGradient;
        plotGradient.setStart(0,0);
        plotGradient.setFinalStop(0,350);
        plotGradient.setColorAt(0,QColor(80,80,80));
        plotGradient.setColorAt(1,QColor(50,50,50));
        plot->setBackground(plotGradient);

        //�������걳��ɫ
        QLinearGradient axisRectGradient;
        axisRectGradient.setStart(0,0);
        axisRectGradient.setFinalStop(0,350);
        axisRectGradient.setColorAt(0,QColor(80,80,80));
        axisRectGradient.setColorAt(1,QColor(30,30,30));
        plot->axisRect()->setBackground(axisRectGradient);

        //����ͼ����ʾλ���Լ�����ɫ
        plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
        plot->legend->setBrush(QColor(255, 255, 255, 200));

        plot->replot();
    }
}

//��ʼ���¶�ͳ��ͼ
void StatisticWidget::initPlotTempture()
{
    //�򻭲����һ������
    m_plots_list.at(0)->addGraph();
    m_plots_list.at(0)->graph(0)->setName(tr("�¶�ֵ(��λ:��)"));
    m_plots_list.at(0)->graph(0)->setPen(QPen(Plot1_LineColor,LineWidth));
    m_plots_list.at(0)->graph(0)->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                                QPen(Plot1_DotColor, LineWidth),
                                QBrush(Plot1_DotColor), DotWidth));
    //���þ�̬���ߵĺ����귶Χ�Լ�����Ӧ����
    m_plots_list.at(0)->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    m_plots_list.at(0)->xAxis->setDateTimeFormat("hh:mm");
    m_plots_list.at(0)->xAxis->setAutoTickStep(false);
    m_plots_list.at(0)->xAxis->setTickStep(60);
    //m_plots_list.at(0)->xAxis->setRange(0,3600*4,Qt::AlignLeft);
}

//��ʼ��ʪ��ͳ��ͼ
void StatisticWidget::initPlotHumidity()
{
    //�򻭲����һ������
    m_plots_list.at(1)->addGraph(0);
    m_plots_list.at(1)->graph(0)->setName(tr("ʪ��ֵ(��λ:%)"));
    m_plots_list.at(1)->graph(0)->setPen(QPen(Plot2_LineColor,LineWidth));
    m_plots_list.at(1)->graph(0)->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                                QPen(Plot2_DotColor, Plot2_LineWidth),
                                QBrush(Plot2_DotColor), Plot2_DotWidth));

    //���ö�̬���ߵĺ������ʽ����Χ
    //    m_plots_list.at(1)->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    //    m_plots_list.at(1)->xAxis->setDateTimeFormat("hh:mm");
    m_plots_list.at(1)->xAxis->setAutoTickStep(false);
    m_plots_list.at(1)->xAxis->setTickStep(120);
    m_plots_list.at(1)->xAxis->setRange(0, 24*60, Qt::AlignLeft);
}

//��ʼ������ͳ��ͼ
void StatisticWidget::initPlotSmoke()
{
    m_plots_list.at(2)->addGraph(0);
    m_plots_list.at(2)->graph(0)->setName(tr("����ֵ(��λ:%)"));
    m_plots_list.at(2)->graph(0)->setPen(QPen(Plot3_LineColor,LineWidth));
    m_plots_list.at(2)->graph(0)->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                                QPen(Plot3_DotColor, LineWidth),
                                QBrush(Plot3_DotColor), DotWidth));
    //���ö�̬���ߵĺ������ʽ����Χ
    m_plots_list.at(2)->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    m_plots_list.at(2)->xAxis->setDateTimeFormat("hh:mm");
    m_plots_list.at(2)->xAxis->setAutoTickStep(false);
    m_plots_list.at(2)->xAxis->setTickStep(60);
    //m_plots_list.at(2)->xAxis->setRange(0, 3600*4, Qt::AlignRight);
    m_plots_list.at(2)->replot();
}

void StatisticWidget::initData()
{
    ColumnNames[0] = tr("device_name");
    ColumnNames[1] = tr("device_value");
    ColumnNames[2] = tr("device_data");
    ColumnNames[3] = tr("device_remark");

    ColumnWidths[0] = 120;
    ColumnWidths[1] = 110;
    ColumnWidths[2] = 160;
    ColumnWidths[3] = 100;

    //������Ҫ��ʾ���ݵı��ͷ�ҳ�İ�ť
    m_sqlhelp->SetControlTable(ui->tableView,ui->labInfo,ui->btnFirst,ui->btnPre,ui->btnNext,ui->btnLast);
    //���س�ʼ����,�����������ʾ
    m_sqlhelp->BindData("v_device_info","device_data","",7,ColumnNames,ColumnWidths);
}

void StatisticWidget::initConnect()
{
    connect(ui->comboBox_view_data,SIGNAL(currentIndexChanged(int)),
            this,SLOT(slotChangeData(int)));
}

//����/�ر��ƶ����Ź���
void StatisticWidget::on_ckMove_stateChanged(int arg1)
{
    bool value = (arg1 == 0? false:true);
    if (value)
    {
        ui->plot_tempture->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom);
        ui->plot_humidity->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom);
        ui->plot_smoke->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom);
    }else
    {
        ui->plot_tempture->setInteractions(QCP::iSelectOther);
        ui->plot_humidity->setInteractions(QCP::iSelectOther);
        ui->plot_smoke->setInteractions(QCP::iSelectOther);
    }
}

//��/�رձ���
void StatisticWidget::on_ckBackground_stateChanged(int arg1)
{
    bool value = (arg1 == 0? false:true);
    if (value)
    {
        m_plots_list.at(0)->graph(0)->setBrush(QBrush(Plot1_BGColor));
        m_plots_list.at(1)->graph(0)->setBrush(QBrush(Plot2_BGColor));
        m_plots_list.at(2)->graph(0)->setBrush(QBrush(Plot3_BGColor));
    }else
    {
        m_plots_list.at(0)->graph(0)->setBrush(QBrush(Plot_NoColor));
        m_plots_list.at(1)->graph(0)->setBrush(QBrush(Plot_NoColor));
        m_plots_list.at(2)->graph(0)->setBrush(QBrush(Plot_NoColor));
    }

    m_plots_list.at(0)->replot();
    m_plots_list.at(1)->replot();
    m_plots_list.at(2)->replot();
}

//���/ȡ��ͼ��
void StatisticWidget::on_ckText_stateChanged(int arg1)
{
    bool value = (arg1 == 0? false:true);
    if (value)
    {
        m_plots_list.at(0)->legend->setVisible(true);
        m_plots_list.at(1)->legend->setVisible(true);
        m_plots_list.at(2)->legend->setVisible(true);
    }else
    {
        m_plots_list.at(0)->legend->setVisible(false);
        m_plots_list.at(1)->legend->setVisible(false);
        m_plots_list.at(2)->legend->setVisible(false);
    }

    //�ػ�
    m_plots_list.at(0)->replot();
    m_plots_list.at(1)->replot();
    m_plots_list.at(2)->replot();
}

void StatisticWidget::slotUpdataData()
{
#if QDEBUG
    qDebug()<<"=================================";
    qDebug()<<"start update statistic data";
    qDebug()<<"=================================";
#endif

    QString new_smoke_value = m_sqlhelp->getLastRecord("device_info","device_value",
                                                       "device_id",DEVICE_SMOKE);
    QString new_smoke_key = m_sqlhelp->getLastRecord("device_info","device_data",
                                                     "device_id",DEVICE_SMOKE);
#if QDEBUG
    qDebug()<<"===========================================\n";
    qDebug() <<"new "<<DEVICE_SMOKE<<" data:"<<new_smoke_value;
    qDebug()<<"===========================================\n";
#endif
    m_plots_list.at(2)->graph(0)->addData(new_smoke_key.toDouble(),
                                          new_smoke_value.toDouble());
}

void StatisticWidget::slotChangeData(int index)
{
    //��ʾ��ǰ����
    if (0 == index)
    {
        loadPlotTempture();
        loadPlotHumidity();
        loadPlotSmoke();
    }
    //��ʾ��������
    else if (1 == index)
    {
        slotShowTempWeekData();
        slotShowHumWeekData();
        slotShowSmokeWeedData();
    }
}

/*
 *ͳ��һ�����ݣ�ֻ��ʾ7����
 *˼·�������ݿ��ж�ȡǰ7������ݣ�������ʾ
 *�ѵ㣺��ȡÿһ�����ݵ�ƽ��ֵ
*/
void StatisticWidget::slotShowTempWeekData()
{
    QStringList month_list;
    month_list <<"01" <<"03" <<"05"<<"07"<<"08"<<"10"<<"12";
    //    QString current_Time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString current_Time = "20160302221632";
    QString start_Timer;
    QString month = current_Time.mid(4,2);
    QString date = current_Time.mid(6,2);
    //�Ե�ǰ���ڽ����жϣ�ͳ��һ������
    foreach (QString str, month_list) {
        if (month.contains(str,Qt::CaseSensitive))
        {
            qDebug()<<"is leap month ";
        }else
        {
            qDebug()<<"not leap month";
        }
    }

    QString sql = "SELECT [device_value],[device_data] FROM [device_info] WHERE [device_id]='";
    sql += " 01' AND [device_data] >";
}

void StatisticWidget::slotShowHumWeekData()
{
}

void StatisticWidget::slotShowSmokeWeedData()
{
}
