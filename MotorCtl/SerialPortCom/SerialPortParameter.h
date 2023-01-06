#pragma once
#include<QString>
#include<stdint.h>
#include<QByteArray>
#pragma execution_character_set("utf-8")

extern QString IntToBinary(int);
extern QString ZeroFill(QString,int);
extern uint16_t ModbusCRC16(QByteArray);
extern QByteArray ModbusCRC16(QByteArray,int);
extern QString ModbusCRC16(QString);
extern void Data_(QByteArray&,int,int bit_=16);

extern int START_ADD;//0x00
/*������*/
extern int CTL_OPCODE_NUM;
extern int CTL_OPCODE_ADDH;
extern int CTL_OPCODE_ADDL;
extern int CTL_ALARMRESET_OPCODE;//Alam Reset���ñ���
extern int CTL_STARTJOGGING_OPCODE;//��ʼ����
extern int CTL_STOPJOGGING_OPCODE;//ֹͣ
extern int CTL_JOGDISABLE_OPCODE;//�㶯����
extern int CTL_JOGENABLE_OPCODE;//�㶯ֹͣ
extern int CTL_ABSOLUTE_OPCODE;	//����ִ�о����˶�
extern int CTL_SETPOSITION_OPCODE;//����λ��
extern int CTL_RELATIVE_OPCODE;	//����ִ������˶�
/*���Ա�����*/
extern int FCT_REALTIMEDATA_NUM;
extern int FCT_REALTIMEDATA_ADDH;
extern int FCT_REALTIMEDATA_ADDL;
extern int FCT_REALTIMEDATA_CODE;//��ȡʵʱ����
extern int SET_TOZERO_NUM;
extern int SET_TOZERO_ADDH;
extern int SET_TOZERO_ADDL;
extern int SET_TOZERO_CODE;//��0
/*λ�ÿ�������*/
extern int FCT_GO_POSITION_NUM;				//(���е�)����λ�ù�����
extern int FCT_GO_POSITION_ADDH;			//����λ����ʼ��ַ��λ
extern int FCT_GO_POSITION_ADDL;			//����λ����ʼ��ַ��λ
extern int FCT_GO_POSITION_REGISTER_SUM;	//����λ�üĴ������� 
extern int FCT_GO_POSITION_BIT;				//����λ�����ֽ���
/*����ԭ������*/
extern int FCT_RE_TO_PHOTOGRAPHY_NUM;			//����ԭ�㹦����
extern int FCT_RE_TO_PHOTOGRAPHY_ADDH;			//����ԭ���ַ��λ
extern int FCT_RE_TO_PHOTOGRAPHY_ADDL;			//����ԭ���ַ��λ
extern int FCT_RE_TO_PHOTOGRAPHY_REGISTER_SUM;	//����ԭ��Ĵ�������
extern int FCT_RE_TO_PHOTOGRAPHY_BIT;			//����ԭ���ֽ���
/*�ٶȿ�������*/
extern int FCT_SPEEDCONTROL_NUM;			
extern int FCT_SPEEDCONTROL_ADDH;			
extern int FCT_SPEEDCONTROL_ADDL;			
extern int FCT_SPEEDCONTROL_REGISTER_SUM;	
extern int FCT_SPEEDCONTROL_BIT;			

/*��ȡ����λ��*/
extern int GET_READPOSITION_NUM;
extern int GET_READPOSITION_ADDH;
extern int GET_READPOSITION_ADDL;
extern int GET_READPOSITION2_ADDL;
extern int GET_READPOSITION_READH;
extern int GET_READPOSITION_READL;



extern int UNITS_RPS_SEC;					
extern int UNITS_RPS;
extern int UNITS_PULSES;
extern int UNITS_RATIO;


/*����˶�*/
enum GoPosition
{
	Relative=0,
	Absolute,
};
