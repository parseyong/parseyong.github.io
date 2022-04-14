// 201901674 박세용
#include <stdio.h>
#include<stdlib.h>
int main() 
{
	int n,i, *ptr,sum=0;
	printf("enter number of elements:");
	scanf("%d",&n);
	ptr= (int*)malloc(n * sizeof(int));
	if(ptr == NULL)
	{
		printf("error memory not allocated.");
		exit(0);
	}
	printf("entwr elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
		sum+=*(ptr+i);
	}
	printf("sum=%d\n",sum);
	free(ptr);
	return 0;
}