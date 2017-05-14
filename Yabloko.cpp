#include <stdio.h>

int main()
{
	puts("Vvedite cenu:");
	double cena;
	if (scanf("%lf",&cena)!=1)
	{
		puts("Error io");
		return -1;
	}
	double cena100;
	cena100=cena/1000;
	printf("Gramm %.2f \n",cena100);
	for (int i=100;i<=1000;i=i+100)
	{
		printf("|\tCena\t%i\tgramm\t",i);
		printf("|\t%.2f\t|\n",(i*cena100));
	}
	return 0;
}