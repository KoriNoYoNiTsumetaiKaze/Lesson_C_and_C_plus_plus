#include <stdio.h>

int main()
{
	puts("Vvedite chislo");
	int VerhGr=0;
	if(scanf("%d",&VerhGr)!=1)
	{
		puts("Error i/o");
		return 1;
	}
	int flag_prost;
	for(int i=2;i<VerhGr;i++)
	{
		flag_prost=1;
		for(int j=2;j<i;j++)
			if(i%j==0)
			{
				flag_prost=0;
				break;
			}
		if(flag_prost)
			printf("Prostoe chislo %d ",i);
	}
	return 1;
}
