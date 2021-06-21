// Lab2.2 Variant(6)
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
int GetResultIteration(int x, double e,double* val) {
	int n = 0;
	do{
		n++;
		*val+= pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
	} while (fabs(sin(x) - *val) >= e);
	return n;
}
int GetResultRecursion(int x, double e,int n,double* val2) {
	*val2 += pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
	if (fabs(sin(x) - *val2) < e) {
		return n;
	}
	n++;
	return GetResultRecursion(x,e,n,val2);
}
int fact(int n) 
{
	if (n < 0) 
		return 0;
	if (n == 0) 
		return 1;
	else 
		return n * fact(n - 1);
}
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		int x=0;
		double e=0.001;
		double val = 0;
		double val2 = 0;
		int n = 1;
		printf("Введите x: ");
		scanf_s("%d", &x);
		printf("e = 0.001\n");
		int num1 = GetResultIteration(x, e, &val);
		int num2 = GetResultRecursion(x, e, n, &val2);
		printf("1.Итерация\nУсловие выполняется при n= %d\nsin(x)=%lf\nsin(x)=%lf\n", num1, sin(x), val);
		printf("1.Рекурсия\nУсловие выполняется при n = % d\nsin(x) = % lf\nsin(x) = % lf\n", num2, sin(x), val2);
		printf("\n\nНажмите Esc, чтобы выйти.\n");
		if (getch() == 27) {
			return 0;
		}
		system("cls");
	}
}

