#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],str2[100];
	int n;
	printf("enter a string");
	scanf("%s",str1);
	strcpy(str2,str1);
	strrev(str2);
	n=strcmp(str1,str2);
	if(n==0)
	{
		printf("%s is a pallindrome",str1);
	}
	else
	{
		printf("%s is not a pallindrome",str1);
	}
	return 0;
}
