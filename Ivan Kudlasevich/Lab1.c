#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    scanf("%d", &n);

    if (n == 1) printf("����\n");
    if (n == 2) printf("���\n");
    if (n == 3) printf("���\n");
    if (n == 4) printf("������\n");
    if (n == 5) printf("����\n");
    if (n == 6) printf("�����\n");
    if (n == 7) printf("����\n");
    if (n == 8) printf("������\n");
    if (n == 9) printf("������\n");
    if (n == 10) printf("������\n");
    if (n == 11) printf("�����������\n");
    if (n == 12) printf("����������\n");
    if (n == 13) printf("����������\n");
    if (n == 14) printf("������������\n");
    if (n == 15) printf("����������\n");
    if (n == 16) printf("����������\n");
    if (n == 17) printf("����������\n");
    if (n == 18) printf("������������\n");
    if (n == 19) printf("������������\n");

    if (n < 20) return 0;

    if (n / 10 == 2) printf("��������");
    if (n / 10 == 3) printf("��������");
    if (n / 10 == 4) printf("�����");
    if (n / 10 == 5) printf("���������");
    if (n / 10 == 6) printf("����������");
    if (n / 10 == 7) printf("���������");
    if (n / 10 == 8) printf("�����������");
    if (n / 10 == 9) printf("���������");

    if (n % 10 == 0 && n != 100)
    {
        printf("\n");
        return 0;
    }
    else if (n != 100) printf(" ");

    if (n % 10 == 1) printf("����\n");
    if (n % 10 == 2) printf("���\n");
    if (n % 10 == 3) printf("���\n");
    if (n % 10 == 4) printf("������\n");
    if (n % 10 == 5) printf("����\n");
    if (n % 10 == 6) printf("�����\n");
    if (n % 10 == 7) printf("����\n");
    if (n % 10 == 8) printf("������\n");
    if (n % 10 == 9) printf("������\n");

    if (n == 100) printf("���\n");

    return 0;
}
