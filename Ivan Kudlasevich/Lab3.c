#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n = 10, m = 10;

int main()
{
    setlocale(LC_ALL, "rus");

    char a[n][m];
    srand(time(NULL));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (rand() % 2) a[i][j] = 'X';
            else a[i][j] = '0';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%c", a[i][j]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 'X')
            {
                // проверка по вертикали
                if (i + 4 < n)
                {
                    int flag = 1;
                    for (int x = 1; x < i + 5; ++x)
                        if (a[i][j] != a[i+x][j])
                        {
                            flag = 0;
                            break;
                        }
                    if (flag == 1)
                    {
                        printf("Крестики выиграли\n");
                        return 0;
                    }
                }
                // проверка по горизонтали
                if (j + 4 < m)
                {
                    int flag = 1;
                    for (int y = 1; y < j + 5; ++y)
                        if (a[i][j] != a[i][j+y])
                        {
                            flag = 0;
                            break;
                        }
                    if (flag)
                    {
                        printf("Крестики выиграли\n");
                        return 0;
                    }
                }
                // проверка по диагонали вниз, враво
                if (i + 4 < n && j + 4 < m)
                {
                    int flag = 1;
                    for (int z = 1; z < i + 5; ++z)
                        if (a[i][j] != a[i+z][j+z])
                        {
                            flag = 0;
                            break;
                        }
                    if (flag)
                    {
                        printf("Крестики выиграли\n");
                        return 0;
                    }
                }
                // проверка по диагонали вниз, влево
                if (i + 4 < n && j - 4 >= 0)
                {
                    int flag = 1;
                    for (int z = 1; z < i + 5; ++z)
                        if (a[i][j] != a[i+z][j-z])
                        {
                            flag = 0;
                            break;
                        }
                    if (flag)
                    {
                        printf("Крестики выиграли\n");
                        return 0;
                    }
                }
            }

    printf("Крестики проиграли\n");
    return 0;
}S
