
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int countY = 0, countD = 0;
    double p, k, t , m;
    int check = 0;

    printf("������� ����� ��������� � ����:\n");
    scanf_s("%lf", &p);

    printf("������� ��������� ������� ��������� � ���������:\n");
    scanf_s("%lf", &k);

    printf("������� ������� ���� ���������:\n");
    scanf("%lf", &t);


    m = p;
    while (!check)
    {
        if (p - t > 0)
        {
            p = p + p * k / 100 - t;
            countY++;
        }
        if (p > m)
        {
            check = 1;
            printf("\n������ ������� ������� ������� �� �������� :)");
        }
        if(p - t < 0 )
            check = 1;
    }

    if (p < m)
    {
        countD = p / (t / 365);
        printf("������� �������� �����: %d �. � %d �.\n", countY, countD);
    }

}
