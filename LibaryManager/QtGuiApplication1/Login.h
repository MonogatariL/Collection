#pragma once

#include <QWidget>
#include "ui_Login.h"
#include "Global.h"
#include "Db.h"

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();

private:
	Ui::Login ui;
	void init();
	void Registry();
};
