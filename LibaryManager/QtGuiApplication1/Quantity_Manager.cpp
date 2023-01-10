#include "Quantity_Manager.h"

Quantity_Manager::Quantity_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->hide();
	ui.SB_Value->setMinimum(0);
	connect(ui.PB_Ok, &QPushButton::clicked, this, [=]() {update_data(); });
	connect(ui.PB_Close, &QPushButton::clicked, this, [=]() {this->hide(); });
}

Quantity_Manager::~Quantity_Manager()
{
}
void Quantity_Manager::add(QString name,int num)
{
	hide();
	show();
	this->setWindowTitle(name);
	mode = 1;
	book_name = name;
	ui.SB_Value->setValue(0);
	ui.SB_Value->setMaximum(num);
	ui.LB_Msg_2->setText(QString("请输入归还数量:"));
	ui.LB_Msg->setText(QString("借阅量：%1").arg(num));
}
void Quantity_Manager::sub(QString name)
{
	hide();
	show();
	this->setWindowTitle(name);
	mode = 2;
	book_name = name;
	ui.SB_Value->setValue(0);
	ui.SB_Value->setMaximum(g_Books[name].bookNum);
	ui.LB_Msg_2->setText(QString("请输入借阅数量:"));
	auto x = g_Books[name].bookLendNum;
	ui.LB_Msg->setText(QString("借阅量：%1  库存剩余：%2").arg(g_Books[name].bookLendNum).arg(g_Books[name].bookNum));
}
void Quantity_Manager::change(QString name)
{
	hide();
	show();
	this->setWindowTitle(name);
	mode = 3;
	book_name = name;
	ui.SB_Value->setValue(g_Books[name].bookNum);
	ui.SB_Value->setMaximum(2147483647);
	ui.LB_Msg_2->setText(QString("修改库存:"));
	ui.LB_Msg->setText(QString("借阅量：%1  库存剩余：%2").arg(g_Books[name].bookLendNum).arg(g_Books[name].bookNum));
}
void Quantity_Manager::update_data()
{
	switch (mode)
	{
	case 1: 
	{
		if (ui.SB_Value->value() != 0)
		{
			db->Update_book_lend(book_name, g_Books[book_name].bookLendNum - (ui.SB_Value->value()));
			db->Update_book_num(book_name, g_Books[book_name].bookNum + (ui.SB_Value->value()));
			QDateTime current_date_time = QDateTime::currentDateTime();//获取当前时间
			QString current_date2 = current_date_time.toString("yyyy.MM.dd-hh:mm");//截取当前时间为分类ID号，年(取后两位)月日时分秒毫秒(前两位)
			Record r(current_U.userName, current_U.userNum, book_name, current_date2, ui.SB_Value->value(), 1);
			db->Add_Record(r);
		}
		break;
	}
	case 2:
	{
		if (ui.SB_Value->value() != 0)
		{
			db->Update_book_lend(book_name, g_Books[book_name].bookLendNum + (ui.SB_Value->value()));
			db->Update_book_num(book_name, g_Books[book_name].bookNum - (ui.SB_Value->value()));
			QDateTime current_date_time = QDateTime::currentDateTime();//获取当前时间
			QString current_date2 = current_date_time.toString("yyyy.MM.dd-hh:mm");//截取当前时间为分类ID号，年(取后两位)月日时分秒毫秒(前两位)
			Record r(current_U.userName, current_U.userNum, book_name, current_date2, ui.SB_Value->value(), 0);
			db->Add_Record(r);
		}
		break;
	}
	case 3:
	{
		db->Update_book_num(book_name, ui.SB_Value->value());
		break;
	}
	}
	emit update_table();
	ui.LB_Msg->setText(QString("借阅量：%1  库存剩余：%2").arg(g_Books[book_name].bookLendNum).arg(g_Books[book_name].bookNum));
	QString msg;
	if (mode == 2)
		msg = "借阅成功";
	else
		msg = "修改完成";
	QMessageBox message(QMessageBox::NoIcon, "完成",msg);
	message.setButtonText(QMessageBox::Ok, QString("确定"));
	message.exec();
	hide();
}