#pragma once
#include "Global.h"
#include<QtWidgets>
#include<QtSql>

class Db
{
public:
	Db();
	~Db();
public:
	bool init_db();
	bool Get_syurui();
	bool Del_syurui(QString);
	bool Add_syurui(QString);
	bool Src_syurui(QString);

	bool Get_book(QString sql="");
	bool Add_book(Book);
	bool Del_book(QString);
	bool Src_book(QString);

	bool Get_user();
	bool Add_user(User);
	bool Src_user(QString,QString);
	bool Del_user();

	bool Add_Record(Record);
	bool Get_Record();
	bool Get_User_Record();

	bool Update_book_lend(QString,int);
	bool Update_book_num(QString, int);

private:
	// 数据库连接信息
	bool init_success = false;
	QString db_host = "";
	QString db_data_source_name = "";
	QString db_user_name = "";
	QString db_user_pwd = "";
	QString db_hostHD = "";
	QString db_data_source_nameHD = "";
	QString db_user_nameHD = "";
	QString db_user_pwdHD = "";
	QSqlDatabase m_db;
	QSqlDatabase m_db_DH;

	QString _dsn;
	QString _dsnHD;
};

extern Db* db;



