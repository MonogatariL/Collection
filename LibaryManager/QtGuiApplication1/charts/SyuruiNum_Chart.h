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

/*列车管压力图*/
class SyuruiNum_Chart
{
public:
	SyuruiNum_Chart();
	~SyuruiNum_Chart();

	void SyuruiNum();//更新数据
	QChartView* Get_SyuruiNum_ChartView() { return SyuruiNum_chartView; }

private:
	/*☆☆☆内存守护者☆☆☆*/
	void SyuruiNum_Init();
	QChartView* SyuruiNum_chartView;
	QChart* SyuruiNum_chart;
	QBarSet* SyuruiNum_bars;
	QBarSeries* SyuruiNum_series;
	QSplineSeries* SyuruiNum_seriesSpline;
	QCategoryAxis* SyuruiNum_axisX;
	QValueAxis* SyuruiNum_axisY;
};
