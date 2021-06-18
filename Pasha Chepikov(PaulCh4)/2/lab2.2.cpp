#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Sin_N(double x, double e) {
	double left = sin(x);
	double right = x;
	printf("%lf\t%lf\n", left, right);
	int n = 2, fact = 1;
	while (fabs(left - right) >= e) {
		fact *= (2*n - 1) * (2*n - 2);
		right += pow((-1), n - 1) * pow(x, (2 * n - 1)) / fact;
		printf("%lf\t%lf\n", left, right);
		n++;
	}
	return n - 1;
}

int Sin_R(double x, double e, int fact, int n, double right) {
	printf("%lf\t%lf\n", sin(x), right);
	if (fabs(sin(x) - right) >= e) {
		fact *= (2 * n - 1) * (2 * n - 2);
		right += pow((-1), n - 1) * pow(x, 2 * n - 1) / fact;
		n = Sin_R(x, e, fact, n + 1, right);
	}
	return n;
}

int main() {
	double x, e;
	int menu = 0;
	while (menu != 9) {
		printf("[0] -> Interation function\n[1] -> Recursive function\n\nYour Choice: "); scanf_s("%d", &menu);
		switch (menu)
		{
			case 0: {
				system("cls");
				printf("Input var x: "); scanf_s("%lf", &x);
				printf("\nInput infelicity: "); scanf_s("%lf", &e);
				system("cls");
				printf("Left expression:\tRight expression\n");
				printf("n = %d\n", Sin_N(x, e));
				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				printf("Input var x: "); scanf_s("%lf", &x);
				printf("\nInput infelicity: "); scanf_s("%lf", &e);
				system("cls");
				printf("Left expression:\tRight expression\n");
				printf("n = %d\n", Sin_R(x, e, 1, 2, x) - 1);
				system("pause");
				system("cls");
				break;
			}
			default: system("cls");
				break;
		}
	}
}