#include <stdio.h>

int main()
{
    int a[7]={1,2,3,4,5,6,7};
    char b;
    printf("Please enter a string:\n");
    scanf("%s",&b);
    switch(b)
case 'Sunday':
    printf("%s is %d\n",a[6]);
    break;
    case 'Monday':
    printf("%s is %d\n",a[0]);
    break;

    case 'Tuesday':
    printf("%s is %d\n",a[1]);
    break;
    case 'Wednesday':
    printf("%s is %d\n",a[2]);
    break;
    case 'Thursday':
    printf("%s is %d\n",a[3]);
    break;
    case 'Friday':
    printf("%s is %d\n",a[4]);
    break;
    case 'Saturday':
    printf("%s is %d\n",a[5]);
    break;
    default:
        printf("Not found!");
    return 0;
}


