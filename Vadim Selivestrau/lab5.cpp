#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
struct MnChsl
{
	int digit;
	struct MnChsl* pprev;
	struct MnChsl* pnext;
};
void NewMNumber(MnChsl** numL, MnChsl** numR)
{
	*numL = (MnChsl*)malloc(sizeof(MnChsl));
	*numR = (MnChsl*)malloc(sizeof(MnChsl));
	(*numL)->pprev = NULL;
	(*numL)->pnext = *numR;
	(*numR)->pprev = *numL;
	(*numR)->pnext = NULL;
	return;
}
void AddDigit(MnChsl* numR, int digit)
{
	MnChsl* node = NULL;
	node = (MnChsl*)malloc(sizeof(MnChsl));
	node->digit = digit;
	node->pprev = numR->pprev;
	node->pnext = numR;
	node->pprev->pnext = node;
	numR->pprev = node;
	return;
}
void Output(MnChsl** numL, MnChsl** numR)
{
	MnChsl* node = (*numL)->pnext;
	while (node != *numR)
	{
		printf("%d", node->digit);
		node = node->pnext;
	}
	return;
}
int DigitsCount(MnChsl** numL, MnChsl** numR)
{
	MnChsl* node = (*numL)->pnext;
	int digitscount = 0;
	while (node != *numR)
	{
		node = node->pnext;
		digitscount++;
	}
	return digitscount;
}
int Equal(MnChsl** num1L, MnChsl** num1R, MnChsl** num2L, MnChsl** num2R)
{
	MnChsl* pointer1 = (*num1L)->pnext;
	MnChsl* pointer2 = (*num2L)->pnext;
	int size1 = DigitsCount(num1L, num1R), size2 = DigitsCount(num2L, num2R);
	if (size1 > size2)
	{
		return 1;
	}
	else if (size1 < size2)
	{
		return -1;
	}
	else if (size1 == size2)
	{
		while (pointer1 != *num1R)
		{
			if (pointer1->digit > pointer2->digit)
			{
				return 1;
			}
			if (pointer1->digit < pointer2->digit)
			{
				return -1;
			}
			pointer1 = pointer1->pnext;
			pointer2 = pointer2->pnext;
		}
	}
	return 0;
}
// остаток от деления на short int
int LongModShort(MnChsl** num1L, MnChsl** num1R, int shortint)
{
	int remainder = 0;
	MnChsl* node = (*num1L)->pnext;
	while (node != *num1R)
	{
		remainder = remainder * 10 + node->digit;
		node = node->pnext;
		remainder %= shortint;
	}
	return remainder;
}
MnChsl* DeleteDigit(MnChsl** numL)
{
	MnChsl* node = (*numL)->pnext;
	MnChsl* tmp = node;
	node->pprev->pnext = node->pnext;
	node->pnext->pprev = node->pprev;
	free(tmp);
	node = (*numL)->pnext;
	return node->pprev;
}
// целая часть от деления на short int
MnChsl* LongDivShort(MnChsl** num1L, MnChsl** num1R, int shortint)
{
	MnChsl* divL = NULL, * divR = NULL;
	if (divL == NULL)
	{
		NewMNumber(&divL, &divR);
	}
	int del = 0;
	MnChsl* spt = (*num1L)->pnext;
	while (spt != *num1R)
	{
		del = del * 10 + spt->digit;
		spt = spt->pnext;
		AddDigit(divR, del / shortint);
		del %= shortint;
	}
	while (divL->pnext->digit == 0)
	{
		divL = DeleteDigit(&divL);
	}
	Output(&divL, &divR);
	return divL;
}
// функция умножения на short int
MnChsl* LongMulShort(MnChsl** num1L, MnChsl** num1R, int shortint)
{
	int intdigits = 0, temp = shortint, count = 0;
	while (temp)
	{
		temp /= 10;
		intdigits++;
	}
	intdigits += DigitsCount(num1L, num1R);
	MnChsl* numL = NULL, * numR = NULL;
	if (numL == NULL)
	{
		NewMNumber(&numL, &numR);
	}
	for (int i = 0; i < intdigits; i++)
	{
		AddDigit(numR, 0);
	}
	int digit = 0, pos = 0;
	MnChsl* spt = (*num1R)->pprev;
	MnChsl* spt1 = numR->pprev;
	int mod = shortint % 10;
	shortint = shortint / 10;
	while (mod != 0)
	{
		while (spt != *num1L)
		{
			spt1->digit += (spt->digit * mod + pos);
			pos = 0;
			if (spt1->digit >= 10)
			{
				pos = spt1->digit / 10;
				spt1->digit = spt1->digit % 10;
			}
			spt = spt->pprev;
			spt1 = spt1->pprev;
		}
		count++;
		if (pos)
		{
			spt1->digit += pos;
			pos = 0;
		}
		mod = shortint % 10;
		shortint = shortint / 10;
		spt = (*num1R)->pprev;
		spt1 = numR->pprev;
		for (int i = 0; i < count; i++)
		{
			spt1 = spt1->pprev;
		}
	}
	while (numL->pnext->digit == 0)//лишние разряды
	{
		numL = DeleteDigit(&numL);
	}
	Output(&numL, &numR);
	return numL;
}
void FreeMemory(MnChsl** numL, MnChsl** numR)
{
	MnChsl* spt = (*numL)->pnext;
	while (spt != *numR)
	{
		MnChsl* tmp = spt;
		spt->pprev->pnext = spt->pnext;
		spt->pnext->pprev = spt->pprev;
		free(tmp);
		spt = (*numL)->pnext;
	}
	free(*numL); *numL = NULL;
	free(*numR); *numR = NULL;
	return;
}
int main(void)
{
	setlocale(LC_ALL, "Rus");
	char* Number1, * Number2;
	Number1 = (char*)malloc(100 * sizeof(char));
	Number2 = (char*)malloc(100 * sizeof(char));
	int shortnum = 0, equal; 

	printf("введите первое многорозрядное число\n");
	fgets(Number1, 100, stdin);
	Number1[strlen(Number1) - 1] = '\0';

	printf("введите первое многорозрядное число\n");
	fgets(Number2, 100, stdin);
	Number2[strlen(Number2) - 1] = '\0';

	struct MnChsl* num1L = NULL, * num1R = NULL, * num2L = NULL, * num2R = NULL;

	if (num1L == NULL)
	{
		NewMNumber(&num1L, &num1R);
	}
	if (num2L == NULL)
	{
		NewMNumber(&num2L, &num2R);
	}
	for (int i = 0; i < strlen(Number1); i++)
	{
		char c = Number1[i];
		AddDigit(num1R, atoi(&c));
	}
	for (int i = 0; i < strlen(Number2); i++)
	{
		char c = Number2[i];
		AddDigit(num2R, atoi(&c));
	}
	int size1 = DigitsCount(&num1L, &num1R), size2 = DigitsCount(&num2L, &num2R), size3 = 0, temp = 0;
	printf("введите short int: \n");
	while (size3 > size1 || size3 > size2 || shortnum < 1)
	{
		scanf_s("%i", &shortnum);
		while (temp)
		{
			temp /= 10;
			size3++;
		}
		if (size3 > size1 || size3 > size2 || shortnum < 1)
		{
			printf("Ошибка, повтрорите\n");
		}
	}
	while (1)
	{
		Sleep(1000);
		system("cls");
		int i = 0;
		printf("1. сравнение двух многоразрядных чисел\n");
		printf("2. остаток от деления многоразрядного числа на short int\n");
		printf("3. возвращает результат целочисленного деления многоразрядного числа на short int\n");
		printf("4. результат умножения многоразрядного числа на short int\n");
		printf("0. выход\n");
		scanf_s("%i", &i);
		switch (i)
		{
		case 1:
			equal = Equal(&num1L, &num1R, &num2L, &num2R);
			if (equal == 1)
			{
				printf("первое число больше второго\n");
			}
			if (equal == 0)
			{
				printf("числа равны\n");
			}
			if (equal == -1)
			{
				printf("второе число больше первого\n");
			}
			break;
		case 2:
			printf("остаток от деления первого многоразрядного числа:\t%d\n", LongModShort(&num1L, &num1R, shortnum));
			printf("остаток от деления второго многоразрядного числа:\t%d\n", LongModShort(&num2L, &num2R, shortnum));
			break;
		case 3:
			printf("целая часть деления первого многоразрядного числа\t"); LongDivShort(&num1L, &num1R, shortnum); printf("\n");
			printf("целая часть деления второго многоразрядного числа\t"); LongDivShort(&num2L, &num2R, shortnum); printf("\n");
			break;
		case 4:
			printf("умножение первого многоразрядного числа\t");  LongMulShort(&num1L, &num1R, shortnum); printf("\n");
			printf("умножение второго многоразрядного числа\t");  LongMulShort(&num2L, &num2R, shortnum); printf("\n");
			break;
		case 0:
			FreeMemory(&num1L, &num1R);
			FreeMemory(&num2L, &num2R);
			free(num1L);
			free(num1R);
			free(num2L);
			free(num2R);
			free(Number1);
			free(Number2);
			return 0;
		default:
			printf("ошибка, повторите\n");
		}
	}
}
