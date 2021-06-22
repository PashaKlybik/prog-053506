////2.2(6)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double Fact(int i)
{
    if (i == 0) return 1;
    else return i * Fact(i - 1);
}

int Recurse(int x, int eps, int vozvr, double itog)
{
    if (fabs(sin(x) - itog) < eps)
    {
        printf("\nRecurse:\nSin(x) = %lf.\nItog = %lf.\n", sin(x), itog);
        return vozvr;
    }
    vozvr++;
    itog = itog + pow(-1, vozvr - 1) * pow(x, 2 * vozvr - 1) / Fact(2 * vozvr - 1);
    return Recurse(x, eps, vozvr, itog);
}

int Iterat(int x, double eps, int vozvr, double itog)
{
    do
    {
        vozvr++;
        itog = itog + pow(-1, vozvr - 1) * pow(x, 2 * vozvr - 1) / Fact(2 * vozvr - 1);
    } while ((fabs(sin(x) - itog) > eps));

    printf("\nIterat:\nSin(x) = %lf.\nItog = %lf.\n", sin(x), itog);
    return vozvr;
}

int main()
{
    int x, eps;
    printf("x: ");
    scanf_s("%d", &x);
    printf("eps: ");
    scanf_s("%d", &eps);

    printf("n = %d.\n", Recurse(x, eps, 1, x));
    printf("n = %d.\n", Iterat(x, eps, 1, x));

    while (true)
    {
        int N;
        printf("\n1-continue\n2-stop\n");
        scanf_s("%d", &N);
        switch (N)
        {
        case 1: printf("Enter enough x:");
            scanf_s("%d", &x);
            printf("n = %d.\n", Recurse(x, eps, 1, x));
            printf("n = %d.\n\n", Iterat(x, eps, 1, x));
            break;
        case 2: exit(0); break;
        default:  printf("Incorrect input. Try again");
        }
    }
    return 0;
}