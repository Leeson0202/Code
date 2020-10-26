#include <stdio.h>
#include <stdlib.h>
#define n 21

typedef struct
{


}ss;
int main()
{
    int a[n] = {2,45,54};
    int j,max,unm;
    max = a[0] > a[1] ? a[0]:a[1];
    unm = a[0] < a[1] ? a[0]:a[1];
    for(j = 3;j<n; j++)
    {
        if(a[j]<unm)
            continue;
        else if(a[j] > max && a[j]>unm)
        {
            unm = max;
            max = a[j];
        }
        else
            unm = a[j];
    }
    printf("最大数为%d，其次是%d",max,unm);

}
