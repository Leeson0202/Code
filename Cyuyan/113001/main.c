#include <stdio.h>
#include <stdlib.h>

int Fib();

int main()
{

    int n,i,sum,count;

    printf("Input n:");
    scanf("%d",&n);
    for(i = 0; i < n;i++)
    {
        sum = Fib(i);
        count += sum;
        printf("Fib(%d)=%d, count=%d\n",n,sum,count);
    }

    return 0;
}

int Fib(int i)
{
    if(i = 0|| i == 1)
    {
        return 1;
    }
    else
    {
        return Fib(i-1)+Fib(i-2);
    }

}
