#include "Charts.h"

Charts::Charts(QWidget *parent)
	: QWidget(parent)
{
    p_c = new SyuruiNum_Chart();
    //c_c = new CouplerForce_Chart();
    //d_c = new DerailmentCoefficient_Chart();
    //l_c = new CurveLine_Chart();
    //v_c = new VerticalSection_Chart();
}

Charts::~Charts()
{
    delete p_c;
    //delete c_c;
    //delete v_c;
    //delete l_c;
    //delete d_c;
}


