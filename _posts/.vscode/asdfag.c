#include <stdio.h>
#include <math.h>

int main(void)
{
    double num=3674654.568,frct,intg;
    frct= modf(num,&intg);
    printf("tlftn: %lf\n",num);
    printf("wjdtn: %lf\n",intg);
printf("thtn: %lf\n",frct);

return 0;


}