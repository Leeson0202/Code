#include <stdio.h>
#include <stdlib.h>
#define N 40
int read();
void shuchu();
void paixu();


int main()
{
    int score[N], n;
    n = read(score);
    printf("学生人数：%d\n",n);
    paixu(score,n);
    shuchu(score,n);
    return 0;
}


int read(int score[])
{
    int i = -1;
    do{
       i++;
       printf("input score:");
       scanf("%d",&score[i]);
      }while(score[i]>=0);
      return i;
}

void shuchu(int score[],int a)
{
    int i;
    for(i =0 ;i < a; i++)
    {
        printf("score = :%d\n",score[i]);
    }
    return;
}

void paixu(int score[],int n)
{
    int i,j,m;
    for(i = 0;i< n-1;i++)
    {
        for(j = i + 1;j<n;j++)
        {
            if(score[i] < score[j])
            {
                m = score[i];
                score[i] = score[j];
                score[j] = m;
            }
        }
    }
    return ;
}


