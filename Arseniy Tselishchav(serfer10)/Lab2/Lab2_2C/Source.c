#include <stdio.h>
#include <math.h>
#include <conio.h>

long int Factorial(int n);

void Iterat(float x, float e, double sum,int n)
{
	while (fabs(sin(x) - sum) > e)
	{
		n++;
		sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / Factorial(2 * n - 1);
	}
	printf("sum: %lf\n", sum);
	printf("sin(x): %f\n", sin(x));
	printf("n: %d\n", n);
}

int Recursive(double x, double e, int n, double sum) 
{
	if (fabs(sin(x) - sum) < e) {
		printf("sum = %lf.\nSin(x) = %lf.\n", sin(x), sum);
		return n;
	}
	n++;
	sum += pow(-1, n - 1) * pow(x, 2 * n - 1) / Factorial(2 * n - 1);
	return Recursive(x, e, n, sum);
}

int main()
{
	float x;
	float e;
	int n=0;
	double expression=0;
	printf("Enter X: ");
	scanf_s("%f", &x);
	printf("Enter E: ");
	scanf_s("%f", &e);
	Iterat(x, e, expression, n);
	printf("Recursive:\n");
	printf("n:%d", Recursive(x, e, n, expression));
	return 0;
}

long int Factorial(int n)
{
	if (n < 0) return 0;

	if (n == 0) return 1;

	else return n * Factorial(n - 1);
}