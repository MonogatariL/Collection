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
	ui.LB_Msg_2->setText(QString("������黹����:"));
	ui.LB_Msg->setText(QString("��������%1").arg(num));
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
	ui.LB_Msg_2->setText(QString("�������������:"));
	auto x = g_Books[name].bookLendNum;
	ui.LB_Msg->setText(QString("��������%1  ���ʣ�ࣺ%2").arg(g_Books[name].bookLendNum).arg(g_Books[name].bookNum));
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
	ui.LB_Msg_2->setText(QString("�޸Ŀ��:"));
	ui.LB_Msg->setText(QString("��������%1  ���ʣ�ࣺ%2").arg(g_Books[name].bookLendNum).arg(g_Books[name].bookNum));
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
			QDateTime current_date_time = QDateTime::currentDateTime();//��ȡ��ǰʱ��
			QString current_date2 = current_date_time.toString("yyyy.MM.dd-hh:mm");//��ȡ��ǰʱ��Ϊ����ID�ţ���(ȡ����λ)����ʱ�������(ǰ��λ)
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
			QDateTime current_date_time = QDateTime::currentDateTime();//��ȡ��ǰʱ��
			QString current_date2 = current_date_time.toString("yyyy.MM.dd-hh:mm");//��ȡ��ǰʱ��Ϊ����ID�ţ���(ȡ����λ)����ʱ�������(ǰ��λ)
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
	ui.LB_Msg->setText(QString("��������%1  ���ʣ�ࣺ%2").arg(g_Books[book_name].bookLendNum).arg(g_Books[book_name].bookNum));
	QString msg;
	if (mode == 2)
		msg = "���ĳɹ�";
	else
		msg = "�޸����";
	QMessageBox message(QMessageBox::NoIcon, "���",msg);
	message.setButtonText(QMessageBox::Ok, QString("ȷ��"));
	message.exec();
	hide();
}