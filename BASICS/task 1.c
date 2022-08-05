#include<stdio.h>
int main()
{
 long long int phone;
 int age;
 char a[30];
 printf("enter name,age,phone no");
 scanf("%s%d%lld",a,&age,&phone);
 printf("Name:%s\nAge:%d\nPhone no:%lld",a,age,phone);
 return 0;
}
