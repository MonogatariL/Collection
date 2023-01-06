#include "SerialPortParameter.h"

int START_ADD=0x00;

/*操作码*/
int CTL_OPCODE_NUM=0x06;
int CTL_OPCODE_ADDH=0x00;
int CTL_OPCODE_ADDL=0x7c;
int CTL_ALARMRESET_OPCODE=0xBA;//重置报警
int CTL_STARTJOGGING_OPCODE=0x96;//启动
int CTL_STOPJOGGING_OPCODE=0xD8;//停止*/
int CTL_JOGDISABLE_OPCODE=0xA3;//点动停止
int CTL_JOGENABLE_OPCODE=0xA2;//点动启动
int CTL_ABSOLUTE_OPCODE=0x67;	//设置执行绝对运动数据内容
int CTL_RELATIVE_OPCODE=0x66;	//设置执行相对运动数据内容
int CTL_SETPOSITION_OPCODE=0xA5;//设置位置
/*绝对式编码器*/
int FCT_REALTIMEDATA_NUM=0x03;
int FCT_REALTIMEDATA_ADDH=0x00;
int FCT_REALTIMEDATA_ADDL=0x00;
int FCT_REALTIMEDATA_CODE=0x02;//读取实时数据
int SET_TOZERO_NUM=0x06;
int SET_TOZERO_ADDH=0x00;
int SET_TOZERO_ADDL=0x20;
int SET_TOZERO_CODE=0x00;//置0
/*位置控制例程*/
int FCT_GO_POSITION_NUM=0x10;
int FCT_GO_POSITION_ADDH=0x00;			//位置控制起始地址高位
int FCT_GO_POSITION_ADDL=0x1B;			//位置控制起始地址低位
int FCT_GO_POSITION_REGISTER_SUM=0x05;	//位置控制寄存器总数 
int FCT_GO_POSITION_BIT=0x0A;			//位置控制总字节数
/*返回原点例程*/
int FCT_RE_TO_PHOTOGRAPHY_NUM=0x10;			//回原点控制功能码
int FCT_RE_TO_PHOTOGRAPHY_ADDH=0x01;		//回原点控制起始地址高位
int FCT_RE_TO_PHOTOGRAPHY_ADDL=0x64;		//回原点控制起始地址低位
int FCT_RE_TO_PHOTOGRAPHY_REGISTER_SUM=0x0A;//回原点控制寄存器总数 
int FCT_RE_TO_PHOTOGRAPHY_BIT=0x14;			//回原点控制总字节数
/*速度控制例程*/
int FCT_SPEEDCONTROL_NUM=0x10;			//速度控制功能码
int FCT_SPEEDCONTROL_ADDH=0x00;			//速度控制起始地址高位
int FCT_SPEEDCONTROL_ADDL=0x2E;			//速度控制起始地址低位
int FCT_SPEEDCONTROL_REGISTER_SUM=0x03;	//速度控制寄存器总数 
int FCT_SPEEDCONTROL_BIT=0x06;			//速度控制总字节数
/*读取绝对位置*/
int GET_READPOSITION_NUM=0x03;
int GET_READPOSITION_ADDH=0x00;
int GET_READPOSITION_ADDL=0x08;
int GET_READPOSITION2_ADDL=0x09;
int GET_READPOSITION_READH=0x00;
int GET_READPOSITION_READL=0x02;
/*单位*/
int UNITS_RPS_SEC=6;	
int UNITS_RPS=240;		
int UNITS_PULSES=240;	
int UNITS_RATIO=10;		


void Data_(QByteArray& msg,int value,int bit_/*=4*/)
{
	bit_/=4;
	QString res=ZeroFill(QString::number(value,16),bit_);
	for(int i=0;i<bit_;i+=2)
	{
		msg.push_back(res.mid(i,2).toInt(0,16));
	}
}

QString IntToBinary(int value)
{
	QString res=QString::number(value,2);
	while(res.size()<9)
		res="0"+res;
	return res;
}

QString ZeroFill(QString s,int n)
{
	while(s.size()<n)
		s="0"+s;
	if(s.size()>n)
		s=s.mid(s.size()-n,n);
	return s;
}

QString ModbusCRC16(QString value)
{
	QByteArray senddata;
	senddata.resize(value.size()/2);
	for(int i=0,j=0;i<senddata.size();i++,j+=2)
	{
		QString key16=QString("%1%2").arg(value[j]).arg(value[j+1]);
		senddata[i]=key16.toInt(0,16);
	}
	uint16_t wcrc=0XFFFF;//预置16位crc寄存器，初值全部为1
	uint8_t temp;//定义中间变量
	for(int i=0,j=0;i<senddata.size();i++)//循环计算每个数据
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//判断右移出的是不是1，如果是1则与多项式进行异或。
			if(wcrc&0X0001){
				wcrc>>=1;//先将数据右移一位
				wcrc^=0XA001;//与上面的多项式进行异或
			}
			else//如果不是1，则直接移出
				wcrc>>=1;//直接移出
		}
	}
	QString res;
	while(wcrc)
	{
		res+=QString::number(uint8_t(wcrc),16);
		wcrc>>=8;
	}
	return res.toUpper();
}

uint16_t ModbusCRC16(QByteArray senddata)
{
	int len=senddata.size();
	uint16_t wcrc=0XFFFF;//预置16位crc寄存器，初值全部为1
	uint8_t temp;//定义中间变量
	int i=0,j=0;//定义计数
	for(i=0;i<len;i++)//循环计算每个数据
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//判断右移出的是不是1，如果是1则与多项式进行异或。
			if(wcrc&0X0001){
				wcrc>>=1;//先将数据右移一位
				wcrc^=0XA001;//与上面的多项式进行异或
			}
			else//如果不是1，则直接移出
				wcrc>>=1;//直接移出
		}
	}
	temp=wcrc;//crc的值
	return wcrc;
}

QByteArray ModbusCRC16(QByteArray senddata,int l)
{
	uint16_t wcrc=0XFFFF;//预置16位crc寄存器，初值全部为1
	uint8_t temp;//定义中间变量
	int i=0,j=0;//定义计数
	for(i=0;i<l;i++)//循环计算每个数据
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//判断右移出的是不是1，如果是1则与多项式进行异或。
			if(wcrc&0X0001){
				wcrc>>=1;//先将数据右移一位
				wcrc^=0XA001;//与上面的多项式进行异或
			}
			else//如果不是1，则直接移出
				wcrc>>=1;//直接移出
		}
	}
	temp=wcrc;//crc的值
	QByteArray res;
	res.resize(2);
	res[0]=uint8_t(wcrc);
	res[1]=uint8_t(wcrc>>8);
	return res;
}



