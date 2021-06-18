#include<stdio.h>
int CountNumberLength(int number) {
	int length;
	for (length = 0; ; length++)
		if ((number /= 10) < 10) break;
	return length;
}
void PrintWithSpaces(int number, int spaces) {
	for (int i = 0; i < spaces; i++)
		putchar(' ');
	printf("%d\n", number);
}
int main() {
	int K = 1500, L = 60, R = K * L;
	PrintWithSpaces(K, CountNumberLength(R) - CountNumberLength(K));
	PrintWithSpaces(L, CountNumberLength(R) - CountNumberLength(L));
	printf("%d\n", R);
	return 0;
}