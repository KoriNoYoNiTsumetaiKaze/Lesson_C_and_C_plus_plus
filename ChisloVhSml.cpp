#include <stdio.h>

int chisloVh1(char *str)
{
	int i=-1,sum=0;
	while(str[i++])
		if(str[0]==str[i])
			sum=sum+1;
	return sum;
}

int main()
{
	puts("Vvedite stroku");
	char str[256];
	gets(str);
	printf("Chislo vstrech= %d\n",chisloVh1(str));
	return 1;
}