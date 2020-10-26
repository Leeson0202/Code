#include <stdio.h>
#include <string.h>
#define max 100

void en( char *);

int main()
{
    char line[max];
    printf("input the string:");
    gets(line);
    en(line);
    printf("%s%s\n","After being encrypted:",line);

    return 0;
}

void en(char *s)
{
    for(; *s != '\0' ; s++)

        if( *s == 'z')
            *s = 'a';
        else

        *s = *s + 1;


}
