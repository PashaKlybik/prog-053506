#include <stdio.h>
#include <math.h>
#include <windows.h>

long double fact(int num)
{
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

int rec(double tempSin, int i, double x, double epsilon)
{
    tempSin =  tempSin + ((pow((-1), i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1)));
    if (fabs(sinf(x) - tempSin) < epsilon)
    {
        printf_s("\nРазложение (рекурсия): %lf", tempSin);
        return i;
    }
    else
        i++;
    return rec(tempSin, i, x, epsilon);
}

int iteration(double x, double epsilon)
{
    double tempSin = 0;
    for (int i = 1;; i++)
    {
        tempSin =  tempSin + ((pow((-1), i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1)));
        if (fabs(sinf(x) - tempSin) < epsilon)
        {
            printf_s("\nРазложение (не рекурсия): %lf", tempSin);
            return i;
        }
    }
}

int main()
{
    double x, epsilon;
    SetConsoleOutputCP(CP_UTF8);
    printf_s("\nВведите x: ");
    scanf_s("%lf", &x);
    printf_s("Введите желаемую погрешность: ");
    scanf_s("%lf", &epsilon);
    printf_s("\nСинус x: %f", sin(x));
    int i = rec(0, 1, x, epsilon);
    int n = iteration(x, epsilon);
    printf_s("\nНеобходимо итераций: %d", n);
    printf_s("\nНеобходимо итераций для рекурсии: %d", i);
    return 0;
}