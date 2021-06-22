#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
system("chcp 1251 & cls");
int N;

printf("N = ");
scanf("%d",&N);

printf("Возрастающая:\n");

for (int i = 1; i <= N; i++)
{
printf("%d\n", i);
}

printf("Убывающая:\n");

for ( int i =N ;i >= 1; i--)
{
printf("%d\n", i);
}
return 0;
}
