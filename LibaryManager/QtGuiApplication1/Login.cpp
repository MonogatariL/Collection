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
	ui.comboBox->addItem("ѧ��");
	ui.comboBox->addItem("������");
	QRegExp regx_pw("[a-zA-Z0-9_.+-*/]+$");
	QValidator* validator_pw = new QRegExpValidator(regx_pw);
	QRegExp regx_pw2("[0-9]+$");
	QValidator* validator_pw2 = new QRegExpValidator(regx_pw2);
	ui.LE1->setValidator(validator_pw2);
	ui.LE3->setValidator(validator_pw);
	ui.LE3->setEchoMode(QLineEdit::Password);//�ı���ʾģʽΪ����ԲȦ
	connect(ui.PB_Login, &QPushButton::clicked, this, [=]() {Registry(); });
	connect(ui.PB_Back, &QPushButton::clicked, this, [=]() {hide(); });
}

void Login::Registry()
{
	QString Num = ui.LE1->text();
	QString Name = ui.LE2->text();
	QString PassWord = ui.LE3->text();
	int Power = ui.comboBox->currentText() == "ѧ��" ? 0 : 1;
	if (Num == "")
	{
		ui.LE_Msg->setText("ѧ�Ų���Ϊ��");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (Num.size() < 8)
	{
		ui.LE_Msg->setText("ѧ�Ź���");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (Name == "")
	{
		ui.LE_Msg->setText("��������Ϊ��");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (PassWord == "")
	{
		ui.LE_Msg->setText("���벻��Ϊ��");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (PassWord.size() < 6)
	{
		ui.LE_Msg->setText("��������6λ");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (g_Users.find(Num)!=g_Users.end())
	{
		ui.LE_Msg->setText("ѧ���Ѵ���");
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	User u(Num, Name, PassWord,Power);
	if (db->Add_user(u))
	{
		ui.LE_Msg->setText(QString("%1��ӳɹ�").arg(Name));
		ui.LE_Msg->setStyleSheet("QLabel{""color:green;""}");
	}
	else
	{
		ui.LE_Msg->setText(QString("���ʧ��"));
		ui.LE_Msg->setStyleSheet("QLabel{""color:red;""}");
	}

}

Login::~Login()
{
}
