// Task 2.2. Variant 6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double fact(double number)
{
	double n = 1;
	while (number > 1)
	{
		n *= number--;
	}
	return n;
}

double rec(double x, double tmp, double err, double* n)
{
	double a = (pow(-1, (*n) - 1) * (pow(x, 2 * (*n) - 1) / fact(2 * (*n) - 1)));
	tmp += a;
	(*n)++;
	if (fabs(a) < err)
	{
		return tmp;
	}
	return rec(x, tmp, err, n);
}

int main()
{
	double err, x;
	printf("Enter the acceptable error: ");
	scanf_s("%lf", &err);
	double res = 0;
	double exp = 0;
	do
	{
		printf("\nx =  ");
		scanf_s("%lf", &x);
		double n = 1;
		do
		{
			exp = (pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1)));
			res += exp;
			n++;
		} while (fabs(exp) > err);
		exp = 0;
		printf("sin(x) = %.10lf  %.10lf while n = %.0lf\n", sin(x), res, n - 1);
		n = 1;
		res = rec(x, exp, err, &n);
		printf("Recursive = %.10lf while n = %.0lf", res, n - 1);
	} while (1);
}