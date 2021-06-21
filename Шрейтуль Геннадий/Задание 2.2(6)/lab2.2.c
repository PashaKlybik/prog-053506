//2.2(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	float x, Y;
	int n, a;
	printf("Enter the number (n) of members of the series: "); scanf("%d", &n);
	printf("The number of numbers from which we count the function: "); scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		printf("\nEnter X: "); scanf("%f", &x);
		float S = 0; int f = 1;
		for (int k = 0; k <= n; k++)
		{
			f = f * (2 * k + 1); S = S + pow(-1, k) * pow(x, 2 * k + 1) / f;
		}
		Y = sin(x);
		printf("S(x)=%f", S); printf("   Y(x)=%f", Y);
	}
	return 0;
}