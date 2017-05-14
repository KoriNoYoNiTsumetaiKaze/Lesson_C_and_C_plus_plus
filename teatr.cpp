#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int Ryadi=34;
	const int Mesta=20;
	int arr[Ryadi][Mesta],i;
	srand(time(0));
	printf("\nMesto\t");
	for(i=0;i<Mesta&&i<10;i++)
	{
		printf(" %d ",i+1);
	}
	for(i=10;i<Mesta;i++)
	{
		printf("%d ",i+1);
	}
	puts("\n");
	for(i=0;i<Ryadi;i++)
	{
		printf("Ryad %d\t",i+1);
		for(int j=0;j<Mesta;j++)
		{
			arr[i][j]=rand()%2;
			printf(" %d ",arr[i][j]);
		}
		puts("");
	}
	printf("\nMesto\t");
	for(i=0;i<Mesta&&i<10;i++)
	{
		printf(" %d ",i+1);
	}
	for(i=10;i<Mesta;i++)
	{
		printf("%d ",i+1);
	}
	int sel_ryad,sel_mesto,kolvoTicked;
	puts("\nVvedite ryad");
	if(scanf("%d",&sel_ryad)!=1)
	{
		return -1;
	}
	puts("Vvedite pervoe mesto");
	if(scanf("%d",&sel_mesto)!=1)
	{
		return -1;
	}
	puts("Vvedite kol-vo biletov");
	if(scanf("%d",&kolvoTicked)!=1)
	{
		return -1;
	}
	sel_ryad=sel_ryad-1;
	sel_mesto=sel_mesto-1;
	if (sel_ryad>=Ryadi||sel_ryad<0)
	{
		sel_ryad=0;
	}
	if (sel_mesto>=Mesta||sel_ryad<0)
	{
		sel_mesto=0;
	}
	int flag_prodano=1;
	for(i=0;i<kolvoTicked;i++)
	{
		if(arr[sel_ryad][sel_mesto+i]!=0)
		{
			flag_prodano=0;
		}
	}
	if(flag_prodano)
	{
		puts("Prodano!");
		for(i=0;i<kolvoTicked;i++)
		{
			arr[sel_ryad][sel_mesto+i]=1;
		}
		printf("\nMesto\t");
		for(i=0;i<Mesta&&i<10;i++)
		{
			printf(" %d ",i+1);
		}
		for(i=10;i<Mesta;i++)
		{
			printf("%d ",i+1);
		}
		puts("\n");
		for(i=0;i<Ryadi;i++)
		{
			printf("Ryad %d\t",i+1);
			for(int j=0;j<Mesta;j++)
			{
				printf(" %d ",arr[i][j]);
			}
			puts("");
		}
		printf("\nMesto\t");
		for(i=0;i<Mesta&&i<10;i++)
		{
			printf(" %d ",i+1);
		}
		for(i=10;i<Mesta;i++)
		{
			printf("%d ",i+1);
		}
	}
	else
	{
		const int freesize=Ryadi*Mesta;
		int free_mesta[freesize],kolvoFreeMest=0;
		for(i=0;i<freesize;i++)
			free_mesta[i]=0;
		for(i=0;i<Mesta;i++)
		{
			if(arr[sel_ryad][i]==0)
			{
				free_mesta[kolvoFreeMest]=i;
				kolvoFreeMest=kolvoFreeMest+1;
			}
		}
		if (kolvoTicked<=kolvoFreeMest)
		{
			printf("Ryad %i imeet doststochno svobodnyh mest\n",sel_ryad+1);
			for(i=0;i<freesize&&i<kolvoTicked;i++)
			{printf("Metsto %d ",free_mesta[i]+1);}
			printf("\n");
		}
		for(i=0;i<Ryadi;i++)
		{
			for(int j=0;j<Mesta;j++)
			{
				flag_prodano=1;
				for(int k=0;k<kolvoTicked;k++)
				{
					if(arr[i][j+k]!=0)
					{
						flag_prodano=0;
					}
				}
				if(flag_prodano)
				{
					printf("Mesta ryadom ryad %d ",i+1);
					printf("nachinaya s %d mesta\n",j+1);
				}
			}
		}

	}
}
