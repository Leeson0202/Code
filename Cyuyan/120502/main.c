#include <stdio.h>
strlen(char *s)
{
    char *p=s;
    while(*p)
        p++;
    return p-s;
}
main()
{
    char a[50];
    printf("Enter string:");
    scanf("%s",a);
    printf("string length=%d\n",strlen(a));
    return 0;
}
