#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

int M = 4, N = 25;

void create(int** arr)
{
	for (int i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void print(int** arr)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n\n");
	}
}

bool check(int** arr, int j, int k)
{
	int* str1 = (int*)malloc(M * sizeof(int));
	int* str2 = (int*)malloc(M * sizeof(int));
	bool pohoj = 0;
	
	for (int i = 0; i < M; i++)
	{
		str1[i] = arr[i][j];
		str2[i] = arr[i][k];
	}
	for (int i = 0; i < M; i++)
		if (str1[i]!=str2[i])
		{
			pohoj = 1;
			break;
		}
	if (!pohoj)return 0;
	for (int x = 0; x < M; x++)
		for (int y = 0; y < M; y++)
			if (str1[x] == str2[y]&& str1[x] != -1)
				str1[x] = str2[y] = -1;
	for (int x = 0; x < M; x++)
		if (str1[x] != -1)pohoj = 0;
	return pohoj;

}

void result(int** arr)
{
	for (int j = 0; j < N; j++)
		for (int k = 1 + j; k < N; k++)
			if (check(arr, j, k))
			{
				printf("[%d] [%d]\n", j + 1, k + 1);
				for (int l = 0; l < M; l++)
				{
					printf(" %d    %d\n", arr[l][j], arr[l][k]);
				}
				printf("\n\n");
			}
}

int main()
{
	srand(time(NULL));
	int** arr = (int**)malloc(M * sizeof(int*));
	create(arr);
	print(arr);
	result(arr);
	return 0;
}