#pragma once

#include <QWidget>
#include "ui_Register.h"
#include "Global.h"
#include "Db.h"
class Register : public QWidget
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();
	void check();
	void init();
private:
	Ui::Register ui;
signals:
	void check_ok(User);
};
