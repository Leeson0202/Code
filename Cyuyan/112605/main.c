
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct hero
{
    char *skill;         //ָ����ʽ
    int *id;
}h1;

int main()
{

    //ʹ�ýṹ��

    struct hero h1;

    strcpy(*h1.skill,"����");
    //*h1.id = 200;
    //printf("\n%d\n",*h1.id);
    printf("\n%s\n",h1.skill);
    return 0;
}
