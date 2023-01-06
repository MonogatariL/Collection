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
/*操作码*/
extern int CTL_OPCODE_NUM;
extern int CTL_OPCODE_ADDH;
extern int CTL_OPCODE_ADDL;
extern int CTL_ALARMRESET_OPCODE;//Alam Reset重置报警
extern int CTL_STARTJOGGING_OPCODE;//开始启动
extern int CTL_STOPJOGGING_OPCODE;//停止
extern int CTL_JOGDISABLE_OPCODE;//点动启动
extern int CTL_JOGENABLE_OPCODE;//点动停止
extern int CTL_ABSOLUTE_OPCODE;	//设置执行绝对运动
extern int CTL_SETPOSITION_OPCODE;//设置位置
extern int CTL_RELATIVE_OPCODE;	//设置执行相对运动
/*绝对编码器*/
extern int FCT_REALTIMEDATA_NUM;
extern int FCT_REALTIMEDATA_ADDH;
extern int FCT_REALTIMEDATA_ADDL;
extern int FCT_REALTIMEDATA_CODE;//读取实时数据
extern int SET_TOZERO_NUM;
extern int SET_TOZERO_ADDH;
extern int SET_TOZERO_ADDL;
extern int SET_TOZERO_CODE;//置0
/*位置控制例程*/
extern int FCT_GO_POSITION_NUM;				//(运行到)绝对位置功能码
extern int FCT_GO_POSITION_ADDH;			//绝对位置起始地址高位
extern int FCT_GO_POSITION_ADDL;			//绝对位置起始地址低位
extern int FCT_GO_POSITION_REGISTER_SUM;	//绝对位置寄存器总数 
extern int FCT_GO_POSITION_BIT;				//绝对位置总字节数
/*返回原点例程*/
extern int FCT_RE_TO_PHOTOGRAPHY_NUM;			//返回原点功能码
extern int FCT_RE_TO_PHOTOGRAPHY_ADDH;			//返回原点地址高位
extern int FCT_RE_TO_PHOTOGRAPHY_ADDL;			//返回原点地址低位
extern int FCT_RE_TO_PHOTOGRAPHY_REGISTER_SUM;	//返回原点寄存器总数
extern int FCT_RE_TO_PHOTOGRAPHY_BIT;			//返回原点字节数
/*速度控制例程*/
extern int FCT_SPEEDCONTROL_NUM;			
extern int FCT_SPEEDCONTROL_ADDH;			
extern int FCT_SPEEDCONTROL_ADDL;			
extern int FCT_SPEEDCONTROL_REGISTER_SUM;	
extern int FCT_SPEEDCONTROL_BIT;			

/*读取绝对位置*/
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


/*相对运动*/
enum GoPosition
{
	Relative=0,
	Absolute,
};
