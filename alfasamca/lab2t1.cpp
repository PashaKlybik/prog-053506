//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <windows.h>

void sell(int win, int bal, int fl)
{
	system("cls");
	float area1 = 2.15 * 1.50;
	float area2 = 0.70 * 2.15;
	float cost1 = 100;
	float cost2 = 150;
	printf("общая площадь застекления: %.2fм.кв. \n", (win * area1 + bal * area2));
	printf("стоимость застекления окон: %.2f$ за окно (2,15 на 1,50 м)\n", cost1);
	printf("стоимость балконной двери: %.2f$ за окно (0,70 на 2,15 м)\n", cost2);
	if (fl > 1)
		printf("процентная надбавка: 15%%\n");
	else
		printf("процентная надбавка: 0%%\n");
	printf("для выхода нажмите любую кнопку\n");
	getchar();
	getchar();
}

void kont()
{
	system("cls");
	printf("краткая иформация:\nМы уже более 2547 лет занимаемся установкой окон по всему миру и Азербайджану.\n Ежегодно мы являемся победителями соревнований по установке окон в Махачкале.\n Наши сотрудники приветливы и добры к нашим клиентам. Выбирайте нас, и вы не пожалеете.\n");
	printf("контакты:\nНаш телефон 77-88 нам звонят и окна просят \n");
	printf("для выхода нажмите любую кнопку\n");
	getchar();
	getchar();
}

void cost(int win, int bal, int fl)
{
	system("cls");
	float cost1 = 100;
	float cost2 = 150;
	if (fl > 1)
		printf("общая стоимость проекта %.2f$\n", ((win * cost1 + bal * cost2) * 1.15));
	else
		printf("общая стоимость проекта %.2f$\n", (win * cost1 + bal * cost2) * 1);
	printf("для выхода нажмите любую кнопку\n");
	getchar();
	getchar();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Здравствуйте, мы компания по установке окон Air Comfort\n");
	int window;
	int balcony;
	int floor;
	printf("введите количество окон, которые хотите установить\n");
	while (scanf("%d", &window) <= 0 || window < 0)
	{
		printf("Некорректный ввод. попробуйте ещё раз \n");
		while (getchar() != '\n') {}
	}
	printf("введите количество балконов\n");
	while (scanf("%d", &balcony) <= 0 || window < 0)
	{
		printf("Некорректный ввод. попробуйте ещё раз \n");
		while (getchar() != '\n') {}
	}
	printf("введите этаж\n");
	while (scanf("%d", &floor) <= 0 || window < 0)
	{
		printf("Некорректный ввод. попробуйте ещё раз \n");
		while (getchar() != '\n') {}
	}
	int button = 1;
	while (button)
	{

		system("cls");
		printf("введите нужную цифру чтобы:\n1. Расчёт и вывод параметров проекта.\n2. Вывод общей стоимости проекта.\n3. краткая информация о компании и контакты.\n4.Выход.\n");
		printf("кнопка: ");
		while (scanf("%d", &button) <= 0)
		{
			printf("Некорректный ввод. попробуйте ещё раз \n");
			while (getchar() != '\n') {}
			printf("кнопка: ");
		}
		printf("\n");
		switch (button)
		{
		case 1:
			sell(window, balcony, floor);
			break;
		case 2:
			cost(window, balcony, floor);
			break;
		case 3:
			kont();
			break;
		case 4:
			printf("Спасибо что выбрали нас");
			button = 0;
			break;
		default:
			printf("такой кнопки нет");
			break;
		}
	}

	return 0;
}