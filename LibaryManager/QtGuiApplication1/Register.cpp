#include "Register.h"

Register::Register(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	ui.widget->setStyleSheet("#widget{"
		"border-image:url(:/page_preview/Resources/BackGround2.png);"
		"}");
	connect(ui.PB_Back, &QPushButton::clicked, this, [=]() {this->hide(); });
}

Register::~Register()
{

}

void Register::init()
{
	QRegExp regx_pw("[a-zA-Z0-9_.+-*/]+$");
	QValidator* validator_pw = new QRegExpValidator(regx_pw);
	QRegExp regx_pw2("[0-9]+$");
	QValidator* validator_pw2 = new QRegExpValidator(regx_pw2);
	ui.LE1->setValidator(validator_pw2);
	ui.LE2->setValidator(validator_pw);
	ui.LE2->setEchoMode(QLineEdit::Password);//�ı���ʾģʽΪ����ԲȦ
	connect(ui.PB_Login, &QPushButton::clicked, this, [=]() {check(); });
}


void Register::check()
{
	QString Num = ui.LE1->text();
	QString PassWord = ui.LE2->text();
	if (Num == "")
	{
		ui.LE_Msg->setText("ѧ�Ų���Ϊ��");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (PassWord == "")
	{
		ui.LE_Msg->setText("���벻��Ϊ��");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (!db->Src_user(Num,PassWord))
	{
		ui.LE_Msg->setText(QString("��¼ʧ�ܣ���ȷ��ѧ��������ȷ"));
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	
	emit check_ok(g_Users[Num]);
}

