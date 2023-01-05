#ifndef INTERNET_H
#define INTERNET_H

#include<QQueue>
#include<QString>
#include<winsock2.h>
#include<stdio.h>
#include<iostream>
#include<process.h>

using namespace std;

class internet
{
public:
    internet();
    ~internet();
//处理组
    void msg_handle(QString);
    int msg_end(int,QString);
    void put_msg(QString res);
    void put_chat_msg(QString res);
    int send_msg(QString res);
    QString get_msg();
    QString get_chat_msg();
//设置组
    bool connect();
    void disconnect();
    void set_addr(QString);
    void set_port(QString);
    void clear();
//状态反馈组
    bool connecting();
    bool queue_empty();
    int queue_size();
    int chat_queue_size();
    SOCKET get_client_fd();
//方便调用的家伙
    bool connect_thread_running;
private:

    WSADATA wsadata;
    SOCKADDR_IN client_addr;
    SOCKET client_fd;

    bool connecting_;
    bool recving_;
    QQueue<QString> msg_queue;
    QQueue<QString> chat_msg_queue;
};

unsigned WINAPI recv_msg(void* arg);

#endif // INTERNET_H
