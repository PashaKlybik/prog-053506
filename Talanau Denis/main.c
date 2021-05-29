#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>


int factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * factorial(num - 1);
}

void Foo1(double x, double E)
{
	double c = 0;
	for (int n = 1; n <= 20; n++)
	{
		c += pow(-1, (n - 1)) * pow(x, 2 * n - 1) / factorial(2 * n - 1);
		//printf("\n%lf", c);

		if (sin(x) - c < E && sin(x) - c > -E)
		{
			printf("\n��� n = %d  ��������� ���������� ����� ��� �� � = %lf\n", n, E);
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
	Foo1(x, E);
}
