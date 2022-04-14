#include <stdio.h>
#include <ctype.h>

int main()
{
    
    char str[200];
    fgets(str,sizeof(str),stdin);
    printf("result :\n");
    int i=0;
    while(str[i]!='0'){
        int ck1=(str[i]>='a') &&(str[i]<='z');
         int ck2=(str[i]>='A') &&(str[i]<='Z');
         if(ck1 ||ck2){
             printf("%c",touppder(str[i]));
         }
         else if(ck2){
             printf("%c",tolower(str[i]));
         }
         else{
             printf("%c",str[i]);
         }
         i++;
    }
    return 0;
}