#include <stdio.h>
#include <math.h>
#include <conio.h>

long int factorial(int n);

int main()
{
	float x;
	float e;
	int n=0;
	long float expression=0;
	printf("Enter X: ");
	scanf_s("%f", &x);
	printf("Enter E: ");
	scanf_s("%f", &e);

	do
	{
		n++;
		float upExp = 2*n - 1;
		expression += pow(-1, n-1) * (pow(x, upExp)) / factorial(2 * n - 1);
	} while (fabs(sin(x)-expression) > e);

	printf("n: %d", n);
	return 0;
}

int factorial(int Exp)
{
	if (Exp <= 2)
		return Exp;
	else
		return Exp * factorial( Exp -1);
}