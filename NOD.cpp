#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("Vvedite chislo a");
	int a=0,b=0;
	if(scanf("%d",&a)!=1)
	{
		puts("Error i/o");
		return -1;
	}
	puts("Vvedite chislo b");
	if(scanf("%d",&b)!=1)
	{
		puts("Error i/o");
		return -1;
	}
	int aish=a,bish=b;
	if(a<b)
	{
		a=bish;
		b=aish;
	}
	int c=0;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	printf("NOD(%d,",aish);
	printf("%d)=",bish);
	printf("%d\n",a);
	return 1;
}