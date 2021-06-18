//Task 1.1. Variant 14

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int divisorCheck(int num)
{
	int checkVar;
	int sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
			sum += i;
	};
	if (num == sum)
		checkVar = 1;
	else
		checkVar = 0;
	return (checkVar);
}

int main()
{
	int amt, outputCriteria;
	printf("Amount of numbers to check: ");
	scanf("%d", &amt);
	for (int i = 1; i <= amt; i++)
	{
		outputCriteria = divisorCheck(i);
		if (outputCriteria == 1)
			printf(" %d", i);
	};
}