#include <stdio.h>
#include <string.h>

void printn(int nn[])
{
    printf("%d\t%d\t%d\t%d\t%d\t", nn[0], nn[1], nn[2], nn[3], nn[4]);
    printf("\n===============\n");
    return;
}

int mylen(char *a)
{
    printf("%p\n", a);
    printf("%p\n", *a);
    printf("%s\n", a);
    return strlen(a);
}

int main()
{
    int num[] = {2, 3, 5, 2, 5};

    // printn(num);
    // printf("%d\t%d\t%d\t%d\t%d\t", num[0], num[1], num[2], num[3], num[4]);
    char aa[] = "nunnsda";
    printf("%d\n", mylen(aa));
    printf("%p\n", aa);
    return 0;
}
