// 201901674 ¹Ú¼¼¿ë
#include <stdio.h>
void sort(int c[],int n);
int main()
{
    int arr1[]={4,3,10,-1};
    int arr2[]={12,2,10,0,-20};
    int len_arr1=sizeof(arr1) / sizeof(int);
    int len_arr2=sizeof(arr2) / sizeof(int);

    int len_arr3 = len_arr1+len_arr2;
    int arr3[len_arr3];

    for(int i=0;i<len_arr1;i++)
    {
        arr3[i]=arr1[i];
    }
    for(int j=0;j<len_arr2;j++){
        arr3[len_arr1+j]=arr2[j];
    }
    sort(arr3,len_arr3);
    for(int k=0;k<len_arr3;k++){
        printf("%d ",arr3[k]);

    }
    return 0;
}
void sort(int c[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        int temp=0;
        if(c[i]>c[i+1])
        {
            temp=c[i];
            c[i]=c[i+1];
            c[i+1]=temp;
            sort(c,n);
        }
    }
}
    
