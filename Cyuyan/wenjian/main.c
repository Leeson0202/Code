#include <stdio.h>
#include <stdlib.h>
#define N 2

struct student
{
    char name[10];
    int num;
    int age;
    char ad[15];
}s[N],*qq;
void save();

int main()
{
    int i;
    for (i = 0; i < N ; i++)
    scanf("%s%d%d%s",s[i].name, &s[i].num, &s[i].age,s[i].ad);
    save();

    return 0;
}

void save()
{
    FILE *fp;
    int i;
    if((fp = fopen("student.dat","wb"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i = 0; i< N;i++)
        if(fwrite(&s[i],sizeof(struct student),1,fp)==0)
        printf("file writr error\n");
    fclose(fp);
}
