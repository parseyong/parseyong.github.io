#define CRT_SECURE_NO-WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    time_t now;
    struct tm*d;
    while(!kbhit())
    {
        system("cls");
        now = time(NULL);
        d= localtime(&now);
        printf("현재 날짜와 시간 : %s\n",asctime(d));
        
    }
    return 0;
}