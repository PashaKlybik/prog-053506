#include <stdio.h>
#include <stdlib.h>

void DecToBin(int);

int main()
{
    int m;
    printf("Type the border of the search M\n");
    scanf("%i", &m);

    for(int i = 7; i < m; i++)
        DecToBin(i);

    return 0;
}

void DecToBin(int num)
{
    int temp = num, power = 1, zeros = 0, ones = 0, flag = 1;
    char binary[255];
    int i = 0;

    while (temp)
    {
        int current = temp % 2;
        binary[i] = current + 48;
        power *= 10;
        i++;

        if (flag == 1)
            if (current == 0)
                if (ones % 3 != 0) return;
                else flag = 0;
        if (flag == 0)
            if (current == 1)
                if (zeros % 3 != 0) return;
                else flag = 1;

        if (current == 1) ones++;
        else if(current == 0) zeros++;


        temp /= 2;
    }

    binary[i] = '\0';

    if(zeros % 3 == 0 && ones % 3 == 0) printf("\n(DEC)\t%i\n(BIN)\t%s\n", num, binary);
}
