
#include<stdio.h>
int main()
{
    int x,y,a,b,Z,R;
    printf("分别输入甲,乙的进价和售价:\n");
    scanf("%d %d %d %d",&x,&y,&a,&b);
    Z=a-x;
    R=b-y;
    printf("\n甲的利润:%d\n乙的利润:%d",Z,R);

    return 0;
}
