#include<stdio.h>
int fact(int n)
{   
    if(n<=0)
    return 1;
	if(n==1)
	return 1;
	else
	return n*fact(n-1);
}
int main()
{
	int number,factorial;
	printf("enter a number");
	scanf("%d",&number);
	factorial=fact(number);
	printf("the factorial of %d is %d",number,factorial);
	return 0;
}
