#include <stdio.h>
#include <stdbool.h>
#include <math.h>


double Fact(int y);
int Recursion(double x, double e, int y, double sum);
int Iteration(double x, double e, int y, double sum);
int main() {
    double x = 0;
    double e = 0;
    char exit;
    while (true)
    {
        printf("x: ");
        scanf("%lf.", &x);
        fflush(stdin);

        printf("e: ");
        scanf("%lf", &e);
        fflush(stdin);

        printf("What do you choose?: x = %lf, e = %lf.\n", x, e);

        printf("y = %d.\n", Recursion(x, e, 1, x));
        printf("y = %d.\n\n", Iteration(x, e, 1, x));

        printf("Enter 'Continue' if you want to continue:");
        while ((getchar()) != '\n');
        exit = getchar();
        if (exit == 'Continue')
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 0;
}
double Fact(int y)
{
    if (y < 0)
    {
        return 0;
    }
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return y * Fact(y - 1);
    }
}
int Recursion(double x, double e, int y, double sum)
{
    if (fabs(sin(x) - sum) < e)
    {
        printf("\nRecursion:\n\nsin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
        return y;
    }

    y++;
    sum += pow(-1, y - 1) * pow(x, 2 * y - 1) / Fact(2 * y - 1);
    return Recursion(x, e, y, sum);
}
int Iteration(double x, double e, int y, double sum)
{
    while ((fabs(sin(x) - sum) > e))
    {
        y++;
        sum += pow(-1, y - 1) * pow(x, 2 * y - 1) / Fact(2 * y - 1);
    }

    printf("\nIteration:\n\nsin(x) = %lf.\nExpression = %lf.\n", sin(x), sum);
    return y;
}
