#include <stdio.h>
#include <stdlib.h>
#define N 256
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool bukv(char letter);
int main() {
    char buffer[N];
    int word = 0;
    long int sum = 0;
    char* m;
    FILE* n;

    n = fopen("text.txt", "r");
    if (!n) exit(1);
    while (fgets(buffer, N, n) != NULL) {
        m = buffer;
        while (*m) {
            if (isdigit(*m) || ((*m == '-' || *m == '+') && isdigit(*(m + 1))))
            {
                long val = strtol(m, &m, 10);
                sum += val;
            }
            else {
                if ((*m == ' ' || *m == '\n') && bukv(*(m - 1))) word++;
                m++;
            }
        }
    }

    if (word == sum)
    {
        printf("word (%d) = sum of numbers(%ld)", word, sum);
    }
    else {

        printf("word (%d) != sum of numbers(%ld)", word, sum);
    }
    fclose(n);
    return 0;
}
bool bukv(char letter) {
    if ((90 >= letter && letter >= 65) || (97 <= letter && letter <= 122))  return true;
    return false;
}