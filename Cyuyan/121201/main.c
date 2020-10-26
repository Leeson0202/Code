#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m;
    int i;
    for (i = 0;;i++);
    {
        m = getchar();
        if(m>96&&m<123)
           {
               printf("%c",m-32);
               return 0;
           }

    }
    return 0;
}



/*
int main()
{
    int i,j,a[] = {1,3,5,2,5,1,9},k,temp;
    for (i = 0;i<6;i++)
    {
        k = i;
        for(j = i+1 ;j<7;j++)
        {
            if(a[k]<a[j])
            {
                temp = a[k];
                *(a+k) = *(a+j);
                *(a+j) = temp;
            }
        }
    }
    for(i = 0;i<7;i++)
    {
        printf("%4d",*(a+i));
    }
    return 0;
}
*/
