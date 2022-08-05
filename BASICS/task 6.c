#include<stdio.h>
#include<math.h>
int main()
{
	long int n,number,digit=0,remainder=0,armstrong=0,num;
	printf("enter a number");
	scanf("%li",&n);
	number=n;
	num=n;
	while(number!=0)
    {
	number=number/10;
	digit++;
    }
    while(n!=0)
    {
    	remainder=n%10;
    	armstrong=pow(remainder,digit)+armstrong;
    	n=n/10;
    }
	if(num==armstrong)
	{
		printf("%li is an armstrong number",num);
	}
	else
	{
		printf("%li is not an armstrong number",num);
	}
    return 0; 
	}
