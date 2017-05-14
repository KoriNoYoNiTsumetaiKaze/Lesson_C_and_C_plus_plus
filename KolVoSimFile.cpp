#include <stdio.h>

void StrCopy(char * dest,const char * sourse)
{
	//while(*dest++=*sourse++);
	printf("%s dest ",dest);
	printf("%s sourse\n",sourse);
}

int main(int argc,char * argv[])
{
	FILE * fr;
	if(!(fr=fopen(argv[1],"r")))
	{
		puts("Error i/o");
		return -1;
	}
	char str[256];
	struct SUMSIM
	{
		char s;
		int kolvo;
	};
	SUMSIM sim[256];
	for(int i=0;i<256;i++)
	{
		//sim[i].s='\0';
		sim[i].kolvo=0;
	}
	int kovsim=0,flag_now;
	while(!feof(fr))
	{
		for(int i=0;i<256;i++)
			str[i]=0;
		fgets(str,256,fr);
		printf("%s\n",str);
		for(int i=0;i<256;i++)
		{
			flag_now=1;
			for(int j=0;j<256;j++)
				if(sim[j].s==str[i])
				{
					flag_now=0;
					sim[j].kolvo=sim[j].kolvo+1;
					break;
				}
			if(flag_now)
			{
				//sim[kovsim].s=str[i];
				//StrCopy(sim[kovsim].s,str[i]);
				//StrCopy(&sim[kovsim].s,&str[i]);
				//printf("%s sim[kovsim].s ",sim[kovsim].s);
				sim[kovsim].kolvo=1;
				kovsim=kovsim+1;
			}
		}
	}
	for(int i=0;i<256;i++)
	{
		printf("%ñ - ",sim[i].s);
		printf("%d\n",sim[i].kolvo);
	}
	fclose(fr);
	return 1;
}