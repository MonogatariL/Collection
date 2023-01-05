#include<iostream>
#include<stdio.h>
#include<mysql.h>
#include"qq_database.h"

qq_database::qq_database()
{   
    mysql_init(&mysql);
    mysql_real_connect(&mysql,"localhost","root","1146011","qq",0,NULL,0);
}
qq_database::~qq_database()
{
    mysql_close(&mysql);
}
int qq_database::qq_login(string &account,string &passwd)
{
    mysql_query(&mysql,"select * from account");
    res=mysql_store_result(&mysql);
    while(row=mysql_fetch_row(res))
    {
        if(account==row[0]&&passwd==row[1])
            return 1;
    }
    return 0;
}
int qq_database::qq_register(string &account,string &passwd)
{   
    
    sprintf(sql,"insert into account values(\"%s\",\"%s\",\"%s\");",account.c_str(),passwd.c_str(),account.c_str());
    if(mysql_query(&mysql,sql)==0)
    {   
        return 1;
    }
    else 
    {
        return 0;
    }
}
int qq_database::qq_check_same_account(string &account,string &passwd)
{
    mysql_query(&mysql,"select * from account");
    res=mysql_store_result(&mysql);
    while(row=mysql_fetch_row(res))
    {   
        if(account==row[0])
            return 0;
    }
    return qq_register(account,passwd);
}
int qq_database::qq_add(string &account,string &target)
{
    
    sprintf(sql,"select * from friends where ID=\"%s\" and ID2=\"%s\";",account.c_str(),target.c_str());
    mysql_query(&mysql,sql);
    res=mysql_store_result(&mysql);
    if(row=mysql_fetch_row(res))
    {
        return 1;
    }
    sprintf(sql,"select * from account where ID=\"%s\";",target.c_str());
    mysql_query(&mysql,sql);
    res=mysql_store_result(&mysql);
    if(row=mysql_fetch_row(res))
    {
        sprintf(sql,"insert into friends values(\"%s\",\"%s\",\"%s\");",account.c_str(),row[0],row[2]);
        if(mysql_query(&mysql,sql)==0)
        {   
            sprintf(sql,"insert into friends values(\"%s\",\"%s\",\"%s\");",row[0],account.c_str(),row[2]);
            if(mysql_query(&mysql,sql)==0)
            {   
                sprintf(sql,"select NAME from account where ID=\"%s\";",account.c_str());
                mysql_query(&mysql,sql);
                res=mysql_store_result(&mysql);
                if(row=mysql_fetch_row(res))
                {
                    sprintf(sql,"update friends set NAME=\"%s\" where ID=\"%s\" AND ID2=\"%s\";",row[0],target.c_str(),account.c_str());
                    if(mysql_query(&mysql,sql)==0)
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
            }
        }
        else 
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}
int qq_database::qq_rename(string &account,string &name)
{
    
    sprintf(sql,"update friends set NAME=\"%s\" where ID2=\"%s\";",name.c_str(),account.c_str());
    if(mysql_query(&mysql,sql)!=0)
    {   
        return 0;
    }
    sprintf(sql,"update account set NAME=\"%s\" where ID=\"%s\";",name.c_str(),account.c_str());
    if(mysql_query(&mysql,sql)!=0)
    {   
        return 0;
    }
    return 1;
}
int qq_database::qq_delete(string &account,string &target)
{
    
    sprintf(sql,"delete from friends where ID=\"%s\" and ID2=\"%s\";",account.c_str(),target.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        sprintf(sql,"delete from friends where ID=\"%s\" and ID2=\"%s\";",target.c_str(),account.c_str());
        if(mysql_query(&mysql,sql)==0)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
vector<pair<string,string>> qq_database::qq_friends(string &account)
{
    vector<pair<string,string>>friends;
    
    sprintf(sql,"select * from friends where ID=\"%s\";",account.c_str());
    mysql_query(&mysql,sql);
    res=mysql_store_result(&mysql);
    while(row=mysql_fetch_row(res))
    {   
        friends.push_back({row[1],row[2]});
    }
    return friends;
}
string qq_database::qq_name(string&account)
{
    
    sprintf(sql,"select NAME from account where ID=\"%s\";",account.c_str());
    mysql_query(&mysql,sql);
    res=mysql_store_result(&mysql);
    row=mysql_fetch_row(res);
    return row[0];
}
int qq_database::qq_add_pls(string &account,string &target)
{   
    if(qq_check_exist(target)==0||qq_check_exist(account)==0)return 0;
    sprintf(sql,"select * from friends where ID=\"%s\" and ID2=\"%s\";",account.c_str(),target.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        res=mysql_store_result(&mysql);
        if(row=mysql_fetch_row(res))
        {
            return 1;
        }
        else
        {
            sprintf(sql,"select * from add_pls where ID=\"%s\" and TARGET=\"%s\";",account.c_str(),target.c_str());
            if(mysql_query(&mysql,sql)==0)
            {
                res=mysql_store_result(&mysql);
                if(row=mysql_fetch_row(res))
                {
                    return 1;
                }
                else
                {   
                    sprintf(sql,"select * from add_pls where ID=\"%s\" and TARGET=\"%s\";",target.c_str(),account.c_str());
                    if(mysql_query(&mysql,sql)==0)
                    {
                        res=mysql_store_result(&mysql);
                        if(row=mysql_fetch_row(res))
                        {
                            sprintf(sql,"delete from add_pls where ID=\"%s\" and TARGET=\"%s\";",target.c_str(),account.c_str());
                            if(mysql_query(&mysql,sql)==0)
                            {
                                return qq_add(account,target);
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                                sprintf(sql,"insert into add_pls values(\"%s\",\"%s\");",account.c_str(),target.c_str());
                                if(mysql_query(&mysql,sql)==0)
                                    return 1;
                                else
                                    return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}
int qq_database::qq_check_exist(string &account)
{
    sprintf(sql,"select * from account where ID=\"%s\";",account.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        res=mysql_store_result(&mysql);
        if(row=mysql_fetch_row(res))
        {
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
int qq_database::qq_change_pw(string &account,string &passwd)
{
    sprintf(sql,"update account set PW=\"%s\" where ID=\"%s\";",passwd.c_str(),account.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        return 1;
    }
    return 0;
}
vector<string> qq_database::qq_check_add_pls(string &account)
{
    vector<string>from;
    sprintf(sql,"select ID from add_pls where target=\"%s\";",account.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        res=mysql_store_result(&mysql);
        while(row=mysql_fetch_row(res))
        {
            from.push_back(row[0]);
        }
    }
    return from;
}
int qq_database::qq_agreen(string &account,string &target)
{
    sprintf(sql,"select * from add_pls where ID=\"%s\" and TARGET=\"%s\";",account.c_str(),target.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        res=mysql_store_result(&mysql);
        if(row=mysql_fetch_row(res))
        {
            sprintf(sql,"delete from add_pls where ID=\"%s\" and TARGET=\"%s\";",account.c_str(),target.c_str());
            if(mysql_query(&mysql,sql)==0)
            {
                return qq_add(account,target);
            }
        }
    }
    return 0;
}
int qq_database::qq_refuse(string &account,string &target)
{
    sprintf(sql,"select * from add_pls where ID=\"%s\" and TARGET=\"%s\";",account.c_str(),target.c_str());
    if(mysql_query(&mysql,sql)==0)
    {
        res=mysql_store_result(&mysql);
        if(row=mysql_fetch_row(res))
        {
            sprintf(sql,"delete from add_pls where ID=\"%s\" and TARGET=\"%s\";",account.c_str(),target.c_str());
            if(mysql_query(&mysql,sql)==0)
            {
                return 1;
            }
        }
    }
    return 0;

}
//\"%s\"