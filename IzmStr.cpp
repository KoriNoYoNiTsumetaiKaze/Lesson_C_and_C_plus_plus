#include <stdio.h>

void IzmStr(char *str)
{
	char new_str[256]={0};
	int end_str=256;
	for (int i=0;i<256;i++)
	{
		if (str[i]==0)
		{
			end_str=i;
			break;
		}
	}
	int pos_sym_new_str=0;
	for (int i=0;i<end_str;i=i+2)
	{
		new_str[pos_sym_new_str]=str[i];
		pos_sym_new_str=pos_sym_new_str+1;
	}
	for (int i=1;i<end_str;i=i+2)
	{
		new_str[pos_sym_new_str]=str[i];
		pos_sym_new_str=pos_sym_new_str+1;
	}
	for (int i=0;i<256;i++)
		str[i]=new_str[i];
}

int main()
{
	puts("Vvedite stroku");
	char str[256];
	gets(str);
	printf("\nIshodnaya stroka %s\n",str);
	IzmStr(str);
	printf("\nResultat %s\n",str);
	return 1;
}