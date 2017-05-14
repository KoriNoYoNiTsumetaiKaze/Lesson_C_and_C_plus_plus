#include <stdio.h>

int main()
{
	int tek=0,sum=0,kolvo=0;
	while(tek!=-1)
	{
		puts("Vvedite chislo");
		if(scanf("%d",&tek)!=1)
			tek=-1;
		if(tek!=-1)
		{
			sum=sum+tek;
			kolvo=kolvo+1;
		}
	}
	printf("Srednee arefmeticheskoe %d/",sum);
	printf("%d=",kolvo);	
	if(kolvo!=0)
		printf("%f\n",(double)sum/kolvo);
	else
		printf("%f\n",0);
	return 1;
}
