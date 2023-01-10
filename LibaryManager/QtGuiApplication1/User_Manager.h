#pragma once

#include <QWidget>
#include "ui_User_Manager.h"
#include "Global.h"
#include "Db.h"

class User_Manager : public QWidget
{
	Q_OBJECT

public:
	User_Manager(QWidget *parent = Q_NULLPTR);
	~User_Manager();
	void init_tableWidget();
	void get_tableWidget();
	void init_ComBox();
private:
	int model;//0：全部 1：借阅 2：归还
	QStringList strListHead;
	QVector<QPushButton*>destruct_ptr;/*哼,想逃？*/
private:
	Ui::User_Manager ui;
public slots:
	void change_syurui(int x) { model = x; get_tableWidget(); };
};
