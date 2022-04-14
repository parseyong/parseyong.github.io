// 201901674 박세용
#include <Stdio.h>

int main()
{
    char str[50];
printf("enter: ");
fgets(str,sizeof(str),stdin);

printf("result : \n");
int i=0;
while(str[i]!='\0'){
    i++;
}
printf("%d\n",i-1);

return 0;
}