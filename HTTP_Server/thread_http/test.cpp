#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<pthread.h>
#include<fcntl.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

pthread_t pid;
pthread_mutex_t lock;
long long thread_num=0; 

void* thread_check_msg(void* arg);
void send_resource(char *path,int client_fd);
void debug(int client_fd,int line,string msg);

int main(int argc,char* argv[])
{
    struct sockaddr_in server_addr,client_addr;
    pthread_mutex_init(&lock,NULL);
    int server_fd,client_fd;
    socklen_t client_sz;
    int ret=0;
    //client_fds.reserve(10);

    memset(&server_addr,0,sizeof(server_addr));
    server_fd=socket(AF_INET,SOCK_STREAM|SOCK_NONBLOCK,0);
    server_addr.sin_family=AF_INET;
    argc==1?server_addr.sin_port=htons(80):server_addr.sin_port=htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    int opt=1;
    setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    ret=bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr));assert(ret==0);
    ret=listen(server_fd,100);assert(ret==0);
    long long connect_num=0;
    long long connect_sum=0; 
    while(1)
    {
        client_fd=accept(server_fd,(struct sockaddr*)&client_addr,&client_sz);
       	if(client_fd<=0)
        {   
            continue;
        }
        printf("client_fd:%d\n",client_fd);
        pthread_mutex_lock(&lock);
        thread_num++;
        printf("[create_thread:%lld]\n",thread_num);
        pthread_mutex_unlock(&lock);
        int *fd=new int;
        *fd=client_fd;
	    cout<<"connect_sum:"<<++connect_sum<<endl;
       	pthread_create(&pid,NULL,thread_check_msg,fd);
        pthread_detach(pid);
    }
        cout<<"anything is die"<<endl;
    close(server_fd);
}
void* thread_check_msg(void* arg)
{
    int client_fd=*(int*)arg;
    delete(arg);
    int ret=0;
    char msg[4396];
    char *path=new char[1024];
    memset(msg,0,sizeof(msg));
    //debug(client_fd,__LINE__,"");
       // sleep(1);
    ret=read(client_fd,msg,sizeof(msg));
    if(ret<=0)
    {   
        delete[] path;
        pthread_mutex_lock(&lock);
	    thread_num--;
        debug(client_fd,__LINE__,"Read msg is NULL");
        close(client_fd);
        pthread_mutex_unlock(&lock);

        return NULL;
    }
    //sleep(1);

    sscanf(msg,"%[^\n]",msg);
    strcpy(path,strstr(msg,"/"));
    sscanf(path,"%[^ ]",path);
    debug(client_fd,__LINE__,path);
    send_resource(path,client_fd);

    pthread_mutex_lock(&lock);
    close(client_fd);
    thread_num--;
    pthread_mutex_unlock(&lock);
    delete[] path;
    //free(arg);
    printf("\n");
    return NULL;

}
void send_resource(char *path,int client_fd)
{
    FILE *fp=NULL;
    char path_[]="src";
    char send_[1024*1024*2];
    long long len;
    strcat(path_,path);
    strcpy(path,path_);
    //debug(client_fd,__LINE__,path);//show url path
    if(strcmp(path,"src/")==0)
    {   
        fp=fopen("src/index.html","rb");
        if(fp==NULL)
        {   
            debug(client_fd,__LINE__,"open html error!");
            return ;
        }
        strcpy(path,"HTTP/1.0 200 ok\n\n");
        write(client_fd,path,strlen(path));
        fseek(fp,0,SEEK_END);
        len=ftell(fp);
        fseek(fp,0,SEEK_SET);
        fread(send_,1,len,fp);
        write(client_fd,send_,strlen(send_));
    }
    else
    {   

        fp=fopen(path,"rb");
        if(fp==NULL)
        {
            printf("[%d]:path url not found!\n",__LINE__);
            return ;
        }
        fseek(fp,0,SEEK_END);
        len=ftell(fp);
        //printf("[%d][%d][%ld]:%lld\n",__LINE__,client_fd,pthread_self(),len);show len of path file
        fseek(fp,0,SEEK_SET);
        char *p_bufs = new char[len+1024];
        char *type=strrchr(path,'.');
        memset(send_,0,sizeof(send_));
        fread(send_,1,len,fp);
        if(strcmp(type,".css")==0)strcpy(type,"text/css");
        if(strcmp(type,".js")==0)strcpy(type,"application/x-javascript");
        if(strcmp(type,".png")==0)strcpy(type,"image/png");
        if(strcmp(type,".jpg")==0)strcpy(type,"image/jpeg");
	if(strcmp(type,".gif")==0)strcpy(type,"image/gif");

        int tlen = sprintf(p_bufs,
                        "HTTP/1.1 200 OK\r\n"
                            "Server: hsoap/2.8\r\n"
                            "Content-Type: %s\r\n"
                            "Content-Length: %lld\r\n"
                            "Connection: close\r\n\r\n",type,len);
        memcpy(p_bufs+tlen, send_, len);
        tlen += len;
        delete[] p_bufs;
        //delete[] type;
        send(client_fd, p_bufs, tlen, 0);
    }    
    //debug(client_fd,__LINE__,"over"); send msg over
    if(fp!=NULL)
        fclose(fp);
}
void debug(int client_fd,int line,string msg)
{   
    printf("[%d][%ld][%d]:%s\n",line,pthread_self(),client_fd,msg.c_str());
}
