#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

typedef struct                       //定义栈的结构
{
    int data[MAX];
    int top;
} SeqStack;


void suanshi();                      //算数 函数

//---------------------------------------------------------主函数
int main()
{

    system("cls");
    int i;
    char x;
    printf("\n\t      ----欢迎使用算术表达式系统----\n");
    printf("\n\t      1.算术表达式求值    2.退出系统\n");
    printf("\n\t 请选择：");
    for(i = 0;; i++)
    {
        x = getch();
        switch(x)
        {
        case '1':
            suanshi();
            break;
        case '2':
            system("cls");
            printf("\n\n\n\n");
            printf("\n\t      ------------退出中------------\n");
            printf("\n\t      ---------欢迎下次使用---------\n");
            printf("\n\n\n\n\n");
            exit(0);
        default:
        {
            printf("\n\n\t   输入错误！");
            getchar();
            main();
        }
        }
    }
}

//-----------------------------------------------------------栈初始化
SeqStack *Init_SeqStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

//-----------------------------------------------------------判断是否为空栈
int Empty_SeqStack(SeqStack *s)
{
    if (s->top ==-1)
        return 1;
    else
        return 0;
}

//----------------------------------------------------------入栈
int Push_SeqStack (SeqStack *s,int x)
{
    if(s->top == MAX-1)
        return 0;         //栈满不能入栈
    else
    {
        s->top++;
        s->data[s->top]=x;
        return 1;
    }
}

//------------------------------------------------------------出栈
int Pop_SeqStack(SeqStack *s, int *x)
{
    if(Empty_SeqStack(s))               //栈空不能出栈
        return 0;
    else
    {
        *x = s->data[s->top];
        s->top--;
        return 1;                      //栈顶元素存入*x，返回
    }

}

//-------------------------------------------------------------取栈顶元素
int Top_SeqStack(SeqStack *s)
{
    if(Empty_SeqStack(s))
        return 0;        //栈空
    else
        return(s->data[s->top]);
}

//---------------------------------------------------------计算四则运算表达式
void suanshi()
{
    system("cls");
    char choice,a1[MAX],*p;
    printf("\n\t请输入算式（以=结束）：\n\n\t\t");
    scanf("%s",a1);
    SeqStack *num,*shufu;
    p = a1;
    char c = *p++;
    int sum, result, a = 0, b,d,e1 = 0,e2, f, x, y, z[MAX]= {0}, i= 1;
    num = Init_SeqStack();                            //对象栈
    shufu = Init_SeqStack();                          //算符栈
    while(c)
    {
        if(c>='0'&&c<='9')
            a = a*10+c-'0';                           //将字符串数字转化为数值
        else
        {
            switch(c)
            {
            case '=':
                x = 0;
                e2 = -1;
                f = -1;
                break;
            case '+':
                x = 1;
                e2 =  1;
                f =  1;
                break;
            case '-':
                x = 2;
                e2 =  1;
                f =  1;
                break;
            case '*':
                x = 3;
                e2 =  2;
                f =  2;
                break;
            case '/':
                x = 4;
                e2 =  2;
                f =  2;
                break;
            case '(':
                x = 5;
                e2 =  0;
                f =  4;
                break;
            case ')':
                x = 6;
                e2 = -1;
                f = -1;
                break;
            }
            if(x != 5&& z[i-1] == 0)                  //将数值入对象栈
            {
                Push_SeqStack(num,a);
                a = 0;
            }
            i++;
            if(Empty_SeqStack(shufu)||e1<f)           //将算符植入算数栈
            {
                Push_SeqStack(shufu,x);
                e1 = e2;                              //修改优先级
            }
            else
            {
                while(e1>=f)
                {
                    Pop_SeqStack(shufu,&y);        //取出两个数据和一个运算符
                    Pop_SeqStack(num,&b);
                    Pop_SeqStack(num,&d);
                    switch(y)                      //判断为何种运算符并做计算
                    {
                    case 1:
                        sum=b+d;
                        break;
                    case 2:
                        sum=d-b;
                        break;
                    case 3:
                        sum=d*b;
                        break;
                    case 4:
                        sum=d/b;
                        break;
                    case 5:
                        Pop_SeqStack(shufu,&z[i++]);
                        break;
                    }
                    Push_SeqStack(num,sum);           //中间结果入对象栈
                    if(Empty_SeqStack(shufu))
                        break;
                    else
                    {
                        y=Top_SeqStack(shufu);
                        if(x==6&&y==5)                //如果遇到"）"和"（"
                        {
                            Pop_SeqStack(shufu,&z[i++]);
                            break;
                        }
                        else
                        {
                            switch(y)                //修改优先级
                            {
                            case 1:
                            case 2:
                                break;
                            case 3:
                            case 4:
                                break;
                            case 5:
                                e2 = 0;
                                break;
                            }
                            e1 = e2;
                        }
                    }
                }
                if(x != 6&&x!=0)                      //如果没有遇到")"
                {
                    Push_SeqStack(shufu,x);
                    switch(x)
                    {
                    case 1:
                    case 2:
                        e2 = 1;
                        break;
                    case 3:
                    case 4:
                        e2 = 2;
                        break;
                    case 5:
                        e2 = 0;
                        f = 4;
                        break;
                    }
                    e1 = e2;
                }
            }
        }
        c = *p++;
    }
    Pop_SeqStack(num,&result);                        //将最终结果出栈
    printf("结果为：%d\n",result);                    //在屏幕上显示最终结果
    getchar();
    printf("是否退出计算(y/Y):");
    if(getch() == 'y'||getch() == 'Y')
        main();
        else
            suanshi();
}

