#include "Syurui_Manager.h"

Syurui_Manager::Syurui_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);  //0:����ʾ��������1:�����ޱ߿�2:�����ö�
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
	strListHead <<  "������"<<"����";
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setHorizontalHeaderLabels(strListHead);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setColumnWidth(0, 140);
	ui.tableWidget->setColumnWidth(1,100);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui.tableWidget->verticalHeader()->hide();
	ui.tableWidget->setAlternatingRowColors(true);
	//ui.tableWidget->verticalScrollBar()->setDisabled(false); // ���ù���
	//connect(ui.tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(getRowColumn(int, int)));
}

void Syurui_Manager::get_tableWidget()
{
	int i = 0;
	/*�ߣ����ӣ�*/
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
		QPushButton* bt = new QPushButton("ɾ������");
		destruct_ptr.push_back(bt);
		connect(bt, &QPushButton::clicked, this, [=](){
			db->Del_syurui(x->syurui);
			get_tableWidget();
			emit update_syurui();
		});
		ui.tableWidget->setCellWidget(i,1, bt);

		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ���п���		ui.tableWidget->item(i, 0)->setFlags(ui.tableWidget->item(i, 0)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭

		i++;
	}
}

void Syurui_Manager::add_Syurui()
{
	QString str = ui.LE_syurui_name->text();
	ui.LE_syurui_name->setText("");
	if (str.size() == 0)
	{
		ui.L_message->setText("����������Ϊ��");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (!db->Src_syurui(str))
	{
		ui.L_message->setText("�Ѵ��ڷ���:"+str);
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (str == "�޷���")
	{
		ui.L_message->setText("ɵ���ǰ�");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if(db->Add_syurui(str))
	{
		emit update_syurui();
		get_tableWidget();
		ui.L_message->setText("��ӳɹ�:" + str);
		ui.L_message->setStyleSheet("QLabel{""color:green;""}");
	}
}
