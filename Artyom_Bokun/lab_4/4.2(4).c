#include <stdio.h>

int StrLen(char *strArr)
{
    int index = 0;

    while (strArr[index] != '\0')
        index++;

    return index;
}

int main()
{
    char str[80], buf[80];
    int i;
    const int indCen = 40;
    FILE *fp;

    fopen_s(&fp, "input.txt", "r");

    if (!fp)
        return -1;

    while (fgets(buf, 80, fp))
    {
        for (i = 0; i < 80; i++)
            str[i] = ' ';

        for (i = 0; i < StrLen(buf) && buf[i] != '\n'; i++)
            str[indCen - StrLen(buf) / 2 + i] = buf[i];

        str[indCen + i - 1] = '\0';
        printf("%s\n", str);
    }
    fclose(fp);
    return 0;
}