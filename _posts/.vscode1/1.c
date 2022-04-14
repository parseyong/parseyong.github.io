//201901674 박세용
#include <stdio.h>

int main()
{
    int i,x[6],sum=0;
    printf("enter 3 numbers: ");
    for(int i=0;i<6;i++)
    {
        scanf("%d",x+i);
        sum +=*(x+i);
    }                           
    printf("sum= %d",sum);
    return 0;
}