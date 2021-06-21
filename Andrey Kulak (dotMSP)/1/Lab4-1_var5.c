//Task 4.1. Variant 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, j, k, max = 0, l, isUnique = 1;
    char c, word[80], longestWord[80];
    printf("Enter the text (To stop the input press CTRL+Z and then Enter): ");
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t' && c != ',' && c != '.' && c != '!' && c != '?' && c != ';' && c != ':') {
            word[i] = c;
            i++;
        }
        else {
            word[i] = '\0';
            i = 0;
            l = strlen(word);
            for (k = 0; k < l; k++) {
                for (j = k; j < l; j++) {
                    if (word[j] == word[k] && j != k)
                        isUnique = 0;
                }
                if (k == l - 1 && isUnique == 1 && k > max) {
                    max = k;
                    strcpy(longestWord, word);
                }
            }
            isUnique = 1;
        }
    }
    printf(longestWord);
    return 0;
}