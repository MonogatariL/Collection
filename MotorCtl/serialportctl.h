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

	SerialPortCom* TerminalRegister1;//����COM8����M1M2M3
	SerialPortCom* TerminalRegister2;//����COM9����M4M5M6

	SerialPortCom* TerminalEncoder1;//����ʽ�������˿�1
	SerialPortCom* TerminalEncoder2;//����ʽ�������˿�2
	SerialPortCom* TerminalEncoder3;//����ʽ�������˿�3
	SerialPortCom* TerminalEncoder4;//����ʽ�������˿�4
	SerialPortCom* TerminalEncoder5;//����ʽ�������˿�5
	SerialPortCom* TerminalEncoder6;//����ʽ�������˿�6

	void GetPosition(int);//��ȡ��λ
	void GetStatu(int);//��ȡ�˶�״̬
	void SetOpcode(int station,int opcode);//COPODE
	void SetMotorSpeed(int station,int addS=1,int subS=1,int S=1);//�����ٶ�
	void SetPosition(int station,int position,int addS=1,int subS=1,int S=1);//����λ��
	void CtlRelativeMove(int station);//����˶�
	void CtlAbsoluteMove(int station);//�����˶�
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
