//task 2.2 var 6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double factorial(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (double)(n * factorial(n - 1));
}

int result(int x, double e)
{
	int n = 0;
	double sum = 0;

	do {
		n++;
		sum += pow(-1, n - 1) * (pow(x, 2 * n - 1) / factorial(2 * n - 1));
	} while (fabs(sin(x) - sum) >= e);
	return n;
}

int main()
{
	char* locale = setlocale(LC_ALL, "");
	double eps, x; 
	printf("________________________________________________________________________________________________________________________\n");
	printf("Введите x: ");
	scanf("%lf", &x);
	printf("________________________________________________________________________________________________________________________\n");
	printf("Введите погрешность: ");
	scanf("%lf", &eps);
	printf("________________________________________________________________________________________________________________________\n");
	printf("Переменная n равна %d", result(x, eps));
	return 0;
}