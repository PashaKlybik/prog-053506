#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_WIDTH 80

void Centralize(char* word, char* line) {
    int len = strlen(word) - 1;
    int spaces = LINE_WIDTH - len;
    int l,r;
    r = spaces/2;
    l = (spaces % 2 == 0) ? r : r+1;

    for(int i = 0; i < r+l+len-1; i++) {
            if(i >= l && i < r+len + ((len%2==0)?0 : 1))
                line[i] = word[i - l];
            else line[i] = ' ';
    }
}

int main()
{
    int n;
    scanf("%i", &n);
    fflush(stdin);
    char word[LINE_WIDTH];

    FILE* fl;
    fl = fopen("text.txt", "w");
    for(int j = 0; j < n; j++) {
        fgets(word, LINE_WIDTH, stdin);
        fflush(stdin);

        char line[LINE_WIDTH];
        Centralize(&word, &line);

        fprintf(fl, "%s\n", line);
    }
    fclose(fl);

    return 0;
}
