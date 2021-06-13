//lab 4_25(1)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CountLen(char input[])
{
    int i = 0;
    while (input[i] != '\n') {
        i++;
    }
    return i;
}

int countW(char input[])
{
    int num = 0;
    for (int i = 0; i < CountLen(input); i++)
    {
        if (input[i] == ' ')
        {
            num++;
        }
    }
    return num + 1;
}

int countS(char input[])
{
    int num = 0;
    for (int i = 0; i < CountLen(input); i++)
    {
        if (input[i] == '.')
        {
            while (input[i] == '.')
            {
                i++;
            }
            num++;
        }
        else if (input[i] == '!')
        {
            while (input[i] == '!') {
                i++;
            }
            num++;
        }
        else if (input[i] == '?')
        {
            while (input[i] == '?')
            {
                i++;
            }
            num++;
        }
    }
    return num;
}

void LongestW(char input[])
{
    int max = 0;
    int a = 0;
    int leng = 0;

    for (int i= 0; input[i] != '\n'; i++)
    {
        if (leng == max)
        {
            a = i - max;
        }

        if (input[i] == ' ')
        {
            leng = 0;
        }
        else {
            leng++;
        }

        if (leng > max)
        {
            max = leng;
        }
    }

    printf("Longest word: ");

    for (int i = 1; i <= max; i++)
    {
        printf("%c", input[a]);
        a++;
    }
    printf("\n");
}

void LongestS(char input[])
{
    int max = 0;
    int a = 0;
    int leng = 0;

    for (int i= 0; input[i] != '\n'; i++)
    {
        if (leng == max)
        {
            a = i - max;
        }

        if (input[i] == '.')
        {
            leng = 0;
        }
        else {
            leng++;
        }

        if (leng > max)
        {
            max = leng;
        }
    }
    printf("Longest Sentence: ");
    for (int i = 1; i <= max; i++)
    {
        printf("%c", input[a]);
        a++;
    }
    printf("\n\n");

}

int main()
{
    char input[100000];

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);


    printf("Count words: %d\n", countW(input));
    printf("Count sentences: %d\n\n", countS(input));
    LongestW(input);
    LongestS(input);
    return 0;

}
