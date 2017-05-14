#include <stdio.h>

int f(int a[],int n, int *p)
{
	int flag_chered=1;//flag cheredovanizya 1-chereduyutsya/0-ne chereduyutsya
	for(int i=1;i<n;i++)
	{
		//printf("%d ",a[i]);
		if (((a[i-1]<=0)&&(a[i]<=0))||((a[i-1]>=0)&&(a[i]>=0)))
		{
			flag_chered=0;
		}
	}
	if (flag_chered)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if (a[i]>0)
			{
				sum=sum+a[i];
			}
		}
		*p=sum;
	}
	else
	{
		int mult=1;
		for(int i=0;i<n;i++)
		{
			if (a[i]<0)
			{
				mult=mult*a[i];
			}
		}
		*p=mult;
	}
	return flag_chered;
}

int main()
{
	const int n=4;
	int a[n]={5,-5,-1,-4},p=0;
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	if (f(a,n,&p))
	{
		puts("\nChereduyutsya");
		printf("Summa poloshitelnih = %d\n",p);
	}
	else
	{
		puts("\nNE Chereduyutsya");
		printf("Proizvedenie otricatelnih = %d\n",p);
	}
	return 1;
}