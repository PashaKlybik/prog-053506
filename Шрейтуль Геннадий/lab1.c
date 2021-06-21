// #1.2(30)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int k;
	printf("Enter K: ");
	scanf("%d", &k);
	if (k <= 180 && k > 0)
	{
		int numbers[90];
		for (int i = 0; i < 90; i++)
			numbers[i] = 10 + i;
		int time = k / 2 + 0.5;
		int a = numbers[time - 1] / 10, b = numbers[time - 1] % 10;
		if (k % 2 == 0)
			printf("The K digit of the sequence: %d", b);
		else
			printf("The K digit of the sequence: %d", a);
	}
	else
		printf("The number K cannot be more than 180");
	return 0;
}