#include <stdio.h>
#define N 10

void ma(int a, int b )
{
    if (a>b)
        printf("%d",a);
    else
    {
        printf("%d",b);
    }
    
}
void mi(int a, int b )
{
    if (a<b)
        printf("%d",a);
    else
    {
        printf("%d",b);
    }
    
}



int main()
{
    int a, b = 1;
    scanf("%d", &a);
    a > b ? ma(a,b) : mi(a,b);
    return 0;
}
