//ВАРИАНТ 3.3.2
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int main()
{
    int m = 0, n = 0;
    int k = 0, l = 0;
    printf("input your size array[n][m]\nn-");
    scanf_s("%d", &n);
    printf("m-");
    scanf_s("%d", &m);
    printf("input your pozition for '1'\ni-");
    scanf_s("%d", &k);
    printf("l-");
    scanf_s("%d", &l);
    int** array = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(array + i) = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = 1 + max(abs(i - k), abs(j - l));
            printf("%2d", array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
}