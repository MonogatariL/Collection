#include "internet.h"
#include<QDebug>
unsigned WINAPI recv_msg(void *arg);
int i=0;
internet::internet()
{
    WSAStartup(MAKEWORD(2,2),&wsadata);
    client_fd=socket(PF_INET,SOCK_STREAM,0);

    client_addr.sin_family=AF_INET;
    client_addr.sin_port=htons(4397);
    client_addr.sin_addr.s_addr=inet_addr("118.31.247.104");
    connect_thread_running=false;
    connecting_=false;
    recving_=false;

}
internet::~internet()
{
    qDebug()<<"网络连接触发析构函数啦"<<endl;
    closesocket(client_fd);
    WSACleanup();
}

//设置组====================================================================================================
bool internet::connect()
{
    if(connecting_)
        return true;
    connect_thread_running=true;
    client_fd=socket(PF_INET,SOCK_STREAM,0);
    for(int i=0;i<10&&connect_thread_running;i++)
    {
        int ret=::connect(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr));
        if(ret==0)
        {
            connecting_=true;
            recving_=true;
            connect_thread_running=false;
            _beginthreadex(NULL,0,recv_msg,(void*)this,0,NULL);
            return true;
        }
        qDebug()<<"请求连接中"<<i<<endl;
    }
    qDebug()<<"connect_die"<<endl;
    connect_thread_running=false;
    return false;
}
void internet::disconnect()
{
    if(!connecting_)
        return;
    connecting_=false;
    recving_=false;
    closesocket(client_fd);
}
void internet::clear()
{
    msg_queue.clear();
}
void internet::set_addr(QString addr)
{
    if(connecting_)return;
    client_addr.sin_addr.s_addr=inet_addr(addr.toUtf8().data());
}
void internet::set_port(QString port)
{
    if(connecting_)return;
    client_addr.sin_port=htons(port.toInt());
}

//状态反馈组====================================================================================================
bool internet::queue_empty()
{
    return msg_queue.empty();
}
int internet::queue_size()
{
    return msg_queue.size();
}

int internet::chat_queue_size()
{
    return chat_msg_queue.size();
}
SOCKET internet::get_client_fd()
{
    return client_fd;
}
bool internet::connecting()
{
    return connecting_;
}


//消息处理组====================================================================================================
unsigned WINAPI recv_msg(void *arg)
{
    internet *client=(internet*)arg;
    SOCKET client_fd=client->get_client_fd();
    int ret;
    char msg[1024];
    while(1)
    {
        memset(msg,0,sizeof(msg));
        ret=recv(client_fd,msg,sizeof(msg),0);
        if(ret<=0)
        {
            qDebug()<<"服务器炸了"<<endl;
            client->disconnect();
            return NULL;
        }
        if(msg[0]=='f')
            client->put_chat_msg(msg);
        else
            client->put_msg(msg);
        //client->msg_handle(msg);
    }
    return NULL;
}
void internet::msg_handle(QString res)
{

}
int internet::msg_end(int index,QString msg)
{

}
int internet::send_msg(QString res)
{
    if(connecting())
        return send(get_client_fd(),res.toUtf8().data(),strlen(res.toUtf8().data()),0);
    else
        return SOCKET_ERROR;
}
QString internet::get_msg()
{
    if(!connecting_||msg_queue.size()==0)
        return "";
    QString msg=msg_queue.front();
    qDebug()<<"get_msg:"<<msg<<endl;
    msg_queue.pop_front();
    return msg;
}

QString internet::get_chat_msg()
{
    if(!connecting_||chat_msg_queue.size()==0)
        return "";
    QString msg=chat_msg_queue.front();
    qDebug()<<"get_chat_msg:"<<msg<<endl;
    chat_msg_queue.pop_front();
    return msg;
}
void internet::put_msg(QString res)
{
    msg_queue.push_back(res);
    qDebug()<<"put_msg:"<<res<<endl;
}

void internet::put_chat_msg(QString res)
{
    chat_msg_queue.push_back(res);
    qDebug()<<"put_chat_msg:"<<res<<endl;
}
