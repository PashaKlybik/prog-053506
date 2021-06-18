//3.2(12)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 1;
	while (1)
	{
		printf("Enter the number N: "); scanf("%d", &n);
		if (n > 0)
		{
			int** array = (int**)malloc(n * sizeof(int*));
			for (int i = 0; i < n; i++)
				array[i] = (int*)malloc(n * sizeof(int));
			for (int i = 0; i < n; i++)
			{
				int tmp = i + 1;
				for (int j = 0; j < n; j++)
				{
					array[i][j] = tmp;
					tmp++;
					if (tmp > n)
						tmp = 1;
				}
			}
			printf("Latin square of order %d: \n", n);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%d\t", array[i][j]);
				}
				printf("\n");
			}
			for (int i = 0; i < n; i++)
				free(array[i]);
			free(array);
			return 0;
		}
		else
		{
			printf("The N number must be greater than 0\n");
		}
	}
}