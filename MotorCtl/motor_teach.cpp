#include "motor_teach.h"
#include "ILDRSystem.h"
extern SysMainUI* pMainFrm;

Motor_Teach::Motor_Teach(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	Init();
	Connects();
}

Motor_Teach::~Motor_Teach()
{
	Spc->hide();
	delete Spc;
}

void Motor_Teach::Init()
{
	/*串口控制界面*/
	Spc=new SerialPortCtl();
	//Spc->show();
	/*设置界面*/
	Ms=new MotorSetting();
	//Ms->show();
	/*仅限数字输入*/
	QIntValidator *IntValidator=new QIntValidator();
	IntValidator->setRange(0,10000);
	ui.Le_1->setValidator(IntValidator);
	ui.Le_2->setValidator(IntValidator);
	ui.Le_3->setText(QString::number(BaseValueAtLimitSwitch3,10));
	ui.Le_4->setText(QString::number(BaseValueAtLimitSwitch4,10));
	ui.Le_5->setText(QString::number(BaseValueAtLimitSwitch5,10));
	ui.Le_6->setText(QString::number(BaseValueAtLimitSwitch6,10));
	UserTextRange();
	/*默认1mm*/
	ui.Rb_10mm->setChecked(true);
	/*初始化上一个坐标值*/
	EncoderPositionChange.resize(6);
	EncoderPositionLast<<-1<<-1<<-1<<-1<<-1<<-1;
	LastPosition<<-1<<-1<<-1<<-1<<-1<<-1;
	StopTimer<<0<<0<<0<<0<<0<<0;
	t=new QTimer(this);
	connect(t,SIGNAL(timeout()),this,SLOT(RefAndReadSlot()));
	t->start(1000);
}

void Motor_Teach::Connects()
{
	connect(ui.Bt_AppAndRef,SIGNAL(clicked()),this,SLOT(ApplyAndRefSlot()));
	connect(ui.Bt_DiscardChange,SIGNAL(clicked()),this,SLOT(DiscardChangeSlot()));
	connect(ui.Bt_RefAndRead,SIGNAL(clicked()),this,SLOT(RefAndReadSlot()));

	connect(ui.Bt_Proposed1,SIGNAL(clicked()),this,SLOT(ProposedSlot()));
	connect(ui.Bt_Proposed2,SIGNAL(clicked()),this,SLOT(ProposedSlot()));
	connect(ui.Bt_Proposed3,SIGNAL(clicked()),this,SLOT(ProposedSlot()));
	connect(ui.Bt_Proposed4,SIGNAL(clicked()),this,SLOT(ProposedSlot()));
	connect(ui.Bt_Proposed5,SIGNAL(clicked()),this,SLOT(ProposedSlot()));
	connect(ui.Bt_Proposed6,SIGNAL(clicked()),this,SLOT(ProposedSlot()));

	connect(ui.Bt_Add1,SIGNAL(clicked()),this,SLOT(AddSlot()));
	connect(ui.Bt_Add2,SIGNAL(clicked()),this,SLOT(AddSlot()));
	connect(ui.Bt_Add3,SIGNAL(clicked()),this,SLOT(AddSlot()));
	connect(ui.Bt_Add4,SIGNAL(clicked()),this,SLOT(AddSlot()));
	connect(ui.Bt_Add5,SIGNAL(clicked()),this,SLOT(AddSlot()));
	connect(ui.Bt_Add6,SIGNAL(clicked()),this,SLOT(AddSlot()));

	connect(ui.Bt_Sub1,SIGNAL(clicked()),this,SLOT(SubSlot()));
	connect(ui.Bt_Sub2,SIGNAL(clicked()),this,SLOT(SubSlot()));
	connect(ui.Bt_Sub3,SIGNAL(clicked()),this,SLOT(SubSlot()));
	connect(ui.Bt_Sub4,SIGNAL(clicked()),this,SLOT(SubSlot()));
	connect(ui.Bt_Sub5,SIGNAL(clicked()),this,SLOT(SubSlot()));
	connect(ui.Bt_Sub6,SIGNAL(clicked()),this,SLOT(SubSlot()));

	connect(Spc->TerminalEncoder1,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalEncoder2,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalEncoder3,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalEncoder4,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalEncoder5,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalEncoder6,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(EncoderMsgGetSlot(SerialPortCom*)));

	connect(Spc->TerminalRegister1,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(RegisterMsgGetSlot(SerialPortCom*)));
	connect(Spc->TerminalRegister2,SIGNAL(readyRead(SerialPortCom*)),this,SLOT(RegisterMsgGetSlot(SerialPortCom*)));

	connect(Ms,SIGNAL(FindLowerLimit()),this,SLOT(FindLowerLimitSlot()));
	connect(Ms,SIGNAL(ValueChange()),this,SLOT(UserTextRange()));

	//ui.Le_1->setStyleSheet("background-color: rgb(255, 170, 0);");
}



void Motor_Teach::ApplyAndRefSlot()
{
	RefAndReadSlot();
	Sleep(500);
	LastPosition[0]=ui.Le_1->text().toInt();
	HeightFromConveyor(0x01,ui.Le_1->text().toInt());
	Sleep(500);
	LastPosition[1]=ui.Le_2->text().toInt();
	HeightFromConveyor(0x02,ui.Le_2->text().toInt());
	Sleep(500);
	LastPosition[2]=ui.Le_3->text().toInt();
	NominalBottleRadius(0x03,ui.Le_3->text().toInt());
	Sleep(500);
	LastPosition[3]=ui.Le_4->text().toInt();
	NominalBottleRadius(0x04,ui.Le_4->text().toInt());
	Sleep(500);
	LastPosition[4]=ui.Le_5->text().toInt();
	DistanceBetweenLight(0x05,ui.Le_5->text().toInt());
	Sleep(500);
	LastPosition[5]=ui.Le_6->text().toInt();
	DistanceBetweenLight(0x06,ui.Le_6->text().toInt());
	Sleep(500);
}

void Motor_Teach::DiscardChangeSlot()
{
	ui.Le_1->setText("0");
	ui.Le_2->setText("0");
	ui.Le_3->setText("0");
	ui.Le_4->setText("0");
	ui.Le_5->setText("0");
	ui.Le_6->setText("0");

}

void Motor_Teach::RefAndReadSlot()
{
	Spc->GetPosition(0x01);
	Spc->GetPosition(0x02);
	Spc->GetPosition(0x03);
	Spc->GetPosition(0x04);
	Spc->GetPosition(0x05);
	Spc->GetPosition(0x06);
}

void Motor_Teach::FindLowerLimitSlot()
{
	for(int i=0;i<LastPosition.size();i++)
	{
		LastPosition[i]=0;
	}
	Spc->SetOpcode(0x01,3);
	Spc->SetOpcode(0x02,3);
	Spc->SetOpcode(0x03,3);
	Spc->SetOpcode(0x04,3);
	Spc->SetOpcode(0x05,3);
	Spc->SetOpcode(0x06,3);
	Sleep(1000);
	Spc->SetMotorSpeed(0x01,1,1,-1);
	Spc->SetMotorSpeed(0x02,1,1,-1);
	Spc->SetMotorSpeed(0x03,1,1,-1);
	Spc->SetMotorSpeed(0x04,1,1,-1);
	Spc->SetMotorSpeed(0x05,1,1,1);
	Spc->SetMotorSpeed(0x06,1,1,1);
	Sleep(1000);
	Spc->SetOpcode(0x01,2);
	Spc->SetOpcode(0x02,2);
	Spc->SetOpcode(0x03,2);
	Spc->SetOpcode(0x04,2);
	Spc->SetOpcode(0x05,2);
	Spc->SetOpcode(0x06,2);
}

/*下限机距离*/
void Motor_Teach::HeightFromConveyor(int station,int move)
{
	int distance;
	if(station!=0x01&&station!=0x02||station==0x01&&EncoderPositionChange[0]==true||station==0x02&&EncoderPositionChange[1]==true)
		return;
	if(station==0x01)
		distance=ui.Distance1->text().toInt();
	else
		distance=ui.Distance2->text().toInt();

	int position=(move-distance)/ScrewThread1*StepNumber1*100;
	Spc->SetPosition(station,position);
	Spc->CtlRelativeMove(station);
}
/*瓶子半径*/
void Motor_Teach::NominalBottleRadius(int station,int radius)
{
	int distance;
	int position;
	if(station!=0x03&&station!=0x04||station==0x03&&EncoderPositionChange[2]==true||station==0x04&&EncoderPositionChange[3]==true)
		return;
	if(station==0x03)
	{
		distance=ui.Distance3->text().toInt();
		if(radius<=BaseValueAtLimitSwitch3)
			position=(-distance)/ScrewThread2*StepNumber2*100;
		else
			position=(radius-distance-BaseValueAtLimitSwitch3)/ScrewThread2*StepNumber2*100;
	}
	else
	{
		distance=ui.Distance4->text().toInt();
		if(radius<=BaseValueAtLimitSwitch4)
			position=(-distance)/ScrewThread2*StepNumber2*100;
		else
			position=(radius-distance-BaseValueAtLimitSwitch4)/ScrewThread2*StepNumber2*100;
	}
	Spc->SetPosition(station,position);
	Spc->CtlRelativeMove(station);
}
/*光源间隔*/
void Motor_Teach::DistanceBetweenLight(int station,int dis)
{
	int distance;
	int position;
	if(station!=0x05&&station!=0x06||station==0x05&&EncoderPositionChange[4]==true||station==0x06&&EncoderPositionChange[5]==true)
		return;
	if(station==0x05)
	{
		distance=ui.Distance5->text().toInt();
		position=(dis-distance*2-BaseValueAtLimitSwitch5)/2/ScrewThread3*StepNumber3*100;
	}
	else
	{
		distance=ui.Distance6->text().toInt();
		position=(dis-distance*2-BaseValueAtLimitSwitch6)/2/ScrewThread3*StepNumber3*100;
	}
	Spc->SetPosition(station,-position);
	Spc->CtlRelativeMove(station);
}


void Motor_Teach::MotorStatuChange(int num,int statu)
{
	QString color;
	switch(statu)
	{
	case 0:color="QLabel{""color:black;""}";break;
	case 1:color="QLabel{""color:yellow;""}";break;
	case 2:color="QLabel{""color:blue;""}";break;
	}
	switch(num)
	{
	case 1:ui.Lb_1->setStyleSheet(color);break;
	case 2:ui.Lb_2->setStyleSheet(color);break;
	case 3:ui.Lb_3->setStyleSheet(color);break;
	case 4:ui.Lb_4->setStyleSheet(color);break;
	case 5:ui.Lb_5->setStyleSheet(color);break;
	case 6:ui.Lb_6->setStyleSheet(color);break;
	}
}

void Motor_Teach::UserTextRange()
{
	QIntValidator IntValidator;
	IntValidator.setRange(BaseValueAtLimitSwitch3,10000);
	ui.Le_3->setValidator(&IntValidator);
	IntValidator.setRange(BaseValueAtLimitSwitch4,10000);
	ui.Le_4->setValidator(&IntValidator);
	IntValidator.setRange(BaseValueAtLimitSwitch5,10000);
	ui.Le_5->setValidator(&IntValidator);
	IntValidator.setRange(BaseValueAtLimitSwitch6,10000);
	ui.Le_6->setValidator(&IntValidator);
}

void Motor_Teach::GetCurrentPosition()/*获取电机当前位置 */ 
{
	Spc->GetPosition(0x01);
	Spc->GetPosition(0x02);
	Spc->GetPosition(0x03);
	Spc->GetPosition(0x04);
	Spc->GetPosition(0x05);
	Spc->GetPosition(0x06);
}

void Motor_Teach::RegisterMsgGetSlot(SerialPortCom* com)
{
	if(!com)
		return;
	/*
	由于串口通信接受消息的时候会附带一条为空的消息，所以这里加以限制
	正常返回数据XX：正常处理
	空返回数据0：此时忽略
	异常返回数据1：异常处理
	*/
	QByteArray res=com->ComGetMsg();
	if(res.size()==0)
		return;
	//qDebug()<<res.toHex();
	if(res.size()!=9)
	{
		return;
	}
	if((int)res[1]!=0x03||(int)res[2]!=0x04)
		return;
	bool start;
	if((int)res[4]==0x09)
		start=false;
	else
		start=true;
	switch((int)res[0])
	{
	case 0x01:MotorStatuChange(1,start);break;
	case 0x02:MotorStatuChange(2,start);break;
	case 0x03:MotorStatuChange(3,start);break;
	case 0x04:MotorStatuChange(4,start);break;
	case 0x05:MotorStatuChange(5,start);break;
	case 0x06:MotorStatuChange(6,start);break;
	}

}

void Motor_Teach::EncoderMsgGetSlot(SerialPortCom* com)
{
	if(!com)
		return;
	/*
	由于串口通信接受消息的时候会附带一条为空的消息，所以这里加以限制
	正常返回数据XX：正常处理
	空返回数据0：此时忽略
	异常返回数据1：异常处理
	*/
	QByteArray res=com->ComGetMsg();
	if(res.size()==0)
		return;
	QString msg;
	int position;//编码器值
	int limitPosition;//距离下限位
	if(res.size()==1)
	{
		msg=com->Get_LastErrorMsg();
	}
	else
	{
		position=MsgTakePosition(res);
		limitPosition=FormulaLowerLimit(position,com);
		msg=QString::number(limitPosition,10);//编码器值转下限距离
	}
	res.toHex();
	if(com==Spc->TerminalEncoder1)
	{
		EncoderPositionChange[0]=true;
		ui.Distance1->setText(msg);
		Ms->SetLimitPosition(1,position);
	}
	if(com==Spc->TerminalEncoder1)
	{
		EncoderPositionChange[0]=true;
		ui.Distance1->setText(msg);
		Ms->SetLimitPosition(1,position);
		ui.Le_1->setStyleSheet("background-color: rgb(255,170,0);");
		if(EncoderPositionLast[0]==-1||EncoderPositionLast[0]==position||abs(EncoderPositionLast[0]-position)<=1000)
		{
			EncoderPositionChange[0]=false;
			MotorStatuChange(1,0);
			if(abs(limitPosition-LastPosition[0])<=1)
			{
				ui.Le_1->setStyleSheet("background-color: rgb(255,255,255);");
			}
			StopTimer[0]++;
			if(LastPosition[0]!=-1&&StopTimer[0]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(limitPosition-LastPosition[0])<=1)
				{
				}
				else
				{
					HeightFromConveyor(0x01,LastPosition[0]);
				}
				StopTimer[0]=0;
			}
		}
		else if(EncoderPositionLast[0]>position)
		{
			MotorStatuChange(1,1);
			StopTimer[0]=0;
		}
		else
		{
			MotorStatuChange(1,2);
			StopTimer[0]=0;
		}
		EncoderPositionLast[0]=position;
	}
	if(com==Spc->TerminalEncoder2)
	{
		EncoderPositionChange[1]=true;
		Ms->SetLimitPosition(2,position);
		ui.Distance2->setText(msg);
		ui.Le_2->setStyleSheet("background-color: rgb(255, 170, 0);");
		if(EncoderPositionLast[1]==-1||EncoderPositionLast[1]==position||abs(EncoderPositionLast[1]-position)<=1000)
		{
			EncoderPositionChange[1]=false;
			MotorStatuChange(2,0);
			if(abs(limitPosition-LastPosition[1])<=1)
				ui.Le_2->setStyleSheet("background-color: rgb(255,255,255);");
			StopTimer[1]++;
			if(LastPosition[1]!=-1&&StopTimer[1]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(position-LastPosition[1])<=1)
				{
					ui.Distance2->setText(QString::number(LastPosition[1],10));
				}
				else
				{
					HeightFromConveyor(0x02,LastPosition[1]);
				}
				StopTimer[1]=0;
			}
		}
		else if(EncoderPositionLast[1]>position)
		{
			MotorStatuChange(2,1);
			StopTimer[1]=0;
		}
		else
		{
			MotorStatuChange(2,2);
			StopTimer[1]=0;
		}
		EncoderPositionLast[1]=position;
	}
	if(com==Spc->TerminalEncoder3)
	{
		EncoderPositionChange[2]=true;
		Ms->SetLimitPosition(3,position);
		ui.Distance3->setText(msg);
		ui.Le_3->setStyleSheet("background-color: rgb(255, 170, 0);");
		if(EncoderPositionLast[2]==-1||EncoderPositionLast[2]==position||abs(EncoderPositionLast[2]-position)<=1000)
		{
			EncoderPositionChange[2]=false;
			MotorStatuChange(3,0);
			if(abs(limitPosition+BaseValueAtLimitSwitch3-ui.Le_3->text().toInt())<=1||ui.Le_3->text().toInt()<=BaseValueAtLimitSwitch3&&limitPosition==0)
				ui.Le_3->setStyleSheet("background-color: rgb(255,255,255);");
			StopTimer[2]++;
			if(LastPosition[2]!=-1&&StopTimer[2]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(position+BaseValueAtLimitSwitch3-LastPosition[2])<=1)
				{
					ui.Distance3->setText(QString::number(LastPosition[2],10));
				}
				else
				{
					HeightFromConveyor(0x03,LastPosition[2]);
				}
				StopTimer[2]=0;
			}
		}
		else if(EncoderPositionLast[2]>position)
		{
			MotorStatuChange(3,1);
			StopTimer[2]=0;
	}
		else
		{
			MotorStatuChange(3,2);
			StopTimer[2]=0;
		}
		EncoderPositionLast[2]=position;
	}
	if(com==Spc->TerminalEncoder4)
	{
		EncoderPositionChange[3]=true;
		Ms->SetLimitPosition(4,position);
		ui.Distance4->setText(msg);
		ui.Le_4->setStyleSheet("background-color: rgb(255, 170, 0);");
		if(EncoderPositionLast[3]==-1||EncoderPositionLast[3]==position||abs(EncoderPositionLast[3]-position)<=1000)
		{
			EncoderPositionChange[3]=false;
			MotorStatuChange(4,0);
			if(abs(limitPosition+BaseValueAtLimitSwitch4-ui.Le_4->text().toInt())<=1||ui.Le_4->text().toInt()<=BaseValueAtLimitSwitch4&&limitPosition==0)
				ui.Le_4->setStyleSheet("background-color: rgb(255,255,255);");
			StopTimer[3]++;
			if(LastPosition[3]!=-1&&StopTimer[3]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(position+BaseValueAtLimitSwitch4-LastPosition[3])<=1)
				{
					ui.Distance4->setText(QString::number(LastPosition[3],10));
				}
				else
				{
					HeightFromConveyor(0x04,LastPosition[3]);
				}
				StopTimer[3]=0;
			}
		}
		else if(EncoderPositionLast[3]>position)
		{
			MotorStatuChange(4,1);
			StopTimer[3]=0;
		}
		else
		{
			MotorStatuChange(4,2);		
			StopTimer[3]=0;
		}	
		EncoderPositionLast[3]=position;
	}
	//M5和M6电机是正速度下降间隔缩小、负速度上升间隔增大
	if(com==Spc->TerminalEncoder5)
	{
		EncoderPositionChange[4]=true;
		Ms->SetLimitPosition(5,position);
		ui.Distance5->setText(msg);
		ui.Le_5->setStyleSheet("background-color: rgb(255, 170, 0);");
		if(EncoderPositionLast[4]==-1||EncoderPositionLast[4]==position||abs(EncoderPositionLast[4]-position)<=1000)
		{
			EncoderPositionChange[4]=false;
			MotorStatuChange(5,0);
			if(abs(limitPosition*2+BaseValueAtLimitSwitch5-ui.Le_5->text().toInt())<=1)
				ui.Le_5->setStyleSheet("background-color: rgb(255,255,255);");
			StopTimer[4]++;
			if(LastPosition[4]!=-1&&StopTimer[4]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(position*2+BaseValueAtLimitSwitch5-LastPosition[4])<=1)
				{
					ui.Distance5->setText(QString::number((LastPosition[4]-BaseValueAtLimitSwitch5)/2,10));
				}
				else
				{
					HeightFromConveyor(0x05,LastPosition[4]);
				}
				StopTimer[4]=0;
			}
		}
		else if(EncoderPositionLast[4]>position)
		{	
			MotorStatuChange(5,2);
			StopTimer[4]=0;
		}
		else
		{
			MotorStatuChange(5,1);
			StopTimer[4]=0;
		}
		EncoderPositionLast[4]=position;
	}
	if(com==Spc->TerminalEncoder6)
	{
		EncoderPositionChange[5]=true;
		Ms->SetLimitPosition(6,position);
		ui.Distance6->setText(msg);
		ui.Le_6->setStyleSheet("background-color: rgb(255, 170, 0);");
		if(EncoderPositionLast[5]==-1||EncoderPositionLast[5]==position||abs(EncoderPositionLast[5]-position)<=1000)
		{
			EncoderPositionChange[5]=false;
			MotorStatuChange(6,0);
			if(abs(limitPosition*2+BaseValueAtLimitSwitch6-ui.Le_6->text().toInt())<=1)
				ui.Le_6->setStyleSheet("background-color: rgb(255,255,255);");
			StopTimer[5]++;
			if(LastPosition[5]!=-1&&StopTimer[5]>2)//如果电机停止移动3秒，展开判断
			{
				if(abs(position*2+BaseValueAtLimitSwitch6-LastPosition[5])<=1)
				{
					ui.Distance6->setText(QString::number((LastPosition[5]-BaseValueAtLimitSwitch6)/2,10));
				}
				else
				{
					HeightFromConveyor(0x06,LastPosition[5]);
				}
				StopTimer[5]=0;
			}
		}
		else if(EncoderPositionLast[5]>position)
		{
			MotorStatuChange(6,2);
			StopTimer[5]=0;
		}
		else
		{
			MotorStatuChange(6,1);
			StopTimer[5]=0;
		}
		EncoderPositionLast[5]=position;
	}
}

int Motor_Teach::MsgTakePosition(QByteArray res)
{
	QByteArray k;
	k.push_back(res[3]);
	k.push_back(res[4]);
	k.push_back(res[5]);
	k.push_back(res[6]);
	QString value=k.toHex();
	int s=value.toInt(NULL,16);
	//qDebug()<<value<<" "<<s<<endl;
	return s;
}

int Motor_Teach::FormulaLowerLimit(int res,SerialPortCom* com)
{
	int LimitPosition;
	float ScrewThread;
	if(com==Spc->TerminalEncoder1)//M1=1
	{
		LimitPosition=LimitPosition1;
		ScrewThread=ScrewThread1;
	}
	if(com==Spc->TerminalEncoder2)//M2=1
	{
		LimitPosition=LimitPosition2;
		ScrewThread=ScrewThread1;
	}
	if(com==Spc->TerminalEncoder3)//M3=2
	{
		LimitPosition=LimitPosition3;
		ScrewThread=ScrewThread2;
	}
	if(com==Spc->TerminalEncoder4)//M4=2
	{
		LimitPosition=LimitPosition4;
		ScrewThread=ScrewThread2;
	}
	if(com==Spc->TerminalEncoder5)//M5=3
	{
		LimitPosition=LimitPosition5;
		ScrewThread=ScrewThread3;
		if(res<1000)//由于之前把编码器置0的原因，出现了一些错误，一个特别的处理方式
			return 0;
	}
	if(com==Spc->TerminalEncoder6)//M6=3
	{
		LimitPosition=LimitPosition6;
		ScrewThread=ScrewThread3;
		if(res<1000)
			return 0;
	}
	/*电机距离下限的计算方式
	1:当前位置编码器值-下限位置编码器值
	2:值除以编码器旋转一圈需要的步数得到旋转圈数
	3:圈数乘以螺纹导程得到距离差
	4:四舍五入
	*/
	double result;
	result=abs(res-LimitPosition);
	result=result/RotationOfEncoder;
	result=result*ScrewThread;
	if(result>(int)result+0.5)
		return (int)(result+1);
	else
		return (int)result;
	
}

void Motor_Teach::ProposedSlot()
{
	p=(QPushButton *)QObject::sender();
	if(p->objectName()=="Bt_Proposed1")
		ui.Le_1->setText(QString::number(Calibration1-100+Height_Datamatrix,10));
	if(p->objectName()=="Bt_Proposed2")
		ui.Le_2->setText(QString::number(Calibration2-100+Height_Datamatrix,10));
	if(p->objectName()=="Bt_Proposed3")
		ui.Le_3->setText(QString::number(DM_Height/2));
	if(p->objectName()=="Bt_Proposed4")
		ui.Le_4->setText(QString::number(DM_Height/2));
	if(p->objectName()=="Bt_Proposed5")
		ui.Le_5->setText("50");
	if(p->objectName()=="Bt_Proposed6")
		ui.Le_6->setText("50");
}

void Motor_Teach::AddSlot()
{
	p=(QPushButton *)QObject::sender();
	int value;
	if(ui.Rb_1mm->isChecked())
		value=1;
	else
		value=10;
	if(p->objectName()=="Bt_Add1")
		ui.Le_1->setText(QString::number(ui.Le_1->text().toInt()+value,10));
	if(p->objectName()=="Bt_Add2")
		ui.Le_2->setText(QString::number(ui.Le_2->text().toInt()+value,10));
	if(p->objectName()=="Bt_Add3")
		ui.Le_3->setText(QString::number(ui.Le_3->text().toInt()+value,10));
	if(p->objectName()=="Bt_Add4")
		ui.Le_4->setText(QString::number(ui.Le_4->text().toInt()+value,10));
	if(p->objectName()=="Bt_Add5")
		ui.Le_5->setText(QString::number(ui.Le_5->text().toInt()+value,10));
	if(p->objectName()=="Bt_Add6")
		ui.Le_6->setText(QString::number(ui.Le_6->text().toInt()+value,10));
	UserTextRange();
}

void Motor_Teach::SubSlot()
{
	p=(QPushButton *)QObject::sender();
	int value;
	if(ui.Rb_1mm->isChecked())
		value=1;
	else
		value=10;
	if(p->objectName()=="Bt_Sub1"&&ui.Le_1->text().toInt()-value>=0)
		ui.Le_1->setText(QString::number(ui.Le_1->text().toInt()-value,10));
	if(p->objectName()=="Bt_Sub2"&&ui.Le_2->text().toInt()-value>=0)								
		ui.Le_2->setText(QString::number(ui.Le_2->text().toInt()-value,10));
	if(p->objectName()=="Bt_Sub3"&&ui.Le_3->text().toInt()-value>=BaseValueAtLimitSwitch3)								
		ui.Le_3->setText(QString::number(ui.Le_3->text().toInt()-value,10));
	if(p->objectName()=="Bt_Sub4"&&ui.Le_4->text().toInt()-value>=BaseValueAtLimitSwitch4)								
		ui.Le_4->setText(QString::number(ui.Le_4->text().toInt()-value,10));
	if(p->objectName()=="Bt_Sub5"&&ui.Le_5->text().toInt()-value>=BaseValueAtLimitSwitch5)								
		ui.Le_5->setText(QString::number(ui.Le_5->text().toInt()-value,10));
	if(p->objectName()=="Bt_Sub6"&&ui.Le_6->text().toInt()-value>=BaseValueAtLimitSwitch6)								
		ui.Le_6->setText(QString::number(ui.Le_6->text().toInt()-value,10));
	UserTextRange();
}
