#include "page_preview.h"

page_preview::page_preview(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();
	init_TableW_book();
	update_ComboBox_syurui();
}

void page_preview::init()
{
	/*Syurui_Manager*/
	sy_manager = new Syurui_Manager();
	sy_manager->hide();
	connect(sy_manager, &Syurui_Manager::update_syurui, this, [=]() {update_TableW_book(); update_Data(); update_ComboBox_syurui(); });
	connect(ui.PB_syurui_manager, &QPushButton::clicked, this, [=]() {
		if (g_model == 0)
		{
			QMessageBox box(QMessageBox::Warning, "提示", "仅限管理员访问");
			box.exec();
			return;
		}
		sy_manager->show_time(); 
		bk_manager->hide();
	});
	/*Book_Manager*/
	bk_manager = new Book_Manager();
	bk_manager->hide();
	connect(bk_manager, &Book_Manager::update_book, this, [=]() {update_TableW_book(); update_Data(); });
	connect(ui.PB_book_manager, &QPushButton::clicked, this, [=]() {
		if (g_model == 0)
		{
			QMessageBox box(QMessageBox::Warning, "提示", "仅限管理员访问");
			box.exec();
			return;
		}
		db->Get_book();
		bk_manager->show_time();
		sy_manager->hide();
	});
	/*Chart_manager*/
	//chart_manager = new Charts();
	//ui.horizontalLayout_3->addWidget(chart_manager->get_SyuruiNum());
	//connect(ui.PB_ChangePage, &QPushButton::clicked, this, [=]() {
	//	static int i = 0;
	//	if (i>= 2)
	//		i = 0;
	//	ui.stackedWidget->setCurrentIndex(i++);
	//});
	/*User_manager*/
	//user_manager = new Login();
	//connect(ui.PB_user, &QPushButton::clicked, this, [=]() {
	//	user_manager->show();
	//});
	/*PB_search*/
	connect(ui.PB_search, &QPushButton::clicked, this, [=]() {
		QString sql = "select * from table_book where ";
		QString price = QString("(bookPrice>=%1 and bookPrice<=%2)").arg(ui.SP1->value()).arg(ui.SP2->value());
		QString time = QString("(bookTime>=%1 and bookTime<=%2)").arg(ui.SP3->value()).arg(ui.SP4->value());
		sql+=price + "and" + time;
		if (ui.LE1->text() != "")
			sql +=QString(" and bookName='%1'" ).arg(ui.LE1->text());
		if(ui.LE2->text()!="")
			sql += QString(" and bookAuthor='%1'").arg(ui.LE2->text());
		if(ui.comboBox->currentText()!="无分类")
			sql += QString(" and bookSyurui='%1'").arg(ui.comboBox->currentText());
		if(ui.checkBox->isChecked())
			sql += QString(" and bookNum>0");
		db->Get_book(sql);
		update_TableW_book();
		ui.Label_Src_Msg->setText(QString("共查询到%1本书籍").arg(g_Books.size()));
		ui.Label_Src_Msg->setStyleSheet("QLabel{""color:green;""}");
	});
	/*PB_clean*/
	connect(ui.PB_clean, &QPushButton::clicked, this, [=]() {
		db->Get_book();
		update_TableW_book();
		ui.LE1->clear();
		ui.LE2->clear();
		ui.LE3->clear();
		ui.SP1->setValue(0);
		ui.SP2->setValue(4396);
		ui.SP3->setValue(0);
		ui.SP4->setValue(2025);
		ui.checkBox->setChecked(false);
		ui.comboBox->setCurrentIndex(0);
		ui.Label_Src_Msg->setText("");
	});
	/*Quantity_Manager*/
	qt_manager = new Quantity_Manager();
	connect(qt_manager, &Quantity_Manager::update_table, this, [=]() {
		update_TableW_book();
		update_TableW_book2();
		update_Data();
		});
}

void page_preview::init_TableW_book()
{
	strListHead2.clear();
	strListHead2 << "书名" << "借阅数量" << "操作";
	ui.TableW_book2->setColumnCount(3);
	ui.TableW_book2->setHorizontalHeaderLabels(strListHead2);
	ui.TableW_book2->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TableW_book2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.TableW_book2->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.TableW_book2->setColumnWidth(2, 150);
	ui.TableW_book2->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui.TableW_book2->setStyleSheet({ "QHeaderView{ background:black;}" });
	ui.TableW_book2->verticalHeader()->hide();

	strListHead.clear();
	strListHead << "书名" << "作者" << "添加日期" << "分类" << "发行年"<<"价格"<<"库存数量" << "借出数量"<<"ID";
	ui.TableW_book->setColumnCount(9);
	ui.TableW_book->setHorizontalHeaderLabels(strListHead);
	ui.TableW_book->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Stretch);
	ui.TableW_book->setColumnWidth(8, 0);
	ui.TableW_book->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Fixed);
	//ui.TableW_book->setStyleSheet({ "QHeaderView{ background:black;}" });
	ui.TableW_book->verticalHeader()->hide();
	connect(ui.TableW_book, &QTableWidget::cellDoubleClicked, this, [=](int row, int col) {
		getRowColumn(row, col);
		});
	update_TableW_book();
	update_TableW_book2();
	update_Data();
}

void page_preview::update_TableW_book()
{
	int i = 0;

	ui.TableW_book->clear();
	ui.TableW_book->setRowCount(0);
	ui.TableW_book->setHorizontalHeaderLabels(strListHead);
	for (auto x : g_Books)
	{

		ui.TableW_book->setRowCount(ui.TableW_book->rowCount() + 1);		ui.TableW_book->setItem(i, 0, new QTableWidgetItem("《"+x.bookName+"》"));
		ui.TableW_book->setItem(i, 1, new QTableWidgetItem(x.bookAuthor));
		ui.TableW_book->setItem(i, 2, new QTableWidgetItem(x.bookAddDate));
		ui.TableW_book->setItem(i, 3, new QTableWidgetItem(x.bookSyurui));
		ui.TableW_book->setItem(i, 4, new QTableWidgetItem(QString::number(x.bookTime, 10) + "年"));
		ui.TableW_book->setItem(i, 5, new QTableWidgetItem(QString::number(x.bookPrice, 10) + "元"));
		ui.TableW_book->setItem(i, 6, new QTableWidgetItem(QString::number(x.bookNum,10)));
		ui.TableW_book->setItem(i, 7, new QTableWidgetItem(QString::number(x.bookLendNum, 10)));
		ui.TableW_book->setItem(i, 8, new QTableWidgetItem(x.bookName));

		ui.TableW_book->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 7)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中		ui.TableW_book->item(i, 0)->setFlags(ui.TableW_book->item(i, 0)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 1)->setFlags(ui.TableW_book->item(i, 1)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 2)->setFlags(ui.TableW_book->item(i, 2)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 3)->setFlags(ui.TableW_book->item(i, 3)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 4)->setFlags(ui.TableW_book->item(i, 4)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 5)->setFlags(ui.TableW_book->item(i, 5)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 6)->setFlags(ui.TableW_book->item(i, 5)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book->item(i, 7)->setFlags(ui.TableW_book->item(i, 5)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑

		i++;
	}
}

void page_preview::update_TableW_book2()
{
	int i = 0;
	for (auto x : destruct_ptr3)
	{
		delete x;
	}
	destruct_ptr3.clear();
	ui.TableW_book2->clear();
	ui.TableW_book2->setRowCount(0);
	ui.TableW_book2->setHorizontalHeaderLabels(strListHead2);
	for (auto x : g_User_Record)
	{

		ui.TableW_book2->setRowCount(ui.TableW_book2->rowCount() + 1);

		ui.TableW_book2->setItem(i, 0, new QTableWidgetItem("《"+x.book + "》"));
		ui.TableW_book2->setItem(i, 1, new QTableWidgetItem(QString::number(x.num, 10)));
		ui.TableW_book2->setItem(i, 2, new QTableWidgetItem(QString::number(x.num, 10)));
		QPushButton* bt3 = new QPushButton("归还"); 
		destruct_ptr3.push_back(bt3);
		connect(bt3, &QPushButton::clicked, this, [=]() {
			qt_manager->add(x.book,x.num);
			});
		ui.TableW_book2->setCellWidget(i, 2, bt3);

		ui.TableW_book2->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.TableW_book2->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中
		ui.TableW_book2->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//垂直居中

		ui.TableW_book2->item(i, 0)->setFlags(ui.TableW_book2->item(i, 0)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book2->item(i, 1)->setFlags(ui.TableW_book2->item(i, 1)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		ui.TableW_book2->item(i, 2)->setFlags(ui.TableW_book2->item(i, 2)->flags() & (~Qt::ItemIsEditable));//系统类型不可编辑
		i++;
	}
}

void page_preview::update_ComboBox_syurui()
{
	ui.comboBox->clear();
	ui.comboBox->addItem("无分类");
	for (auto s : g_Syuruis)
	{
		ui.comboBox->addItem(s->syurui);
	}
}

void page_preview::update_Data()
{
	ui.LB1->setText(QString::number(g_Books.size(), 10)+"本");
	ui.LB2->setText(QString::number(g_Syuruis.size(), 10)+"类");
	int res = 0;
	int lend = 0;
	for (auto x : g_Books)
	{
		res += x.bookNum;
		lend += x.bookLendNum;
	}
	ui.LB3->setText(QString::number(res, 10)+"本");
	ui.LB4->setText(QString::number(lend, 10)+"本");

}

void page_preview::getRowColumn(int r, int c)
{
	QString bookName = ui.TableW_book->item(r, 8)->text();
	qt_manager->sub(bookName);
}

void page_preview::keyPressEvent(QKeyEvent* key)
{
	if (key->key() == Qt::Key_0)
		chart_manager->update_SyuruiNum();
}


page_preview::~page_preview()
{
	delete sy_manager;
	delete bk_manager;
}
