#include <stdio.h>
int main()
{
    int i,num, a, b, c, d;
    for (i = 32; i < 100; i++)
    {
        num = i * i;
        a = num / 1000;   //��λ
        b = num / 100 % 10;  //ǧλ
        c = num % 100 / 10;  //ʮλ
        d = num % 10;    //��λ
        if (a == b && c == d && a != c)
        {
            printf("%d",num);
        }
    }
    return 0;

}
