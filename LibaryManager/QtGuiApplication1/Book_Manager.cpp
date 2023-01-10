#include "Book_Manager.h"

Book_Manager::Book_Manager(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	get_CB_Book_Syurui();
	init_TableW_book();
	get_tableWidget();
	connect(ui.PB_Add_Book, &QPushButton::clicked, this, [=](){
		add_Book();
	});
	connect(ui.PB_Back, &QPushButton::clicked, this, [=]() {
		hide();
		});
	/*Quantity_Manager*/
	qt_manager = new Quantity_Manager();
	connect(qt_manager, &Quantity_Manager::update_table, this, [=]() {
		get_tableWidget();
		emit update_book();
		});
	ui.widget->setStyleSheet("#widget{"
		"border-image:url(:/page_preview/Resources/BackGround2.png);"
		"}");
}

void Book_Manager::show_time()
{
	if (isHidden())
		show();
	get_CB_Book_Syurui();
	ui.L_message->clear();
}

void Book_Manager::add_Book()
{
	QString Name = ui.LE_Book_Name->text();
	QString Author = ui.LE_Book_Author->text();
	QString Syurui = ui.CB_Book_Syurui->currentText();
	int Time =ui.SB_Time->value();
	int Price = ui.SB_Price->value();
	int Num = ui.SB_Book_Num->value();
	if (Name == "")
	{
		ui.L_message->setText("��������Ϊ��");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (Author == "")
	{
		ui.L_message->setText("���߲���Ϊ��");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	if (g_Books.find(Name) != g_Books.end())
	{
		ui.L_message->setText(Name+"�Ѵ���");
		ui.L_message->setStyleSheet("QLabel{""color:red;""}");
		return;
	}
	Book book(Name,Author,Syurui,Num, Time,Price);
	if (db->Add_book(book))
	{
		ui.L_message->setText(Name + "�����");
		ui.L_message->setStyleSheet("QLabel{""color:green;""}");
		emit update_book();
		get_tableWidget();
	}

}

void Book_Manager::get_CB_Book_Syurui()
{	
	ui.CB_Book_Syurui->clear();
	for (auto s : g_Syuruis)
	{
		ui.CB_Book_Syurui->addItem(s->syurui);
	}
	ui.CB_Book_Syurui->addItem("�޷���");
}



void Book_Manager::init_TableW_book()
{
	strListHead << "����" << "����" << "�������" << "����" << "�������" << "�������"<<"������"<<"�۸�"<< "ɾ���鼮" << "���Ĵ��";
	ui.TableW_book->setColumnCount(10);
	ui.TableW_book->setHorizontalHeaderLabels(strListHead);
	ui.TableW_book->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TableW_book->setColumnWidth(0, 150);
	ui.TableW_book->setColumnWidth(1, 50);
	ui.TableW_book->setColumnWidth(2, 100);
	ui.TableW_book->setColumnWidth(3, 50);
	ui.TableW_book->setColumnWidth(4, 80);
	ui.TableW_book->setColumnWidth(5, 80);
	ui.TableW_book->setColumnWidth(6, 80);
	ui.TableW_book->setColumnWidth(7, 80);
	//ui.TableW_book->setColumnWidth(8, 60);
	ui.TableW_book->setColumnWidth(9, 60);
	//ui.TableW_book->setColumnWidth(10, 60);
	//ui.TableW_book->setColumnWidth(11, 60);
	//ui.tableWidget->setColumnWidth(1, 60);
	//ui.tableWidget->setColumnWidth(2, 100);
	ui.TableW_book->setAlternatingRowColors(true);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Fixed);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(9, QHeaderView::Fixed);
	//ui.TableW_book->horizontalHeader()->setSectionResizeMode(10, QHeaderView::Fixed);
	//ui.TableW_book->horizontalHeader()->setSectionResizeMode(11, QHeaderView::Fixed);
	ui.TableW_book->verticalHeader()->hide();
	//ui.TableW_book->verticalScrollBar()->setDisabled(false); // ���ù���
	//connect(ui.tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(getRowColumn(int, int)));
}

void Book_Manager::get_tableWidget()
{
	int i = 0;

	ui.TableW_book->clear();
	for (auto ptr : destruct_ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
	destruct_ptr.clear();
	ui.TableW_book->setRowCount(0);
	ui.TableW_book->setHorizontalHeaderLabels(strListHead);
	for (auto x : g_Books)
	{

		ui.TableW_book->setRowCount(ui.TableW_book->rowCount() + 1);		ui.TableW_book->setItem(i, 0, new QTableWidgetItem("��" + x.bookName + "��"));
		ui.TableW_book->setItem(i, 1, new QTableWidgetItem(x.bookAuthor));
		ui.TableW_book->setItem(i, 2, new QTableWidgetItem(x.bookAddDate));
		ui.TableW_book->setItem(i, 3, new QTableWidgetItem(x.bookSyurui));
		ui.TableW_book->setItem(i, 4, new QTableWidgetItem(QString::number(x.bookNum, 10)));
		ui.TableW_book->setItem(i, 5, new QTableWidgetItem(QString::number(x.bookLendNum, 10)));
		ui.TableW_book->setItem(i, 6, new QTableWidgetItem(QString::number(x.bookTime, 10)+"��"));
		ui.TableW_book->setItem(i, 7, new QTableWidgetItem(QString::number(x.bookPrice, 10)+"Ԫ"));
		//QPushButton* bt1 = new QPushButton("�黹�鼮"); destruct_ptr.push_back(bt1);
		//connect(bt1, &QPushButton::clicked, this, [=]() {
		//	qt_manager->add(x.bookName);
		//	});
		//QPushButton* bt2 = new QPushButton("����鼮"); destruct_ptr.push_back(bt2);
		//connect(bt2, &QPushButton::clicked, this, [=]() {
		//	qt_manager->sub(x.bookName);
		//	});
		QPushButton* bt3 = new QPushButton("ɾ���鼮"); destruct_ptr.push_back(bt3);
		connect(bt3, &QPushButton::clicked, this, [=]() {
			QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��ɾ����" + x.bookName + "����");
			box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
			box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
			box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
			int confimBtn = box.exec();
			if (confimBtn == QMessageBox::Ok) {
				db->Del_book(x.bookName);
				get_tableWidget();
				emit update_book();
			}
			});
		QPushButton* bt4 = new QPushButton("���Ŀ��"); destruct_ptr.push_back(bt4);
		connect(bt4, &QPushButton::clicked, this, [=]() {
			qt_manager->change(x.bookName);
			});
		//ui.TableW_book->setCellWidget(i, 8, bt1);
		//ui.TableW_book->setCellWidget(i, 9, bt2);
		ui.TableW_book->setCellWidget(i, 8, bt3);
		ui.TableW_book->setCellWidget(i, 9, bt4);

		ui.TableW_book->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 7)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//��ֱ����		ui.TableW_book->item(i, 0)->setFlags(ui.TableW_book->item(i, 0)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 1)->setFlags(ui.TableW_book->item(i, 1)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 2)->setFlags(ui.TableW_book->item(i, 2)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 3)->setFlags(ui.TableW_book->item(i, 3)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 4)->setFlags(ui.TableW_book->item(i, 4)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 5)->setFlags(ui.TableW_book->item(i, 5)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 6)->setFlags(ui.TableW_book->item(i, 6)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭
		ui.TableW_book->item(i, 7)->setFlags(ui.TableW_book->item(i, 7)->flags() & (~Qt::ItemIsEditable));//ϵͳ���Ͳ��ɱ༭

		i++;
	}
}

Book_Manager::~Book_Manager()
{
}
