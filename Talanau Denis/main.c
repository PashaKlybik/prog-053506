#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>


double cable, cost1, cost2, cost3;

void Cable(int fl, double ht, double wt, double dist)
{
    cable = fl * (ht + wt + dist);
    printf("����� ������ ������ �����: %lf\n", cable);
}

void Cost_EQT(int floors, int box, int cablepr)
{
    cost1 = cable * cablepr + floors * box;
    printf("\n��������� ������������ �������� ������������ �����: %lf $\n", cost1);
}

void Total_cost(int number, int floors, int socet, int connector, int canal, int mountingBox)
{
    cost3 = cost2 + cost1 + (number * (socet + 2 * connector) + floors * (mountingBox + canal));
    printf("\n����� ��������� ������� �����: %lf $\n", cost3);
}

void Cost_of_Designing(int number, int floors, int socet, int connector, int canal, int mountingBox)
{
    cost2 = 0.3 * (cost1 + (number * (socet + 2 * connector) + floors * (mountingBox + canal)));
    printf("\n��������� �������������� ���� �����: %lf $\n", cost2);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a, number, floors, socet = 1, box = 110, connector = 1, canal = 20, mountingBox = 33;
    double height, width, distance, cablepr = 1.50;
    int check = 0;

    printf("������� ���������� �����������: ");
    scanf_s("%d", &number);

    printf("������� ���������� ������, ������� ����� ������������ � ����: ");
    scanf_s("%d", &floors);

    printf("������� ������ ��������: ");
    scanf_s("%lf", &height);

    printf("������� ������� ���������� ����: ");
    scanf_s("%lf", &width);

    printf("������� ������� ���������� �� ����� ����������� �� ������������������ ����� �� �����: ");
    scanf_s("%lf", &distance);

    printf("\n������� 1 ����� ������ ��������� �������������� ����");
    printf("\n������� 2 ����� ������ ����� ������ ������");
    printf("\n������� 3 ����� ������ ��������� ������������ �������� ������������");
    printf("\n������� 4 ����� ������ ����� ��������� �������");
    printf("\n������� 5 ����� ����������� ���������� � �����");
    printf("\n������� 6 ����� �����\n");

    while (!check)
    {
        scanf_s("%d", &a);
        switch (a)
        {
        case 1:
            Cost_of_Designing(number, floors, socet, connector, canal, mountingBox); break;
        case 2:
            Cable(floors, height, width, distance); break;
        case 3:
            Cost_EQT(floors, box, cablepr); break;
        case 4:
            Total_cost(number, floors, socet, connector, canal, mountingBox); break;
        case 5:
            printf("�������� ���������� ���������� ���� � ����� \n�������� +375 (29) 678-45-78\n"); break;
        case 6:
            check = 1; break;
        default:
            printf("������, ������ �������� ������ ���������� ��� ���\n"); break;
        }
    }
}
