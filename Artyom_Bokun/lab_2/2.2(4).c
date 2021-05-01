#include <stdio.h>
#include <math.h>
#include <windows.h>

long double fact(int num)
{
    if(num < 0)
        return 0;
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

int iteration(float x)
{
    double sigma, tempSin = 0;
    printf("Введите желаемую погрешность: ");
    scanf("%lf", &sigma);
    for (int i = 1;; i++)
    {
        tempSin = tempSin +((pow((-1),i-1)*pow(x,2*i-1)/fact(2*i-1)));
        if (sinf(x)-tempSin < sigma && sinf(x)-tempSin > -sigma)
        {
            printf("\nРазложение: ");
            printf("%f", tempSin);
            return i;
        }
    }
}

int main()
{
    double x, raz;
    SetConsoleOutputCP(CP_UTF8);
    printf("\nВведите x: ");
    scanf("%lf", &x);
    int n = iteration(x);
    printf("\nСинус x: ");
    printf("%f", sin(x));
    printf("\nНеобходимо иттераций: ");
    printf("%d", n);
    return 0;
}
