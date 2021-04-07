#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//24 (3.2)
int main()
{
	int m, n;
	printf("Enter m,n\n");
	scanf_s("%d", &m);
	scanf_s("%d", &n);

	int**A = new int*[m];
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
	}
	
	int a = -1, b, itog = 1;
	int max = m * n;
	int left = -1, right = n - 1, top = 0, bot = m - 1;

	while (left <= right && top <= bot)
	{
		for (b = ++left; b <= right && itog <= max; b++)
		{
			A[a + 1][b] = itog++;
		}
		for (a = ++top; a <= bot && itog <= max; a++)
		{
			A[a][b - 1] = itog++;
		}
		for (b = --right; b >= left && itog <= max; b--)
		{
			A[a - 1][b] = itog++;
		}
		for (a = --bot; a >= top && itog <= max; a--)
		{
			A[a][b + 1] = itog++;
		}
	}
		for (a = 0; a < m; a++)
		{
			for (b = 0; b < n; b++)
			{
				printf("%3d", A[a][b]);
			}
			printf("\n");
		}

		for (int i = 0; i <m; i++)
		{
			delete[] A[i];
		}
		delete[] A;
}


