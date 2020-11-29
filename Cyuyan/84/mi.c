#include <stdio.h>

int main()
{
    int *a;
    int c = 1;
    a = &c;
    printf("%d", *a);

    // a = &c;
    // int **b;
    // b = &a;
    // int ***m;

    // m = &b;

    // printf("1  %p\n", a );  // a 的地址
    // printf("2  %p\n", &a);  // 指向 a 的指针的地址 
    // printf("3  %p\n", *a);  // a 指向的地址

    // printf("4  %p\n", b );  // b 的地址
    // printf("5  %p\n", &b);  // 指向 b 的指针的地址
    // printf("6  %p\n", *b);  // b 指向的地址
    // printf("7  %p\n", c);   // c的地址
    // printf("8  %p\n", m);   // m的地址
