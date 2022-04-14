//201901674 ¹Ú¼¼¿ë
#include <stdio.h>
int intersection(int a[],int s_a,int n[],int s_b,int result[]);

int main()
{
    int a[]={1,3,5};
    int b[]={3,5,8,9};
    int result[20];
    int count,i,size_a,size_b;
    size_a = sizeof(a)/sizeof(int);
    size_b=  sizeof(b)/sizeof(int);
    count= intersection(a,size_a,b,size_b,result);
    for(i =0;i<count;i++)
    {
        printf("%d",result[i]);
    }
 printf("\n");
    return 0;
}