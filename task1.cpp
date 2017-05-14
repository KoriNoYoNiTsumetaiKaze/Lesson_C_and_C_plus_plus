#include <stdio.h>

int main()
{
	puts("Vvedy chislo:");
	int VhZnc=0;
	int k10=0;
	int k1=0;
	int ObrZnc=0;
	if (scanf("%i",&VhZnc)!=1)
	{
		puts("Error io");
		return -1;
	}
	k1=VhZnc%10;
	printf("Kol-vo ed: %i\n",k1);
	VhZnc=VhZnc-k1;
	k10=VhZnc/10;
	printf("Kol-vo desyatkov: %i\n",k10);
	printf("Summa cifr: %i\n",(k10+k1));
	ObrZnc=k1*10+k10;
	printf("Obratnoe chislo: %i\n",ObrZnc);
	return 0;
}