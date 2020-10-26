#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define OVERFLOW -2
typedef struct{
	 int arrive;
     int treat;   //客户的信息结构
}QNODE;
typedef struct node{
     QNODE data;
     struct node *next;  //队列中的元素信息
}LNODE;
LNODE *front,*rear;    // 队头指针和队尾指针
QNODE curr,temp;
char Fname[120];     //读取文件的文件名
    FILE*fp;
void EnQueue(LNODE**hpt,LNODE**tpt,QNODE e){
	LNODE*p=(LNODE*)malloc(sizeof(LNODE));
	if(!p)exit(OVERFLOW);
	p->data=e;//---------------------(1)
    p->next=NULL; //-----------------(2)
	if(*hpt==NULL)*tpt=*hpt=p;
	 else *tpt=(*tpt)->next=p;
}
int DeQueue(LNODE**hpt,LNODE**tpt,QNODE*cp){
	LNODE*p=*hpt;
	if(*hpt==NULL)return 1;
	*cp=p->data;//------------------------(3)
    *hpt=(*hpt)->next;//-----------------(4)
	if(*hpt==NULL)*tpt=NULL;
	free(p);
	return 0;
}
int main()
{
int dwait=0,clock=0,wait=0,count=0,have=0,finish;
printf("Enter name for file:");
scanf("%s",Fname);  /*输入装客户模拟数据的文件的文件名*/
if((fp=fopen(Fname,"r"))==NULL)//------------------(5)
    {
        printf("wrong!");
         return 0;
    }
have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
front=NULL;rear=NULL;
do{  /*约定每轮循环，处理一位客户*/
	if(front==NULL&&have==2){  /*等待队列为空，但还有客户*/
	dwait+=temp.arrive-clock;   /*累计业务员总等待时间*/
	clock=temp.arrive;         /*时钟推进到暂存变量中的客户的到达时间*/
	EnQueue(&front,&rear,temp);  /* 暂存变量中的客户信息进队*/
have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
}
count++;   /*累计客户人数*/
DeQueue(&front,&rear,&curr);    /*出队一位客户信息*/
wait+=clock-curr.arrive;         /*累计到客户的总等待时间*/
finish=clock+curr.treat;          /*设定业务办理结束时间*/
while(have==2&&temp.arrive<=finish){
/*下一位客户的到达时间在当前客户处理结束之前*/
	EnQueue(&front,&rear,temp);   /*暂存变量中的客户信息进队*/
have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
}
clock=finish;   /*时钟推进到当前客户办理结束时间*/
}while(have==2||front!=NULL);
printf("Operator waiting time:%d,Average waiting time of customers：%f\n",dwait,(double)wait/count);
printf("Total simulation time: %d\nNumber of customers: %d\nTotal waiting time: %d\n",clock,count,wait);
getch();
}
