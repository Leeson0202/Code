#include<stdio.h>
int main()
{
    int a = 0;
    printf("a = %p\n",a);
    a = 10;
    printf("a = %p\n",a);
    a = 50;
    printf("a = %p\n",a);
    return 0;
}