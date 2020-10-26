#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct node
{
    int a;
    char b;
}  ww;

int main()
{
    ww i;//struct node a;
    ww *p;
    i.a; i.b;
    p->a;p->b;


    /*
    int i;
    int *p=NULL,*d=NULL;//a = 6;
    p = &i;

    d = &p;
    printf("%p  %p  %p  %p  %p \n",&i,p,&p,d,&d);

    d = p;
    printf("%p  %p  %p  %p  %p \n",&i,p,&p,d,&d);
    /*

    int a[5]= {0,1,2,3,4};
    p = a;
    printf("%d\n",*p);
    i= 0;
    while(i<5)
    {
        printf("%d\n",*p);
        p++;
        i++;
    };

    /*
    *p = 8; //a = 8
    printf("a = %d\n",a);
    printf("*p = %d\n",*p);
    gaibian( a );

    printf("a = %d\n",a);
    printf("*p = %d\n",*p);
    printf("Hello world!\n");*/
    return 0;
}

void gaibian(int b)
{
    b = 6;//a = 6
    return ;
}
