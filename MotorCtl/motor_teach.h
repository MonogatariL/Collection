#ifndef MOTOR_TEACH_H
#define MOTOR_TEACH_H

#include <QtGui/QWidget>
#include <QVector>
#include "ui_motor_teach.h"
#include "serialportctl.h"
#include "motorsetting.h"

class Motor_Teach : public QWidget
{
	Q_OBJECT

public:
	Motor_Teach(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Motor_Teach();

	SerialPortCtl *Spc;//串口控制面板
	MotorSetting *Ms;//设置界面
	int DM_Height;
	int Height_Datamatrix;
	Ui::Motor_TeachClass ui;
private:
	QPushButton* p;//傀儡
	void Init();
	void Connects();

	int MsgTakePosition(QByteArray);//位置数据处理
	int FormulaLowerLimit(int,SerialPortCom* com);//通用 下限计算公式
	void HeightFromConveyor(int,int);//M1M2 计算公式
	void NominalBottleRadius(int,int);//M3M4 计算公式
	void DistanceBetweenLight(int,int);//M5M6 计算公式

	void MotorStatuChange(int num,int statu);//根据电机状态改变颜色
private:
	QVector<int>EncoderPositionLast;//编码器当前值与上一次比较用于对上移、下移、停止的判断
	QVector<int>StopTimer;//停止计时器，当电机不移动时会计数，计数超过一定次数会判断是否达到上次期望的位置
	QVector<int>LastPosition;//保存上一次期望位置
	QVector<bool>EncoderPositionChange;//如果编码器的值发生改变则为true，此时将不能执行新的指令
	QTimer *t;//实时位置刷新计时器
public slots:
	void ApplyAndRefSlot();		//按钮Apply and refresh photo槽
	void DiscardChangeSlot();	//按钮discard Change槽
	void RefAndReadSlot();		//按钮Ref and Read槽
	void FindLowerLimitSlot();	//查找下限位并获取编码器值槽

	void UserTextRange();//值域
	void GetCurrentPosition();//获取电机当前位置
	void RegisterMsgGetSlot(SerialPortCom*);//接受寄存器的消息
	void EncoderMsgGetSlot(SerialPortCom*);//接受编码器的消息
	void ProposedSlot();//建议值槽
	void AddSlot();
	void SubSlot();
};

#endif // MOTOR_TEACH_H
