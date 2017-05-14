#include <stdio.h>

int main()
{
	puts("Vvedite stroku");
	char str[256];
	gets(str);
	for(int i=0;i<256;i++)
	{
		if(64<str[i]&&91>str[i])
		  str[i]=str[i]+32;
		  else
		   if(96<str[i]&&123>str[i])
			str[i]=str[i]-32;
	}
	printf("%s\n",str);
/*	for(int i=0;i<256;i++)
	{
		s=(char)i;
		printf("%d - ",i);
		printf("%c\n",s);
	}*/
	return 1;
}
