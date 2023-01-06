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

	bool ComReadIs;//可以读取
	bool ComWriteIs;//可以发送
	/*最后发送的报文对应参数，响应的参数其一致则为正常*/
	int LastStationName;
	int LastNum;
	int LastRegisterAddH;
	int LastRegisterAddL;
	int LastRegisterNumH;
	int LastRegisterNumL;
	int MsgType;/*0=0x03 1=0x06 2=0x10*/
	/*错误报警*/
	bool IsError;
	QString LastErrorMsg;
	/*响应超时*/
	QTimer *t;
	int WaitTime;
	bool IsWait;
	/**/
	QTimer *s;
public:

	QVector<QString> Get_PortEnum();//读取端口列表

	bool ComOpen(QIODevice::OpenModeFlag model=QIODevice::ReadWrite);	//打开连接
	bool ComClose();													//关闭连接

	QByteArray ComGetMsg();												//接受数据
	void ComPutMsg(QByteArray);											//发送数据
		
/*电机控制功能集*/
	void Get_MotorPosition(int StationName_=-1,int k=1);//电机位置——寄存器读取
	void Get_StatusCode(int StationName_=-1);//电机运动状态——寄存器读取 11为运行中 09为停止
	void Get_RealTimeDate(int StationName_=-1);//获取实时数据——绝对式编码器
	void Set_ToZero(int StationName_=-1);//编码器置0——绝对式编码器
	void Ctl_Opcode(int StationName_=-1,int value=0);//操作码无参数通用

	//速度控制例程。设置站名、加速度、减速度
	void Set_SpeedControl(int StationName_=-1,int AddSpeed=100,int SubSpeed=100,int Speed=10);
	//位置控制例程。设置站名、目标位置、加速度、减速度、速度
	void Set_GoPosition(int StationName_=-1,int Position=200000,int AddSpeed=100,int SubSpeed=100,int Speed=1);

private:
	QByteArray MsgHanding03(QByteArray);
	QByteArray MsgHanding06(QByteArray);
	QByteArray MsgHanding10(QByteArray);

	void Set_LastResponse(int,int,int,int,int,int);//发送指令后存储该次指令数据并根据返回数据进行对比
	void ComGetMsgError(QString setError);//设置错误原因并发送警告信号
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
/*简易接口*/
public:
	/*整体配置*/
	void ComSetting(BaudRateType BaudRate=BAUD9600,DataBitsType DataBits=DATA_8,ParityType Parity=PAR_NONE,	
		StopBitsType StopBits=STOP_1,FlowType FlowControl=FLOW_OFF,long Timeout_Millisec=500);
	QString Get_LastErrorMsg(){
		if(IsError)
			return LastErrorMsg;
		else
			return "No";
	}
	/*是否已打开端口*/
	bool isOpen()
	{
		return myCom->isOpen();
	}
	/*设置定时器时间*/
	void setWaitTime(int time)
	{
		WaitTime=time;
	}
	/*设置站名*/
	void setStationName(int name)
	{
		StationName=name;
	}
	/*设置串口名*/
	void setPortName(QString name)
	{
		if(!myCom)
			return;
		myCom->setPortName("\\\\.\\"+name);
	}
	/*设置波特率*/
	void setBaudRate(BaudRateType BaudRate)
	{
		if(!myCom)
			return;
		myCom->setBaudRate(BaudRate);
	}
	/*设置数据位*/
	void setDataBits(DataBitsType DataBits)
	{
		if(!myCom)
			return;
		myCom->setDataBits(DataBits);
	}
	/*校验位*/
	void setParity(ParityType Parity)
	{
		if(!myCom)
			return;
		myCom->setParity(Parity);
	}
	/*停止位*/
	void setStopBits(StopBitsType StopBits)
	{
		if(!myCom)
			return;
		myCom->setStopBits(StopBits);
	}
	/*数据流控制位*/
	void setFlowControl(FlowType Flow)
	{
		if(!myCom)
			return;
		myCom->setFlowControl(Flow);
	}
	/*延时时间*/
	void setTimeout_Millisec(long time)
	{
		if(!myCom)
			return;
		myCom->setTimeout(time);
	}
};

#endif // SERIALPORTCOM_H
