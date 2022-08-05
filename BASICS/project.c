#include<stdio.h>
//following are taken as granted
//max mark is 100,max no of students 100

int n;

struct student
{
	char name[100];
	int eng;
	int math;
	int sci;
	int comp;
	int lang;
	int avg;
	
};
grade(int j)
	   {
	   	printf("GRADE:");
		if(j>=80)
        printf(" A");
        else if(j>=60)
        printf(" B");
        else if(j>=50)
        printf(" C");
        else if(j>=40)
        printf(" D");
        else
        printf(" F");
	  }
int main()
{
	student s1[100];
	int i;
	printf("enter the total number of students ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nstudent-%d",i+1);
		printf("\nenter the name:");
		scanf("%s",s1[i].name);
		printf("\nENGLISH:");
		scanf("%d",&s1[i].eng);
		grade(s1[i].eng);
		printf("\nLANGUAGE:");
		scanf("%d",&s1[i].lang);
		grade(s1[i].lang);		
		printf("\nMATHS:");
		scanf("%d",&s1[i].math);
		grade(s1[i].math);
     	        printf("\nSCIENCE:");
		scanf("%d",&s1[i].sci);
		grade(s1[i].sci);
		printf("\nCOMPUTER:");
		scanf("%d",&s1[i].comp);
		grade(s1[i].comp);
		printf("\nSUM:%d",s1[i].eng+s1[i].lang+s1[i].math+s1[i].sci+s1[i].comp);
		s1[i].avg=(s1[i].eng+s1[i].lang+s1[i].math+s1[i].sci+s1[i].comp)/5;
		printf("\naverage:%d",s1[i].avg);
		printf("\nOVERALL");
		grade(s1[i].avg);
		
	}
  
return 0;

   
   	
}
