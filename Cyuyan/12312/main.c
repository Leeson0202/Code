#include<stdio.h>
int main()
{
    double x=0,h=100.0;
    float length, high;
    int i;
    for(i=1; i<=10; i++)
    {
        x +=h;
        h = h /2.0;
        x += h;
    }
    length = float(x);
    high = float(h);
    printf("the total of road is %f\n", length);
    printf("the tenth is %f meter\n", high);
    return 0;
}
