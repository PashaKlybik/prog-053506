#include <stdio.h>
#include <math.h>

void Menu() {
	printf("\nМеню шара:\n1. Ввести радиус\n2. Вывести площадь поверхности\n3. Вывести объема\n4. Вывести длину ребра вписанного правильного тетраэдра\n5. Вывести площади сечения, проведенного на расстоянии k от центра шара\n6. Выход\n");
}

int main() {
	system("chcp 1251");
	int value = 0;
	int radius = 1;
	int k = 0;
	while (1){
		Menu();
		printf("Выберите операцию: ");
		scanf("%d", &value);
		switch (value) {
			case 1:
				printf("Введите радиус: ");
				scanf("%d", &radius);
				if (radius <= 0) radius = 1;
				printf("Новый радиус - %d", radius);
				break;
			case 2:
				printf("Площадь поверхности шара - %f", M_PI*pow(radius, 2));

				break;
			case 3:
				printf("Объём шара - %f", 4.0/3.0 * M_PI*pow(radius, 3));
				break;
			case 4:
				printf("Длина ребра правильного тетраэдера вписанного в шар - %f", pow(6, 1/2)/radius*4);
				break;
			case 5:
				scanf("%d", &k);
				printf("Площади сечения, проведенного на расстоянии k от центра шара - %f", (pow(radius,2)-pow(k,2))*M_PI);
				break;
			case 6:
				return 0;
		}
	}
}