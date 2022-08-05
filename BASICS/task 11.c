#include<stdio.h>
struct book
{
	char author[100];
	char title[100];
	char genre[100];
}b1;
void input()
{
	scanf("%s",b1.author);
	scanf("%s",b1.title);
	scanf("%s",b1.genre);
}
void output()
{
	printf("\nTITLE:%s\nAUTHOR:%s\nGENRE:%s",b1.author,b1.title,b1.genre);
}
int main()
{
	printf("enter the tile,author,genre of the book(without spaces)");
	input();
	output();
	return 0;
}
