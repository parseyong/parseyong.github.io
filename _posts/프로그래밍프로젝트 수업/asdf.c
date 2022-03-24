#include <stdio.h>

int main(void)
{
   long number;
   printf("입력된 정수의 부호바꾸기\n");
   printf("숫자(부호포함)입력 후 enter>");
   scanf("%ld", &number,sizeof(number));
   number = ~number+1;
   printf("부호가 바뀐값:%ld",number);
   return 0;

}
