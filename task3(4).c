#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 100
#define MinSize 1

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void choiseFunction(int*choise)
{
	printf("If you want random input 1. If you want input masive by hands input 0.\n");
	while (scanf_s("%d", choise) != 1 || *choise < 0 || *choise>1 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("If you want random input 1. If you want input masive by hands input 0.\n");
	}

}

void inputMasiveHand(int *m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Input element[%d][%d]:", i+1, j+1);
			while ((scanf_s("%d", &m[i * MaxSize + j]) != 1) || getchar() != '\n')
			{
				rewind(stdin);
				printf("Error\n");
				printf("Input element[%d][%d]:", i+1, j+1);
			}
		}
			
		
	}
}

void inputMasiveRandom(int* m, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			m[i * MaxSize + j] = random(-5, 5);
		}


	}
}

void inputSize(int* n)
{
	printf("Input how much rows and columns in masive[1-100]:");
	while (scanf_s("%d", n) != 1 || *n < MinSize || *n>MaxSize|| getchar() != '\n')
	{
		printf("Error\n");
		rewind(stdin);
		printf("Input how much rows and columns in masive[1-100]:");
	} 
}

void masiveShow(int *m, int n)
{
	printf("Masive:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d", m[i * MaxSize + j]);
		printf("\n");
		printf("       ");
	}

}

int main ()
{
	int mas[MaxSize][MaxSize];
	int side;
	int sum = 0;
	int choise;
	choiseFunction(&choise);
	inputSize(&side);
	if (choise == 0)
	{
		inputMasiveHand(&mas[0][0], side);
	}
	if (choise == 1)
	{
		inputMasiveRandom(&mas[0][0],side);
	}
	masiveShow(&mas[0][0], side);
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j <side; j++)
			if ((i >= j) && (i + j <=side - 1))
				sum += mas[i][j];
	}
	printf("\nSum:%d",sum);
	return 0;
}

