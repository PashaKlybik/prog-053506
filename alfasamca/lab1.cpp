#include <stdio.h>
#include <math.h>
int main()
{
        for (int i = 100; i < 1000; i++)
    {
        int b = i, sum = 0;
        while (b > 9)
        {
            int a = b % 10;
            b = b / 10;
            sum += pow(a, 3);
        }
        sum += pow(b, 3);
        if (sum == i)
        {
            printf("i=%d\n", i);
        }
    }

    return 0;
}


