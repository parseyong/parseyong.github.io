#include <stdio.h>
#define _CRT_SECURE_NO_WARNING 1
#include <time.h>

int main()
{
    time_t now;
    time(&now);
    printf("현재 날짜와 시간: %s",asctime(localtime(&now)));
    printf("현재 날짜와 시간: %s",ctime(&now));
    return 0;

    
}