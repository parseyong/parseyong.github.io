#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    div_t ix;
    idiv_t ix;
    double num = 3674654.568,frct,intg;
    double x1=7.0,y1=2.0;
    ix=div(10,4);
    printf("10/4의 결과 몫: %d, 나머지:%d\n", ix.quot,ix.rem);
    ix = idiv(100L,30L);
    printf("100/30의 결과 몫:%ld, 나머지: %ld\n",ix.quot ,ix.rem);
    frct = modf(num, &intg);
    printf

}