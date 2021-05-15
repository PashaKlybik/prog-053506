//task1.2 var19
#include <stdio.h>
int main()
{
    int s, buf3 = 0,buf5=0, coin3=0, coin5=0;
    printf("Write the s:\n");
    scanf_s("%d", &s);
    if (s > 7) {
        if (s % 5 == 0) {
            coin5 = s / 5;
        }
        else {
            buf3 = s % 5;
            buf5 = s - buf3;
            for (;;) {
                if (buf3 % 3 == 0) {
                    coin3 = buf3 / 3;
                    coin5 = buf5 / 5;
                    break;
                }
                else  {
                    buf3 = buf3 + 5;
                    buf5 = s - buf3;
                }
            }
        }
    }
    else 
    printf("Arror,Write s>7\n");
    printf("coin3=%d\n", coin3);
    printf("coin5=%d", coin5);
}
