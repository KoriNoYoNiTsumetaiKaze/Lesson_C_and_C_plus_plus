#include <stdio.h>

int main()
{
	puts("Vvedite chislo");
	int VhZnc=0;
	if (scanf("%i",&VhZnc)!=1)
	{
		puts("Error i/o");
		return -1;
	}
	int ost=0,cif=0;
	ost=VhZnc/2;
	cif=VhZnc%2;
	printf("Oststok=%i\n",ost);
	printf("Cifra chisla=%i\n",cif);
	long cislo2=cif;
	int raz=10;
	while((ost!=1)&&(ost!=0))
	{
		VhZnc=ost;
		ost=VhZnc/2;
		cif=VhZnc%2;
		printf("Oststok=%i\n",ost);
		printf("Cifra chisla=%i\n",cif);
		cislo2=cislo2+(cif*raz);
		raz=raz*10;
	}
	cislo2=cislo2+(ost*raz);
	printf("Cislo v dvoichnoy systeme=%ld\n",cislo2);
	return 1;
}