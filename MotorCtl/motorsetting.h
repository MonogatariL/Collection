#ifndef MOTORSETTING_H
#define MOTORSETTING_H

#include <QWidget>
#include<QFile>
#include<QSettings>
#include<QMessageBox>
#include<QVector>

#include <qDebug>

#include "ui_motorsetting.h"
/*M1M2�������:���Ƶ��̡���������תһȦ��Ҫ�Ĳ���*/
extern double ScrewThread1;
extern double StepLength1;
extern long StepNumber1;
/*M3M4�������:���Ƶ��̡���������תһȦ��Ҫ�Ĳ��������޿��ؽ���ֵ*/
extern double ScrewThread2;
extern double StepLength2;
extern long StepNumber2;
extern long BaseValueAtLimitSwitch3;
extern long BaseValueAtLimitSwitch4;
/*M5M6�������:���Ƶ��̡���������תһȦ��Ҫ�Ĳ��������޿��ؽ���ֵ*/
extern double ScrewThread3;
extern double StepLength3;
extern long StepNumber3;
extern long BaseValueAtLimitSwitch5;
extern long BaseValueAtLimitSwitch6;
/*6������ʽ������������ֵ*/
extern long LimitPosition1;
extern long LimitPosition2;
extern long LimitPosition3;
extern long LimitPosition4;
extern long LimitPosition5;
extern long LimitPosition6;
/*����ʽ��������תһȦ��Ȧ��*/
extern long RotationOfEncoder;
/*ʹ��У׼��������λ����M1M2�ľ���*/
extern long Calibration1;
extern long Calibration2;

class MotorSetting : public QWidget
{
	Q_OBJECT

public:
	MotorSetting(QWidget *parent = 0);
	~MotorSetting();
public:
	void SetLimitPosition(int station,int value);
private:
	Ui::MotorSetting ui;

	void Init();
	void Connects();
	void ReadInit();
	void UpData();
signals:
	void FindLowerLimit();//����������ִ���ƶ�����λ����
	void ValueChange();
private slots:
	void SaveInit();
	void ExportInit();
	void FindLowerLimitSlot(){emit FindLowerLimit();}
	void SaveToSettingSlot();
};

#endif // MOTORSETTING_H
