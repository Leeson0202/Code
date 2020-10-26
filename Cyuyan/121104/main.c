#include  <stdio.h>
#include  <string.h>
#define N 80

void mm();
int main()
{
    int i;
	char  name[5][N];
	printf("Input five countries' names:\n");
	for (i = 0;i<5;i++)
    {
        gets(name[i]);
    }
    mm(name);


	printf("The minimum is:\n");
	for(i = 0;i<5 ; i++)
    {
        puts(name[i]);
    }
    return 0;
}

void mm(char name[5][N])
{
    int i,j;
    char temp[N];
    for (i = 0;i<4;i++)
    {
        for(j = i+1; j<5; j++)
        {
            if(strcmp(name[i],name[j])>0)
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
    return ;
}
