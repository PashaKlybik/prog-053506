#include <iostream>
#include <math.h>
int factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}
int main()
{
	double x, nx, Sum=0;
	int n = 0;
	printf("input x: ");
	scanf_s("%f", &x);
	printf("input pogreshnost nx: ");
	scanf_s("%f", &nx);
	do 
	{
		n++;
		double znak = pow(-1, n - 1);
		double chisl = pow(x, 2 * n - 1);
		double znam = factorial(2 * n - 1);
		Sum += znak*(chisl / znam);
	} 	while (fabs(sin(x) - Sum) >= nx);
	printf("%d", n);
}