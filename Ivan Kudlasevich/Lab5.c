#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int n = 0, flag = 0;
    char str[2000], stack[2000], ch;

    printf("Введите строку\n");

    for (int i = 0; i < strlen(str); ++i)
        if (str[i]) stack[n++] = str[i];

    while ((ch = getchar()) != '\n')
    {
        if (ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == ' ') continue;

        str[n] = ch;
        stack[n++] = ch;
    }

    for (int i = 0; i < n; ++i)
        if (str[i] != stack[--n])
        {
            printf("Строка не является палиндромом\n");
            return 0;
        }

    printf("Строка - палиндром\n");
    return 0;
}
