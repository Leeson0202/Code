#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Max 100
typedef struct /*定义栈的结构*/
{
    int data[Max];
    int top;
} SeqStack;


int main()
{
    int x,i;
    printf("\n\t欢迎使用算术表达式系统");
    printf("\n\t1.算术表达式求值    2.退出系统");
    printf("\n\t 请选择：");
    scanf("%d",&x);
    printf("\n\t ");
    for(i = 0;; i++)
    {
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            suanshi();
            break;
        case 2:
            printf("\n\t退出中");
            printf("\n\t欢迎下次使用");
            exit(0);
        default:
        {
            printf("\n\t输入错误！");
            getchar();
            main();
        }
        }
    }
}

SeqStack *Init_SeqSeqStack()       //栈初始化
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

int empty_SeqStack(SeqStack *s)      //判断是否为空栈
{
    if (s->top ==-1)
        return 1;
    else
        return 0;
}

int Push_SeqStack (SeqStack *s,int x)
{

}





















