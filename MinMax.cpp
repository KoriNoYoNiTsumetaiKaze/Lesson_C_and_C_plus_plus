#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	const int size=5;
	double arr[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=(double)rand()/rand();
		printf("%lf \n",arr[i]);
	}
	int pos_max=0,pos_min=0,i=0;
	double maxZnc=arr[0],minZnc=arr[0];
	for(i=1;i<size;i++)
	{
		if(maxZnc<arr[i])
		{
			maxZnc=arr[i];
			pos_max=i;
		}
		if(arr[i]<minZnc)
		{
			minZnc=arr[i];
			pos_min=i;
		}
	}
	printf("maxZnc= %lf \n",maxZnc);
	printf("pos_max= %d \n",pos_max);
	printf("minZnc= %lf \n",minZnc);
	printf("pos_min= %d \n",pos_min);
	if (pos_max<pos_min)
	{
		i=pos_max;
		pos_max=pos_min;
		pos_min=i;
	}
	double multMinMax=1;
	for(i=pos_min;i<=pos_max;i++)
	{
		multMinMax=multMinMax*arr[i];
	}
	printf("Proizvedenie ot min do max= %lf \n",multMinMax);
}