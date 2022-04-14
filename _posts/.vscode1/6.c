//201901674 박세용
#include <stdio.h>

int main()
{
    int a=14,b=5,result;
    result =a-b;
    printf("일반계산 : %d-(%2d)=%d\n",a,b,result);
    result=a+b ;
printf("1의보수 : %d+(%2d)=%d\n",a,-b,result);
result = a+(-b+1);
printf("2의보수 : %d+(%2d)=%d\n",a,-b+1,result);
    return 0;
}