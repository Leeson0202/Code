#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

typedef struct                       //����ջ�Ľṹ
{
    int data[MAX];
    int top;
} SeqStack;


void suanshi();                      //���� ����

//---------------------------------------------------------������
int main()
{

    system("cls");
    int i;
    char x;
    printf("\n\t      ----��ӭʹ���������ʽϵͳ----\n");
    printf("\n\t      1.�������ʽ��ֵ    2.�˳�ϵͳ\n");
    printf("\n\t ��ѡ��");
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
            printf("\n\t      ------------�˳���------------\n");
            printf("\n\t      ---------��ӭ�´�ʹ��---------\n");
            printf("\n\n\n\n\n");
            exit(0);
        default:
        {
            printf("\n\n\t   �������");
            getchar();
            main();
        }
        }
    }
}

//-----------------------------------------------------------ջ��ʼ��
SeqStack *Init_SeqStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

//-----------------------------------------------------------�ж��Ƿ�Ϊ��ջ
int Empty_SeqStack(SeqStack *s)
{
    if (s->top ==-1)
        return 1;
    else
        return 0;
}

//----------------------------------------------------------��ջ
int Push_SeqStack (SeqStack *s,int x)
{
    if(s->top == MAX-1)
        return 0;         //ջ��������ջ
    else
    {
        s->top++;
        s->data[s->top]=x;
        return 1;
    }
}

//------------------------------------------------------------��ջ
int Pop_SeqStack(SeqStack *s, int *x)
{
    if(Empty_SeqStack(s))               //ջ�ղ��ܳ�ջ
        return 0;
    else
    {
        *x = s->data[s->top];
        s->top--;
        return 1;                      //ջ��Ԫ�ش���*x������
    }

}

//-------------------------------------------------------------ȡջ��Ԫ��
int Top_SeqStack(SeqStack *s)
{
    if(Empty_SeqStack(s))
        return 0;        //ջ��
    else
        return(s->data[s->top]);
}

//---------------------------------------------------------��������������ʽ
void suanshi()
{
    system("cls");
    char choice,a1[MAX],*p;
    printf("\n\t��������ʽ����=��������\n\n\t\t");
    scanf("%s",a1);
    SeqStack *num,*shufu;
    p = a1;
    char c = *p++;
    int sum, result, a = 0, b,d,e1 = 0,e2, f, x, y, z[MAX]= {0}, i= 1;
    num = Init_SeqStack();                            //����ջ
    shufu = Init_SeqStack();                          //���ջ
    while(c)
    {
        if(c>='0'&&c<='9')
            a = a*10+c-'0';                           //���ַ�������ת��Ϊ��ֵ
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
            if(x != 5&& z[i-1] == 0)                  //����ֵ�����ջ
            {
                Push_SeqStack(num,a);
                a = 0;
            }
            i++;
            if(Empty_SeqStack(shufu)||e1<f)           //�����ֲ������ջ
            {
                Push_SeqStack(shufu,x);
                e1 = e2;                              //�޸����ȼ�
            }
            else
            {
                while(e1>=f)
                {
                    Pop_SeqStack(shufu,&y);        //ȡ���������ݺ�һ�������
                    Pop_SeqStack(num,&b);
                    Pop_SeqStack(num,&d);
                    switch(y)                      //�ж�Ϊ�����������������
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
                    Push_SeqStack(num,sum);           //�м��������ջ
                    if(Empty_SeqStack(shufu))
                        break;
                    else
                    {
                        y=Top_SeqStack(shufu);
                        if(x==6&&y==5)                //�������"��"��"��"
                        {
                            Pop_SeqStack(shufu,&z[i++]);
                            break;
                        }
                        else
                        {
                            switch(y)                //�޸����ȼ�
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
                if(x != 6&&x!=0)                      //���û������")"
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
    Pop_SeqStack(num,&result);                        //�����ս����ջ
    printf("���Ϊ��%d\n",result);                    //����Ļ����ʾ���ս��
    getchar();
    printf("�Ƿ��˳�����(y/Y):");
    if(getch() == 'y'||getch() == 'Y')
        main();
        else
            suanshi();
}

