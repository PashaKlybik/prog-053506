#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    int n = 0;
    char str[2000], ch;

    printf("¬ведите текст и добавьте тильду ~ в конце\n");
    while ((ch = getchar()) != '~')
    {
        if (ch == '\n') str[n++] = ' ';
        else str[n++] = ch;
    }
    str[n] = '\0';

    for (int i = n - 1; i >= 0; --i)
        printf("%c", str[i]);

    return 0;
}
