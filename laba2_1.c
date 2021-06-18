#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Menu(int tag1, int tag2) {
	printf("Меню: \n*Пицца с ветчиной и грибами : %dруб.\n*Пицца с ветчиной и овощами : %dруб.\n\n", tag1, tag2);
}
void Profit(int clients, float standart_pizza, float veg_pizza) {
	int profit = ((clients / 2) * standart_pizza) + ((clients / 2) * veg_pizza);
	printf("Прибыль составляет: %dруб.", profit);
}
void program_info() {
	printf("Версия: Capri Pizza Planning 1.0 (2021)\n");
	printf("Автор: Калинина Екатерина\n");
}

void Ingridients(int meat, int mushrooms, int veg, int torment, int clients) {
	int full_meat, full_mushrooms, full_veg, full_torment, spez_torment;
	full_meat = meat * clients;
	full_torment = torment * clients;
	full_veg = veg * (clients / 2);
	full_mushrooms = mushrooms * (clients / 2);
	spez_torment = full_torment * 1.5;
	printf("\n\nЧтобы нам накормить посетителей нам понадобится\n\n1.Ветчины: %dг. (%dруб.)\t2.Муки: %dг. (%dруб.)\n3.Овощей: %dг. (%dруб.)\t4.Грибов: %dг. (%dруб.)\n ", full_meat, full_meat * 7, full_torment, spez_torment, full_veg, full_veg * 3, full_mushrooms, full_mushrooms * 10);
}

int main() {
	system("chcp 1251 & cls");
	int working_time, clients = 0, meat = 700, mushrooms = 800, veg = 450, torment = 225, act = 0;

	float standart_pizza = 4.5 * (torment + mushrooms + meat), veg_pizza = 4.5 * (torment + mushrooms + veg);
	printf("Введите время работы\n 1 - Утро(9:00-13:00)\t2 - Обед(13:00-18:00)\t3 - Вечер(18:00-23:00)\n");
	scanf_s("%d", &working_time);

	while (working_time != 1 && working_time != 2 && working_time != 3) {
		printf("Ошибка!\nВведите время работы\n 1 - Утро(9:00-13:00)\t2 - Обед(13:00-18:00)\t3 - Вечер(18:00-23:00)\n");
		scanf_s("%d", &working_time);
	}

	if (working_time == 1) {
		clients = 30;
	}
	else if (working_time == 2) {
		clients = 90;
	}
	else if (working_time == 3) {
		clients = 240;
	}

	while (1) {
		printf("\n\n1.Вывести стоимость пицц.\n2.Расчет прибыли за интервал.\n3.Количество посетителей.\n4.Расчет ингридиентов.\n5. Информация о программе.\n6.Выход из программы\n");

		scanf_s("%d", &act);

		while (act != 1 && act != 2 && act != 3 && act != 4 && act != 5 && act != 6) {
			printf("Ошибка!\n1.Вывести стоимость пицц.\n2.Расчет прибыли за интервал.\n3.Количество посетителей.\n4.Расчет ингридиентов.\n5. Информация о программе.\n6.Выход из программы\n");
			scanf_s("%d\n>", &act);
		}
		switch (act) {
		case 1:
			Menu(standart_pizza, veg_pizza);
			break;
		case 2:
			Profit(clients, standart_pizza, veg_pizza);
			break;
		case 3:
			printf("%d - Посетителей будет", clients);
			break;
		case 4:
			Ingridients(meat, mushrooms, veg, torment, clients);
			break;
		case 5:
			program_info();
			break;
		case 6:
			printf("\n");
			return 0;
		}
	}
}