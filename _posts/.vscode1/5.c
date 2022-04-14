//201901674 박세용
#include <stdio.h>
#include <math.h>
long dec_to_octal(long n);
int main()
{

long n;
printf("10진수 입력하고 enter>");
scanf("%ld",&n);
printf("10진수 : %ld\n",n);
printf("8진수 : %ld",dec_to_octal(n));

    return 0;
}
long dec_to_octal(long n)
{
    if(n<=7)
    {
        return n;
    }
    return dec_to_octal(n/8) * 10 + n%8;
}