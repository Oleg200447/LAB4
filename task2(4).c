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

void inputMasiveHand(int* m, int n_row,int n_col)
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

void inputMasiveRandom(int* m, int n_row,int n_col)
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

void inputSize(int* n_row,int *n_col)
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

void masiveShow(int* m, int n_row,int n_col)
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

void masiveShowRes(int* m, int n_row, int n_col)
{
	printf("\nResult:");
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
			printf("%4d", m[i * MaxSize + j]);
		printf("\n");
		printf("       ");
	}

}

int findRow(int* m, int n_row, int n_col)
{
	int cheker = 0;
	int row = -1;
	
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 1; j < n_col; j++)
			if (m[i*MaxSize+j] < m[i * MaxSize + (j-1)])
			{
				cheker++;

			}
		if (cheker == n_col - 1)
		{
			row = i;
			break;
		}
		cheker = 0;
	}
	return row;
}

void changer(int* m, int row, int n_col)
{
	int num,col=0;
	for (int j = n_col; j > n_col / 2; j--)
	{
		num = m[row * MaxSize + col];
		m[row * MaxSize + col] = m[row * MaxSize + (j - 1)];
		m[row * MaxSize + (j - 1)] = num;
		col++;
	}

}

int main()
{
	int mas[MaxSize][MaxSize];
	int n_row=0,n_col=1,choise=-1;		
	choiseFunction(&choise);
	inputSize(&n_row,&n_col);
	if (choise == 0)
	{
		inputMasiveHand(&mas[0][0], n_row,n_col);
	}
	if (choise == 1)
	{
		inputMasiveRandom(&mas[0][0], n_row,n_col);
	}
	masiveShow(&mas[0][0],n_row,n_col);
	int row = findRow(&mas[0][0], n_row, n_col);
	if (row != -1)
	{
		printf("\nRow number:%d\n", row + 1);
	}
	changer(&mas[0][0], row, n_col);
    masiveShowRes(&mas[0][0], n_row, n_col);
	return 0;
}