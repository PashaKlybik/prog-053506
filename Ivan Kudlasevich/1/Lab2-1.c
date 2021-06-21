#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const double gravConst = 0.0000000000667418478;
const double pi = acos(-1);

double weight[3], radius[3], speed[3], time;

void EnteringParameters(double *a, double *b, double *c)
{
    printf("Введите массу, радиус орбиты и скорость движения планеты\n");
    scanf("%lf %lf %lf", a, b, c);
}

double orbitLength(double radius)
{
    return 2 * pi * radius;
}

double distanceBetweenPlanets(double radius1, double speed1, double radius2, double speed2, double time)
{
    double angle1 = (int)(speed1 * time) % (int)(orbitLength(radius1)) * 360;
    double angle2 = (int)(speed2 * time) % (int)(orbitLength(radius2)) * 360;

    return sqrt(radius1 * radius1 + radius2 * radius2 - 2 * radius1 * radius2 * cos(angle1 - angle2));
}

double gravitationalInteraction(double weight1, double weight2, double distance)
{
    return gravConst * weight1 * weight2 / distance * distance;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 3;

    for (int i = 0; i < n; ++i)
        EnteringParameters(&weight[i], &radius[i], &speed[i]);
    printf("\n");

    for (int i = 0; i < n; ++i)
        printf("Длительность года на планете 2G_%i: %lf\n", i + 1, orbitLength(radius[i]) / speed[i]);
    printf("\n");

    printf("Введите сколько времени прошло\n");
    scanf("%lf", &time);
    printf("\n");

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            printf("Расстояние между 2G_%i и 2G_%i спустя время %.2lf: %lf\n", i + 1, j + 1, time, distanceBetweenPlanets(radius[i], speed[i], radius[j], speed[j], time));
    printf("\n");

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            printf("Гравитационное взаимодействие между 2G_%i и 2G_%i спустя время %.2lf: %.17lf\n",
                    i + 1, j + 1, time, gravitationalInteraction(weight[i], weight[j], distanceBetweenPlanets(radius[i], speed[i], radius[j], speed[j], time)));

    return 0;
}
