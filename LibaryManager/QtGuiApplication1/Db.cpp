#include "Db.h"

Db::Db()
{
	init_db();
	Get_syurui();
	Get_book(); 
	Get_user();
	Get_Record();
}

Db::~Db()
{
}

bool Db::init_db()
{
	init_success = false;
	QString pAddress = QCoreApplication::applicationDirPath() + "/Setting.ini";
	QSettings settings(pAddress, QSettings::IniFormat);
	db_host = READ_INI_STR("DBParam/DBServer", "127.0.0.1");
	db_data_source_name = READ_INI_STR("DBParam/DBName", "library");
	db_user_name = READ_INI_STR("DBParam/DBUser", "sa");
	db_user_pwd = READ_INI_STR("DBParam/DBPwd", "occ");
	_dsn = "DRIVER={SQL SERVER};SERVER=" + db_host + ";DATABASE=" + db_data_source_name + ";UID=" + db_user_name + ";PWD=" + db_user_pwd + ";";
	//连接数据库
	if (_dsn.isEmpty())
	{
		QString err_msg = m_db.lastError().text();
		QMessageBox message(QMessageBox::NoIcon, "错误！", "连接数据库失败!\n " + err_msg);
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}

	m_db = QSqlDatabase::addDatabase("QODBC", "first");
	m_db.setDatabaseName(_dsn);

	if (!m_db.open())
	{
		QString err_msg = m_db.lastError().text();
		QMessageBox message(QMessageBox::NoIcon, "错误！", "连接数据库失败!\n " + err_msg);
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	init_success = true;
	return true;
}
bool Db::Get_syurui()
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	if (!sql_query.exec("SELECT * FROM Table_Syurui"))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", "SELECT * FROM Table_Syurui失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	for (auto ptr : g_Syuruis)
	{
		delete ptr;
		ptr = nullptr;
	}
	g_Syuruis.clear();
	while (sql_query.next())
	{
		QString syurui = sql_query.value("syurui").toString();
		QString syurui_ID = sql_query.value("syurui_ID").toString();
		int count = sql_query.value("count").toInt();
		if (g_Syuruis.find(syurui) == g_Syuruis.end())
		{
			Lib_Syurui *s=new Lib_Syurui();
			s->syurui = syurui;
			s->syurui_ID = syurui_ID;
			s->count = count;
			g_Syuruis[syurui] = s;
		}
		else
		{
			g_Syuruis[syurui]->syurui = syurui;
			g_Syuruis[syurui]->syurui_ID = syurui_ID;
			g_Syuruis[syurui]->count = count;
		}
	}
	return true;
}
bool Db::Del_syurui(QString syurui_name)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql = QString("delete from Table_Syurui where syurui='%1'").arg(syurui_name);

	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql+"失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	sql = QString("update table_book set bookSyurui = '无分类' where bookSyurui = '%1'").arg(syurui_name);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}

	auto iter = g_Syuruis.find(syurui_name);
	g_Syuruis.erase(iter);

	for (auto& b : g_Books)
	{
		if (b.bookSyurui == syurui_name)
			b.bookSyurui = "无分类";
	}
	return true;
}

bool Db::Add_syurui(QString syurui_name)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QDateTime current_date_time = QDateTime::currentDateTime();//获取当前时间
	QString current_date = current_date_time.toString("yyMMddhhmmssz");//截取当前时间为分类ID号，年(取后两位)月日时分秒毫秒(前两位)

	QString sql = QString("insert into Table_Syurui (syurui,syurui_ID,count) VALUES ('%1','%2',0)")\
		.arg(syurui_name).arg(current_date);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	return Get_syurui();
}

bool Db::Src_syurui(QString syurui_name)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QString sql = QString("select * from Table_Syurui where syurui='%1'").arg(syurui_name);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	while (sql_query.next())
		return false;
	return true;
}

bool Db::Get_book(QString s)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql;
	if (s == "")
		sql = "SELECT * FROM Table_Book";
	else
		sql = s;
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql+"失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	g_Books.clear();
	while (sql_query.next())
	{
		QString bookId = sql_query.value("bookId").toString();
		QString bookName = sql_query.value("bookName").toString();
		QString bookAuthor = sql_query.value("bookAuthor").toString();
		QString bookAddDate = sql_query.value("bookAddDate").toString();
		QString bookSyurui = sql_query.value("bookSyurui").toString();
		int bookLendNum = sql_query.value("bookLendNum").toInt();
		int bookNum = sql_query.value("bookNum").toInt();
		int bookTime = sql_query.value("bookTime").toInt();
		int bookPrice = sql_query.value("bookPrice").toInt();
		if (g_Syuruis.find(bookName) == g_Syuruis.end())
		{
			Book b;
			b.bookId = bookId;
			b.bookName = bookName;
			b.bookAuthor = bookAuthor;
			b.bookAddDate = bookAddDate;
			b.bookSyurui = bookSyurui;
			b.bookLendNum = bookLendNum;
			b.bookNum = bookNum;
			b.bookPrice = bookPrice;
			b.bookTime = bookTime;
			g_Books[bookName] = b;
		}
		else
		{
			g_Books[bookName].bookId = bookId;
			g_Books[bookName].bookName = bookName;
			g_Books[bookName].bookAuthor = bookAuthor;
			g_Books[bookName].bookAddDate = bookAddDate;
			g_Books[bookName].bookSyurui = bookSyurui;
			g_Books[bookName].bookLendNum = bookLendNum;
			g_Books[bookName].bookNum = bookNum;
			g_Books[bookName].bookPrice = bookPrice;
			g_Books[bookName].bookTime = bookTime;
		}
	}
	return true;
}

bool Db::Add_book(Book book)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QDateTime current_date_time = QDateTime::currentDateTime();//获取当前时间
	QString current_date = current_date_time.toString("yyMMddhhmmssz");//截取当前时间为分类ID号，年(取后两位)月日时分秒毫秒(前两位)
	QString current_date2 = current_date_time.toString("yyyy.MM.dd");//截取当前时间为分类ID号，年(取后两位)月日时分秒毫秒(前两位)

	QString sql = QString("insert into Table_Book (bookName,bookId,bookSyurui,bookAddDate,bookAuthor,bookLendNum,bookNum,bookTime,bookPrice) VALUES ('%1','%2','%3','%4','%5',%6,%7,%8,%9)")\
		.arg(book.bookName).arg(current_date).arg(book.bookSyurui).arg(current_date2)\
		.arg(book.bookAuthor).arg(0).arg(book.bookNum).arg(book.bookTime).arg(book.bookPrice);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}

	return Get_book();
}

bool Db::Del_book(QString bookName)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql = QString("delete from Table_Book where bookName='%1'").arg(bookName);

	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	auto iter = g_Books.find(bookName);
	g_Books.erase(iter);
	return true;

}

bool Db::Src_book(QString sql)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	return true;
}

bool Db::Update_book_lend(QString name, int num)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql = QString("update table_book set bookLendNum=%1 where bookName='%2'").arg(num).arg(name);

	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	g_Books[name].bookLendNum = num;
	return true;
}

bool Db::Update_book_num(QString name, int num)
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql = QString("update table_book set bookNum=%1 where bookName='%2'").arg(num).arg(name);

	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	g_Books[name].bookNum = num;
	return true;
}

bool Db::Add_user(User u)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QString sql = QString("insert into Table_User (userNum,userName,userPw,userPower) VALUES ('%1','%2','%3',%4)")\
		.arg(u.userNum).arg(u.userName).arg(u.userPw).arg(u.userPower);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	return Get_user();
}

bool Db::Src_user(QString Num,QString Pw)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QString sql = QString("Select * from table_user where userNum='%1' and userPw='%2'").arg(Num).arg(Pw);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	while (sql_query.next())
		return true;
	return false;
}

bool Db::Get_user()
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	if (!sql_query.exec("SELECT * FROM Table_User"))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", "SELECT * FROM Table_User失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}

	g_Users.clear();
	while (sql_query.next())
	{
		QString userNum = sql_query.value("userNum").toString();
		QString userName = sql_query.value("userName").toString();
		QString userPw = sql_query.value("userPw").toString();
		int userPower = sql_query.value("userPower").toInt();
		if (g_Users.find(userNum) == g_Users.end())
		{
			User u;
			u.userNum = userNum;
			u.userName = userName;
			u.userPw = userPw;
			u.userPower = userPower;
			g_Users[userNum] = u;
		}
		else
		{
			g_Users[userNum].userNum = userNum;
			g_Users[userNum].userName = userName;
			g_Users[userNum].userPw = userPw;
			g_Users[userNum].userPower = userPower;
		}
	}
	return true;
}

bool Db::Del_user()
{
	return 1;

}

bool Db::Add_Record(Record r)
{
	if (!init_success)
		return false;
	QSqlQuery sql_query(m_db);
	QString sql = QString("insert into Table_takeRecord (userName,userId,book,time,num,type) VALUES ('%1','%2','%3','%4',%5,%6)")\
		.arg(r.userName).arg(r.userId).arg(r.book).arg(r.time).arg(r.num).arg(r.type);
	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	return Get_Record();
}

bool Db::Get_Record()
{
	if (!init_success)
		return false;

	QSqlQuery sql_query(m_db);
	QString sql="select * from table_takeRecord";

	if (!sql_query.exec(sql))
	{
		QMessageBox message(QMessageBox::NoIcon, "错误！", sql + "失败！");
		message.setButtonText(QMessageBox::Ok, QString("确定"));
		message.exec();
		return false;
	}
	g_Record.clear();
	QMap<QString, int>user_r;
	while (sql_query.next())
	{
		QString userName = sql_query.value("userName").toString();
		QString userId = sql_query.value("userId").toString();
		QString book = sql_query.value("book").toString();
		QString time = sql_query.value("time").toString();
		int num = sql_query.value("num").toInt();
		int type = sql_query.value("type").toInt();
		
		Record r;
		r.userName = userName;
		r.userId = userId;
		r.book = book;
		r.time = time;
		r.num = num;
		r.type = type;

		g_Record.push_back(r);

		if (r.userName == current_U.userName)
		{
			if (type == 0)
				user_r[book] += num;
			else
				user_r[book] -= num;
		}
	}
	g_User_Record.clear();
	for (auto iter = user_r.begin(); iter != user_r.end(); iter++)
	{
		QString book = iter.key();
		int num = iter.value();
		if (num == 0)
			continue;
		Record r(book, num);
		g_User_Record.push_back(r);
	}
	return true;
}

bool Db::Get_User_Record()
{
	return false;
}
