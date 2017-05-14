#include <stdio.h>

//int power(int base, int pow)
//{
//	if(pow == 0)
//		return base;
//	return 1+power(base, pow-1);
//}

void Print(const float * arr, int size);

int main(int argc, char *argv[])
{
	/*if(1==argc)
	{
		puts("No parametrs");
		return -1;
	}
	for(int i=1;i<argc;i++)
		puts(argv[i]);*/
	//printf("%d\n", power(2,10));

	float arr[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,
					9.9,10.10};
	Print(arr,10);
	return 0;
}

void Print(const float * arr, int size)
{
	if(size == 0)
		return;
	Print(arr+1, size-1);
	printf("%.2f ", arr[0]);
}