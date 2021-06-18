#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");

    FILE *file;
    file = fopen("../input.txt", "r");

    int i = 0, flag = 0;
    char str[2000], ch;

    printf("Введите текст со скобками\n");

    while ((ch = getchar()) != '\n')
    {
        if (flag) continue;

        if ((ch == ')' || ch == '}' || ch == ']') && i == 0)
        {
            flag = 1;
            continue;
        }

        if (ch == '}' && str[i-1] != '{') flag = 1;
        if (ch == ')' && str[i-1] != '(') flag = 1;
        if (ch == ']' && str[i-1] != '[') flag = 1;

        if (ch == ')' || ch == '}' || ch == ']') --i;
        if (ch == '(' || ch == '{' || ch == '[') str[i++] = ch;
    }


    if (flag) printf("Скобочная последовательность не верна\n");
    else printf("Скобочная последовательность правильна");
    return 0;
}
