#ifndef FIGURECONTROL_H
#define FIGURECONTROL_H
#include <QCheckBox>
#include <QLabel>
#include <QListWidgetItem>
#include <QListWidget>
#include "qcustomplot.h"


class FigureControl : public QCheckBox
{
    Q_OBJECT
public:
    explicit FigureControl(QWidget *parent = 0);

signals:

private:
    // 液压回路图中传感器显示控制
    QImage *image;
    QLabel *imageLabel;
    // 数据采集图中绘图控制
    QCustomPlot *figure;
    QListWidgetItem *figureItem;
    QListWidget *figureList;
    QString figureName;
    QString figureLabel;
    // 传感器选择下拉菜单
    QComboBox *comBox;

public:
    void setImageLabel(QLabel *ui_label);
    void setSensorImage(QString path);

    void setFigureList(QListWidget *ui_listwidget);
    void setFigureName(QString name);
    void setFigureLabel(QString name);
    void addGraph(QCustomPlot *figure);
    void setPlot(QCustomPlot *figure);
    void addPlotData(QVector<double> x,QVector<double> y);
    void setPlotData(QVector<double> x,QVector<double> y);
    void updatePlot();

    void setCombox(QComboBox *ui_combox);

private slots:
    void controlSensor(bool displayed);
    void setPlotRange(int index);
};

#endif // FIGURECONTROL_H
