#pragma once

#include"SyuruiNum_Chart.h"

class Charts : public QWidget
{
	Q_OBJECT

public:
	Charts(QWidget *parent=nullptr);
	~Charts();
public:
	/*ѹ��ͼ*/
	void update_SyuruiNum() { p_c->SyuruiNum(); }
	QChartView* get_SyuruiNum() { return p_c->Get_SyuruiNum_ChartView(); }
	///*����ͼ*/
	//void update_CouplerForce(QVector<QString>Trains) { c_c->CouplerForce(Trains); }
	//QChartView* get_CouplerForce() { return c_c->Get_CouplerForce_chartView(); }
	///*�ѹ�ϵ��*/
	//void update_DerailmentCoefficient(QVector<QString>Trains) { d_c->DerailmentCoefficient(Trains); }
	//QChartView* get_DerailmentCoefficient() { return d_c->Get_DerailmentCoefficient_chartView(); }
	///*����ͼ*/
	//void update_CurveLine(QString tm) { l_c->CurveLine(tm); }
	//QChartView* get_CurveLine() { return l_c->Get_CurveLine_chartView(); }
	///*�ݶ���*/
	//void update_VerticalSection(QVector<QString>Trains, QString tm) { v_c->VerticalSection(Trains,tm); };
	//QChartView* get_VerticalSection() { return v_c->Get_VerticalSection_chartView(); }
private:
	SyuruiNum_Chart* p_c;
	//CouplerForce_Chart* c_c;
	//DerailmentCoefficient_Chart* d_c;
	//CurveLine_Chart* l_c;
	//VerticalSection_Chart* v_c;
};
