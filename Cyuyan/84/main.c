#include <stdio.h>
#define MaxSize  100
typedef int DataType;
typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)   /*��ʼ��˳���L*/
{
    L->size = 0;                    /*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx   ����ɹ�����1������ʧ�ܷ���0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("˳��������޷�����! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        for(j = L->size; j < i; j--)
            L->list[j+1] = L->list[j];/*Ϊ������׼��*/

        L->list[i] = x;/*����*/
        L->size ++;/*Ԫ�ظ�����1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("����i���Ϸ�");
        return 0;
    }
    else
    {
        *x = L->list[i-1];/*����ɾ����Ԫ�ص�����x��*/
        for(j = i ; j <= L->size-1; j++)
            L->list[j-1] = L->list[j];/*����ǰ��*/
        L->size--;/*����Ԫ�ظ�����1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}

void Listlianjie(SeqList *L1,SeqList *L2)     //�� List 2 ���뵽 List 1 ��
{
    int j = 0;
    while(L1->size < MaxSize && j < L2->size)
    {
        L1->list[L1->size] = L2->list[j];
       j++;
       L1->size++;
    };
    return;
}

void main(void)
{
    SeqList myList1;
    SeqList myList2;
    int i, x;
    ListInitiate(&myList1);  //��ʼ�� List 1
    ListInitiate(&myList2);  //��ʼ�� List 2
    for(i = 0; i < 10; i++)            //�� List 1 �в���1-10
        ListInsert(&myList1, i, i+1);
    for(i = 0; i < 10; i++)            //�� List 1 �в���11-20
        ListInsert(&myList2, i, i+11);
    ListDelete(&myList1, 5, &x);           //ɾ�� List 1 �е�Ԫ��5
    printf("List 1 : ");
    for(i = 0; i < ListLength(myList1); i++)   //��ӡ List 1
    {
        ListGet(myList1,i,&x);
        printf("%d ", x);
    }
    printf("\nList 2 : ");
    for(i = 0; i < ListLength(myList2); i++)   //��ӡ List 2
    {
        ListGet(myList2,i,&x);
        printf("%d ", x);
    }
    printf("\n");
    printf("\n��List 2 ���� List 1 ��\n");     //�� List 2 ���뵽 List 1 ��
    Listlianjie(&myList1,&myList2);
    printf("List 1 : ");
    for(i = 0; i < ListLength(myList1); i++)   //��ӡ List 1
    {
        ListGet(myList1,i,&x);
        printf("%d ", x);
    }
    printf("\n\n");
}
