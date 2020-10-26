#include <stdio.h>
#include <stdlib.h>

int search(int *p, int n, int x);

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int x,m;
    printf("Enterx: ");
    scanf("%d",&x);
    m = search(a,10,x);
    if(m>= 0)
    {
        printf("Index is %d \n",m);
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}

int search(int *p, int n, int x)
{
    int low,high,mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(x == p[mid])
            break;
        else if(x<p[mid])
            high = mid - 1;
        else
            low = mid+1;
    }
    if(low<=high)
        return mid;
    else
        return -1;
}