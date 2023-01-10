#include "Syurui_Manager.h"

Syurui_Manager::Syurui_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);  //0:不显示在任务栏1:窗口无边框2:窗口置顶
	//this->installEventFilter(this);
	ui.widget->setStyleSheet("#widget{"
		"border-image:url(:/page_preview/Resources/BackGround2.png);"
		"}");

	init_tableWidget();
	get_tableWidget();
	connect(ui.PB_quit, &QPushButton::clicked, this, [=](){this->hide(); });
	connect(ui.PB_add_syurui, &QPushButton::clicked, this, [=](){add_Syurui(); });

}

Syurui_Manager::~Syurui_Manager()
{
}

void Syurui_Manager::show_time()
{
	//get_tableWidget();
	if (isHidden())
		show();
	ui.L_message->clear();
}

void Syurui_Manager::init_tableWidget()
{
	strListHead <<  "分类名"<<"操作";
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setColumnWidth(0, 140);
	ui.tableWidget->setColumnWidth(1,100);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui.tableWidget->verticalHeader()->hide();
	ui.tableWidget->setAlternatingRowColors(true);
	//ui.tableWidget->verticalScrollBar()->setDisabled(false); // 禁用滚动
	//connect(ui.tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(getRowColumn(int, int)));
}

void Syurui_Manager::get_tableWidget()
{
	int i = 0;
	/*哼，想逃？*/
	for (auto ptr : destruct_ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
	destruct_ptr.clear();

	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	for (auto x : g_Syuruis)
	{

		ui.tableWidget->setRowCount(ui.tableWidget->rowCount() + 1);		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(x->syurui));
		QPushButton* bt = new QPushButton("删除分类");
		destruct_ptr.push_back(bt);
		connect(bt, &QPushButton::clicked, this, [=](){
			db->Del_syurui(x->syurui);
			get_tableWidget();
			emit update_syurui();
		});
		ui.tableWidget->setCellWidget(i,1, bt);

		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中靠右		ui.tableWidget->item(i, 0)->setFlags(ui.tableWidget->item(i, 0)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑

		i++;
	}
}

void Syurui_Manager::add_Syurui()
{
	QString str = ui.LE_syurui_name->text();
	ui.LE_syurui_name->setText("");
	if (str.size() == 0)
	{
		ui.L_message->setText("分类名不能为空");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (!db->Src_syurui(str))
	{
		ui.L_message->setText("已存在分类:"+str);
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (str == "无分类")
	{
		ui.L_message->setText("傻逼是吧");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if(db->Add_syurui(str))
	{
		emit update_syurui();
		get_tableWidget();
		ui.L_message->setText("添加成功:" + str);
		ui.L_message->setStyleSheet("QLabel{""color:green;""}");
	}
}
