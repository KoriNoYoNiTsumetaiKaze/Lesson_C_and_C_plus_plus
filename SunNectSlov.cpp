#include <stdio.h>

int SumNechSlov(char * str)
{
	int i,flag2probel=1;
	while(flag2probel)
	{
		flag2probel=0;
		for(i=1;i<256;i++)
			if(str[i-1]==' '&&str[i]==' ')
			{
				flag2probel=1;
				for(int j=i;j<255;j++)
					str[j]=str[j+1];
			}
	}
	printf("%s\n",str);
	int flag_nechet=1,sum=0;
	i=-1;
	while(str[i++])
	{
		if(str[i]==' ')
			if (flag_nechet)
				flag_nechet=0;
			else
				flag_nechet=1;
		else
			if ((flag_nechet)&&(str[i]!=0))
				sum=sum+1;
	}
	return sum;
}

int main()
{
	puts("Vvedite stroku");
	char str[256];
	gets(str);
	printf("Chislo vstrech= %d\n",SumNechSlov(str));
	return 1;
}