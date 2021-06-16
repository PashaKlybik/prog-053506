#include<iostream>
#include<string.h>
using namespace std;

int Nowlength(char* Arr)
{
	int count = 0;
	for (int i = 0;; i++)
	{
		if (Arr[i] == '\0') break;
		count++;
	}
	return count++;
}

int main(int argc, char* argv[])
{
	int N;
	long a = 1, F = 1, b = 0, count;
	char Arr[1000] = "1";
	char str[25] = "";

	printf_s("Enter the number of the digit you want to receive: ");
	scanf_s("%d", &N);
	printf_s("\nFibonacci sequence: 1 ");

	count = N;

	while (true)
	{
		_itoa_s(F, str, 10);
		printf_s("%d ", F);
		strcat_s(Arr, str);

		b = F;
		F = F + a;
		a = b;

		if (Nowlength(Arr) >= N) break;
	}
	printf_s("...\nNumeral: %c", Arr[N - 1]);

	return(0);
}