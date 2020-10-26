
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct hero
{
    char *skill;         //指针形式
    int *id;
}h1;

int main()
{

    //使用结构体

    struct hero h1;

    strcpy(*h1.skill,"花花");
    //*h1.id = 200;
    //printf("\n%d\n",*h1.id);
    printf("\n%s\n",h1.skill);
    return 0;
}
