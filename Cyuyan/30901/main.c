#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char a[20];
    int b[18];
    int i;
    int s = 0,k;
    printf("���������֤��ǰʮ��λ��\n");
    gets(a);
    for(i = 0;i<17;i++)
    {
        b[i] = a[i]-'0';

    }

    for(i = 0; i<17  ;i++)
    {
        s += ((int)pow(2,(17-i)) % 11) * b[i];
    }
    k = s%11;
    a[17] = ( 12 - k)%11;

    printf("\n���һλ�ǣ�");
    if(a[17] == 10)
        printf("X");
    else
        printf("%d",a[17]);
    printf("\n���֤����Ϊ��");
    for(i = 0;i<17; i++)
        printf("%d",b[i]);

    if(a[17] == 10)
        printf("X\n");
    else
        printf("%d\n",a[17]);
        getchar();
    return 0;
}




