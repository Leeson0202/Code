#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Max 100
typedef struct /*����ջ�Ľṹ*/
{
    int data[Max];
    int top;
} SeqStack;


int main()
{
    int x,i;
    printf("\n\t��ӭʹ���������ʽϵͳ");
    printf("\n\t1.�������ʽ��ֵ    2.�˳�ϵͳ");
    printf("\n\t ��ѡ��");
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
            printf("\n\t�˳���");
            printf("\n\t��ӭ�´�ʹ��");
            exit(0);
        default:
        {
            printf("\n\t�������");
            getchar();
            main();
        }
        }
    }
}

SeqStack *Init_SeqSeqStack()       //ջ��ʼ��
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

int empty_SeqStack(SeqStack *s)      //�ж��Ƿ�Ϊ��ջ
{
    if (s->top ==-1)
        return 1;
    else
        return 0;
}

int Push_SeqStack (SeqStack *s,int x)
{

}





















