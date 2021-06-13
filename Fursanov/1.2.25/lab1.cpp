#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

char* DecBin(int chislo, int size)  // переводим число из десятичного представления в 32х битную строку двоичного представления
{									
	int i;
	char* bin;
	bin = (char*)malloc(size * sizeof(char));

	for (i = size - 1; i >= 0; --i)
	{
			bin[i] = ((chislo >> i) & 1) + 48;
	}
	return bin;
}

bool check(char* bin, int size)     // проверка на симметричность строки начиная с первой единицы
{
	bool simetr = 1;
	int i = 0;
	int j = size-1;
	while (bin[j] == '0')   // начинаем идти по массиву с конца, игнорируя все нули до первой единицы
		j--;
	for (i, j; j >= i; i++, j--)
		if (bin[i] != bin[j])simetr = 0;
	return simetr;
}

int main()
{
	int size(sizeof(int) * 8);
	int m=0;
	while (m <= 0)
	{
		printf("Enter m: ");
		scanf("%d", &m);
		if (m <= 0)          //проверка на корректный ввод
		{
			printf("Invalid input. Please try again r\n");
			while (getchar() != '\n') {}
		}
		else
			for (int i = 1; i <= m; i++)
			{
				if (check(DecBin(i, size),size))
				{
					char* Bin;
					Bin = (char*)malloc(size * sizeof(char));
					Bin = DecBin(i, size);
					int j = size - 1;
					while (Bin[j] == '0')
						j--;
					printf("decimal: %d", i);
					printf(" binary: ");
					for (j; j >= 0; --j)
					{                       
						printf("%c", Bin[j]);
					}
					printf("\n");
				}
			}
	}
	return 0;
}
