#include<stdio.h>
int main()
{
	float math,comp,stat,sum,avg;
	printf("enter the marks for 3 subjects(maths,computer,statistics):");
	scanf("%f%f%f",&math,&comp,&stat);
	sum=math+comp+stat;
	avg=sum/3;
	printf("\nMarks obtained:\n\tMaths:%0.1f\n\tComputer:%0.1f\n\tstatistics:%0.1f\nSum:%0.1f\naverage:%f",math,comp,stat,sum,avg);
    return 0;	
}
