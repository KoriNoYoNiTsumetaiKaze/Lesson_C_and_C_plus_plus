#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int size=20;
	int arr[size],i;
	srand(time(0));
	for(i=0;i<size;i++)
	{
		arr[i]=rand()%101-50;
		printf("%d \n",arr[i]);
	}
	int firstNotNull=0;
	for(i=0;i<size;i++)
	{
		if(arr[i]!=0)
		{
			firstNotNull=arr[i];
			break;
		}
	}
	printf("firstNotNull= %d \n",firstNotNull);
	for(i=0;i<size;i++)
	{
		if ((arr[i]%firstNotNull)==0)
		{
			printf("%d \n",arr[i]);
		}
	}
}