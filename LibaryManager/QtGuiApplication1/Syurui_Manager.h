#pragma once

#include <QWidget>
#include "ui_Syurui_Manager.h"
#include "Global.h"
#include "Db.h"

class Syurui_Manager : public QWidget
{
	Q_OBJECT

public:
	Syurui_Manager(QWidget *parent = Q_NULLPTR);
	~Syurui_Manager();

	void show_time();

private:
	Ui::Syurui_Manager ui;
	QStringList strListHead;
	QVector<QPushButton*>destruct_ptr;/*ºß,ÏëÌÓ£¿*/

	void add_Syurui();
	void init_tableWidget();
	void get_tableWidget();
signals:
	void update_syurui();
};
