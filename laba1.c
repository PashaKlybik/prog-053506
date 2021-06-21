#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	system("chcp 1251");
	system("cls");
	float chislo;
	int rub, kop;
	printf("ведите число : ");
	scanf_s("%f", &chislo);
	rub = (int)chislo;
	kop = (100 * (chislo - rub));
	printf("%d рублей ", rub);
	printf("%d копеек", kop);
	return 0;
}