#include <stdio.h>

int main(void)
{
    double number;
    long inumber;
    int count =0;
    printf("실수입력하고 엔터>");
    scanf("%lf", &number,sizeof(number));
    inumber = (long)number;
    printf("입력된 값 : %lf\n", number);
     printf("정수부분 : %ld\n", inumber);
    while (inumber >0L)
    {
        inumber /=10L;
        count++;
    }
printf("정수자리수: ");
return 0;
}