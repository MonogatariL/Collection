#include "SyuruiNum_Chart.h"

SyuruiNum_Chart::SyuruiNum_Chart()
{
    SyuruiNum_Init();
}

SyuruiNum_Chart::~SyuruiNum_Chart()
{
    delete SyuruiNum_chartView;
    delete SyuruiNum_chart;
    delete SyuruiNum_bars;
    delete SyuruiNum_series;
    delete SyuruiNum_seriesSpline;
    delete SyuruiNum_axisX;
    delete SyuruiNum_axisY;
}

void SyuruiNum_Chart::SyuruiNum_Init()
{
    SyuruiNum_chart = new QChart();
    SyuruiNum_chart->legend()->setVisible(false);/*标签不可见*/
    SyuruiNum_chart->setMargins(QMargins(10, 0, 0, 0));/*chart间距*/

    SyuruiNum_bars = new QBarSet("");

    SyuruiNum_series = new QBarSeries();
    SyuruiNum_series->setLabelsVisible(false);/*标签不可见*/
    SyuruiNum_series->append(SyuruiNum_bars);/*添加数据集*/
             
    SyuruiNum_seriesSpline = new QSplineSeries();
    SyuruiNum_seriesSpline->setPointsVisible(false);/*曲线点不可见*/

    SyuruiNum_chart->addSeries(SyuruiNum_series);
    SyuruiNum_chart->addSeries(SyuruiNum_seriesSpline);

    //SyuruiNumaxisX = new QBarCategoryAxis();忏悔录<QBarCategoryAxis在存储数据的时候加载极慢，100个字符单位的添加卡顿高达10秒>
    //SyuruiNumaxisX->setGridLineVisible(false);/*Y轴线不可见*/
    //SyuruiNum_Chart->setAxisX(SyuruiNumaxisX, SyuruiNumseries);/*在chart中添加x轴和Series*/
    //SyuruiNum_Chart->setAxisX(SyuruiNumaxisX, SyuruiNumseriesSpline);/*在chart中添加x轴和Series*/

    SyuruiNum_axisY = new QValueAxis();
    SyuruiNum_axisY->setLabelFormat("%d");/*更改Y轴数值显示，默认保留小数，这里取整*/
    SyuruiNum_axisY->setTickCount(4);/*将Y轴数值分为7段*/
    SyuruiNum_chart->setAxisY(SyuruiNum_axisY, SyuruiNum_series);/*在chart中添加y轴和Series*/
    SyuruiNum_chart->setAxisY(SyuruiNum_axisY, SyuruiNum_seriesSpline);/*在chart中添加y轴和Series*/
    SyuruiNum_axisY->setRange(0, 20);/*数值型坐标轴特有的范围界定*/
             
    SyuruiNum_axisX = new QCategoryAxis();
    SyuruiNum_axisX->setGridLineVisible(false);
    SyuruiNum_axisX->setLabelFormat("%d");/*更改Y轴数值显示，默认保留小数，这里取整*/
    SyuruiNum_axisX->setReverse(true);/*反转了*/
    SyuruiNum_axisX->setTickCount(10);
    SyuruiNum_chart->setAxisX(SyuruiNum_axisX, SyuruiNum_series);/*在chart中添加y轴和Series*/
    SyuruiNum_chart->setAxisX(SyuruiNum_axisX, SyuruiNum_seriesSpline);/*在chart中添加y轴和Series*/

    SyuruiNum_chartView = new QChartView();
    SyuruiNum_chartView->setRenderHint(QPainter::Antialiasing);/*抗锯齿*/
    SyuruiNum_chartView->setChart(SyuruiNum_chart);
}

void SyuruiNum_Chart::SyuruiNum()//更新压力图数据
{
    /*清空柱状图的数据*/
    while (SyuruiNum_bars->count())
    {
        SyuruiNum_bars->remove(0);
    }
    /*清空曲线数据*/
    SyuruiNum_seriesSpline->clear();
    SyuruiNum_axisX->setRange(0, g_Syuruis.size());

    int i = 1;
    for (auto iter = g_Syuruis.begin(); iter != g_Syuruis.end(); iter++)
    {
        SyuruiNum_axisX->append(iter.key(), i++);
        
    }

    //for (i = 0; i < Trains.size(); i++)
    //{
    //    *SyuruiNum_bars << Trains[i].nPL;/*柱形图添加*/
    //    SyuruiNum_seriesSpline->append(i, Trains[i].nPL);/*曲线点添加*/
    //}
}

/*☆☆☆内存泄漏警告☆☆☆*/
  /*列车管压力图效果测试例*/
//QChartView* SyuruiNum_Chart::Pressure()
//{
//    QVector<int>values{ 550,450,350,400,200,300,450,450,350,350 };
//    for (int i = 0; i < 50; i++)
//    {
//        values.push_back(6 * i);
//    }
//    QChart* chart = new QChart();
//    chart->legend()->setVisible(false);/*标签不可见*/
//    chart->setMargins(QMargins(0, 0, 0, 0));/*chart间距*/
//    /*=====柱形图和曲线图=====*/
//    QBarSet* bars = new QBarSet("");/*柱形图数据集*/
//    QBarSeries* series = new QBarSeries();/*柱形图*/
//    series->append(bars);/*添加数据集*/
//    series->setLabelsVisible(false);/*标签不可见*/
//    QSplineSeries* seriesSpline = new QSplineSeries();/*曲线图*/
//    seriesSpline->setPointsVisible(false);/*曲线点不可见*/
//    for (int i = 0; i < values.size(); i++)
//    {
//        *bars << values[i];
//        seriesSpline->append(QPoint(i, values[i]));
//    }
//    chart->addSeries(series);/*添加series*/
//    chart->addSeries(seriesSpline);/*添加series*/
//    /*=====X轴和Y轴=====*/
//    QBarCategoryAxis* axisX = new QBarCategoryAxis();/*X轴为列车节降序，所以为非数值型*/
//    axisX->setGridLineVisible(false);/*Y轴线不可见*/
//    for (int i = 0; i < values.size(); i++)
//    {
//        axisX->append(QString("%1").arg(i));
//    }
//    chart->setAxisX(axisX, series);/*在chart中添加x轴和Series*/
//    chart->setAxisX(axisX, seriesSpline);/*在chart中添加x轴和Series*/
//    QValueAxis* axisY = new QValueAxis();/*Y轴为列车管压力值，数值型*/
//    axisY->setLabelFormat("%d");/*更改Y轴数值显示，默认保留小数，这里取整*/
//    axisY->setTickCount(5);/*将Y轴数值分为5段*/
//    chart->setAxisY(axisY, series);/*在chart中添加y轴和Series*/
//    chart->setAxisY(axisY, seriesSpline);/*在chart中添加y轴和Series*/
//    axisY->setRange(0, 600);/*数值型坐标轴特有的范围界定*/
//    /*======放入View中====*/
//    QChartView* SyuruiNum_ChartView = new QChartView(chart);
//    SyuruiNum_ChartView->setRenderHint(QPainter::Antialiasing);/*抗锯齿*/
//    return SyuruiNum_ChartView;
//}

