#include <stdio.h>
#include <math.h>

int main()
{
	puts("Vvedite x1");
	int x1,y1,r1,x2,y2,r2,x3,y3,r3;
	if (scanf("%i",&x1)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite y1");
	if (scanf("%i",&y1)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite r1");
	if (scanf("%i",&r1)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite x2");
	if (scanf("%i",&x2)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite y2");
	if (scanf("%i",&y2)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite r2");
	if (scanf("%i",&r2)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite x3");
	if (scanf("%i",&x3)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite y3");
	if (scanf("%i",&y3)!=1)
	{
		puts("Error io");
		return -1;
	}
	puts("Vvedite r3");
	if (scanf("%i",&r3)!=1)
	{
		puts("Error io");
		return -1;
	}
	int d1,d2,d3,x,y;
	x=x1-x2;
	x=x*x;
	y=y1-y2;
	y=y*y;
	d1=sqrt((float)(x+y));
	x=x2-x3;
	x=x*x;
	y=y2-y3;
	y=y*y;
	d2=sqrt((float)(x+y));
	x=x3-x1;
	x=x*x;
	y=y3-y1;
	y=y*y;
	d3=sqrt((float)(x+y));
	if(d1<(r1+r2)&&d2<(r2+r3)&&d3<(r3+r1))
		puts("Peresekayutsya");
	else
			puts("NE peresekayutsya");
	return 0;
}
