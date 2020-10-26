#include <Winsock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <pthread.h>


void Receive();
void Send();
void creatThread();

SOCKET s =NULL;
pthread_t t[1000];
int threadCount=0;

void main(int argc,char* argv[])
{
    printf("本程序制作人学号：713901040041\n");
    printf("程序说明：服务器端和客户端为同一个程序，请使用不同的参数运行.\n");
    printf("接收程序请使用 r参数；发送程序请使用 s参数。\n");
    //printf("len : %d\n", argc);
    //printf("count %d\n",argc);
    //printf("value: %s\n",argv[1]);
    //printf("%d",argv[1][0]=='r');

    if(argc<=1)
    {
        printf("please input program arguments ...\n");
        exit(0);
    }
    if(argc>1 && argv[1][0]=='r')
    {
        printf("run receive ...\n");
        Receive();
    }
    if(argc>1 && argv[1][0]=='s')
    {
        printf("run send ...\n");
        Send();
    }
}


void* receiveWork(void * args)
{
    SOCKET sc=accept(s,0,0);
    if(sc==INVALID_SOCKET)
    {
        printf("sc Error");
    }
    creatThread();

    printf("----------客户端已经连接到本机的%d线程连接！\n",threadCount-2);
#define BUF_SIZE 4096
    int receByt=0;
    while(1)
    {
        char buf[BUF_SIZE];
        receByt=recv(sc,buf,BUF_SIZE,0);
        buf[receByt]='\0';
        if(receByt>0)
        {
            printf("线程接收的消息是：%s\n",buf);
        }
        else
        {
            printf("客户端已退出，");
            break;
        }

    }
    int ic=closesocket(sc);
    printf("服务器结束连接！\n");
    return NULL;
}

void creatThread()
{
    pthread_create(&t[threadCount++],NULL,receiveWork,NULL);
}


void Receive()
{
    WSAData wsd;
    WSAStartup(MAKEWORD(2,0),&wsd);
    s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(s==INVALID_SOCKET)
    {
        printf("socket created Error");
    }
    struct sockaddr_in ch;
    memset(&ch,0,sizeof(ch));
    ch.sin_family=AF_INET;
    ch.sin_addr.s_addr=INADDR_ANY;
    ch.sin_port=htons(1041);
    int b=bind(s,(struct sockaddr *) &ch,sizeof(ch));
    if(b==SOCKET_ERROR)
    {
        printf("bind 失败，出错代码是：%d\n",WSAGetLastError());
        exit(0);
    }
#define QUEUE_SIZE 5
    int l=listen(s,QUEUE_SIZE);
    printf("正在监听本机的1041端口！\n");

    creatThread();

    for(int i=0; i<1000; i++)
    {
        pthread_join(t[i],NULL);
    }

    int is=closesocket(s);
}



void Send()
{
    WSAData wsd;
    WSAStartup(MAKEWORD(2,0),&wsd);

    SOCKET s =NULL;
    s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(s==INVALID_SOCKET)
    {
        printf("socket created Error");
    }
    struct sockaddr_in ch;
    memset(&ch,0,sizeof(ch));
    ch.sin_family=AF_INET;
    ch.sin_addr.s_addr=inet_addr("127.0.0.1");
    ch.sin_port=htons(1041);

    int c=connect(s,(struct sockaddr *) &ch,sizeof(ch));
    printf("已经连接到服务器的1041端口！现在可以向服务器发送消息了！\n");
#define BUF_SIZE 4096
    char info[1024],buf[BUF_SIZE];

    while(1)
    {
        gets(info);
        if(info[0]=='\0')
            break;
        strcpy(buf,info);
        int nsend=send(s,buf,strlen(buf),0);
    }
    int ic=closesocket(s);
}
