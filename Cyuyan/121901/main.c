#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    FILE *fp;
    char ch;
    int i;

    if ((fp = fopen("stus.txt","w")) == NULL)
    {
        printf("���ļ�");
        exit(0);
    }

    for (i = 0;i<128;i++)
    {
        fputc(i,fp);
    }
    fclose(fp);
    if ((fp = fopen("stus.txt","r")) == NULL)
    {
        printf("���ļ�ʧ��");
        exit(0);
    }
   while((ch = fgetc(fp)!= EOF))
   {
       putchar(ch);
       printf("\t");
   }
    fclose(fp);
    return 0;
}
