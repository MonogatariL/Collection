#pragma once

#include <QWidget>
#include "ui_Book_Manager.h"
#include "Global.h"
#include "Db.h"
#include "Quantity_Manager.h"
class Book_Manager : public QWidget
{
	Q_OBJECT

public:
	Book_Manager(QWidget *parent = Q_NULLPTR);
	~Book_Manager();
	void show_time();

private:
	Ui::Book_Manager ui;
	Quantity_Manager* qt_manager;
	QStringList strListHead;
	QVector<QPushButton*>destruct_ptr;/*∫ﬂ,œÎÃ”£ø*/

	void init_TableW_book();
	void add_Book();
	void get_CB_Book_Syurui();
	void get_tableWidget();

signals:
	void update_book();
};
