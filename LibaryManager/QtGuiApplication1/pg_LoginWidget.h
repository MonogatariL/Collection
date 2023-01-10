#pragma once
#include <QWidget>
#include "ui_pg_LoginWidget.h"
#include "console.h"
#include "Register.h"
#include "Login.h"

class pg_LoginWidget : public QWidget
{
	Q_OBJECT

public:
	pg_LoginWidget(QWidget *parent = Q_NULLPTR);
	~pg_LoginWidget();

private:
	Ui::pg_LoginWidget ui;

private:
	
	void paintEvent(QPaintEvent* event);
	//初始化函数
	void InitButton();
	void InitBKG();
	void initText();

private slots:
	void slot_BtnOnline();
	void slot_BtnOfflineTest();
	void slot_BtnOnlineAnalyze();
private:
	//UI数据
	QImage* pBKGImage1 = nullptr;
	QImage* pBKGImage2 = nullptr;
	console* w;
	Login* l;
	Register* r;
};
