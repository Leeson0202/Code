#include <stdio.h>
int main()
{
    int i,num, a, b, c, d;
    for (i = 32; i < 100; i++)
    {
        num = i * i;
        a = num / 1000;   //万位
        b = num / 100 % 10;  //千位
        c = num % 100 / 10;  //十位
        d = num % 10;    //个位
        if (a == b && c == d && a != c)
        {
            printf("%d",num);
        }
    }
    return 0;

}
