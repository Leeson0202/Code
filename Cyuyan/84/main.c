
#include <stdio.h> /*���ļ�����printf()�Ⱥ���*/
#include <stdlib.h>/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType; /*����DataTypeΪint*/

typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head) /*��ʼ��*/
{
    /*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
    if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    (*head)->next = NULL; /*����β���NULL */
}

int ListLength(SLNode *head) /* ������ĳ���*/
{
    SLNode *p = head; /*pָ����Ԫ���*/
    int size = 0;     /*size��ʼΪ0*/

    while (p->next != NULL) /*ѭ������*/
    {
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
    SLNode *p, *q;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/
    while (p->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("����λ�ò�����");
        return 0;
    }

    /*�����½����ָ��qָʾ*/
    if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    q->data = x;

    //�˶γ�����һ������
    q->next = p->next; /*��ָ��q->next��ֵ*/
    p->next = q;       /*��ָ��p->next���¸�ֵ*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/
    while (p->next != NULL && p->next->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("ɾ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    s = p->next;       /*ָ��sָ������Ԫ��ai���*/
    *x = s->data;      /*��ָ��s��ָ��������Ԫ����ֵ����x*/
    p->next = s->next; /*������Ԫ��ai���ӵ�������ɾ��*/
    free(s);           /*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("ȡԪ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    *x = p->data;
    return 1;
}

void Destroy(SLNode **head)
{
    SLNode *p, *p1;

    p = *head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}

SLNode *Link(SLNode *a, SLNode *b)
{
    SLNode *r = NULL, *pa = a->next, *pb = b->next;
    a->next = NULL; //��ʼ�� Ϊ��
    while (pa && pb)
        if (pa->data <= pb->data)
        {
            r = pa->next;       // 1 r = pa+1
            pa->next = a->next; // 2 pa+1 = a+1 = null
            a->next = pa;       // 3 a+1 = pa
            pa = r;             // 4 pa = r
        }
        else
        {
            r = pb->next;
            pb->next = a->next;
            a->next = pb;
            pb = r;
        }
    if (pa)
        pb = pa;
    while (pb)
    {
        r = pb->next;
        pb->next = a->next;
        a->next = pb;
        pb = r;
    }
    free(pb);
}

int sort(SLNode *a)
{
    SLNode *pa = a;

    return 1;
}

void main(void)
{
    SLNode *head1, *head2;
    int i, x, j;
    ListInitiate(&head1);
    ListInitiate(&head2); /*��ʼ��*/

    for (i = 0; i < 10; i++)
    {
        if (ListInsert(head1, i, i+1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }
    for (i = 0 ; i < 5; i++)
    {
        if (ListInsert(head2, i, i+1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }

    if (ListDelete(head1, 4, &x) == 0) /*ɾ������Ԫ��5*/
    {
        printf("����! \n");
        return;
    }
    printf("ɾ����");
    for (i = 0; i < ListLength(head1); i++)
    {

        if (ListGet(head1, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return;
        }
        else
            printf("%d ", x); /*��ʾ����Ԫ��*/
    }


    Link(head1, head2);
    printf("\n���ӣ�");
    for (i  = 0; i < ListLength(head1); i++)
    {

        if (ListGet(head1, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return;
        }
        else
            printf("%d ", x); /*��ʾ����Ԫ��*/
    }

    Destroy(&head1);
    Destroy(&head2);
}
