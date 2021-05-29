//lab 4_25(2)

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int CountLen(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        i++;
    }
    return i;
}

float CommB(char input[], int l)
{
    float count = 0;
    for (int i = 0; i < l; i++)
    {
        if (input[i] == '/' && input[i + 1] == '/')
        {
            while (input[i] != '\n')
            {
                count++;
                i++;
            }
        }
    }
    return count;
}

int main()
{
    char* mass;
    FILE* File;

    File = fopen("input.txt", "r");

    fseek(File, 0, SEEK_END);
    int bytes = ftell(File);
    fseek(File, 0, SEEK_SET);
    mass = (char*)calloc(bytes, sizeof(char));

    int i = 0;
    while (true)
    {
        if (feof(File))
        {
            mass[i - 1] = '\0';
            break;
        }
        mass[i] = fgetc(File);
        i++;
    }

    fclose(File);

    printf("TEXT:\n--------------------------------------------\n");
    for (int j = 0; j < CountLen(mass); j++)
    {
        printf("%c", mass[j]);
    }
    printf("\n--------------------------------------------\n");

    printf("Size: %ld Bytes.\n", bytes);
    printf("Commented code: %.f Bytes\n", CommB(mass, CountLen(mass)));
    printf("Percent Of commented code: %.3f%%\n\n", (CommB(mass, CountLen(mass)) * 100) / bytes);

	free(mass);
	return 0;
}
