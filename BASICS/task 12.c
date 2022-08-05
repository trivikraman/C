#include<stdio.h>
int main()
{
	float cel,fahr;
	int choice;
	printf("1.celsius to fahrenheit\n2.fahrenheit to celsius");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("enter the temperature(in celsius)");
	scanf("%f",&cel);	
	fahr=(9*cel+160)/5;
	printf("Temperature (in fahrenheit):%f",fahr);
	break;
	case 2:
    printf("enter the temperature(in fahrenheit)");
	scanf("%f",&fahr);	
	cel=(5*fahr-160)/9;
	printf("Temperature (in celsius):%f",cel);
	break;
	default:
	printf("exit-invalid choice");
    }
return 0;
	
}
