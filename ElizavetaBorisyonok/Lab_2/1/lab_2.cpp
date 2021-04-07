﻿//2.1 (25)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


void vivod(int _a, int _b)
{
	printf("Обычная дробь: \n");
	printf("%d", _a);
	printf("\n-\n");
	printf("%d", _b);
	printf("\n");
	printf("Десятичная: \n");
	float s = 0;
	s = (float)_a / _b;
	printf("%f", s);
	printf("\n");

	printf("Научный формат: \n");
	printf("%e", s);
}

void obrvivod(int _a, int _b)
{
	printf("Обратная дробь: \n");
	printf("%d", _b);
	printf("\n-\n");
	printf("%d", _a);
}

void sokrvivod(int _a, int _b)
{
	printf("Сокращенная дробь: \n");
	int i;
	if (_a < _b)
	{
		i = _a;
	}
	else
	{
		i = _b;
	}
	for (; i > 0; i--)
	{
		if (_a % i == 0 && _b % i == 0)
		{
			_a /= i;
			_b /= i;
		}
	}
	printf("%d", _a);
	printf("\n-\n");
	printf("%d", _b);
}

void informat(void)
{
	printf("Эта программа написана Борисенок Елизаветой, учащейся группы 053506.");
}

int main()
{
	begin:
	system("chcp 1251 & cls");
	int a, b;
	int N;

	printf("Введите рациональную дробь\n");
	scanf_s("%d", &a);
	printf("-\n");
	scanf_s("%d", &b);
	printf("Выберите действие:\n");
	printf("1 - Вывести число.\n");
	printf("2 - Вывод обратного числа.\n");
	printf("3 - Вывод сокращенного рационального числа.\n");
	printf("4 - Информация о версии и авторе программы.\n");
	printf("5 - Ввести данные еще раз.\n");
	printf("6 - Выход из программы.\n");

	int operat = 5;
	while (operat != 3)
	{

		printf("\n----------------------\n");
		scanf_s("%d", &N);
		printf("----------------------\n");
		switch (N)
		{
		case 1:
			vivod(a, b); break;
		case 2:
			obrvivod(a, b);  break;
		case 3:
			sokrvivod(a, b);  break;
		case 4:
			informat(); break;
		case 5:
			system("cls"); goto begin; break;
		case 6:
			exit(0);
		default:
			printf("Ошибка ввода."); break;
		}
	}
}

