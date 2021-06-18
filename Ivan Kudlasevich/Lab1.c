#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    scanf("%d", &n);

    if (n == 1) printf("Один\n");
    if (n == 2) printf("Два\n");
    if (n == 3) printf("Три\n");
    if (n == 4) printf("Четыре\n");
    if (n == 5) printf("Пять\n");
    if (n == 6) printf("Шесть\n");
    if (n == 7) printf("Семь\n");
    if (n == 8) printf("Восемь\n");
    if (n == 9) printf("Девять\n");
    if (n == 10) printf("Десять\n");
    if (n == 11) printf("Одиннадцать\n");
    if (n == 12) printf("Двенадцать\n");
    if (n == 13) printf("Тринадцать\n");
    if (n == 14) printf("Четырнадцать\n");
    if (n == 15) printf("Пятнадцать\n");
    if (n == 16) printf("Шеснадцать\n");
    if (n == 17) printf("Семнадцать\n");
    if (n == 18) printf("Восемнадцать\n");
    if (n == 19) printf("Девятнадцать\n");

    if (n < 20) return 0;

    if (n / 10 == 2) printf("Двадцать");
    if (n / 10 == 3) printf("Тридцать");
    if (n / 10 == 4) printf("Сорок");
    if (n / 10 == 5) printf("Пятьдесят");
    if (n / 10 == 6) printf("Шестьдесят");
    if (n / 10 == 7) printf("Семьдесят");
    if (n / 10 == 8) printf("Восемьдесят");
    if (n / 10 == 9) printf("Девяносто");

    if (n % 10 == 0 && n != 100)
    {
        printf("\n");
        return 0;
    }
    else if (n != 100) printf(" ");

    if (n % 10 == 1) printf("один\n");
    if (n % 10 == 2) printf("два\n");
    if (n % 10 == 3) printf("три\n");
    if (n % 10 == 4) printf("четыре\n");
    if (n % 10 == 5) printf("пять\n");
    if (n % 10 == 6) printf("шесть\n");
    if (n % 10 == 7) printf("семь\n");
    if (n % 10 == 8) printf("восемь\n");
    if (n % 10 == 9) printf("девять\n");

    if (n == 100) printf("Сто\n");

    return 0;
}
