//2.1 (25)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


void vivod(int _a, int _b)
{
	printf("������� �����: \n");
	printf("%d", _a);
	printf("\n-\n");
	printf("%d", _b);
	printf("\n");
	printf("����������: \n");
	float s = 0;
	s = (float)_a / _b;
	printf("%f", s);
	printf("\n");

	printf("������� ������: \n");
	printf("%e", s);
}

void obrvivod(int _a, int _b)
{
	printf("�������� �����: \n");
	printf("%d", _b);
	printf("\n-\n");
	printf("%d", _a);
}

void sokrvivod(int _a, int _b)
{
	printf("����������� �����: \n");
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
	printf("��� ��������� �������� ��������� ����������, �������� ������ 053506.");
}

int main()
{
	begin:
	system("chcp 1251 & cls");
	int a, b;
	int N;

	printf("������� ������������ �����\n");
	scanf_s("%d", &a);
	printf("-\n");
	scanf_s("%d", &b);
	printf("�������� ��������:\n");
	printf("1 - ������� �����.\n");
	printf("2 - ����� ��������� �����.\n");
	printf("3 - ����� ������������ ������������� �����.\n");
	printf("4 - ���������� � ������ � ������ ���������.\n");
	printf("5 - ������ ������ ��� ���.\n");
	printf("6 - ����� �� ���������.\n");

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
			printf("������ �����."); break;
		}
	}
    return 0;
}
