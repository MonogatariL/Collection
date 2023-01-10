#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QBarCategoryAxis>
#include"Global.h"


QT_CHARTS_USE_NAMESPACE

/*�г���ѹ��ͼ*/
class SyuruiNum_Chart
{
public:
	SyuruiNum_Chart();
	~SyuruiNum_Chart();

	void SyuruiNum();//��������
	QChartView* Get_SyuruiNum_ChartView() { return SyuruiNum_chartView; }

private:
	/*�����ڴ��ػ��ߡ���*/
	void SyuruiNum_Init();
	QChartView* SyuruiNum_chartView;
	QChart* SyuruiNum_chart;
	QBarSet* SyuruiNum_bars;
	QBarSeries* SyuruiNum_series;
	QSplineSeries* SyuruiNum_seriesSpline;
	QCategoryAxis* SyuruiNum_axisX;
	QValueAxis* SyuruiNum_axisY;
};
