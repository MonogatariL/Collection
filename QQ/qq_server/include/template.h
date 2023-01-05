#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<fcntl.h>
#include<error.h>

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define msg_size 1024

void initialization(struct sockaddr_in& server_addr,int &server_fd)
{   
    server_fd=socket(PF_INET,SOCK_STREAM|SOCK_CLOEXEC|SOCK_NONBLOCK,0);
    server_addr.sin_family=AF_INET;
}
void Error_msg(string msg)
{
    cout<<"Error_msg:"<<msg<<endl;
}