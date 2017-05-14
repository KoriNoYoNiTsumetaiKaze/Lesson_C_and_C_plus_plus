#include <stdio.h>
#include <string.h>

int strLen(const char * s);
void strCpy(char* dest, const char * source);
void strCat(char* dest, const char * source);
int strCmp(const char * s1, const char * s2);

int main()
{
	char str1[256], str2[256], str3[256];
	gets(str1);
	printf("%d\n", strLen(str1));
	strCpy(str2, str1);
	strCat(str2, str1);
	puts(str2);
	printf("%d\n", strCmp(str1, str2));
	return 0;
}

int strLen(const char * s)
{
	int len = 0;
	while(s[len++]);
	return len-1;
}

void strCpy(char* dest, const char * source)
{
	while(*dest++ = *source++);
	//int i=0;
	//while(source[i]!='\0')
	//{
	//	dest[i] = source[i];
	//	i++;
	//}
	//dest[i] = source[i];
}

void strCat(char* dest, const char * source)
{
	dest +=strLen(dest);
	strCpy(dest, source);
}

int strCmp(const char * s1, const char * s2)
{
	while(*s1)
	{
		if(*s1>*s2)
			return 1;
		if(*s1<*s2)
			return -1;
		s1++;
		s2++;
	}
	if(*s2)
		return -1;
	return 0;
}