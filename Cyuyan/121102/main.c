#include<stdio.h>
int main()
{
    char str[100];
    int i,j;
    printf("Input string:");
    gets(str);
    for (i=0,j=strlen(str)-1; i<=strlen(str)-1; i++)
    {
        if(str[i]==str[j])
        {
            if(i == strlen(str)-1)
            {
                printf("Yes!");
                return 0;
            }

        }
        else break;


    }
    printf("No!");

    return 0;
}
