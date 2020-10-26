#include <stdio.h>
#define nn 10
int main()
{
    int a[nn];
    for(int j;j<nn; j++)
    {
            a[j] = j;
    }
    printf("a 为：\n");
    for(int j = 0;j<nn;j++)
    {
        printf("%d",a[j]);
    }
    printf("\n");
    return 0;
}