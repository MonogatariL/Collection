#pragma once
#ifndef QQ_DATABASE_H
#define QQ_DATABASE_H
#include<mysql.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

class qq_database
{
public:
    qq_database();
    ~qq_database();

    int qq_check_same_account(string &account,string &passwd);
    int qq_register(string &account,string &passwd);
    int qq_login(string &account,string &passwd);
    int qq_add(string &account,string &target);
    int qq_rename(string &account,string &name);
    int qq_delete(string &account,string &target);
    int qq_check_exist(string &account);
    int qq_add_pls(string &account,string &target);
    vector<string> qq_check_add_pls(string &account);
    int qq_change_pw(string &account,string &passwd);
    string qq_name(string&account);
    vector<pair<string,string>> qq_friends(string &account);
    int qq_agreen(string &account,string &target);
    int qq_refuse(string &account,string &target);
    
private:
    char sql[128];
    MYSQL mysql;		//数据库结构体
    MYSQL_RES* res;		//结果集合结构体
    MYSQL_ROW row;      //存放记录的数组 类型为char**
};



#endif