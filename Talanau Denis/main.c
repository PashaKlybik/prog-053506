#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>

#define NUM_OF_MATRIX  2
#define NUM_OF_WORDS   3
#define SIZE_0F_WORD   15

int main()
{
	system("chcp 1251");
	system("cls");
	int i, j, k, m, diff = ' ';
	int check = 0;
	char*** matrix;

	matrix = (char***)calloc(NUM_OF_MATRIX, sizeof(char**));
	for (i = 0; i < NUM_OF_MATRIX; i++)
	{
		matrix[i] = (char**)calloc(NUM_OF_WORDS, sizeof(char*));
		printf("Введите массив %d:\n", i + 1);

		for (j = 0; j < NUM_OF_WORDS; j++)
		{
			matrix[i][j] = (char*)calloc(SIZE_0F_WORD, sizeof(char));
			gets(matrix[i][j]);
		}
		putchar('\n');
	}


	for (i = 0; i < NUM_OF_MATRIX; i++)
	{
		for (j = 0; j < NUM_OF_WORDS; j++)
		{
			check = 1;

			for (int k = 0; matrix[i][j][k]; k++)
			{
				for (int m = 0; matrix[i][j][m];  m++)
				{
					if (matrix[i][j][k] == matrix[i][j][m] && k!=m)
						check = 0;
				}
			}

			if (!check)
			{
				for (int k = 0; matrix[i][j][k]; k++)
					if (matrix[i][j][k] >= 'A' && matrix[i][j][k] <= 'Z')
						matrix[i][j][k] += diff;
			}
			else
			{
				for (int k = 0; matrix[i][j][k]; k++)
					if (matrix[i][j][k] >= 'a' && matrix[i][j][k] <= 'z')
						matrix[i][j][k] -= diff;
			}
		}
	}

	printf("-----------------------------\nМассивы после преобразования:\n");
	for (i = 0; i < NUM_OF_MATRIX; i++)
	{
		printf("\nArray %d:\n", i + 1);
		for (j = 0; j < NUM_OF_WORDS; j++)
		{
			puts(matrix[i][j]);
		}
		putchar('\n');
	}

	for (i = 0; i < NUM_OF_MATRIX; i++)
	{
		for (j = 0; j < NUM_OF_WORDS; j++)
		{
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);

	getchar();
	return 0;
}
