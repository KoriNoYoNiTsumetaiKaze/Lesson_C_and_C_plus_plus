#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	const int m=10;
	int a[m];
	srand(time(0));
	for(int i=0;i<m;i++)
	{
		a[i]=rand()%101-50;
		printf("%d ",a[i]);
	}
	printf("\n");
	puts("Vvedite sdvig");
	int n=0;
	if(scanf("%d",&n)!=1)
	{
		puts("Error i/o");
		return -1;
	}
/*	int last=0,nlast=0;
	f(a,n,&last,k,&nlast);
	printf("Posledniy element massiva vhodyashiy v diapozon %d\n",last);
	printf("Nomer poslednego elementa massiva vhodyashego v diapozon %d\n",nlast);*/
	return 1;
}