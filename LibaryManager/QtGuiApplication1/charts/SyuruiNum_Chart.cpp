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
    SyuruiNum_chart->legend()->setVisible(false);/*��ǩ���ɼ�*/
    SyuruiNum_chart->setMargins(QMargins(10, 0, 0, 0));/*chart���*/

    SyuruiNum_bars = new QBarSet("");

    SyuruiNum_series = new QBarSeries();
    SyuruiNum_series->setLabelsVisible(false);/*��ǩ���ɼ�*/
    SyuruiNum_series->append(SyuruiNum_bars);/*������ݼ�*/
             
    SyuruiNum_seriesSpline = new QSplineSeries();
    SyuruiNum_seriesSpline->setPointsVisible(false);/*���ߵ㲻�ɼ�*/

    SyuruiNum_chart->addSeries(SyuruiNum_series);
    SyuruiNum_chart->addSeries(SyuruiNum_seriesSpline);

    //SyuruiNumaxisX = new QBarCategoryAxis();���¼<QBarCategoryAxis�ڴ洢���ݵ�ʱ����ؼ�����100���ַ���λ����ӿ��ٸߴ�10��>
    //SyuruiNumaxisX->setGridLineVisible(false);/*Y���߲��ɼ�*/
    //SyuruiNum_Chart->setAxisX(SyuruiNumaxisX, SyuruiNumseries);/*��chart�����x���Series*/
    //SyuruiNum_Chart->setAxisX(SyuruiNumaxisX, SyuruiNumseriesSpline);/*��chart�����x���Series*/

    SyuruiNum_axisY = new QValueAxis();
    SyuruiNum_axisY->setLabelFormat("%d");/*����Y����ֵ��ʾ��Ĭ�ϱ���С��������ȡ��*/
    SyuruiNum_axisY->setTickCount(4);/*��Y����ֵ��Ϊ7��*/
    SyuruiNum_chart->setAxisY(SyuruiNum_axisY, SyuruiNum_series);/*��chart�����y���Series*/
    SyuruiNum_chart->setAxisY(SyuruiNum_axisY, SyuruiNum_seriesSpline);/*��chart�����y���Series*/
    SyuruiNum_axisY->setRange(0, 20);/*��ֵ�����������еķ�Χ�綨*/
             
    SyuruiNum_axisX = new QCategoryAxis();
    SyuruiNum_axisX->setGridLineVisible(false);
    SyuruiNum_axisX->setLabelFormat("%d");/*����Y����ֵ��ʾ��Ĭ�ϱ���С��������ȡ��*/
    SyuruiNum_axisX->setReverse(true);/*��ת��*/
    SyuruiNum_axisX->setTickCount(10);
    SyuruiNum_chart->setAxisX(SyuruiNum_axisX, SyuruiNum_series);/*��chart�����y���Series*/
    SyuruiNum_chart->setAxisX(SyuruiNum_axisX, SyuruiNum_seriesSpline);/*��chart�����y���Series*/

    SyuruiNum_chartView = new QChartView();
    SyuruiNum_chartView->setRenderHint(QPainter::Antialiasing);/*�����*/
    SyuruiNum_chartView->setChart(SyuruiNum_chart);
}

void SyuruiNum_Chart::SyuruiNum()//����ѹ��ͼ����
{
    /*�����״ͼ������*/
    while (SyuruiNum_bars->count())
    {
        SyuruiNum_bars->remove(0);
    }
    /*�����������*/
    SyuruiNum_seriesSpline->clear();
    SyuruiNum_axisX->setRange(0, g_Syuruis.size());

    int i = 1;
    for (auto iter = g_Syuruis.begin(); iter != g_Syuruis.end(); iter++)
    {
        SyuruiNum_axisX->append(iter.key(), i++);
        
    }

    //for (i = 0; i < Trains.size(); i++)
    //{
    //    *SyuruiNum_bars << Trains[i].nPL;/*����ͼ���*/
    //    SyuruiNum_seriesSpline->append(i, Trains[i].nPL);/*���ߵ����*/
    //}
}

/*�����ڴ�й©�������*/
  /*�г���ѹ��ͼЧ��������*/
//QChartView* SyuruiNum_Chart::Pressure()
//{
//    QVector<int>values{ 550,450,350,400,200,300,450,450,350,350 };
//    for (int i = 0; i < 50; i++)
//    {
//        values.push_back(6 * i);
//    }
//    QChart* chart = new QChart();
//    chart->legend()->setVisible(false);/*��ǩ���ɼ�*/
//    chart->setMargins(QMargins(0, 0, 0, 0));/*chart���*/
//    /*=====����ͼ������ͼ=====*/
//    QBarSet* bars = new QBarSet("");/*����ͼ���ݼ�*/
//    QBarSeries* series = new QBarSeries();/*����ͼ*/
//    series->append(bars);/*������ݼ�*/
//    series->setLabelsVisible(false);/*��ǩ���ɼ�*/
//    QSplineSeries* seriesSpline = new QSplineSeries();/*����ͼ*/
//    seriesSpline->setPointsVisible(false);/*���ߵ㲻�ɼ�*/
//    for (int i = 0; i < values.size(); i++)
//    {
//        *bars << values[i];
//        seriesSpline->append(QPoint(i, values[i]));
//    }
//    chart->addSeries(series);/*���series*/
//    chart->addSeries(seriesSpline);/*���series*/
//    /*=====X���Y��=====*/
//    QBarCategoryAxis* axisX = new QBarCategoryAxis();/*X��Ϊ�г��ڽ�������Ϊ����ֵ��*/
//    axisX->setGridLineVisible(false);/*Y���߲��ɼ�*/
//    for (int i = 0; i < values.size(); i++)
//    {
//        axisX->append(QString("%1").arg(i));
//    }
//    chart->setAxisX(axisX, series);/*��chart�����x���Series*/
//    chart->setAxisX(axisX, seriesSpline);/*��chart�����x���Series*/
//    QValueAxis* axisY = new QValueAxis();/*Y��Ϊ�г���ѹ��ֵ����ֵ��*/
//    axisY->setLabelFormat("%d");/*����Y����ֵ��ʾ��Ĭ�ϱ���С��������ȡ��*/
//    axisY->setTickCount(5);/*��Y����ֵ��Ϊ5��*/
//    chart->setAxisY(axisY, series);/*��chart�����y���Series*/
//    chart->setAxisY(axisY, seriesSpline);/*��chart�����y���Series*/
//    axisY->setRange(0, 600);/*��ֵ�����������еķ�Χ�綨*/
//    /*======����View��====*/
//    QChartView* SyuruiNum_ChartView = new QChartView(chart);
//    SyuruiNum_ChartView->setRenderHint(QPainter::Antialiasing);/*�����*/
//    return SyuruiNum_ChartView;
//}

