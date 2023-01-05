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
    server_fd=socket(PF_INET,SOCK_STREAM,0);
    server_addr.sin_family=AF_INET;
}
void Error_msg(string msg)
{
    cout<<"Error_msg:"<<msg<<endl;
}

int main(int argc,char *argv[])
{
    int client_fd;
    struct sockaddr_in client_addr;
    char msg[msg_size];
    int ret;

    initialization(client_addr,client_fd);
    switch(argc)
    {
        case 2:
        {
            client_addr.sin_port=htons(atoi(argv[1]));
            client_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        }break;
        case 3:
        {
            client_addr.sin_port=htons(atoi(argv[1]));
            client_addr.sin_addr.s_addr=inet_addr(argv[2]);
        }break;
        default:
        {
            client_addr.sin_port=htons(4396);
            client_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        }
    }

    ret=connect(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr));
    assert(ret==0);
    cout<<"<***Connection_Successful***>"<<endl;
    while(1)
    {   
        memset(msg,0,sizeof(msg));
        fgets(msg,sizeof(msg),stdin);
        if(strcmp(msg,"quit\n")==0)
            break;
        write(client_fd,msg,strlen(msg));
        memset(msg,0,sizeof(msg));
        read(client_fd,msg,sizeof(msg));

        fputs(msg,stdout);
    }

    close(client_fd);
}