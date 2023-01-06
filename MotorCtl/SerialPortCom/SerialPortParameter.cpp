#include "SerialPortParameter.h"

int START_ADD=0x00;

/*������*/
int CTL_OPCODE_NUM=0x06;
int CTL_OPCODE_ADDH=0x00;
int CTL_OPCODE_ADDL=0x7c;
int CTL_ALARMRESET_OPCODE=0xBA;//���ñ���
int CTL_STARTJOGGING_OPCODE=0x96;//����
int CTL_STOPJOGGING_OPCODE=0xD8;//ֹͣ*/
int CTL_JOGDISABLE_OPCODE=0xA3;//�㶯ֹͣ
int CTL_JOGENABLE_OPCODE=0xA2;//�㶯����
int CTL_ABSOLUTE_OPCODE=0x67;	//����ִ�о����˶���������
int CTL_RELATIVE_OPCODE=0x66;	//����ִ������˶���������
int CTL_SETPOSITION_OPCODE=0xA5;//����λ��
/*����ʽ������*/
int FCT_REALTIMEDATA_NUM=0x03;
int FCT_REALTIMEDATA_ADDH=0x00;
int FCT_REALTIMEDATA_ADDL=0x00;
int FCT_REALTIMEDATA_CODE=0x02;//��ȡʵʱ����
int SET_TOZERO_NUM=0x06;
int SET_TOZERO_ADDH=0x00;
int SET_TOZERO_ADDL=0x20;
int SET_TOZERO_CODE=0x00;//��0
/*λ�ÿ�������*/
int FCT_GO_POSITION_NUM=0x10;
int FCT_GO_POSITION_ADDH=0x00;			//λ�ÿ�����ʼ��ַ��λ
int FCT_GO_POSITION_ADDL=0x1B;			//λ�ÿ�����ʼ��ַ��λ
int FCT_GO_POSITION_REGISTER_SUM=0x05;	//λ�ÿ��ƼĴ������� 
int FCT_GO_POSITION_BIT=0x0A;			//λ�ÿ������ֽ���
/*����ԭ������*/
int FCT_RE_TO_PHOTOGRAPHY_NUM=0x10;			//��ԭ����ƹ�����
int FCT_RE_TO_PHOTOGRAPHY_ADDH=0x01;		//��ԭ�������ʼ��ַ��λ
int FCT_RE_TO_PHOTOGRAPHY_ADDL=0x64;		//��ԭ�������ʼ��ַ��λ
int FCT_RE_TO_PHOTOGRAPHY_REGISTER_SUM=0x0A;//��ԭ����ƼĴ������� 
int FCT_RE_TO_PHOTOGRAPHY_BIT=0x14;			//��ԭ��������ֽ���
/*�ٶȿ�������*/
int FCT_SPEEDCONTROL_NUM=0x10;			//�ٶȿ��ƹ�����
int FCT_SPEEDCONTROL_ADDH=0x00;			//�ٶȿ�����ʼ��ַ��λ
int FCT_SPEEDCONTROL_ADDL=0x2E;			//�ٶȿ�����ʼ��ַ��λ
int FCT_SPEEDCONTROL_REGISTER_SUM=0x03;	//�ٶȿ��ƼĴ������� 
int FCT_SPEEDCONTROL_BIT=0x06;			//�ٶȿ������ֽ���
/*��ȡ����λ��*/
int GET_READPOSITION_NUM=0x03;
int GET_READPOSITION_ADDH=0x00;
int GET_READPOSITION_ADDL=0x08;
int GET_READPOSITION2_ADDL=0x09;
int GET_READPOSITION_READH=0x00;
int GET_READPOSITION_READL=0x02;
/*��λ*/
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
	uint16_t wcrc=0XFFFF;//Ԥ��16λcrc�Ĵ�������ֵȫ��Ϊ1
	uint8_t temp;//�����м����
	for(int i=0,j=0;i<senddata.size();i++)//ѭ������ÿ������
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//�ж����Ƴ����ǲ���1�������1�������ʽ�������
			if(wcrc&0X0001){
				wcrc>>=1;//�Ƚ���������һλ
				wcrc^=0XA001;//������Ķ���ʽ�������
			}
			else//�������1����ֱ���Ƴ�
				wcrc>>=1;//ֱ���Ƴ�
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
	uint16_t wcrc=0XFFFF;//Ԥ��16λcrc�Ĵ�������ֵȫ��Ϊ1
	uint8_t temp;//�����м����
	int i=0,j=0;//�������
	for(i=0;i<len;i++)//ѭ������ÿ������
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//�ж����Ƴ����ǲ���1�������1�������ʽ�������
			if(wcrc&0X0001){
				wcrc>>=1;//�Ƚ���������һλ
				wcrc^=0XA001;//������Ķ���ʽ�������
			}
			else//�������1����ֱ���Ƴ�
				wcrc>>=1;//ֱ���Ƴ�
		}
	}
	temp=wcrc;//crc��ֵ
	return wcrc;
}

QByteArray ModbusCRC16(QByteArray senddata,int l)
{
	uint16_t wcrc=0XFFFF;//Ԥ��16λcrc�Ĵ�������ֵȫ��Ϊ1
	uint8_t temp;//�����м����
	int i=0,j=0;//�������
	for(i=0;i<l;i++)//ѭ������ÿ������
	{
		temp=senddata.at(i);
		wcrc^=temp;
		for(j=0;j<8;j++){
			//�ж����Ƴ����ǲ���1�������1�������ʽ�������
			if(wcrc&0X0001){
				wcrc>>=1;//�Ƚ���������һλ
				wcrc^=0XA001;//������Ķ���ʽ�������
			}
			else//�������1����ֱ���Ƴ�
				wcrc>>=1;//ֱ���Ƴ�
		}
	}
	temp=wcrc;//crc��ֵ
	QByteArray res;
	res.resize(2);
	res[0]=uint8_t(wcrc);
	res[1]=uint8_t(wcrc>>8);
	return res;
}



