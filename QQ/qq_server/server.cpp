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
#include<mysql.h>
#include<qq_database.h>
#include<take_string.h>
#include<map>
#include<set>

using namespace std;
#define msg_size 1024
map<int,string>onlines;
map<string,int>online;
void my_agreement(vector<string>&msg,qq_database &qq,int client);

void initialization_server(struct sockaddr_in& server_addr,int &server_fd,int argc,char *argv[])
{   

    server_fd=socket(PF_INET,SOCK_STREAM|SOCK_NONBLOCK,IPPROTO_TCP);
    server_addr.sin_family=AF_INET;
    switch(argc)
    {
        case 2:
        {
            server_addr.sin_port=htons(atoi(argv[1]));
            server_addr.sin_addr.s_addr=INADDR_ANY;
        }break;
        default:
        {
            server_addr.sin_port=htons(4397);
            server_addr.sin_addr.s_addr=INADDR_ANY;
        }
    }
}
void Error_msg(string msg)
{
    cout<<"Error_msg:"<<msg<<endl;
}
int main(int argc,char* argv[])
{   
    int idle_fd=open("/dev/null",O_RDONLY|O_CLOEXEC);
    qq_database qq;
    int server_fd,client_fd;
    struct sockaddr_in server_addr,client_addr;
    socklen_t client_sz;
    int ret=0;;
    char msg[msg_size];
    initialization_server(server_addr,server_fd,argc,argv);


    int optset=1;
    ret=setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,&optset,sizeof(optset));assert(ret==0);
    ret=bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr));assert(ret==0);
    ret=listen(server_fd,5);assert(ret==0);

    struct epoll_event event;
    vector<struct epoll_event>events(16);
    vector<int>client_fds;
    int epoll_fd;

    epoll_fd=epoll_create(5555);
    event.data.fd=server_fd;
    event.events=EPOLLIN;

    epoll_ctl(epoll_fd,EPOLL_CTL_ADD,server_fd,&event);

    while(1)
    {
        int event_cnt=epoll_wait(epoll_fd,&*events.begin(),static_cast<int>(events.size()),-1);
        
        if(event_cnt==-1)
        {
            if(errno==EINTR)
                continue;
            Error_msg("epoll_wait");
        }
        if(event_cnt==0)
            continue;
        if((size_t)event_cnt==events.size())
            events.resize(events.size()*2);
        for(int i=0;i<event_cnt;i++)
        {
            if(events[i].data.fd==server_fd)
            {
                client_sz=sizeof(client_sz);
                client_fd=accept4(server_fd,(struct sockaddr*)&client_addr,&client_sz,O_NONBLOCK);
                if(client_fd==-1)
                {
                    if(errno==EMFILE)
                    {
                        close(idle_fd);
                        idle_fd=accept(server_fd,NULL,NULL);
                        close(idle_fd);
                        idle_fd=open("/dev/null",O_RDONLY|O_NONBLOCK);
                        continue;
                    }
                    else
                    Error_msg("accept4?");
                }
                printf("[Client]<IP:%s><PT:%d><***CONNECT***>\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
                event.data.fd=client_fd;
                event.events=EPOLLIN|EPOLLET;
                epoll_ctl(epoll_fd,EPOLL_CTL_ADD,client_fd,&event);

                client_fds.push_back(client_fd);
            }
            else if(events[i].events&EPOLLIN)
            {
                client_fd=events[i].data.fd;
                if(client_fd<0)
                    continue;
                memset(msg,0,sizeof(msg));
                ret=read(client_fd,msg,sizeof(msg));
                if(ret<=0)
                {    
                    printf("[CLient]<FD:%d><***CLOSE***>\n",client_fd);
                    close(client_fd);
                    online[onlines[client_fd]]=0;
                    epoll_ctl(epoll_fd,EPOLL_CTL_DEL,client_fd,NULL);
                    client_fds.erase(remove(client_fds.begin(),client_fds.end(),client_fd),client_fds.end());
                    continue; 
                }
                sscanf(msg,"%[^\r\n]",msg);
                printf("[%d]%s\n",__LINE__,msg);
                vector<string>q(Split_string(msg));
                my_agreement(q,qq,client_fd);
                //write(client_fd,my_agreement(q,qq)?"1":"0",sizeof("1"));
                //printf("[%d]%s\n",__LINE__,msg);
        
            } 
        }
    }
    close(server_fd);
    close(epoll_fd);
    return 0;
     
}

void my_agreement(vector<string>&msg,qq_database &qq,int client_fd)
{
    string head=msg[0];
    if(head=="register")
    {
        write(client_fd,qq.qq_check_same_account(msg[1],msg[2])?"1":"0",sizeof("1"));
    }
    if(head=="name") 
    {   
        string name=qq.qq_name(msg[1]);
        write(client_fd,name.c_str(),sizeof(name.c_str()));
    }
    if(head=="login")
    {   if(online[msg[1]]!=0)
        {
            write(client_fd,"2",sizeof("2"));
        }
        else if(qq.qq_login(msg[1],msg[2]))
        {
            write(client_fd,"1",sizeof("1"));
            onlines[client_fd]=msg[1];
            online[msg[1]]=client_fd;
        }
        else   
            write(client_fd,"0",sizeof("0"));
    } 
    if(head=="add_pls")
    {
        write(client_fd,qq.qq_add_pls(msg[1],msg[2])?"1":"0",sizeof("1"));
    } 
    if(head=="add")
    {
        write(client_fd,qq.qq_add(msg[1],msg[2])?"1":"0",sizeof("1"));
    } 
    if(head=="rename")
    {
        write(client_fd,qq.qq_rename(msg[1],msg[2])?"1":"0",sizeof("1"));
    }
    if(head=="delete")  
    { 
        write(client_fd,qq.qq_delete(msg[1],msg[2])?"1":"0",sizeof("1"));
    } 
    if(head=="check")
    {
        write(client_fd,qq.qq_check_exist(msg[1])?"1":"0",sizeof("1"));
    }
    if(head=="friends")     
    { 
        vector<pair<string,string>>friends=qq.qq_friends(msg[1]);
        int x=friends.size();
        //cout<<x<<endl;
        write(client_fd,to_string(x).c_str(),strlen(to_string(x).c_str()));
        char msg_[128];
        for(int i=0;i<friends.size();i++)
        {   
            memset(msg_,0,sizeof(msg_));
            if(online[friends[i].first]!=0)
                sprintf(msg_,"%s %s 1 ",friends[i].second.c_str(),friends[i].first.c_str());
            else
                sprintf(msg_,"%s %s 0 ",friends[i].second.c_str(),friends[i].first.c_str());
            //printf("[%d]%s\n",__LINE__,msg_);
            write(client_fd,msg_,strlen(msg_));
        }  
    }
    if(head=="change")
    {
        write(client_fd,qq.qq_change_pw(msg[1],msg[2])?"1":"0",sizeof("1"));
    }
    if(head=="check_add")
    {
        vector<string>from=qq.qq_check_add_pls(msg[1]);
        int x=from.size();
        write(client_fd,to_string(x).c_str(),strlen(to_string(x).c_str()));
        //cout<<x<<endl;
        char msg_[128];
        for(int i=0;i<from.size();i++)
        {
            memset(msg_,0,sizeof(msg_));
            sprintf(msg_,"%s ",from[i].c_str());
            //printf("[%d]%s\n",__LINE__,msg_);
            write(client_fd,msg_,strlen(msg_));
        } 
    }  
    if(head=="agreen")
    {
        write(client_fd,qq.qq_agreen(msg[1],msg[2])?"1":"0",sizeof("1"));
    }
    if(head=="refuse") 
    {
        write(client_fd,qq.qq_refuse(msg[1],msg[2])?"1":"0",sizeof("1"));
    }
    if(head=="to")
    {        
        if(online[msg[1]]==0)
        {
            write(client_fd,"error",strlen("error"));
            return;
        }
        else
        {   
            char buf[1024];
            sprintf(buf,"from %s %s",onlines[client_fd].c_str(),msg[2].c_str());
            printf("[%d]%s\n",__LINE__,buf);
            write(online[msg[1]],buf,strlen(buf));
        }
    }
}   
 