#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxsize 50

/* ˳��ջ�ṹ */
typedef struct
{
    char data[maxsize];
    int top; /* ����ջ��ָ�� */
} sstack;

int Pushstack( sstack **p,char c); //��ջ����
char bijiao(char e,char c);      //�Ƚ��ַ�
int getindex(char c);            //��ȡ�ַ������±�
char Popstack( sstack **p);       //��ջ����

int initStack( sstack *p)  //��ʼ��ջ
{
    p->top = -1;
    if(p->top == -1) return 1;

    return 0;
}

int setstack(sstack *p) //opter�ײ�Ԫ����Ϊ��#��
{
    if(p->top != -1) return 0;
    p->top++;
    p->data[p->top] = '#';
    return 1;
}

int getsop(char op[maxsize])  // ������ʽ
{


    printf("\n��������ʽ(��#����)��"); //������ʽ
    gets(op);
    return 1;


}
char apart(char op[maxsize],sstack *opnd,sstack *opter)
      //��ֱ��ʽ ����oped ��Opter����ջ ��������
{
    int i;
    char c,f;
    char ch1,ch2;
    for(i = 0; i<strlen(op); i++) //���ζ�ȡ��������
    {
        c = op[i];
        if(c >='0' && c<='9')
        {
            c = op[i];
            if(Pushstack(&opnd,c) == 0)
            {
                printf("\n��ջʧ��");
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
                    printf("\n��ջʧ��");
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
                    printf("\n��ջʧ��");

            }
            else if(c == '#')
               return Popstack(&opnd);
            else
            {
                printf("\n�������");
                system("cls");
                exit(0);
            }
        }
    }
    return Popstack(&opnd);

}

int Pushstack( sstack **p,char c)  //��ջ����
{
    (*p)->top++;
    (*p)->data[(*p)->top]=c;
    if((*p)->data[(*p)->top]== NULL) return 0;
    return 1;
}
char Popstack( sstack **p)
      //��ջ���� ��ȡ����Ԫ��
{
    char ch;
    ch = (*p)->data[(*p)->top];
    (*p)->top--;
    return ch;
}

char bijiao(char e,char c)
  //�Ƚ��ַ������ȼ�
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
        {'!','!','!','!','!','!','!'} //������󷵻�'!'
    };
    int index1 =getindex(e);
    int index2 =getindex(c);
    return priority[index1][index2];

}

int getindex(char c) //��ȡ���ȼ���Ӧ������
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
    char num;//�����
    sstack opter,opnd;  //����������ջ
    char op[maxsize];//c������Ԫ�أ�op��������ʽ
    if(initStack(&opter)== 0||initStack(&opnd)== 0)    //����ջ
    {
        printf("\n����ʧ�ܣ�");
        return 0;
    }
    if(setstack(&opter) == 0)  //��opter��ջ����Ϊ��#��
    {
        printf("\n����ջ��Ԫ��ʧ��");
        return 0;
    }
    printf("��ʼ�����\n");
    system("pause");
    system("cls");           //����

    getsop(op);     //��ȡ�������ʽ
    puts(op);
    num = apart(op,&opnd,&opter);  //��ֲ���ȡ�����
    printf("%c",num);
    return 0;
}
