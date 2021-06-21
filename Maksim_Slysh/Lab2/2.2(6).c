//lab2.2 var6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fact(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (double)(n * fact(n - 1));
}

int main()
{
	int n=0;
	double e, x,sum=0;
	printf("Enter x:");
	scanf_s("%lf", &x);
    printf("Enter epsilon:");
	scanf_s("%lf", &e);
    do {
		n++;
		sum += pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
	} while (fabs(sin(x) - sum) >= e);
    printf("n = %d", n);
	return 0;
}