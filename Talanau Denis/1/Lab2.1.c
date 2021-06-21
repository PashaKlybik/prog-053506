#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>


double cable, cost1, cost2, cost3;

void Cable(int fl, double ht, double wt, double dist)
{
    cable = fl * (ht + wt + dist);
    printf("Общая длинна кабеля равна: %lf\n", cable);
}

void Cost_EQT(int floors, int box, int cablepr)
{
    cost1 = cable * cablepr + floors * box;
    printf("\nСтоимость необходимого сетевого оборудования равна: %lf $\n", cost1);
}

void Total_cost(int number, int floors, int socet, int connector, int canal, int mountingBox)
{
    cost3 = cost2 + cost1 + (number * (socet + 2 * connector) + floors * (mountingBox + canal));
    printf("\nОбщая стоимость проекта равна: %lf $\n", cost3);
}

void Cost_of_Designing(int number, int floors, int socet, int connector, int canal, int mountingBox)
{
    cost2 = 0.3 * (cost1 + (number * (socet + 2 * connector) + floors * (mountingBox + canal)));
    printf("\nСтоимость проектирования сети равна: %lf $\n", cost2);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a, number, floors, socet = 1, box = 110, connector = 1, canal = 20, mountingBox = 33;
    double height, width, distance, cablepr = 1.50;
    int check = 0;

    printf("Введите количество подключений: ");
    scanf_s("%d", &number);

    printf("Введите количество этажей, которые хотят подключиться к сети: ");
    scanf_s("%d", &floors);

    printf("Введите высоту потолков: ");
    scanf_s("%lf", &height);

    printf("Введите толщину перекрытий дома: ");
    scanf_s("%lf", &width);

    printf("Введите среднее расстояния от точки подключения до распределительного шкафа на этаже: ");
    scanf_s("%lf", &distance);

    printf("\nВведите 1 чтобы узнать стоимость проектирования сети");
    printf("\nВведите 2 чтобы узнать общую длинну кабеля");
    printf("\nВведите 3 чтобы узнать стоимость необходимого сетевого оборудования");
    printf("\nВведите 4 чтобы узнать общую стоимость проекта");
    printf("\nВведите 5 чтобы постмотреть информацию о фирме");
    printf("\nВведите 6 чтобы выйти\n");

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
            printf("Компания занимается прокладкой сети в домах \nКонтакты +375 (29) 678-45-78\n"); break;
        case 6:
            check = 1; break;
        default:
            printf("Ошибка, введен неверный символ попробуйте ещё раз\n"); break;
        }
    }
}
