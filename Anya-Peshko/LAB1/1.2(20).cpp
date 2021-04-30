//Task 1.2 Variant 20
#include <stdio.h>

int main()
{
    int sumInt = 0, sumFract= 0, i = 0;
    char s[30];
    printf("Enter a real number:\n");
    gets_s(s);

    while (s[i] != '.') { 
        sumInt += s[i] - '0' ;
        i++;
    }

    i++;

    while (s[i] != '\0') {
        sumFract += s[i] - '0';
        i++;
    }

    if (sumInt > sumFract)
        printf("sumInt = %d\n", sumInt);
    else if (sumFract > sumInt)
        printf("sumFract = %d\n", sumFract);
    else if (sumInt == sumFract)
        printf("sumInt = sumFract = %d\n", sumInt);

}

