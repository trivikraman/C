#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[]={8,6,7,11,22,37,41,56,92,61,28,66,90,77,82,59,15,42,50,70};
    int *b=(int*)malloc(20*sizeof(int));
    int i=0,j,k,n,f=0;
    n=sizeof(a)/sizeof(int);
    for(i=0;i<n;i++)
    {
        //k=a[i];
        for(j=2;j<(a[i]/2);j++)
        {
            if(a[i]%j==0)
                {
                    f=1;
                    break;
                }
        }
        if(f==0)
            b[i]=a[i];
    }
    printf("\nprime nos of element a are: ");
    for(i=0;i<20;i++)
        printf("%d\n",b[i]);
    return 0;
}