#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int gaussMethod(int m, int n, double* a, double eps);

int main()
{
    int m, n, i, j, rank;
    double* a;
    double eps, det;

    printf("Введите размеры матрицы m, n: ");
    scanf_s("%d%d", &m, &n);

    a = new double[m * n];

    printf("Введите элементы матрицы:\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf_s("%lf", &(a[i * n + j]));
        }
    }

    printf("Введите точность вычислений eps: ");
    scanf_s("%lf", &eps);

    rank = gaussMethod(m, n, a, eps);

    printf("Ступенчатый вид матрицы: \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%10.3lf ", a[i * n + j]);
        }
        printf("\n"); 
    }
    printf("Ранг матрицы = %d\n", rank);

    if (m == n)
    {
        det = 1.0;
        for (i = 0; i < m; i++)
        {
            det *= a[i * n + i];
        }
    }
    delete[] a; 
    scanf_s("%lf", &eps);

    return 0;
}

int gaussMethod(int m, int n, double* a, double eps)
{
    int i, j, k, l;
    double r;

    i = 0; j = 0;

    while (i < m && j < n)
    {
        r = 0.0;
        for (k = i; k < m; ++k)
        {
            if (fabs(a[k * n + j]) > r)
            {
                l = k; 
                r = fabs(a[k * n + j]); 
            }
        }
        if (r <= eps)
        {
            for (k = i; k < m; ++k)
            {
                a[k * n + j] = 0.0;
            }
            ++j; 
            continue; 
        }
        if (l != i)
        {
 
            for (k = j; k < n; ++k)
            {
                r = a[i * n + k];
                a[i * n + k] = a[l * n + k];
                a[l * n + k] = (-r);
            }
        }

        r = a[i * n + j];
        for (k = i + 1; k < m; ++k)
        {
            double c = (-a[k * n + j]) / r;
            a[k * n + j] = 0.0;
            for (l = j + 1; l < n; ++l)
            {
                a[k * n + l] += c * a[i * n + l];
            }
        }

        ++i; ++j; 
    }

    return i;
}
