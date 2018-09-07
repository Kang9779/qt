#include "figurecontrol.h"

FigureControl::FigureControl(QWidget *parent) : QCheckBox(parent)
{
   figureName="压力";
   figureLabel="P(MPa)";
   connect(this,SIGNAL(toggled(bool)),this,SLOT(controlSensor(bool)));
}

void FigureControl::setImageLabel(QLabel *ui_label)
{
    imageLabel=ui_label;
}

void FigureControl::setSensorImage(QString path)
{
    image=new QImage;
    image->load(path);
    imageLabel->setPixmap(QPixmap::fromImage(*image));
    imageLabel->hide();
}

void FigureControl::setFigureList(QListWidget *ui_listwidget)
{
    figureList=ui_listwidget;
}

void FigureControl::setFigureName(QString name)
{
    figureName=name;
}

void FigureControl::setFigureLabel(QString name)
{
    figureLabel=name;
}

void FigureControl::addGraph(QCustomPlot *figure)
{
    figure->addGraph();
//    // 设置标题
//    figure->plotLayout()->insertRow(0);
//    figure->plotLayout()->addElement(0, 0, new QCPTextElement(figure, title, QFont("sans", 10, QFont::Bold)));
    // 标题空白区域太大，采用legend方式
    QPen borderPen;
    borderPen.setColor(QColor(0,0,0,0));
    QBrush brush;
    brush.setColor(QColor(0,0,0,0));
    figure->legend->setVisible(true);
    figure->legend->setBorderPen(borderPen);
    figure->legend->setBrush(brush);
    figure->graph(0)->setName(figureName);
    // 减小空白区域面积
    figure->plotLayout()->setOuterRect(QRect(0,0,0,0));
    figure->plotLayout()->setMargins(QMargins(0,0,0,0));
    //figure->plotLayout()->setRowStretchFactor(1, 0.001);
}

void FigureControl::setPlot(QCustomPlot *figure)
{
    // 图形交互操作：缩放、平移等
    figure->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);
    //设置网格
    figure->xAxis->setBasePen(QPen(Qt::red,1));
    figure->yAxis->setBasePen(QPen(Qt::red,1));
    figure->xAxis->setTickPen(QPen(Qt::red,1));
    figure->yAxis->setTickPen(QPen(Qt::red,1));
    figure->xAxis->setTickLabelColor(Qt::black);
    figure->yAxis->setTickLabelColor(Qt::black);
    figure->xAxis->grid()->setPen(QPen(Qt::red, 1, Qt::DotLine));
    figure->yAxis->grid()->setPen(QPen(Qt::red, 1, Qt::DotLine));
    figure->xAxis->grid()->setSubGridPen(QPen(QColor(255,0,0,128),1,Qt::DotLine));
    figure->yAxis->grid()->setSubGridPen(QPen(QColor(255,0,0,128),1,Qt::DotLine));
    figure->xAxis->grid()->setSubGridVisible(true);
    figure->yAxis->grid()->setSubGridVisible(true);
    figure->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    figure->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    // Set legend
//    figureBoom->legend->setVisible(true);
//    QFont legendFont = font();  // start out with MainWindow's font..
//    legendFont.setPointSize(9); // and make a bit smaller for legend
//    figureBoom->legend->setFont(legendFont);
//    figureBoom->legend->setBrush(QBrush(QColor(255,255,255,230)));
//    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
//    figure->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    // Set graph 0
    // 设置曲线画笔
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    figure->graph(0)->setPen(pen);
    //figureBoom->graph(0)->setLineStyle(QCPGraph::lsLine);
    //figure->graph(0)->setName("压力 P1");
    // Set ranges
    figure->yAxis->setRange(0,10);
//    figureBoom->graph(0)->rescaleValueAxis();
    // Set label
    figure->xAxis->setLabel("时间 (s)");
    //figure->yAxis->setLabel("压力 (MPa)");
    // 清除当前绘图
    figure->graph(0)->data()->clear();
    // 时间轴
    figure->setLocale(QLocale(QLocale::Chinese, QLocale::China));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    figure->xAxis->setTicker(timeTicker);
    figure->replot();
}

void FigureControl::addPlotData(QVector<double> x, QVector<double> y)
{
    if(this->isChecked())
    {
        figure->graph(0)->addData(x,y);
        figure->graph(0)->data()->removeBefore(x[0]-5);
        // figure->replot();
    }
}

void FigureControl::setPlotData(QVector<double> x, QVector<double> y)
{
    if(this->isChecked())
    {
        figure->graph(0)->data()->clear();
        figure->graph(0)->setData(x,y);
        figure->replot();
    }
}

void FigureControl::updatePlot()
{
    if(this->isChecked())
    {
        figure->graph(0)->rescaleKeyAxis();
        figure->replot();
    }
}

void FigureControl::setCombox(QComboBox *ui_combox)
{
    comBox=ui_combox;
    comBox->addItems(QStringList() << "0~10V (电压)"<<"-5~5V (电压)" << "4~20mA (电流)");
    connect(comBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setPlotRange(int)));
}

void FigureControl::controlSensor(bool displayed)
{
    if(displayed)
    {
        imageLabel->show();
        figure=new QCustomPlot(this);
        addGraph(figure);
        figure->setFixedSize(470,120);
        // 绘图设置
        setPlot(figure);
        figure->yAxis->setLabel(figureLabel);
        // figure加入ListWidget
        figureItem=new QListWidgetItem(figureList);
        figureList->setItemWidget(figureItem,figure);
        figureList->addItem(figureItem);
    }
    else
    {
        imageLabel->hide();
        // 从ListWidget中删除figure
        figureList->removeItemWidget(figureItem);
        delete figureItem;
    }
}

void FigureControl::setPlotRange(int index)
{
    if(this->isChecked())
    {
        switch(index)
        {
        case 0/*"0~10V (电压)"*/:
            figure->graph(0)->valueAxis()->setRange(0,10);
            break;
        case 1/*"-5~5V (电压)"*/:
            figure->graph(0)->valueAxis()->setRange(-5,5);
            break;
        case 2/*"4~20mA (电流)"*/:
            figure->graph(0)->valueAxis()->setRange(4,20);
            break;
        }
        figure->replot();
    }
}
