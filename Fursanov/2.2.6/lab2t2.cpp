#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <cmath>

#define M_PI       3.14159265358979323846

double stfakt(double x, int n)		// объединённая функция факториала и степени
{
	double fakt = 1;
	for (int i = 1; i <= n; i++)
	{
		fakt *= x / i;
	}
	return fakt;
}

int minus(int i)
{
	if (i % 2 == 1)return 1;
	else return -1;
}

double sinus(double x, int n)
{
	while (x > 2 * M_PI)
		x -= 2 * M_PI;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += minus(i) * stfakt(x, 2 * i - 1);
	}
	return ans;
}

double ABS(double a, double b)
{
	if (a - b > 0)return (a - b);
	else return (b - a);
}

int main()
{
	setlocale(LC_ALL, "Russian");   
	double x=0,e=0;
	printf("Введите угол x (в радианах) : ");
	while (scanf_s("%lf", &x) == 0)
	{
			printf("Некорректный ввод. попробуйте ещё раз \n");
			while (getchar() != '\n') {}
			printf("Введите угол x (в радианах) : ");
	}
	printf("Введите погрешность: ");
	while (e < 0.000000000000001)
	{
		while (scanf_s("%lf", &e) == 0)
		{
			printf("Некорректный ввод. попробуйте ещё раз \n");
			while (getchar() != '\n') {}
			printf("Введите погрешность: ");
		}
	}
	printf("\n");
	int i;
	for ( i = 1; ABS(sin(x),sinus(x, i)) > e; i++);
	printf("sin(%lf) = %.16lf                  моя функция\n", x, sinus(x,i));
	printf("sin(%lf) = %.16lf           функция библиотеки\n", x, sin(x));
	printf("для заданной погрешности e=%.15lf n=%d",e,i);
	return 0;
}