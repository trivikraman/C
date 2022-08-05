#include<stdio.h>
int main()
{
	int a[100],n,i,l,s;
	printf("enter the number of elements you need to enter:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the element %d\t",i+1);
		scanf("%d",&a[i]);
	}
	l=s=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>l)
		l=a[i];
		if(a[i]<s)
		s=a[i];
	}
	printf("the largest element in the array is %d\nthe smallest element in the array is %d",l,s);
	return 0;
}
