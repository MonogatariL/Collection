#include "pg_LoginWidget.h"
#include <QPainter>
pg_LoginWidget::pg_LoginWidget(QWidget *parent)
	: QWidget(parent)
	, pBKGImage1(nullptr)
	, pBKGImage2(nullptr)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	setAttribute(Qt::WA_TranslucentBackground);

	w = new console();
	l = new Login();
	r = new Register();
	connect(r, &Register::check_ok, this, [=](User u) {
		current_U =u;
		g_model = u.userPower;
		w->show();
		w->ui.label->setText(current_U.userName + ",欢迎使用");
		db->Get_User_Record();
		w->ui.page1_preview->update_TableW_book2();
		l->hide(); 
		r->hide(); 
		this->hide();});
	InitBKG();
	InitButton();
	initText();
}

pg_LoginWidget::~pg_LoginWidget()
{
	if (pBKGImage1)
	{
		delete pBKGImage1;
		pBKGImage1 = nullptr;
	}
	if (pBKGImage2)
	{
		delete pBKGImage2;
		pBKGImage2 = nullptr;
	}
}

void pg_LoginWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	if (pBKGImage1)
	{
		painter.drawImage(QPoint(0, 0), *pBKGImage1);
	}

	QPainterPath pathBack;

	QPainter painterCenter(ui.widget_center);
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, ui.widget_center->width(), ui.widget_center->height()),3, 3);
	painterCenter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	if (pBKGImage2)
	{
		painterCenter.drawImage(QPoint(0, 0), *pBKGImage2);
 	}
}

void pg_LoginWidget::InitButton()
{
	connect(ui.pB_onlineMode, &QPushButton::clicked, this, &pg_LoginWidget::slot_BtnOnline);
	connect(ui.pB_offlineTestMode, &QPushButton::clicked, this, &pg_LoginWidget::slot_BtnOfflineTest);
	connect(ui.pB_onlineAnalyzeMode, &QPushButton::clicked, this, &pg_LoginWidget::slot_BtnOnlineAnalyze);
}

void pg_LoginWidget::InitBKG()
{
	pBKGImage1 = new QImage(QStringLiteral(":/Login/Resources/LoginResource/bg.png"));
	pBKGImage2 = new QImage(QStringLiteral(":/Login/Resources/LoginResource/bg2.png"));

}

void pg_LoginWidget::initText()
{
	ui.label_AppName->setText("图书管理系统");
	ui.pB_onlineMode->setText("登录用户");
	ui.pB_onlineAnalyzeMode->setText("注册用户");
	ui.pB_offlineTestMode->setText("退出系统");
}

void pg_LoginWidget::slot_BtnOnline()
{
	r->show();
	l->hide();
}

void pg_LoginWidget::slot_BtnOfflineTest()
{
	close();
}

void pg_LoginWidget::slot_BtnOnlineAnalyze()
{
	r->hide();
	l->show();
}
