//201901674 �ڼ���
#include <stdio.h>
#include <math.h>
void dec_to_bin(long n);
int main()
{
    long n;
    printf("10������ �Է��ϰ� enter>");
    scanf("%ld",&n);
    printf("10����: %ld\n",n);
    printf("2���� : ");
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