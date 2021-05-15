//task 1.2 var 10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <locale.h>
void main(void)
{
	char* locale = setlocale(LC_ALL, "");
	int n, k, i;
	double f, sum = 0, p = 1;
	printf("¬ведите количество слагаемых: ");
	scanf("%d", &n);
	printf("¬ведите вещественное число f: ");
	scanf("%lf", &f);
		for (int i = 1; i <= n; i++)
		{
			 sum = 0;
			for (int k = 0; k <= i; k++)
			{
				sum += (f + k);
			}
			p *= 1 / sum;
		}
	printf("\np = %lg", p);
}