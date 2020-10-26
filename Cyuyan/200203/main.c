#include <stdio.h>
#include <stdlib.h>
#define N 5

void input(double[]);
void sort(double[]);
void show(double[]);
int find(double* ,int findnum);//下标
int main()
{
    double scores[N] = { };
    input(scores);
    printf("\n排列前的学生成绩：\n");
    show(scores);
    sort(scores);
    printf("\n排列后·的学生成绩：\n");
    show(scores);
    return 0;
}

void input(double scores[])
{
    int i;
    for(i = 0; i<N ; i++)
    {
        printf("请输入第%d个成绩：",i+1);
        scanf("%lf",&scores[i]);
    }

}

void sort(double scores[])
{
    int i,j;
    double temp;
    for(i = 0; i < N - 1; i++)
    {
        for(j = i+1; j<N; j++)
        {
            if(scores[i] < scores[j])
            {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

}
void show(double scores[])
{
    int i;
    for(i = 0;i<N ; i++)
    {
        printf("第%d个同学的成绩为：%.2lf\n",i+1,*(scores+i));
    }


}

int find(double *scores,int findnum)
{
    int i,findindex = -1;
    for(i = 0 ; i<N; i++)
    {

    }
}
