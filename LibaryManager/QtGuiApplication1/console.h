#pragma once

#include <QWidget>
#include "ui_console.h"

class console : public QWidget
{
	Q_OBJECT

public:
	console(QWidget *parent = Q_NULLPTR);
	~console();
	Ui::console ui;
protected:
	bool eventFilter(QObject *, QEvent *);
private:
};
