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

	SerialPortCtl *Spc;//���ڿ������
	MotorSetting *Ms;//���ý���
	int DM_Height;
	int Height_Datamatrix;
	Ui::Motor_TeachClass ui;
private:
	QPushButton* p;//����
	void Init();
	void Connects();

	int MsgTakePosition(QByteArray);//λ�����ݴ���
	int FormulaLowerLimit(int,SerialPortCom* com);//ͨ�� ���޼��㹫ʽ
	void HeightFromConveyor(int,int);//M1M2 ���㹫ʽ
	void NominalBottleRadius(int,int);//M3M4 ���㹫ʽ
	void DistanceBetweenLight(int,int);//M5M6 ���㹫ʽ

	void MotorStatuChange(int num,int statu);//���ݵ��״̬�ı���ɫ
private:
	QVector<int>EncoderPositionLast;//��������ǰֵ����һ�αȽ����ڶ����ơ����ơ�ֹͣ���ж�
	QVector<int>StopTimer;//ֹͣ��ʱ������������ƶ�ʱ���������������һ���������ж��Ƿ�ﵽ�ϴ�������λ��
	QVector<int>LastPosition;//������һ������λ��
	QVector<bool>EncoderPositionChange;//�����������ֵ�����ı���Ϊtrue����ʱ������ִ���µ�ָ��
	QTimer *t;//ʵʱλ��ˢ�¼�ʱ��
public slots:
	void ApplyAndRefSlot();		//��ťApply and refresh photo��
	void DiscardChangeSlot();	//��ťdiscard Change��
	void RefAndReadSlot();		//��ťRef and Read��
	void FindLowerLimitSlot();	//��������λ����ȡ������ֵ��

	void UserTextRange();//ֵ��
	void GetCurrentPosition();//��ȡ�����ǰλ��
	void RegisterMsgGetSlot(SerialPortCom*);//���ܼĴ�������Ϣ
	void EncoderMsgGetSlot(SerialPortCom*);//���ܱ���������Ϣ
	void ProposedSlot();//����ֵ��
	void AddSlot();
	void SubSlot();
};

#endif // MOTOR_TEACH_H
