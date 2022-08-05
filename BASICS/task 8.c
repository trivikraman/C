#include<stdio.h>
int n;
int mul(int j)
{
printf("\n%d * %d = %d",n,j,n*j);
}
int main()
{
 int limit,i;
 printf("enter the number:");
 scanf("%d",&n);
 printf("enter the limit:");
 scanf("%d",&limit);
 printf("             MULTIPLICATION TABLE OF %d",n);
 for(i=1;i<=limit;i++)
 {
 mul(i);
 } 
 return 0;
}
