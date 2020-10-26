#include <stdio.h>
#include <stdlib.h>

int God(int a, int b);

int main()
{
    int year,month;

    printf("Please enter year,month:");
    scanf("%d,%d",&year,&month);
    if((year%4 == 0&&year%100!= 0)||year%400 == 0)
        printf("%d is leap year\n",year);
    else
        printf("%d is not leap year\n",year);

            if(month>2&&month<6)
            printf("The season is spring\n");
            if(month>5&&month<9)
            printf("The season is summer\n");
            if(month>8&&month<12)
            printf("The season is autumn\n");
            if(month==1||month == 2|| month == 12)
            printf("The season is winter\n");
if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
printf("The number of days of this month is 31");
else if(month == 4||month == 6||month == 9||month == 11)
    printf("The number of days of this month is 30");
else
    {
        if((year%4 == 0&&year%100!= 0)||year%400 == 0)
        printf("The number of days of this month is 29");
    else
        printf("The number of days of this month is 28");
    }
    return 0;
}










