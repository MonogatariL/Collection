#include "Global.h"

QMap<QString, Lib_Syurui*>g_Syuruis;
QMap<QString, Book>g_Books;
QMap<QString, User>g_Users;
QVector<Record>g_Record;
QVector<Record>g_User_Record;

int g_model;
User current_U;

Global::Global()
{

}

Global::~Global()
{
}
