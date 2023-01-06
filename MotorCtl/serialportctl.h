#ifndef SERIALPORTCTL_H
#define SERIALPORTCTL_H

#include <QWidget>
#include "ui_serialportctl.h"
#include<QDate>
#include "SerialPortCom.h"

class SerialPortCtl : public QWidget
{
	Q_OBJECT

public:
	SerialPortCtl(QWidget *parent = 0);
	~SerialPortCtl();

	SerialPortCom* TerminalRegister1;//控制COM8——M1M2M3
	SerialPortCom* TerminalRegister2;//控制COM9——M4M5M6

	SerialPortCom* TerminalEncoder1;//绝对式编码器端口1
	SerialPortCom* TerminalEncoder2;//绝对式编码器端口2
	SerialPortCom* TerminalEncoder3;//绝对式编码器端口3
	SerialPortCom* TerminalEncoder4;//绝对式编码器端口4
	SerialPortCom* TerminalEncoder5;//绝对式编码器端口5
	SerialPortCom* TerminalEncoder6;//绝对式编码器端口6

	void GetPosition(int);//获取定位
	void GetStatu(int);//获取运动状态
	void SetOpcode(int station,int opcode);//COPODE
	void SetMotorSpeed(int station,int addS=1,int subS=1,int S=1);//设置速度
	void SetPosition(int station,int position,int addS=1,int subS=1,int S=1);//设置位置
	void CtlRelativeMove(int station);//相对运动
	void CtlAbsoluteMove(int station);//绝对运动
private:
	Ui::SerialPortCtl ui;
	QPushButton* p;
	bool ComOpen(SerialPortCom*,QString);
private slots:
	bool ComConnect();
	void SendMsg(QByteArray);
	void GetError(SerialPortCom*);
};

#endif // SERIALPORTCTL_H
