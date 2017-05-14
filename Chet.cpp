#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int size=10;
	int arr[size],i;
	srand(time(0));
	for(i=0;i<size;i++)
	{
		arr[i]=rand()%101-50;
		printf("%d \n",arr[i]);
	}
	for(i=0;i<size;i++)
	{
		if ((arr[i]&1)==0)
			printf("Chetnoe= %d \n",arr[i]);
	}

}