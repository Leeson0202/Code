#include<stdio.h>
int main(void)
{
    float a,b,c,d,e;
    printf("������������������:");
    scanf("%f%f%f",&a,&b,&c);
    d = a+b+c;
    e = d/3;
    printf("�������ĺ�Ϊ%.3f, ��ֵΪ%.3f",a+b+c,(a+b+c)/3);
    return 0;
}
