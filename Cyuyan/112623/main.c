#include <stdio.h>
#include <stdlib.h>

struct
{
    int num[20];      //ѧ��
    char name[20];     //����
    int score[20];    //�ɼ�
}s1;



int main()
{
    int i;
    printf("������ѧ�� ���� �ɼ���");
    for(i = 0; i < 2 ; i++)
    {
        scanf("%d,%s,%d",&s1.num[i],&s1.name[i],&s1.score[i]);

    }
    printf("ѧ��   ����    �ɼ�\n");
     for(i = 0; i < 2 ; i++)
    {

        printf("%d   %s    %d",s1.num[i],s1.name[i],s1.score[i]);

    }

    return 0;
}
