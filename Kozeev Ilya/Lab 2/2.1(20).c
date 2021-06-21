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
		printf("%s\n", "1.Ввод радиуса");
		printf("%s\n", "2.Площадь круга");
		printf("%s\n", "3.Площадь сектора");
		printf("%s\n", "4.Длина окружности");
		printf("%s\n", "5.Сторона квадрата");
		printf("%s\n", "6.Объём конуса");
		printf("%s\n", "7.О программе");
		printf("%s\n", "8.Выход");
		menu = getch();
		switch (menu) {
		case '1':
			system("cls");
			printf("Введите радиус круга:");
			scanf("%d", &r);
			printf("R = %d\n", r);
			break;
		case '2':
			S = pi * r * r;
			system("cls");
			printf("Площадь круга равна = %f\n", S);
			break;
		case '3':
			system("cls");
			printf("Введите угол сектора:");
			scanf_s("%f", &b);
			s = (pi * r * r * b) / 360;
			printf("Площадь сектора равна  %f\n", s);
			break;	
		case '4':
			system("cls");
			l =	2 * pi * r;
			printf("Длина дуги равна %f\n", l);
			break;
		case '5':
			system("cls");
			a =  r * 2;
			printf("Сторона квадрата равна %f\n", a);
			break;
		case '6':
			system("cls");
			v = (pi * r * r * r) / 3;
			printf("Объём конуса равен %f\n", v);
			break; 
		case '7':
			system("cls");
			printf("%s\n", "Круг ver. 1.0.0 by Ilya");
			break;
		case '8':
			exit = 1;
			break;
		default:
			system("cls");
			printf("Выберите от 1 до 8\n");
			break;
		}
	} while (exit != 1);
	
	system("pause");
	return 0;
}