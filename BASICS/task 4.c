#include<stdio.h>
#include<string.h>
int main()
{
 char *str,first[30],last[30];
 printf("enter the first name:");
 scanf("%s",first);
 printf("\nenter the last name:");
 scanf("%s",last);
 str=strcat(first,last);
 printf("The full name is %s",str);
 return 0;
}
