#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	int arr[a][a];
	for (int i = 0; i < a; i++)
	{
		int q = i + 1;
		for (int j = 0; j < a; j++)
		{
			arr[i][j] = q;
			q++;
			if (q > a) q = 1;
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}