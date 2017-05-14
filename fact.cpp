#include <stdio.h>

int main()
{
	puts("Vvedite chislo");
	int hgr=0;
	if (scanf("%i",&hgr)!=1)
	{
		puts("Error io\n");
		return -1;
	}
	int FactZnc;
	int SumFact=1;
	puts("Factorial 0 = 1");
	for(int n=1;n<=hgr;n++)
	{
		FactZnc=1;
		for(int i=1;i<=n;i++)
		{
			FactZnc=FactZnc*i;
		}
		SumFact=SumFact+FactZnc;
		printf("Factorial %i ",n);
		printf("= %i\n",FactZnc);
	}
	puts("-----------------------------");
	printf("Summa factorial %i \n",SumFact);
	return 0;
}