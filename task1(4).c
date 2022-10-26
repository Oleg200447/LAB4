#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 100
#define MinSize 1

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void choiseFunction(int* choise)
{
	printf("If you want random input 1. If you want input masive by hands input 0.\n");
	while (scanf_s("%d", choise) != 1 || *choise < 0 || *choise>1 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("If you want random input 1. If you want input masive by hands input 0.\n");
	}

}

void inputMasiveHand(int* m, int n_row, int n_col)
{
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			printf("Input element[%d][%d]:", i + 1, j + 1);
			while ((scanf_s("%d", &m[i * MaxSize + j]) != 1) || getchar() != '\n')
			{
				rewind(stdin);
				printf("Error\n");
				printf("Input element[%d][%d]:", i + 1, j + 1);
			}
		}


	}
}

void inputMasiveRandom(int* m, int n_row, int n_col)
{
	srand(time(NULL));
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			m[i * MaxSize + j] = random(-100, 100);
		}


	}
}

void inputSize(int* n_row, int* n_col)
{
	printf("Input how much rows in masive[1-100]:");
	while (scanf_s("%d", n_row) != 1 || *n_row < MinSize || *n_row>MaxSize || getchar() != '\n')
	{
		printf("Error\n");
		rewind(stdin);
		printf("Input how much rows in masive[1-100]:");
	}
	printf("Input how much columns in masive[1-100]:");
	while (scanf_s("%d", n_col) != 1 || *n_col < MinSize || *n_col>MaxSize || getchar() != '\n')
	{
		printf("Error\n");
		rewind(stdin);
		printf("Input how much columns in masive[1-100]:");
	}
}

void masiveShow(int* m, int n_row, int n_col)
{
	printf("Masive:");
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
			printf("%4d", m[i * MaxSize + j]);
		printf("\n");
		printf("       ");
	}

}

void strNoZero(int* m, int n_row, int n_col)
{
	int cheker=0;
	int row_no_zero=0;
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			if (m[i*MaxSize+j] != 0)
				cheker++;
			if (cheker == n_col)
				row_no_zero++;
		}
		cheker = 0;
	}
	printf("\nThere are %d rows without zeros.\n", row_no_zero);
}

void maxMoreTwo(int* m, int n_row, int n_col)
{
	int max = m[0],cheker=0,min;
	for (int i = 0; i < n_row; i++)
		for (int j = 0; j < n_col; j++)
		{
			if (m[i*MaxSize+j] == max)
				cheker++;
			if (m[i* MaxSize +j] > max)
			{
				max = m[i * MaxSize + j];
				cheker = 0;
				cheker++;
			}

		}
	if (cheker >= 2)
	{
		printf("\nMax element which we can see more than 1 time - %d.\n", max);
	}
	else
	{
		min = m[0];
		for (int i = 0; i < n_row; i++)
			for (int j = 0; j < n_col; j++)
				if (m[i * MaxSize + j] < min)
					min = m[i * MaxSize + j];
		int max_les2 = max;
		cheker = 0;
		for (int k = 0; k < n_row * n_col - 1; k++)
		{
			max = min;
			for (int i = 0; i < n_row; i++)
				for (int j = 0; j < n_col; j++)
				{
					if (m[i * MaxSize + j] == max)
						cheker++;
					if (m[i * MaxSize + j] > max && m[i * MaxSize + j] < max_les2)
					{
						max = m[i * MaxSize + j];
						cheker = 0;
						cheker++;

					}

				}
			if (cheker >= 2)
			{
				printf("\nMax element which we can see more than 1 time - %d.\n", max);
				break;
			}
			else
			{
				cheker = 0;
				max_les2 = max;
			}
		}

	}
	if (cheker == 0)
		printf("There no any number which we can see two or more times.");
}

int main()
{
	int mas[100][100];
	int n_row = 0, n_col = 0,choise=-1;
	choiseFunction(&choise);
	inputSize(&n_row, &n_col);
	if (choise == 0)
	{
		inputMasiveHand(&mas[0][0], n_row, n_col);
	}
	if (choise == 1)
	{
		inputMasiveRandom(&mas[0][0], n_row, n_col);
	}
	masiveShow(&mas[0][0], n_row, n_col);
	strNoZero(&mas[0][0], n_row, n_col);
	maxMoreTwo (&mas[0][0], n_row, n_col);
	return 0;
}