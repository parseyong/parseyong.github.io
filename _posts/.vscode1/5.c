//201901674 �ڼ���
#include <stdio.h>
#include <math.h>
long dec_to_octal(long n);
int main()
{

long n;
printf("10���� �Է��ϰ� enter>");
scanf("%ld",&n);
printf("10���� : %ld\n",n);
printf("8���� : %ld",dec_to_octal(n));

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