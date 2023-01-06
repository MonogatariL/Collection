#ifndef MOTORSETTING_H
#define MOTORSETTING_H

#include <QWidget>
#include<QFile>
#include<QSettings>
#include<QMessageBox>
#include<QVector>

#include <qDebug>

#include "ui_motorsetting.h"
/*M1M2电机参数:螺纹导程、步长、旋转一圈需要的步数*/
extern double ScrewThread1;
extern double StepLength1;
extern long StepNumber1;
/*M3M4电机参数:螺纹导程、步长、旋转一圈需要的步数、下限开关界限值*/
extern double ScrewThread2;
extern double StepLength2;
extern long StepNumber2;
extern long BaseValueAtLimitSwitch3;
extern long BaseValueAtLimitSwitch4;
/*M5M6电机参数:螺纹导程、步长、旋转一圈需要的步数、下限开关界限值*/
extern double ScrewThread3;
extern double StepLength3;
extern long StepNumber3;
extern long BaseValueAtLimitSwitch5;
extern long BaseValueAtLimitSwitch6;
/*6个绝对式编码器的下限值*/
extern long LimitPosition1;
extern long LimitPosition2;
extern long LimitPosition3;
extern long LimitPosition4;
extern long LimitPosition5;
extern long LimitPosition6;
/*绝对式编码器旋转一圈的圈数*/
extern long RotationOfEncoder;
/*使用校准工具至限位开关M1M2的距离*/
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
	void FindLowerLimit();//请求电机界面执行移动下限位函数
	void ValueChange();
private slots:
	void SaveInit();
	void ExportInit();
	void FindLowerLimitSlot(){emit FindLowerLimit();}
	void SaveToSettingSlot();
};

#endif // MOTORSETTING_H
