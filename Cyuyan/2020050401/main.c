#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxsize 50

/* 顺序栈结构 */
typedef struct
{
    char data[maxsize];
    int top; /* 用于栈顶指针 */
} sstack;

int Pushstack( sstack **p,char c); //入栈操作
char bijiao(char e,char c);      //比较字符
int getindex(char c);            //获取字符数码下标
char Popstack( sstack **p);       //出栈操作

int initStack( sstack *p)  //初始化栈
{
    p->top = -1;
    if(p->top == -1) return 1;

    return 0;
}

int setstack(sstack *p) //opter底层元素设为‘#’
{
    if(p->top != -1) return 0;
    p->top++;
    p->data[p->top] = '#';
    return 1;
}

int getsop(char op[maxsize])  // 输入表达式
{


    printf("\n请输入算式(以#结束)："); //输入表达式
    gets(op);
    return 1;


}
char apart(char op[maxsize],sstack *opnd,sstack *opter)
      //拆分表达式 放入oped 和Opter两个栈 并计算结果
{
    int i;
    char c,f;
    char ch1,ch2;
    for(i = 0; i<strlen(op); i++) //依次读取数组内容
    {
        c = op[i];
        if(c >='0' && c<='9')
        {
            c = op[i];
            if(Pushstack(&opnd,c) == 0)
            {
                printf("\n进栈失败");
                exit(0);
            }
        }
        else
        {
            f = bijiao(opter->data[opter->top],c);

            if(f =='<')
            {
                if(Pushstack(&opter,c) == 0)
                {
                    printf("\n进栈失败");
                    exit(0);
                }
            }
            else if(f =='=')
            {
                Popstack(&opter);
            }
            else if(f =='>')
            {
                ch1 = Popstack(&opnd);
                ch2 = Popstack(&opnd);
                if(Pushstack(&opnd,ch1+ch2) == 0)
                    printf("\n进栈失败");

            }
            else if(c == '#')
               return Popstack(&opnd);
            else
            {
                printf("\n输入错误！");
                system("cls");
                exit(0);
            }
        }
    }
    return Popstack(&opnd);

}

int Pushstack( sstack **p,char c)  //进栈操作
{
    (*p)->top++;
    (*p)->data[(*p)->top]=c;
    if((*p)->data[(*p)->top]== NULL) return 0;
    return 1;
}
char Popstack( sstack **p)
      //出栈操作 获取顶部元素
{
    char ch;
    ch = (*p)->data[(*p)->top];
    (*p)->top--;
    return ch;
}

char bijiao(char e,char c)
  //比较字符的优先级
{
    char priority[8][7]=
    {
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='},
        {'!','!','!','!','!','!','!'} //输入错误返回'!'
    };
    int index1 =getindex(e);
    int index2 =getindex(c);
    return priority[index1][index2];

}

int getindex(char c) //获取优先级对应的数码
{
    int index =0;
    switch(c)
    {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        index = 3;
        break;
    case '(':
        index = 4;
        break;
    case ')':
        index = 5;
        break;
    case '#':
        index = 6;
        break;
    default:
        index = 7;
        break;
    }
    return index;
}

int main()
{
    char num;//最后结果
    sstack opter,opnd;  //定义两个空栈
    char op[maxsize];//c用来存元素，op用来存表达式
    if(initStack(&opter)== 0||initStack(&opnd)== 0)    //创建栈
    {
        printf("\n创建失败！");
        return 0;
    }
    if(setstack(&opter) == 0)  //将opter的栈底设为‘#’
    {
        printf("\n设置栈底元素失败");
        return 0;
    }
    printf("初始化完成\n");
    system("pause");
    system("cls");           //清屏

    getsop(op);     //获取算术表达式
    puts(op);
    num = apart(op,&opnd,&opter);  //拆分并获取最后结果
    printf("%c",num);
    return 0;
}
