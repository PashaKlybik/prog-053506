#include <stdio.h>
#include <conio.h>
#include <math.h>

void CheckTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void BiggestSide(double* a, double* b, double* c);

int main()
{
	printf("Enter cordinates 1,2,3\n");
	int x1, y1;
	int x2, y2;
	int x3, y3;

	printf("X1,Y1 ");
	scanf_s("%d", &x1);
	scanf_s("%d", &y1);
	printf("X2,Y2 ");
	scanf_s("%d", &x2);
	scanf_s("%d", &y2);
	printf("X3,Y3 ");
	scanf_s("%d", &x3);
	scanf_s("%d", &y3);
	CheckTriangle(x1, y1, x2, y2, x3, y3);

	return 0;
}

void BiggestSide(double* a, double* b, double* c)
{
	double buf;
	if (*a > *b || *a == *b)
	{
		if (*a > *c)
		{
			buf = *c;
			*c = *a;
			*a = buf;
		}
	}
	else
	{
		if (*b > *c)
		{
			buf = *c;
			*c = *b;
			*b = buf;
		}
	}
}

void CheckTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double sideA;
	double sideB;
	double sideC;
	sideA = sqrt(pow(abs(x2 - x1), 2.) + pow(abs(y2 - y1), 2.));
	sideB = sqrt(pow(abs(x3 - x2), 2.) + pow(abs(y3 - y2), 2.));
	sideC = sqrt(pow(abs(x3 - x1), 2.) + pow(abs(y3 - y1), 2.));
	BiggestSide(&sideA, &sideB, &sideC);
	printf("%lf,%lf,%lf\n", sideA, sideB, sideC);
	if (sideA + sideB > sideC && sideB + sideC > sideA && sideA + sideC > sideB)
	{
		if (pow(sideA, 2) + pow(sideB, 2) == pow(sideC, 2))
		{
			printf("This is Rectangle\n");
		}
		else
		{
			if (sideA == sideB || sideA==sideC || sideC == sideB)
				printf("Two same sides int Rectangle\n");
			else
				printf("This is random Triangle\n");
		}

		int str;
		double per = sideA + sideB + sideC;
		printf("1. Perimetr\t2. Triangle area\t3.Version and author\telse.exit\n");
		scanf_s("%d", &str);
		switch (str)
		{
		case 1: printf("Perimetr: %lf",per); break;
		case 2:	printf("Area : %lf", sqrt(per / 2 * (per / 2 - sideA) * (per / 2 - sideB) * (per / 2 - sideC))); break;
		case 3: printf("Version 2.1\nTselishchav Arseniy 053506"); break;
		default:break;
		}
	}
	else
		printf("No Triangle");
}

