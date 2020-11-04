#include <stdio.h>
int main()
{
    int i, s1 = 1, s2 = 1;
    float x, sum = 0;
    for (i = 1; i <= 20; i++)
    {
        x = s1 + s2;
        s1 = s2;
        s2 = x;
        sum = (double)s2 / s1;
    }
    printf("sum = %9.6f\n", sum);
}