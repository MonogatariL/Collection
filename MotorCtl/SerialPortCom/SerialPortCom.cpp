#include "serialportcom.h"

SerialPortCom::SerialPortCom(QString ComName)
	:ComReadIs(false)
	,ComWriteIs(false)
	,StationName(0x01)
	,WaitTime(1000)
	,IsWait(false)
	,IsError(false)
	,MsgType(0)
{
	//myComSetting.BaudRate=BAUD9600;
	//myComSetting.DataBits=DATA_8;
	//myComSetting.Parity=PAR_NONE;
	//myComSetting.StopBits=STOP_1;
	//myComSetting.FlowControl=FLOW_OFF;
	//myComSetting.Timeout_Millisec=500;

	myCom = new Win_QextSerialPort(ComName,myComSetting,QextSerialBase::EventDriven);
	connect(myCom,SIGNAL(readyRead()),this,SLOT(_readyRead()));
	setPortName(ComName);
	ComOpen();

	t=new QTimer(this);
	connect(t,SIGNAL(timeout()),this,SLOT(_timeOut()));
	Get_PortEnum();
}

SerialPortCom::~SerialPortCom()
{
	delete myCom;
}

void SerialPortCom::Get_RealTimeDate(int StationName_/*=-1*/)
{
	if(IsWait)
	{
		ComGetMsgError("Wait for the previous instruction");
		return;
	}
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);					
	else	
		msg.push_back(StationName_);
	msg.push_back(FCT_REALTIMEDATA_NUM);			
	msg.push_back(FCT_REALTIMEDATA_ADDH);			
	msg.push_back(FCT_REALTIMEDATA_ADDL);			
	msg.push_back(START_ADD);			
	msg.push_back(FCT_REALTIMEDATA_CODE);			
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=0;
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Set_ToZero(int StationName_/*=-1*/)
{
	if(IsWait)
	{
		ComGetMsgError("Wait for the previous instruction");
		return;
	}
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);					
	else	
		msg.push_back(StationName_);
	msg.push_back(SET_TOZERO_NUM);			
	msg.push_back(SET_TOZERO_ADDH);			
	msg.push_back(SET_TOZERO_ADDL);			
	msg.push_back(START_ADD);			
	msg.push_back(SET_TOZERO_CODE);				
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=1;
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Ctl_Opcode(int StationName_/*=-1*/,int value/*=0*/)
{
	if(IsWait)
	{
		ComGetMsgError("Wait for the previous instruction");
		return;
	}
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);					//1:站号
	else	
		msg.push_back(StationName_);
	msg.push_back(CTL_OPCODE_NUM);					//2:功能码
	msg.push_back(CTL_OPCODE_ADDH);				//3:寄存器地址高位
	msg.push_back(CTL_OPCODE_ADDL);				//4:寄存器地址低位
	msg.push_back(START_ADD);							
	switch(value)
	{
		case 0:msg.push_back(CTL_ABSOLUTE_OPCODE);break;//绝对位移
		case 1:msg.push_back(CTL_RELATIVE_OPCODE);break;//相对位移
		case 2:msg.push_back(CTL_STARTJOGGING_OPCODE);break;//开始移动（会一直走到下限）
		case 3:msg.push_back(CTL_STOPJOGGING_OPCODE);break;//停止移动
		case 4:msg.push_back(CTL_JOGDISABLE_OPCODE);break;//点动（没用过）
		case 5:msg.push_back(CTL_JOGENABLE_OPCODE);break;//停止点动（没用过）
		case 6:msg.push_back(CTL_SETPOSITION_OPCODE);break;//设置为起点
		default:msg.push_back(CTL_ALARMRESET_OPCODE);break;
	}
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=1;
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Set_SpeedControl(int StationName_/*=-1*/,int AddSpeed,int SubSpeed/*=100*/,int Speed/*=1*/)
{
	if(IsWait)
	{
		ComGetMsgError("Wait for the previous instruction");
		return;
	}
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);						//1:站号
	else	
		msg.push_back(StationName_);
	msg.push_back(FCT_SPEEDCONTROL_NUM);				//2:功能码
	msg.push_back(FCT_SPEEDCONTROL_ADDH);				//3:起始地址高位
	msg.push_back(FCT_SPEEDCONTROL_ADDL);				//4:起始地址低位
	msg.push_back(START_ADD);							//5:寄存器总数高位
	msg.push_back(FCT_SPEEDCONTROL_REGISTER_SUM);		//6:寄存器总数低位
	msg.push_back(FCT_SPEEDCONTROL_BIT);				//7:总字节数
	Data_(msg,AddSpeed*UNITS_RPS_SEC);							
	Data_(msg,SubSpeed*UNITS_RPS_SEC);
	Data_(msg,Speed*UNITS_RPS);
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=2;
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Set_GoPosition(int StationName_/*=-1*/,int Position,int AddSpeed/*=100*/,int SubSpeed/*=100*/,int Speed/*=10*/)
{
	if(IsWait)
	{
		ComGetMsgError("Wait for the previous instruction");
		return;
	}
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);					//1:站号
	else	
		msg.push_back(StationName_);
	msg.push_back(FCT_GO_POSITION_NUM);				//2:功能码
	msg.push_back(FCT_GO_POSITION_ADDH);			//3:起始地址高位
	msg.push_back(FCT_GO_POSITION_ADDL);			//4:起始地址低位
	msg.push_back(START_ADD);						//5:寄存器总数高位
	msg.push_back(FCT_GO_POSITION_REGISTER_SUM);	//6:寄存器总数低位
	msg.push_back(FCT_GO_POSITION_BIT);				//7:总字节数
	Data_(msg,AddSpeed*UNITS_RPS_SEC);							
	Data_(msg,SubSpeed*UNITS_RPS_SEC);
	Data_(msg,Speed*UNITS_RPS);
	Data_(msg,Position,32);
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=2;
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::ComSetting(BaudRateType BaudRate/*=BAUD9600*/,DataBitsType DataBits/*=DATA_8*/,ParityType Parity/*=PAR_NONE*/, StopBitsType StopBits/*=STOP_1*/,FlowType FlowControl/*=FLOW_OFF*/,long Timeout_Millisec/*=500*/)
{
	setBaudRate(BaudRate);
	setDataBits(DataBits);
	setParity(Parity);
	setStopBits(StopBits);
	setFlowControl(FlowControl);
	setTimeout_Millisec(Timeout_Millisec);
}

QVector<QString> SerialPortCom::Get_PortEnum()
{
	QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
	for(int i=0;i<ports.size();i++)
	{
		qDebug()<<ports[i].enumName<<" "<<ports[i].friendName<<" "<<ports[i].physName<<" "<<ports[i].portName<<endl;
	}
	QVector<QString>res;
	return res;
}

bool SerialPortCom::ComOpen(QIODevice::OpenModeFlag model/*=QIODevice::ReadWrite*/)
{
	if(!myCom)
		return false;
	if(myCom->isOpen())
		ComClose();
	if(myCom->open(model))
	{
		ComReadIs=(model==QIODevice::ReadOnly||model==QIODevice::ReadWrite);
		ComWriteIs=(model==QIODevice::WriteOnly||model==QIODevice::ReadWrite);
		ComSetting();
		return true;

	}
	else
	{
		ComWriteIs=false;
		ComReadIs=false;
		return false;
	}
}

bool SerialPortCom::ComClose()
{
	if(!myCom||myCom->isOpen()==false)
		return false;
	ComReadIs=false;
	ComWriteIs=false;
	myCom->close();
	return true;
}

QByteArray SerialPortCom::ComGetMsg()
{
	/*
	由于串口通信接受消息的时候会附带一条为空的消息，所以这里加以限制
	正常返回数据XX：正常处理
	空返回数据0：此时忽略
	异常返回数据1：异常处理
	*/
	if(IsWait)
	{
		t->stop();
		IsWait=false;
	}
	QByteArray res;
	if(ComReadIs)
	{
		res=myCom->readAll();
	}
	if(res.size()==0)
	{
		return res;
	}
	switch(MsgType)
	{
	case 0:return MsgHanding03(res);
	case 1:return MsgHanding06(res);
	case 2:return MsgHanding10(res);
	}
	return res;
}

void SerialPortCom::ComPutMsg(QByteArray msg)
{
	if(!isOpen())
	{
		ComGetMsgError("Port Not Open");
		return;
	}
	if(!ComWriteIs)
	{
		ComGetMsgError("Port Forbidden to send");
		return;
	}
	myCom->write(msg);
}

void SerialPortCom::Get_MotorPosition(int StationName_/*=-1*/,int k)
{
	if(IsWait)
		return;
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);						//1:站号
	else	
		msg.push_back(StationName_);
	msg.push_back(GET_READPOSITION_NUM);				//2:功能码
	msg.push_back(GET_READPOSITION_ADDH);				//3:寄存器地址高位
	if(k)
		msg.push_back(GET_READPOSITION2_ADDL);				//4:寄存器地址低位
	else
		msg.push_back(GET_READPOSITION_ADDL);				//4:寄存器地址低位
	msg.push_back(GET_READPOSITION_READH);				//5:数据内容
	msg.push_back(GET_READPOSITION_READL);				//5:数据内容
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=0;
	
	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Get_StatusCode(int StationName_/*=-1*/)
{
	if(IsWait)
		return;
	QByteArray msg;
	if(StationName_==-1)
		msg.push_back(StationName);						//1:站号
	else	
		msg.push_back(StationName_);
	msg.push_back(GET_READPOSITION_NUM);				//2:功能码
	msg.push_back(GET_READPOSITION_ADDH);				//3:寄存器地址高位
	msg.push_back(0x01);								//4:寄存器地址低位
	msg.push_back(GET_READPOSITION_READH);				//5:数据内容
	msg.push_back(GET_READPOSITION_READL);				//5:数据内容
	QByteArray crc=ModbusCRC16(msg,msg.size());
	msg.push_back(crc[0]);							//12:CRC校验码高位
	msg.push_back(crc[1]);							//13:CRC校验码低位
	ComPutMsg(msg);
	MsgType=0;

	Set_LastResponse(msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	emit sendMsg(msg);
}

void SerialPortCom::Set_LastResponse(int Id,int Num,int AddH,int AddL,int NumH,int NumL)
{
	(int)LastStationName=Id;
	(int)LastNum=Num;
	(int)LastRegisterAddH=AddH;
	(int)LastRegisterAddL=AddL;
	(int)LastRegisterNumH=NumH;
	(int)LastRegisterNumL=NumL;

	//t->start(WaitTime);
	//IsWait=true;
}

void SerialPortCom::ComGetMsgError(QString setError)
{
	IsWait=false;
	t->stop();
	IsError=true;
	LastErrorMsg=setError;
	emit abnormalReturn(this);
}

QByteArray SerialPortCom::MsgHanding03(QByteArray res)
{
	QByteArray noReturn;
	noReturn.push_back(0xff);
	if(res.size()<5)
	{
		ComGetMsgError("Num0x03:Data Exception");//返回数据错误
		return noReturn;
	}
	/*
	异常返回的数据格式为：0A 83 XX CRC_L CRC_H
	其中，XX = 01H：不支持写入功能码10H
	XX = 02H：不合法的寄存器
	XX = 03H：不合法的数据区
	XX = 11H：寄存器不支持读取
	*/
	//res[1]也就是功能码位，0x90对应写多个寄存器，0x86对应写单个寄存器，0x83对应读取保持寄存器
	if(res.size()==5)
	{
		switch(res[2])
		{
		case 0x01:ComGetMsgError("Num0x03:Function code reading is not supported");return noReturn;
		case 0x02:ComGetMsgError("Num0x03:Illegal register");return noReturn;
		case 0x03:ComGetMsgError("Num0x03:Illegal data area");return noReturn;
		case 0x11:ComGetMsgError("Num0x03:Register does not support reading");return noReturn;
		}
	}
	/*EXAMPLE
	主机发送数据：从站地址、功能码、数据起始地址(16位)、数据个数、CRC高低
	主机发送：01 03 00 01 00 01 D5 CA
	从站返回数据：从站地址、功能码、数据个数、数据*数据个数、CRC高低
	从站返回：01 03 02 00 09 78 42
	*/
	if(LastStationName!=(int)res[0])
	{
		ComGetMsgError("Num0x03:StationId is Error");//站号不符
		return noReturn;
	}
	else if(LastNum!=(int)res[1])
	{
		ComGetMsgError("Num0x03:Function Code Is Error");//功能码不符
		return noReturn;
	}
	return res;
}

QByteArray SerialPortCom::MsgHanding06(QByteArray res)
{
	QByteArray noReturn;
	noReturn.push_back(0xff);
	if(res.size()<5)
	{
		ComGetMsgError("Num0x10:Data Exception");//返回数据错误
		return noReturn;
	}
	/*
	异常返回的数据格式为：0B 86 XX CRC_L CRC_H
	其中，XX = 01H：不支持写入功能码10H
	XX = 02H：不合法的寄存器
	XX = 03H：不合法的数据区
	XX = 12H：寄存器不支持写入
	XX = 13H：设定值超范围
	*/
	//res[1]也就是功能码位，0x90对应写多个寄存器，0x86对应写单个寄存器，0x83对应读取保持寄存器
	if(res.size()==5)
	{
		switch(res[2])
		{
		case 0x01:ComGetMsgError("Num0x10:Function code writing is not supported");return noReturn;
		case 0x02:ComGetMsgError("Num0x10:Illegal register");return noReturn;
		case 0x03:ComGetMsgError("Num0x10:Illegal data area");return noReturn;
		case 0x12:ComGetMsgError("Num0x10:Register does not support writing");return noReturn;
		case 0x13:ComGetMsgError("Num0x10:Set value out of range");return noReturn;
		}
	}
	/*EXAMPLE
	主机发送数据：从站地址、功能码、寄存器起始地址(16位)、数据、CRC高低
	主机发送：0B 06 00 1D 01 2C 19 2B
	从站返回数据：从站地址、功能码、寄存器起始地址(16位)、数据、CRC高低
	从站返回：0B 06 00 1D 01 2C 19 2B
	*/
	if(LastStationName!=(int)res[0])
	{
		ComGetMsgError("Num0x06:StationId is Error");//站号不符
		return noReturn;
	}
	else if(LastNum!=(int)res[1])
	{
		ComGetMsgError("Num0x06:Function Code Is Error");//功能码不符
		return noReturn;
	}
	else if(LastRegisterAddH!=(int)res[2])
	{
		ComGetMsgError("Num0x06:RegisterHight Address Is Error");//地址高位不符s
		return noReturn;
	}
	else if(LastRegisterAddL!=(int)res[3])
	{
		ComGetMsgError("Num0x06:RegisterLow Address Is Error");//地址低位不符
		return noReturn;
	}
	else if(LastRegisterNumH!=(int)res[4])
	{
		ComGetMsgError("Num0x06:DataHight of registers is Error");//寄存器数量高位不符
		return noReturn;
	}
	else if(LastRegisterNumL!=(int)res[5])
	{
		ComGetMsgError("Num0x06:DataLow of registers is Error");//寄存器数量低位不符
		return noReturn;
	}
	return res;
}

QByteArray SerialPortCom::MsgHanding10(QByteArray res)
{
	QByteArray noReturn;
	noReturn.push_back(0xff);
	if(res.size()<5)
	{
		ComGetMsgError("Num0x10:Data Exception");//返回数据错误
		return noReturn;
	}
	/*
	异常返回的数据格式为：0A 90 XX CRC_L CRC_H
	其中，XX = 01H：不支持写入功能码10H
	XX = 02H：不合法的寄存器
	XX = 03H：不合法的数据区
	XX = 12H：寄存器不支持写入
	XX = 13H：设定值超范围
	*/
	//res[1]也就是功能码位，0x90对应写多个寄存器，0x86对应写单个寄存器，0x83对应读取保持寄存器
	if(res.size()==5)
	{
		switch(res[2])
		{
		case 0x01:ComGetMsgError("Num0x10:Function code writing is not supported");return noReturn;
		case 0x02:ComGetMsgError("Num0x10:Illegal register");return noReturn;
		case 0x03:ComGetMsgError("Num0x10:Illegal data area");return noReturn;
		case 0x11:ComGetMsgError("Num0x10:Register does not support reading");return noReturn;
		case 0x12:ComGetMsgError("Num0x10:Register does not support writing");return noReturn;
		case 0x13:ComGetMsgError("Num0x10:Set value out of range");return noReturn;
		}
	}
	/*EXAMPLE
	主机发送数据：从站地址、功能码、寄存器起始地址(16位)、数据数量(16位)、字节数、数据、CRC高低
	主机发送：0A 10 00 1E 00 02 04 00 00 75 30 70 8F
	从站返回数据：从站地址、功能码、寄存器起始地址(16位)、数据数量(16位)、CRC高低
	从站返回：0A 10 00 1E 00 02 20 B5
	*/
	if(LastStationName!=(int)res[0])
	{
		ComGetMsgError("Num0x10:StationId is Error");//站号不符
		return noReturn;
	}
	else if(LastNum!=(int)res[1])
	{
		ComGetMsgError("Num0x10:Function Code Is Error");//功能码不符
		return noReturn;
	}
	else if(LastRegisterAddH!=(int)res[2])
	{
		ComGetMsgError("Num0x10:RegisterHight Address Is Error");//地址高位不符
		return noReturn;
	}
	else if(LastRegisterAddL!=(int)res[3])
	{
		ComGetMsgError("Num0x10:RegisterLow Address Is Error");//地址低位不符
		return noReturn;
	}
	else if(LastRegisterNumH!=(int)res[4])
	{
		ComGetMsgError("Num0x10:NumberHight of registers is Error");//寄存器数量高位不符
		return noReturn;
	}
	else if(LastRegisterNumL!=(int)res[5])
	{
		ComGetMsgError("Num0x10:NumberLow of registers is Error");//寄存器数量低位不符
		return noReturn;
	}
	return res;
}
