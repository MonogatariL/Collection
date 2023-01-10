#include "User_Manager.h"

User_Manager::User_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init_tableWidget();
	get_tableWidget();
	init_ComBox();
	connect(ui.CB_user, SIGNAL(currentIndexChanged(int)), SLOT(change_syurui(int)));
}

User_Manager::~User_Manager()
{
}

void User_Manager::init_tableWidget()
{
	strListHead << "学号" << "姓名" << "权限";
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.tableWidget->setColumnWidth(0, 140);
	//ui.tableWidget->setColumnWidth(1, 60);
	//ui.tableWidget->setColumnWidth(2, 100);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	ui.tableWidget->verticalHeader()->hide();
	//ui.tableWidget->verticalScrollBar()->setDisabled(false); // 禁用滚动
	//connect(ui.tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(getRowColumn(int, int)));
}

void User_Manager::get_tableWidget()
{
	int i = 0;

	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	for (auto x : g_Users)
	{
		if (model == 1 && x.userPower == 1||model==2&&x.userPower!=1)
			continue;
		ui.tableWidget->setRowCount(ui.tableWidget->rowCount() + 1);
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(x.userNum));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(x.userName));
		if (x.userPower == 1)
		{
			ui.tableWidget->setItem(i, 2, new QTableWidgetItem("管理员"));
			ui.tableWidget->item(i, 2)->setTextColor(Qt::red);
		}
		else
		{
			ui.tableWidget->setItem(i, 2, new QTableWidgetItem("学生"));
		}
		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 0)->setFlags(ui.tableWidget->item(i, 0)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 1)->setFlags(ui.tableWidget->item(i, 1)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 2)->setFlags(ui.tableWidget->item(i, 2)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑

		i++;
	}
}

void User_Manager::init_ComBox()
{
	ui.CB_user->clear();
	ui.CB_user->addItem("无分类");
	ui.CB_user->addItem("学生");
	ui.CB_user->addItem("管理员");
}
