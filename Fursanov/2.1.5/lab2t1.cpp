#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void sell(int Veg, float* mas, int* prise, float* cost)
{
	if (Veg == 0)
		printf("Цена/кг картофеля 500р\n");
	if (Veg == 1)
		printf("Цена/кг моркови 1000р\n");
	if (Veg == 2)
		printf("Цена/кг свёклы 700р\n");
	if (mas[Veg] == 0)
	{
	}
	mas[Veg] = 0;
		printf(" Заказать(кг): ");
		while (scanf("%f", &mas[Veg]) <= 0)
		{
			printf("Некорректный ввод. попробуйте ещё раз \n");
			while (getchar() != '\n') {}
			printf(" Заказать(кг): ");
		}
		printf("Заказ принят\n");
		printf("\n");
		cost[Veg] = mas[Veg] * prise[Veg];

}

void shopping_cart(float* mas, int* prise, float* cost)
{
	printf("Корзина\n");
	printf("Картофель:\n\tцена: %dруб.\n\tзаказано: %.2fкг.\n\tстоимость: %.0fруб\n", prise[0], mas[0], cost[0]);
	printf("Морковь:\n\tцена: %dруб.\n\tзаказано: %.2fкг.\n\tстоимость: %.0fруб\n", prise[1], mas[1], cost[1]);
	printf("Свёкла:\n\tцена: %dруб.\n\tзаказано: %.2fкг.\n\tстоимость: %.0fруб\n\n", prise[2], mas[2], cost[2]);
}

void Cost(float* mas, int* prise, float* cost)
{
	int discount = 0;
	printf("итого:\n");
	printf("\tкартофель: %.0fруб.\n",cost[0]);
	printf("\tморковь: %.0fруб.\n", cost[1]);
	printf("\tсвёкла: %.0fруб.\n", cost[2]);
	printf("\tдоставка: 15000 руб.\n");
	if (mas[0] + mas[1] + mas[2] > 10)
		discount = 10;
	if (mas[0] + mas[1] + mas[2] > 25)
		discount = 20;
	if (mas[0] + mas[1] + mas[2] > 50)
		discount = 30;
	float finaly = (cost[0] + cost[0] + cost[0] + 15000) * (100 - discount) / 100;
	printf("\tскидка %d%%\n",discount);
	printf("____________________________________________________________________\n");
	printf("(%.0fруб. + %.0fруб. + %.0fруб. + 15000руб.) - %d%% = %.2fруб.\n\n", cost[0], cost[1], cost[2],discount,finaly);

}

void feedback()
{
	printf("\tНазвание магазина: eVegetables\n");
	printf("\tНомер лицензии: 52426\n");
	printf("\tКонтактная информация:\n\t\tТелефон: 8-800-555-35-35\n\t\tМы в Одноклассниках: eVegetables.Ок.by\n\t\tПочта: eVegetables@mail.by\n\n");
}

int main()
{
	float* mas = (float*)malloc(3 * sizeof(float));
	int* prise = (int*)malloc(3 * sizeof(int));
	float* cost = (float*)malloc(3 * sizeof(float));
	prise[0] = 500;
	prise[1] = 1000;
	prise[2] = 700;
	mas[0] = 0;
	mas[1] = 0;
	mas[2] = 0;
	cost[0] = 0;
	cost[1] = 0;
	cost[2] = 0;

	setlocale(LC_ALL, "Russian");
	printf("Вас приветствует торговое предприятие eVegetables\n");
	int button = 1;
	while (button)
	{
		printf("введите нужную цифру чтобы:\n1. Заказать картофель.\n2. Заказать морковь.\n3. Заказать свёклу.\n4. Корзина.\n5. Расчёт стоимости заказа.\n6. Обратная связь.\n7.Выход.\n");
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
			sell(button-1, mas, prise, cost);
			break;
		case 2:
			sell(button - 1, mas, prise, cost);
			break;
		case 3:
			sell(button - 1, mas, prise, cost);
			break;
		case 4:
			shopping_cart(mas, prise, cost);
			break;
		case 5:
			Cost(mas, prise, cost);
			break;
		case 6:
			feedback();
			break;
		case 7:
			printf("Благодарим вас за посещение нашего магазина");
			button = 0;
			break;
		default:
			printf("такой кнопки нет");
			break;
		}

	}

	return 0;
}
