#include "console.h"

console::console(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setWindowFlags(Qt::FramelessWindowHint);
	//ui.label->installEventFilter(this);
	this->setWindowTitle("图书管理系统");
	connect(ui.PB_library, &QPushButton::clicked, this, [=]() {
		ui.stackedWidget->setCurrentIndex(0);
	});
	connect(ui.PB_record, &QPushButton::clicked, this, [=]() {
		if (g_model == 0)
		{
			QMessageBox box(QMessageBox::Warning, "提示", "仅限管理员访问");
			box.exec();
			return;
		}
		ui.widget->get_tableWidget();
		ui.stackedWidget->setCurrentIndex(1);
	});
	connect(ui.PB_user, &QPushButton::clicked, this, [=]() {
		if (g_model == 0)
		{
			QMessageBox box(QMessageBox::Warning, "提示", "仅限管理员访问");
			box.exec();
			return;
		}
		ui.stackedWidget->setCurrentIndex(2);
	});
	ui.widget_3->setStyleSheet("#widget_3{"
		"border-image:url(:/page_preview/Resources/BackGround2.png);"
		"}");
}

console::~console()
{
}

bool console::eventFilter(QObject *watched, QEvent *event)
{
	//static QPoint mousePoint;
	//static bool mousePressed = false;
	//QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
	//if (watched == ui.label)
	//{
	//	switch (event->type())
	//	{
	//	case QEvent::MouseButtonPress:
	//		if (mouse_event->button() == Qt::LeftButton)
	//		{
	//			mousePressed = true;
	//			mousePoint = mouse_event->globalPos() - this->pos();
	//			return true;
	//		}
	//	case QEvent::MouseButtonRelease:mousePressed = false; return true;
	//	case QEvent::MouseMove:this->move(mouse_event->globalPos() - mousePoint); return true;
	//	default:break;
	//	}
	//}
	return true;
}