#include <stdio.h>
#include <stdlib.h>

struct
{
    int num[20];      //学号
    char name[20];     //姓名
    int score[20];    //成绩
}s1;



int main()
{
    int i;
    printf("亲输入学号 姓名 成绩：");
    for(i = 0; i < 2 ; i++)
    {
        scanf("%d,%s,%d",&s1.num[i],&s1.name[i],&s1.score[i]);

    }
    printf("学号   姓名    成绩\n");
     for(i = 0; i < 2 ; i++)
    {

        printf("%d   %s    %d",s1.num[i],s1.name[i],s1.score[i]);

    }

    return 0;
}
