//task 2.1 var 20
#include <stdio.h>
#include <locale.h>
//#include <math.h>
	
int main(int argc, char* argv[])
{
	int r;
	float b;
	double	pi = 3.14,S,s,l,a,v;
	char* locale = setlocale(LC_ALL, "");
	char menu;
	int exit = 0;
	do
	{
		printf("%s\n", "1.���� �������");
		printf("%s\n", "2.������� �����");
		printf("%s\n", "3.������� �������");
		printf("%s\n", "4.����� ����������");
		printf("%s\n", "5.������� ��������");
		printf("%s\n", "6.����� ������");
		printf("%s\n", "7.� ���������");
		printf("%s\n", "8.�����");
		menu = getch();
		switch (menu) {
		case '1':
			system("cls");
			printf("������� ������ �����:");
			scanf("%d", &r);
			printf("R = %d\n", r);
			break;
		case '2':
			S = pi * r * r;
			system("cls");
			printf("������� ����� ����� = %f\n", S);
			break;
		case '3':
			system("cls");
			printf("������� ���� �������:");
			scanf_s("%f", &b);
			s = (pi * r * r * b) / 360;
			printf("������� ������� �����  %f\n", s);
			break;	
		case '4':
			system("cls");
			l =	2 * pi * r;
			printf("����� ���� ����� %f\n", l);
			break;
		case '5':
			system("cls");
			a =  r * 2;
			printf("������� �������� ����� %f\n", a);
			break;
		case '6':
			system("cls");
			v = (pi * r * r * r) / 3;
			printf("����� ������ ����� %f\n", v);
			break; 
		case '7':
			system("cls");
			printf("%s\n", "���� ver. 1.0.0 by Ilya");
			break;
		case '8':
			exit = 1;
			break;
		default:
			system("cls");
			printf("�������� �� 1 �� 8\n");
			break;
		}
	} while (exit != 1);
	
	system("pause");
	return 0;
}