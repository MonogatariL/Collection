#pragma once

#include <QWidget>
#include "ui_Borrowed_Manager.h"
#include "Global.h"
#include "Db.h"

class Borrowed_Manager : public QWidget
{
	Q_OBJECT

public:
	Borrowed_Manager(QWidget *parent = Q_NULLPTR);
	~Borrowed_Manager();
	
	void init_ComBox();
	void init_tableWidget();
	void get_tableWidget();
private:
	int model;//0��ȫ�� 1������ 2���黹
	QStringList strListHead;
	QVector<QPushButton*>destruct_ptr;/*��,���ӣ�*/
private:
	Ui::Borrowed_Manager ui;
public slots:
	void change_syurui(int x) { model = x; get_tableWidget();};
};
