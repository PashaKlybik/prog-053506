//Lab 1.2 Variant 1
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <inttypes.h>
int GetCount(int number) {
	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}
	return count;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int number;
	/*while (1) {
		printf("������� ����� � ��������� [100,9999]\n");
		scanf_s("%d", &number);
		int count = GetCount(number);

		if (count == 3) {
			int composition = 1;
			while (number != 1) {
				composition *= number % 10;
				number /= 10;
			}
			printf("������������ ���� �����: ");
			printf("%d\n", composition);
		}
		if (count == 4) {
			int sum = 0;
			while (number != 0) {
				sum += number % 10;
				number /= 10;
			}
			printf("����� ���� �����: ");
			printf("%d\n", sum);
		}
		if(count > 4 || count<3) {
			printf("�� ����� �� �������� �����.");
			Sleep(2000);
			system("cls");
		}
		getch();
	}*/

	uint16_t s;
	scanf_s("%d", &s);
	printf("%d",&s);
	system("pause");
}
