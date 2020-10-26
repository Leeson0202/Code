#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,sum = 0,k[5] = {10,90,5,4,3};
    for (i = 0; i< 5; i++)
    {
        sum += k[i];
        printf("sum = %d\n",sum);
    }
    return 0;
}
