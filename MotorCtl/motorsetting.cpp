#include "motorsetting.h"
/*
100counts=1步
20000counts=1转
*/
/*M1M2电机参数:螺纹导程、步长、旋转一圈需要的步数*/
double ScrewThread1=3.175;
double StepLength1=0.015875;
long StepNumber1=200;
/*M3M4电机参数:螺纹导程、步长、旋转一圈需要的步数、下限开关界限值*/
double ScrewThread2=2.54;
double StepLength2=0.0127;
long StepNumber2=200;
long BaseValueAtLimitSwitch3=10;//当电机达到下限位的时候，此时建议拍摄的瓶子半径
long BaseValueAtLimitSwitch4=10;
/*M5M6电机参数:螺纹导程、步长、旋转一圈需要的步数、下限开关界限值*/
double ScrewThread3=2;
double StepLength3=0.01;
long StepNumber3=200;
long BaseValueAtLimitSwitch5=10;//当光源间隔电机达到下限位的时候，此时该值为光源间隔
long BaseValueAtLimitSwitch6=10;
/*6个绝对式编码器的下限值*/
long LimitPosition1=5542;//131593;
long LimitPosition2=167643;//131593;
long LimitPosition3=76978;//107333;//131593;
long LimitPosition4=122922;//131705;//131593;
long LimitPosition5=23181;//262665;
long LimitPosition6=236665;//262665;
/*绝对式编码器旋转一圈的圈数*/
long RotationOfEncoder=1024;
/*使用校准工具至限位开关M1M2的距离*/
long Calibration1=100;
long Calibration2=100;

MotorSetting::MotorSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ReadInit();
	Init();
	Connects();
}

MotorSetting::~MotorSetting()
{

}

void MotorSetting::SetLimitPosition(int station,int value)
{
	switch(station)
	{
	case 1:ui.Lb_EncoderValue1->setText(QString::number(value,10));break;
	case 2:ui.Lb_EncoderValue2->setText(QString::number(value,10));break;
	case 3:ui.Lb_EncoderValue3->setText(QString::number(value,10));break;
	case 4:ui.Lb_EncoderValue4->setText(QString::number(value,10));break;
	case 5:ui.Lb_EncoderValue5->setText(QString::number(value,10));break;
	case 6:ui.Lb_EncoderValue6->setText(QString::number(value,10));break;
	}
}

void MotorSetting::Init()
{
	QIntValidator* IntValidator = new QIntValidator();
	IntValidator->setRange(0,2147483647);
	ui.Le_ScrewThread1->setValidator(IntValidator);
	ui.Le_ScrewThread2->setValidator(IntValidator);
	ui.Le_ScrewThread3->setValidator(IntValidator);
//	ui.Le_StepLength1->setValidator(IntValidator);
//	ui.Le_StepLength2->setValidator(IntValidator);
//	ui.Le_StepLength3->setValidator(IntValidator);
	ui.Le_StepNumber1->setValidator(IntValidator);
	ui.Le_StepNumber2->setValidator(IntValidator);
	ui.Le_StepNumber3->setValidator(IntValidator);
	ui.Le_LimitPosition1->setValidator(IntValidator);
	ui.Le_LimitPosition2->setValidator(IntValidator);
	ui.Le_LimitPosition3->setValidator(IntValidator);
	ui.Le_Calibration1->setValidator(IntValidator);
	ui.Le_Calibration2->setValidator(IntValidator);
	UpData();
}

void MotorSetting::Connects()
{
	ui.Pb_Save->hide();
	connect(ui.Pb_Save,SIGNAL(clicked()),this,SLOT(SaveInit()));
	connect(ui.Pb_Export,SIGNAL(clicked()),this,SLOT(ExportInit()));
	connect(ui.Pb_FindLowerLimit,SIGNAL(clicked()),this,SLOT(FindLowerLimitSlot()));
	connect(ui.Pb_SaveToSetting,SIGNAL(clicked()),this,SLOT(SaveToSettingSlot()));
}
/*程序启动时读取配置文件*/
void MotorSetting::ReadInit()
{
	QFile file("Config/MotorSetting.ini");
	if(!file.exists())
	{
		QMessageBox::warning(this,"Warning","MotorSetting.ini not found");
		return;
	}
	QSettings m_psetting("Config/MotorSetting.ini",QSettings::IniFormat);//设置路径
	m_psetting.beginGroup("MotorSetting");
	if(m_psetting.contains("ScrewThread1"))
		ScrewThread1=m_psetting.value("ScrewThread1").toDouble();
	if(m_psetting.contains("ScrewThread2"))
		ScrewThread2=m_psetting.value("ScrewThread2").toDouble();
	if(m_psetting.contains("ScrewThread3"))
		ScrewThread3=m_psetting.value("ScrewThread3").toDouble();
	if(m_psetting.contains("StepLength1"))
		StepLength1=m_psetting.value("StepLength1").toDouble();
	if(m_psetting.contains("StepLength2"))
		StepLength2=m_psetting.value("StepLength2").toDouble();
	if(m_psetting.contains("StepLength3"))
		StepLength3=m_psetting.value("StepLength3").toDouble();
	if(m_psetting.contains("BaseValueAtLimitSwitch3"))
		BaseValueAtLimitSwitch3=m_psetting.value("BaseValueAtLimitSwitch3").toInt();
	if(m_psetting.contains("BaseValueAtLimitSwitch4"))
		BaseValueAtLimitSwitch4=m_psetting.value("BaseValueAtLimitSwitch4").toInt();
	if(m_psetting.contains("BaseValueAtLimitSwitch5"))
		BaseValueAtLimitSwitch5=m_psetting.value("BaseValueAtLimitSwitch5").toInt();
	if(m_psetting.contains("BaseValueAtLimitSwitch6"))
		BaseValueAtLimitSwitch6=m_psetting.value("BaseValueAtLimitSwitch6").toInt();
	if(m_psetting.contains("Calibration1"))
		Calibration1=m_psetting.value("Calibration1").toInt();
	if(m_psetting.contains("Calibration2"))
		Calibration2=m_psetting.value("Calibration2").toInt();
	m_psetting.endGroup();
	m_psetting.beginGroup("Encoder");
	if(m_psetting.contains("LimitPositionEncoderValue1"))
		LimitPosition1=m_psetting.value("LimitPositionEncoderValue1").toInt();
	if(m_psetting.contains("LimitPositionEncoderValue2"))
		LimitPosition2=m_psetting.value("LimitPositionEncoderValue2").toInt();
	if(m_psetting.contains("LimitPositionEncoderValue3"))
		LimitPosition3=m_psetting.value("LimitPositionEncoderValue3").toInt();
	if(m_psetting.contains("LimitPositionEncoderValue4"))
		LimitPosition4=m_psetting.value("LimitPositionEncoderValue4").toInt();
	if(m_psetting.contains("LimitPositionEncoderValue5"))
		LimitPosition5=m_psetting.value("LimitPositionEncoderValue5").toInt();
	if(m_psetting.contains("LimitPositionEncoderValue6"))
		LimitPosition6=m_psetting.value("LimitPositionEncoderValue6").toInt();
	m_psetting.endGroup();
}
void MotorSetting::UpData()
{
	ui.Le_ScrewThread1->setText(QString::number(ScrewThread1));
	ui.Le_ScrewThread2->setText(QString::number(ScrewThread2));
	ui.Le_ScrewThread3->setText(QString::number(ScrewThread3));
	//ui.Le_StepLength1->setText(QString::number(StepLength1));
	//ui.Le_StepLength2->setText(QString::number(StepLength2));
	//ui.Le_StepLength3->setText(QString::number(StepLength3));
	ui.Le_StepNumber1->setText(QString::number(StepNumber1));
	ui.Le_StepNumber2->setText(QString::number(StepNumber2));
	ui.Le_StepNumber3->setText(QString::number(StepNumber3));
	ui.Le_LimitPosition1->setText(QString::number(LimitPosition1));
	ui.Le_LimitPosition2->setText(QString::number(LimitPosition2));
	ui.Le_LimitPosition3->setText(QString::number(LimitPosition3));
	ui.Le_LimitPosition4->setText(QString::number(LimitPosition4));
	ui.Le_LimitPosition5->setText(QString::number(LimitPosition5));
	ui.Le_LimitPosition6->setText(QString::number(LimitPosition6));
	ui.Le_LimitSwitch3->setText(QString::number(BaseValueAtLimitSwitch3));
	ui.Le_LimitSwitch4->setText(QString::number(BaseValueAtLimitSwitch4));
	ui.Le_LimitSwitch5->setText(QString::number(BaseValueAtLimitSwitch5));
	ui.Le_LimitSwitch6->setText(QString::number(BaseValueAtLimitSwitch6));
	ui.Le_Calibration1->setText(QString::number(Calibration1));
	ui.Le_Calibration2->setText(QString::number(Calibration2));

}

void MotorSetting::ExportInit()
{
	SaveInit();
	QFile file("Config/MotorSetting.ini");
	if(!file.exists())
	{
		//QMessageBox::warning(this,"Warning","MotorSetting.ini not found");
		file.open(QFile::WriteOnly|QFile::Text);
		//return;
	}
	QSettings m_psetting("Config/MotorSetting.ini",QSettings::IniFormat);
	m_psetting.setIniCodec(QTextCodec::codecForName("GBK"));
	m_psetting.setValue("/MotorSetting/ScrewThread1",ui.Le_ScrewThread1->text().toDouble());
	m_psetting.setValue("/MotorSetting/ScrewThread2",ui.Le_ScrewThread2->text().toDouble());
	m_psetting.setValue("/MotorSetting/ScrewThread3",ui.Le_ScrewThread3->text().toDouble());
	//m_psetting.setValue("/MotorSetting/StepLength1",ui.Le_StepLength1->text().toDouble());
	//m_psetting.setValue("/MotorSetting/StepLength2",ui.Le_StepLength2->text().toDouble());
	//m_psetting.setValue("/MotorSetting/StepLength3",ui.Le_StepLength3->text().toDouble());
	m_psetting.setValue("/MotorSetting/BaseValueAtLimitSwitch3",ui.Le_LimitSwitch3->text().toInt());
	m_psetting.setValue("/MotorSetting/BaseValueAtLimitSwitch4",ui.Le_LimitSwitch4->text().toInt());
	m_psetting.setValue("/MotorSetting/BaseValueAtLimitSwitch5",ui.Le_LimitSwitch5->text().toInt());
	m_psetting.setValue("/MotorSetting/BaseValueAtLimitSwitch6",ui.Le_LimitSwitch6->text().toInt());
	m_psetting.setValue("/MotorSetting/Calibration1",ui.Le_Calibration1->text().toInt());
	m_psetting.setValue("/MotorSetting/Calibration2",ui.Le_Calibration2->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue1",ui.Le_LimitPosition1->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue2",ui.Le_LimitPosition2->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue3",ui.Le_LimitPosition3->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue4",ui.Le_LimitPosition4->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue5",ui.Le_LimitPosition5->text().toInt());
	m_psetting.setValue("/Encoder/LimitPositionEncoderValue6",ui.Le_LimitPosition6->text().toInt());

	QMessageBox::about(this,"Warning","Save Success");
}

void MotorSetting::SaveToSettingSlot()
{
	LimitPosition1=ui.Lb_EncoderValue1->text().toInt();
	LimitPosition2=ui.Lb_EncoderValue2->text().toInt();
	LimitPosition3=ui.Lb_EncoderValue3->text().toInt();
	LimitPosition4=ui.Lb_EncoderValue4->text().toInt();
	LimitPosition5=ui.Lb_EncoderValue5->text().toInt();
	LimitPosition6=ui.Lb_EncoderValue6->text().toInt();
	UpData();
}

void MotorSetting::SaveInit()
{
	ScrewThread1=ui.Le_ScrewThread1->text().toFloat();
	ScrewThread2=ui.Le_ScrewThread2->text().toFloat();
	ScrewThread3=ui.Le_ScrewThread3->text().toFloat();
//	StepLength1=ui.Le_StepLength1->text().toFloat();
//	StepLength2=ui.Le_StepLength2->text().toFloat();
//	StepLength3=ui.Le_StepLength3->text().toFloat();
	BaseValueAtLimitSwitch3=ui.Le_LimitSwitch3->text().toInt();
	BaseValueAtLimitSwitch4=ui.Le_LimitSwitch4->text().toInt();
	BaseValueAtLimitSwitch5=ui.Le_LimitSwitch5->text().toInt();
	BaseValueAtLimitSwitch6=ui.Le_LimitSwitch6->text().toInt();
	LimitPosition1=ui.Le_LimitPosition1->text().toInt();
	LimitPosition2=ui.Le_LimitPosition2->text().toInt();
	LimitPosition3=ui.Le_LimitPosition3->text().toInt();
	LimitPosition4=ui.Le_LimitPosition4->text().toInt();
	LimitPosition5=ui.Le_LimitPosition5->text().toInt();
	LimitPosition6=ui.Le_LimitPosition6->text().toInt();
	Calibration1=ui.Le_Calibration1->text().toInt();
	Calibration2=ui.Le_Calibration2->text().toInt();
	UpData();
	emit ValueChange();
}


