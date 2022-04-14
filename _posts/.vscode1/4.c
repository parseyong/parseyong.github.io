//201901674 박세용
#include <stdio.h>
#include <math.h>
void dec_to_bin(long n);
int main()
{
    long n;
    printf("10진수를 입력하고 enter>");
    scanf("%ld",&n);
    printf("10진수: %ld\n",n);
    printf("2진수 : ");
    dec_to_bin(n);
    printf("\n");

    
    return 0;
}
void dec_to_bin(long n)
{
    if(n>1)
    {
        dec_to_bin(n/2);
    }
    printf("%ld",n%2);
}