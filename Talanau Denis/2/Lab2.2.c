#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>



int factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
		return num * factorial(num - 1);
}

int Recursion(double x, double E , double c , int n )
{
	if (sin(x) - c < E && sin(x) - c > -E)
	{
		printf("\n��� n = %d  ��������� sin(x) = %lf ���������� ����� ��� �� � = %lf\n", n - 1, c, E);
		return n;
	}

	c = c + pow(-1, n - 1) * pow(x, 2 * n - 1) / factorial(2 * n - 1);
	//printf("\n%lf", c);
	n++;
	return Recursion(x, E, c, n);
}

void Iteration(double x, double E, double c)
{

	for (int n = 1; n <= 20; n++)
	{
		c += pow(-1, (n - 1)) * pow(x, 2 * n - 1) / factorial(2 * n - 1);
		//printf("\n%lf", c);

		if (sin(x) - c < E && sin(x) - c > -E)
		{
			printf("\n��� n = %d  ��������� sin(x) = %lf ���������� ����� ��� �� � = %lf\n", n,c, E);
			break;
		}
		if (n == 20)
		{
			printf("\n��� ������� �������� �� ���������� ����� �����������\n");
		}
	}
}

int main()
{
	setlocale(0, "rus");
	double x, E;
	printf("������� x: ");
	scanf_s("%lf", &x);
	printf("������� ����������� E: ");
	scanf_s("%lf", &E);
	printf("sin(x) = %lf\n", sin(x));
	printf("\n������������ �����:\n");
	Iteration(x, E, 0);
	printf("\n����������� �����:\n");
	Recursion(x, E, 0, 1);
}
