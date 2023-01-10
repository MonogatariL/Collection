#include "Borrowed_Manager.h"

Borrowed_Manager::Borrowed_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init_tableWidget();
	init_ComBox();
	connect(ui.CB_syurui, SIGNAL(currentIndexChanged(int)), SLOT(change_syurui(int)));
}

Borrowed_Manager::~Borrowed_Manager()
{
}

void Borrowed_Manager::init_ComBox()
{
	ui.CB_syurui->clear();
	ui.CB_syurui->addItem("无分类");
	ui.CB_syurui->addItem("借阅");
	ui.CB_syurui->addItem("归还");
}

void Borrowed_Manager::init_tableWidget()
{
	strListHead << "用户名" << "用户ID" << "书籍"<<"时间"<<"数量"<<"类型";
	ui.tableWidget->setColumnCount(6);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.tableWidget->setColumnWidth(0, 140);
	//ui.tableWidget->setColumnWidth(1, 60);
	ui.tableWidget->setColumnWidth(3, 200);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	ui.tableWidget->verticalHeader()->hide();
	ui.tableWidget->verticalScrollBar()->setDisabled(false); // 禁用滚动
	//connect(ui.tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(getRowColumn(int, int)));
}

void Borrowed_Manager::get_tableWidget()
{
	int i = 0;

	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	for (auto x : g_Record)
	{
		if (model == 1 && x.type == 1|| model == 2 && x.type == 0)
			continue;
		ui.tableWidget->setRowCount(ui.tableWidget->rowCount() + 1);
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(x.userName));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(x.userId));
		ui.tableWidget->setItem(i, 2, new QTableWidgetItem("《"+x.book + "》"));
		ui.tableWidget->setItem(i, 3, new QTableWidgetItem(x.time));
		ui.tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(x.num,10)));
		if (x.type == 0)
		{
			ui.tableWidget->setItem(i, 5, new QTableWidgetItem("借阅"));
			ui.tableWidget->item(i, 5)->setTextColor(Qt::red);
		}
		else
		{
			ui.tableWidget->setItem(i, 5, new QTableWidgetItem("归还"));
			ui.tableWidget->item(i, 5)->setTextColor(Qt::green);
		}

		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.tableWidget->item(i, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中

		ui.tableWidget->item(i, 0)->setFlags(ui.tableWidget->item(i, 0)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 1)->setFlags(ui.tableWidget->item(i, 1)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 2)->setFlags(ui.tableWidget->item(i, 2)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 3)->setFlags(ui.tableWidget->item(i, 3)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 4)->setFlags(ui.tableWidget->item(i, 4)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.tableWidget->item(i, 5)->setFlags(ui.tableWidget->item(i, 5)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		i++;
	}
}
