#ifndef SERIALPORTCOM_H
#define SERIALPORTCOM_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include "SerialPortParameter.h"
#include "win_qextserialport.h"
#include "qextserialenumerator.h"

class SerialPortCom : public QObject
{
	Q_OBJECT

public:
	//SerialPortCom(QObject *parent);
	SerialPortCom(QString ComName="COM1");
	~SerialPortCom();

private:
	struct PortSettings myComSetting;
	Win_QextSerialPort* myCom;
	int StationName;

	bool ComReadIs;//���Զ�ȡ
	bool ComWriteIs;//���Է���
	/*����͵ı��Ķ�Ӧ��������Ӧ�Ĳ�����һ����Ϊ����*/
	int LastStationName;
	int LastNum;
	int LastRegisterAddH;
	int LastRegisterAddL;
	int LastRegisterNumH;
	int LastRegisterNumL;
	int MsgType;/*0=0x03 1=0x06 2=0x10*/
	/*���󱨾�*/
	bool IsError;
	QString LastErrorMsg;
	/*��Ӧ��ʱ*/
	QTimer *t;
	int WaitTime;
	bool IsWait;
	/**/
	QTimer *s;
public:

	QVector<QString> Get_PortEnum();//��ȡ�˿��б�

	bool ComOpen(QIODevice::OpenModeFlag model=QIODevice::ReadWrite);	//������
	bool ComClose();													//�ر�����

	QByteArray ComGetMsg();												//��������
	void ComPutMsg(QByteArray);											//��������
		
/*������ƹ��ܼ�*/
	void Get_MotorPosition(int StationName_=-1,int k=1);//���λ�á����Ĵ�����ȡ
	void Get_StatusCode(int StationName_=-1);//����˶�״̬�����Ĵ�����ȡ 11Ϊ������ 09Ϊֹͣ
	void Get_RealTimeDate(int StationName_=-1);//��ȡʵʱ���ݡ�������ʽ������
	void Set_ToZero(int StationName_=-1);//��������0��������ʽ������
	void Ctl_Opcode(int StationName_=-1,int value=0);//�������޲���ͨ��

	//�ٶȿ������̡�����վ�������ٶȡ����ٶ�
	void Set_SpeedControl(int StationName_=-1,int AddSpeed=100,int SubSpeed=100,int Speed=10);
	//λ�ÿ������̡�����վ����Ŀ��λ�á����ٶȡ����ٶȡ��ٶ�
	void Set_GoPosition(int StationName_=-1,int Position=200000,int AddSpeed=100,int SubSpeed=100,int Speed=1);

private:
	QByteArray MsgHanding03(QByteArray);
	QByteArray MsgHanding06(QByteArray);
	QByteArray MsgHanding10(QByteArray);

	void Set_LastResponse(int,int,int,int,int,int);//����ָ���洢�ô�ָ�����ݲ����ݷ������ݽ��жԱ�
	void ComGetMsgError(QString setError);//���ô���ԭ�򲢷��;����ź�
signals:
	void readyRead(SerialPortCom* my);
	void abnormalReturn();
	void abnormalReturn(SerialPortCom*);
	void sendMsg(QByteArray);
private slots:
	void _readyRead()
	{
		emit readyRead(this);
	}
	void _timeOut()
	{
		MsgType=0;
		ComGetMsgError("Recive time out");
	}
/*���׽ӿ�*/
public:
	/*��������*/
	void ComSetting(BaudRateType BaudRate=BAUD9600,DataBitsType DataBits=DATA_8,ParityType Parity=PAR_NONE,	
		StopBitsType StopBits=STOP_1,FlowType FlowControl=FLOW_OFF,long Timeout_Millisec=500);
	QString Get_LastErrorMsg(){
		if(IsError)
			return LastErrorMsg;
		else
			return "No";
	}
	/*�Ƿ��Ѵ򿪶˿�*/
	bool isOpen()
	{
		return myCom->isOpen();
	}
	/*���ö�ʱ��ʱ��*/
	void setWaitTime(int time)
	{
		WaitTime=time;
	}
	/*����վ��*/
	void setStationName(int name)
	{
		StationName=name;
	}
	/*���ô�����*/
	void setPortName(QString name)
	{
		if(!myCom)
			return;
		myCom->setPortName("\\\\.\\"+name);
	}
	/*���ò�����*/
	void setBaudRate(BaudRateType BaudRate)
	{
		if(!myCom)
			return;
		myCom->setBaudRate(BaudRate);
	}
	/*��������λ*/
	void setDataBits(DataBitsType DataBits)
	{
		if(!myCom)
			return;
		myCom->setDataBits(DataBits);
	}
	/*У��λ*/
	void setParity(ParityType Parity)
	{
		if(!myCom)
			return;
		myCom->setParity(Parity);
	}
	/*ֹͣλ*/
	void setStopBits(StopBitsType StopBits)
	{
		if(!myCom)
			return;
		myCom->setStopBits(StopBits);
	}
	/*����������λ*/
	void setFlowControl(FlowType Flow)
	{
		if(!myCom)
			return;
		myCom->setFlowControl(Flow);
	}
	/*��ʱʱ��*/
	void setTimeout_Millisec(long time)
	{
		if(!myCom)
			return;
		myCom->setTimeout(time);
	}
};

#endif // SERIALPORTCOM_H
