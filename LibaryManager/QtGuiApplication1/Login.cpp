#include "Login.h"

Login::Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
	ui.widget->setStyleSheet("#widget{"
		"border-image:url(:/page_preview/Resources/BackGround2.png);"
		"}");
}

void Login::init()
{
	ui.comboBox->addItem("学生");
	ui.comboBox->addItem("管理人");
	QRegExp regx_pw("[a-zA-Z0-9_.+-*/]+$");
	QValidator* validator_pw = new QRegExpValidator(regx_pw);
	QRegExp regx_pw2("[0-9]+$");
	QValidator* validator_pw2 = new QRegExpValidator(regx_pw2);
	ui.LE1->setValidator(validator_pw2);
	ui.LE3->setValidator(validator_pw);
	ui.LE3->setEchoMode(QLineEdit::Password);//文本显示模式为密码圆圈
	connect(ui.PB_Login, &QPushButton::clicked, this, [=]() {Registry(); });
	connect(ui.PB_Back, &QPushButton::clicked, this, [=]() {hide(); });
}

void Login::Registry()
{
	QString Num = ui.LE1->text();
	QString Name = ui.LE2->text();
	QString PassWord = ui.LE3->text();
	int Power = ui.comboBox->currentText() == "学生" ? 0 : 1;
	if (Num == "")
	{
		ui.LE_Msg->setText("学号不能为空");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (Num.size() < 8)
	{
		ui.LE_Msg->setText("学号过短");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (Name == "")
	{
		ui.LE_Msg->setText("姓名不能为空");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (PassWord == "")
	{
		ui.LE_Msg->setText("密码不能为空");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (PassWord.size() < 6)
	{
		ui.LE_Msg->setText("密码至少6位");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (g_Users.find(Num)!=g_Users.end())
	{
		ui.LE_Msg->setText("学号已存在");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	User u(Num, Name, PassWord,Power);
	if (db->Add_user(u))
	{
		ui.LE_Msg->setText(QString("%1添加成功").arg(Name));
		ui.LE_Msg->setStyleSheet("QLabel{""color:green;""}");
	}
	else
	{
		ui.LE_Msg->setText(QString("添加失败"));
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
	}

}

Login::~Login()
{
}
