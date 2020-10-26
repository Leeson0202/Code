#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i = 0;i<37; i++)
    {
        if(i*4+(36-i)*2 == 100)
            printf("%d,%d\n",i,36-i);
    }
    return 0;
}
