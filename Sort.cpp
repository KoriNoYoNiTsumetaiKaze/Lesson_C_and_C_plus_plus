#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sortmax(int arr[],int size)
{
	int last=size-1,max=0,pmax=0,h,i;
	for(i=last;i>0;i--)
	{
		max=arr[i];
		pmax=i;
		for(int j=0;j<=i;j++)
			if(max<arr[j])
			{
				max=arr[j];
				pmax=j;
			}
		h=arr[pmax];
		arr[pmax]=arr[i];
		arr[i]=h;
	}
	int half=size/2;
	for(i=0;i<half;i++)
	{
		h=arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i]=h;
	}
	puts("Sort max");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	puts("");
}

void SortObmen(int arr[],int size)
{
	int flag_next=1,h=0;
	while(flag_next)
	{
		flag_next=0;
		for(int i=1;i<size;i++)
			if(arr[i-1]<arr[i])
			{
				h=arr[i-1];
				arr[i-1]=arr[i];
				arr[i]=h;
				flag_next=1;
			}
	}
	puts("Sort Obmen");
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	puts("");
}

void SortVs(int arr[],int harr[],int size)
{
	int p=0,h=0,i,j;
	puts("Sort Vstafka");
	for(i=0;i<size;i++)
	{

	}
/*	for(i=0;i<size;i++)
	{
		p=i;
		for(j=1;j<size;j++)
		{
			if(arr[j-1]>=arr[i]&&arr[j]<=arr[i])
			{
				p=j;
			}
		}
		for(j=0;j<p;j++)
		{
			harr[j]=arr[j];
		}
		harr[p]=arr[i];
		for(j=p+1;j<size;j++)
		{
			harr[j-1]=arr[j];
		}
		for(j=0;j<size;j++)
		{
			arr[j]=harr[j];
			printf("%d ",arr[j]);
		}
		puts("");
	}
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	puts("");*/
}

int main()
{
	const int size=15;
	int arr[size]={0},harr[size]={0};
	srand(time(0));
	for(int i=0;i<size;i++)
	{
		arr[i]=rand()%101-50;
		printf("%d ",arr[i]);
	}
	puts("");
	int arr1[size]={0};
	for(int i=0;i<size;i++)
		arr1[i]=arr[i];
	sortmax(arr1,size);
	for(int i=0;i<size;i++)
		arr1[i]=arr[i];
	SortObmen(arr1,size);
	for(int i=0;i<size;i++)
		arr1[i]=arr[i];
	SortVs(arr1,harr,size);
	return 1;
}