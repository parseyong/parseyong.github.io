//201901674 �ڼ���
#include <stdio.h>

int main()
{
    int a=14,b=5,result;
    result =a-b;
    printf("�Ϲݰ�� : %d-(%2d)=%d\n",a,b,result);
    result=a+b ;
printf("1�Ǻ��� : %d+(%2d)=%d\n",a,-b,result);
result = a+(-b+1);
printf("2�Ǻ��� : %d+(%2d)=%d\n",a,-b+1,result);
    return 0;
}