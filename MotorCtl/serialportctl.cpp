#include "serialportctl.h"

SerialPortCtl::SerialPortCtl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	TerminalRegister1=new SerialPortCom("COM8");
	TerminalRegister2=new SerialPortCom("COM9");
	TerminalEncoder1=new SerialPortCom("COM10");
	TerminalEncoder2=new SerialPortCom("COM11");
	TerminalEncoder3=new SerialPortCom("COM12");
	TerminalEncoder4=new SerialPortCom("COM13");
	TerminalEncoder5=new SerialPortCom("COM14");
	TerminalEncoder6=new SerialPortCom("COM15");

	connect(TerminalRegister1,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalRegister2,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder1,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder2,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder3,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder4,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder5,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder6,SIGNAL(sendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));
	connect(TerminalEncoder6,SIGNAL(SendMsg(QByteArray)),this,SLOT(SendMsg(QByteArray)));

	connect(TerminalRegister1,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalRegister2,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder1,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder2,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder3,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder4,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder5,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));
	connect(TerminalEncoder6,SIGNAL(abnormalReturn(this)),this,SLOT(GetError(this)));

	connect(ui.Bt_Connect1,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect2,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect3,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect4,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect5,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect6,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect7,SIGNAL(clicked()),this,SLOT(ComConnect()));
	connect(ui.Bt_Connect8,SIGNAL(clicked()),this,SLOT(ComConnect()));

}

SerialPortCtl::~SerialPortCtl()
{

}

bool SerialPortCtl::ComConnect()
{
	p=(QPushButton *)QObject::sender();
	if(p->objectName()=="Bt_Connect1")
		return ComOpen(TerminalRegister1,ui.Le_PortName1->text());
	if(p->objectName()=="Bt_Connect2")
		return ComOpen(TerminalRegister2,ui.Le_PortName2->text());
	if(p->objectName()=="Bt_Connect3")
		return ComOpen(TerminalEncoder1,ui.Le_PortName3->text());
	if(p->objectName()=="Bt_Connect4")
		return ComOpen(TerminalEncoder2,ui.Le_PortName4->text());
	if(p->objectName()=="Bt_Connect5")
		return ComOpen(TerminalEncoder3,ui.Le_PortName5->text());
	if(p->objectName()=="Bt_Connect6")
		return ComOpen(TerminalEncoder4,ui.Le_PortName6->text());
	if(p->objectName()=="Bt_Connect7")
		return ComOpen(TerminalEncoder5,ui.Le_PortName7->text());
	if(p->objectName()=="Bt_Connect8")
		return ComOpen(TerminalEncoder6,ui.Le_PortName8->text());
}

void SerialPortCtl::SendMsg(QByteArray res)
{
	return;
	QByteArray temp =res;
	//if(temp.size()==0)
	//	return ;
	QDataStream out(&temp,QIODevice::ReadWrite);    //将字节数组读入
	ui.Te_Msg->insertPlainText(QDateTime::currentDateTime().toString("\nyyyy-MM-dd hh:mm:ss") + " [SEND] ");
	while(!out.atEnd())
	{
		qint8 outChar = 0;
		out>>outChar;   //每字节填充一次，直到结束
		//十六进制的转换
		QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
		ui.Te_Msg->insertPlainText(str.toUpper());//大写
		ui.Te_Msg->insertPlainText(" ");//每发送两个字符后添加一个空格
		ui.Te_Msg->moveCursor(QTextCursor::End);
	}
	ui.Te_Msg->insertPlainText("\n");
}

void SerialPortCtl::GetError(SerialPortCom* com)
{
	ui.Te_Msg->insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " [errorGet]"+TerminalRegister1->Get_LastErrorMsg()+"\n");
}

bool SerialPortCtl::ComOpen(SerialPortCom* com,QString portname)
{
	com->setPortName(portname);
	if(com->ComOpen())
	{
		ui.Te_Msg->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + " [remind]PortOpen:" + portname + "\n");
		return true;
	}
	else
	{
		ui.Te_Msg->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + " [remind]PortOpenError:" + portname + "\n");
		return false;
	}
}

void SerialPortCtl::GetPosition(int station)
{
	switch(station)
	{
	case 0x01:TerminalEncoder1->Get_RealTimeDate(0x01);break;
	case 0x02:TerminalEncoder2->Get_RealTimeDate(0x01);break;
	case 0x03:TerminalEncoder3->Get_RealTimeDate(0x01);break;
	case 0x04:TerminalEncoder4->Get_RealTimeDate(0x01);break;
	case 0x05:TerminalEncoder5->Get_RealTimeDate(0x01);break;
	case 0x06:TerminalEncoder6->Get_RealTimeDate(0x01);break;
	}
}

void SerialPortCtl::GetStatu(int station)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Get_StatusCode(0x01);break;
	case 0x02:TerminalRegister1->Get_StatusCode(0x02);break;
	case 0x03:TerminalRegister1->Get_StatusCode(0x03);break;
	case 0x04:TerminalRegister2->Get_StatusCode(0x04);break;
	case 0x05:TerminalRegister2->Get_StatusCode(0x05);break;
	case 0x06:TerminalRegister2->Get_StatusCode(0x06);break;
	}
}

void SerialPortCtl::SetOpcode(int station,int code)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Ctl_Opcode(0x01,code);break;
	case 0x02:TerminalRegister1->Ctl_Opcode(0x02,code);break;
	case 0x03:TerminalRegister1->Ctl_Opcode(0x03,code);break;
	case 0x04:TerminalRegister2->Ctl_Opcode(0x04,code);break;
	case 0x05:TerminalRegister2->Ctl_Opcode(0x05,code);break;
	case 0x06:TerminalRegister2->Ctl_Opcode(0x06,code);break;
	}
}

void SerialPortCtl::SetMotorSpeed(int station,int addS,int subS,int S)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Set_SpeedControl(0x01,addS,subS,S);break;
	case 0x02:TerminalRegister1->Set_SpeedControl(0x02,addS,subS,S);break;
	case 0x03:TerminalRegister1->Set_SpeedControl(0x03,addS,subS,S);break;
	case 0x04:TerminalRegister2->Set_SpeedControl(0x04,addS,subS,S);break;
	case 0x05:TerminalRegister2->Set_SpeedControl(0x05,addS,subS,S);break;
	case 0x06:TerminalRegister2->Set_SpeedControl(0x06,addS,subS,S);break;
	}
}

void SerialPortCtl::SetPosition(int station,int position,int addS/*=1*/,int subS/*=1*/,int S/*=1*/)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Set_GoPosition(0x01,position,addS,subS,S);break;
	case 0x02:TerminalRegister1->Set_GoPosition(0x02,position,addS,subS,S);break;
	case 0x03:TerminalRegister1->Set_GoPosition(0x03,position,addS,subS,S);break;
	case 0x04:TerminalRegister2->Set_GoPosition(0x04,position,addS,subS,S);break;
	case 0x05:TerminalRegister2->Set_GoPosition(0x05,position,addS,subS,S);break;
	case 0x06:TerminalRegister2->Set_GoPosition(0x06,position,addS,subS,S);break;
	}
}

void SerialPortCtl::CtlRelativeMove(int station)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Ctl_Opcode(0x01,1);break;
	case 0x02:TerminalRegister1->Ctl_Opcode(0x02,1);break;
	case 0x03:TerminalRegister1->Ctl_Opcode(0x03,1);break;
	case 0x04:TerminalRegister2->Ctl_Opcode(0x04,1);break;
	case 0x05:TerminalRegister2->Ctl_Opcode(0x05,1);break;
	case 0x06:TerminalRegister2->Ctl_Opcode(0x06,1);break;
	}
}

void SerialPortCtl::CtlAbsoluteMove(int station)
{
	switch(station)
	{
	case 0x01:TerminalRegister1->Ctl_Opcode(0x01,0);break;
	case 0x02:TerminalRegister1->Ctl_Opcode(0x02,0);break;
	case 0x03:TerminalRegister1->Ctl_Opcode(0x03,0);break;
	case 0x04:TerminalRegister2->Ctl_Opcode(0x04,0);break;
	case 0x05:TerminalRegister2->Ctl_Opcode(0x05,0);break;
	case 0x06:TerminalRegister2->Ctl_Opcode(0x06,0);break;
	}
}

