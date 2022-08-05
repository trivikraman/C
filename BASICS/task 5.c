#include<stdio.h>
#include<math.h>
int main()
{
long int n,number,digit=0,remainder=0,reverse=0;  
printf("enter a number:");
scanf("%ld",&n);
number=n;
while(number!=0)
{
	number=number/10;
	digit++;

}
printf("digits:%d",digit);
while(n!=0)
{   
    digit--;
	remainder=n%10;
	reverse=remainder*pow(10,digit)+reverse;
	n=n/10;

}
	 printf("the reversed number is %ld",reverse);
	 return 0;
}
