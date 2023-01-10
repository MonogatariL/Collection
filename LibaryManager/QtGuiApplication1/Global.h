#pragma once
#include<QtWidgets>
#include<QtCharts>
#include<QVector>

#pragma execution_character_set("utf-8")

#define READ_INI_STR(key, default_value) (settings.contains(key) ? settings.value(key).toString() : default_value)
#define READ_INI_INT(key, default_value) (settings.contains(key) ? settings.value(key).toInt() : default_value)
class Lib_Syurui;
class Book;
class User;
class Record;

extern QMap<QString, Lib_Syurui*>g_Syuruis;//key syurui
extern QMap<QString, Book>g_Books;//key bookName
extern QMap<QString, User>g_Users;
extern QVector<Record>g_Record;//整体借阅归还记录
extern QVector<Record>g_User_Record;//当前用户待归还记录

extern int g_model;
extern User current_U;
//enum syurui
//{
//	syurui_ranobe=0,
//	syurui_politics,
//	syurui_science,
//	syurui_military,
//	syurui_literary,
//	syurui_historical,
//	syurui_astronomy,
//	syurui_agriculture,
//	syurui_biology,
//	syurui_sports,
//	syurui_novel,
//};
class Record
{
public:
	Record() {}
	Record(QString b,int num):book(b),num(num){}
	Record(QString N, QString I, QString B, QString T, int num, int type) :userName(N),userId(I),book(B),time(T),num(num),type(type) {}
	QString userName;
	QString userId;
	QString book;
	QString time;
	int num;
	int type;
};
class User
{
public:
	User() {}
	User(QString N, QString Name, QString ID,int P) :userNum(N), userName(Name), userPw(ID),userPower(P) {}
	QString userNum;
	QString userName;
	QString userPw;
	int userPower;
};
class Book
{
public:
	Book(){}
	Book(QString N, QString A, QString S, int Num,int T,int P) :bookName(N), bookAuthor(A), bookSyurui(S), bookNum(Num),bookTime(T),bookPrice(P){}
	QString bookId;
	QString bookName;
	QString bookAuthor;
	QString bookAddDate;
	QString bookSyurui;
	int bookLendNum;
	int bookNum;
	int bookTime;
	int bookPrice;
	
};

class Lib_Syurui
{
public:
	QString syurui;
	QString syurui_ID;
	int count;
};

class Global
{
public:
	Global();
	~Global();
};
