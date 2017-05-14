#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void f(int a[],int n,int *last,int k,int *nlast)
{
	for(int i=n-1;i>=0;i--)
		if((a[i]>=-k)&&(a[i]<=k))
		{
			*last=a[i];
			*nlast=i;
			break;
		}
}

int main()
{
	const int n=10;
	int a[n];
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%101-50;
		printf("%d ",a[i]);
	}
	printf("\n");
	puts("Vvedite granicu");
	int k=0;
	if(scanf("%d",&k)!=1)
	{
		puts("Error i/o");
		return -1;
	}
	int last=0,nlast=0;
	f(a,n,&last,k,&nlast);
	printf("Posledniy element massiva vhodyashiy v diapozon %d\n",last);
	printf("Nomer poslednego elementa massiva vhodyashego v diapozon %d\n",nlast);
	return 1;
}