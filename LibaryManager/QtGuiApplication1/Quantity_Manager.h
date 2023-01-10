#pragma once

#include <QWidget>
#include "ui_Quantity_Manager.h"
#include "Global.h"
#include "Db.h"
class Quantity_Manager : public QWidget
{
	Q_OBJECT

public:
	Quantity_Manager(QWidget *parent = Q_NULLPTR);
	~Quantity_Manager();
	void add(QString,int);
	void sub(QString);
	void change(QString);
private:
	Ui::Quantity_manager ui;
	int mode;
	QString book_name;
	int book_num;

	void update_data();
signals:
	void update_table();
};
