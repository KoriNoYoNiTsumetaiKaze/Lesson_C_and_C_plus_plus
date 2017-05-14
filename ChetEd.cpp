#include <stdio.h>

long To2(int VhZnc)
{
	long cislo2=0;
	int raz=1,ost=0,cif=0;
	do
	{
		ost=VhZnc/2;
		cif=VhZnc%2;
		cislo2=cislo2+(cif*raz);
		raz=raz*10;
		VhZnc=ost;
	}
	while((ost!=1)&&(ost!=0));
	cislo2=cislo2+(ost*raz);
	return cislo2;
}

int main()
{
	puts("Vvedite chislo");
	int VhZnc=0;
	if (scanf("%i",&VhZnc)!=1)
	{
		puts("Error i/o");
		return -1;
	}
	long Ish10To2=To2(VhZnc);
	printf("Ishodnoe cislo v dvoichnoy systeme=%ld\n",Ish10To2);
/*	int raz=10;
	long ost=Ish10To2,cif=0;
	do
	{
		cif=ost%(raz*10);
		cif=cif/raz;
		if(cif!=0)
		{
			Ish10To2=Ish10To2-raz;
		}
		raz=raz*100;
	}
	while(raz<ost);
	printf("Ismenennoe cislo v dvoichnoy systeme=%ld\n",Ish10To2);*/
/*	int ost=VhZnc,mask=0,step2,tekstep=1;
	do
	{
		ost=ost/2;
		ost=ost/2;
		step2=2;
		for(int i=1;i<tekstep;i++)
			step2=step2*step2;
		mask=mask+step2;
		tekstep=tekstep+2;
	}
	while((ost!=1)&&(ost!=0));
	printf("mask=%ld\n",mask);
	printf("maskTo2=%ld\n",To2(mask));*/
	printf("VhZnc=%ld\n",VhZnc);
	VhZnc=VhZnc&2;
	printf("VhZnc=%ld\n",VhZnc);
	printf("Ishodnoe cislo v dvoichnoy systeme=%ld\n",To2(VhZnc));
	return 1;
}