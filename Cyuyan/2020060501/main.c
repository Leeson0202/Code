/*
һά����ʵ���⣺�����ֳ�ͳ�֡���֪ĳ������n��ѡ�ֲ�����
m��m>2������ίΪ����ѡ�����֣����10�֣����0�֣���
ͳ�ֹ���Ϊ����ÿ��ѡ�ֵ�m���÷��У�ȥ��һ����߷ֺ�һ����ͷֺ�
ȡƽ������Ϊ��ѡ�ֵ����÷֡�Ҫ����ʵ�֣�
��1������n��ѡ�ֵ����÷֣��Ӹߵ������ѡ�ֵĵ÷����α���ȷ����������
��2�����ݸ�ѡ�ֵ����÷������ί����ѡ�����������Ĳ�࣬
��ÿ����ί���ֵ�׼ȷ�Ժ�����ˮ׼����һ�����������ۣ�
ÿλ��ί�����ַ�����(10 -(��ί��ѡ��x������ - x�ĵ÷�)^2 ���ۼӺ�)��
�Ӹߵ����������ί�÷ֵ����α�
������ʾ��
    printf("How many Athletes?");
    scanf("%d", &n);                                /* ����ѡ������ */
//   printf("How many judges?");
//    scanf("%d", &m);                              /* ������ί���� */
//
  //  printf("Order of Athletes:\n");          /* ѡ�ֵ÷����� */
    //printf("Order of judges:\n");            /* ��ί�÷����� */

// �������ܣ�ͳ�Ʋ���ѡ�ֵĵ÷�
//void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m)
//    printf("\nAthlete %d is playing.", i);
//    printf("\nPlease enter his number code:");
//    scanf("%d", &sh[i]);

 for (j = 1; j <= m; j++)              /* ��j����ί */
        {
            printf("Judge %d gives score:", j);

        printf("Delete a maximum score:%.1f\n", max);
        printf("Delete a minimum score:%.1f\n", min);    /*ȥ��һ����߷ֺ���ͷ�*/

/* �������ܣ��Է����Ӹߵ������� */
void Sort(int h[], float f[], int n)

/* �������ܣ���ӡ���α� */
void Print(int h[], float f[], int n)
printf("order\tfinal score\tnumber code\n");
printf("%5d\t%11.3f\t%6d\n", i, f[i], h[i]);

/* �������ܣ�ͳ����ί�ĵ÷� */
void CountJudgeScore(int ph[], float pf[], int m, float sf[], float f[],  int n)#include <stdio.h>
*/ */


#include <stdlib.h>
#define max 1000

int main()
{
    int a[max],b[max];
    int i,j,n,T;
    scanf("%d",&T);
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", a[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", b[i]);
    }
    printf("%d", a[0]);
    for(i = 1; i < n; i++)
    {
        printf("+%d", a[i]);
    }
    printf("%d", b[0]);
    for(i = 0; i < n; i++)
    {
        printf("+%d", b[i]);
    }
    printf("Hello world!\n");
    return 0;
}
