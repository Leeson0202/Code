/*
一维数组实验题：大奖赛现场统分。已知某大奖赛有n个选手参赛，
m（m>2）个评委为参赛选手评分（最高10分，最低0分）。
统分规则为：在每个选手的m个得分中，去掉一个最高分和一个最低分后，
取平均分作为该选手的最后得分。要求编程实现：
（1）根据n个选手的最后得分，从高到低输出选手的得分名次表，以确定获奖名单；
（2）根据各选手的最后得分与各评委给该选手所评分数的差距，
对每个评委评分的准确性和评分水准给出一个定量的评价，
每位评委的评分方法：(10 -(评委对选手x的评分 - x的得分)^2 的累加和)，
从高到低输出各评委得分的名次表。
输入提示：
    printf("How many Athletes?");
    scanf("%d", &n);                                /* 输入选手人数 */
//   printf("How many judges?");
//    scanf("%d", &m);                              /* 输入评委人数 */
//
  //  printf("Order of Athletes:\n");          /* 选手得分排序 */
    //printf("Order of judges:\n");            /* 评委得分排序 */

// 函数功能：统计参赛选手的得分
//void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m)
//    printf("\nAthlete %d is playing.", i);
//    printf("\nPlease enter his number code:");
//    scanf("%d", &sh[i]);

 for (j = 1; j <= m; j++)              /* 第j个评委 */
        {
            printf("Judge %d gives score:", j);

        printf("Delete a maximum score:%.1f\n", max);
        printf("Delete a minimum score:%.1f\n", min);    /*去掉一个最高分和最低分*/

/* 函数功能：对分数从高到低排序 */
void Sort(int h[], float f[], int n)

/* 函数功能：打印名次表 */
void Print(int h[], float f[], int n)
printf("order\tfinal score\tnumber code\n");
printf("%5d\t%11.3f\t%6d\n", i, f[i], h[i]);

/* 函数功能：统计评委的得分 */
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
