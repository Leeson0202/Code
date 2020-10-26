#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int arrive;
    int treat;//客户的信息结构
} QNODE;
FILE *fp;

int main()
{
    QNODE aa;
    aa.arrive = 88;
    int m,n;
    fp = fopen("a0.txt","r");
    printf("%d",aa.arrive);
    do{
        fscanf(fp,"%d%d",&m,&n);
        fclose(fp);
        printf("%d %d ",m,n);

    }while(!feof(fp));
    fclose(fp);
    return 0;
}
