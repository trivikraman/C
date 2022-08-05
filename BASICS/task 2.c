#include<stdio.h>
int main()
{
	float cel,fahr;
	printf("Enter the temperature (in celsius)");
	scanf("%f",&cel);
	fahr=(9*cel+160)/5;
	printf("Temperature (in fahrenheit):%f",fahr);
	return 0;
}
