#include <stdio.h>
#include <stdlib.h>

#define fr(i,x,y) for(int i = x; i <= y; i ++)
#define rf(i,x,y) for(int i = x; i >= y; i --)

int calc(int x){
    int y = sqrt(x);
    while(y * y < x)y ++;
    while(y * y > x)y --;

    return y;
}

int bw(int x, int n){
    int r = 1;
    while(n){
        if(n & 1)r *= x;
        x = x * x;
        n>>=1;
    }
    return r;
}

int stack[228];

int main()
{
    int n;
    scanf("%d", &n);

    int cur = 0, d = 1, last = 0;
    ///O( log10(sqrt(n))*log2(log10(sqrt(n))) )


    while(cur < n){
        int have = (calc(bw(10,d) - 1) - calc(last)) * d;

        if(cur + have < n){
            last = bw(10,d) - 1;
            cur += have;
            d ++;
        }
        else {
            int tmp = calc(last);
            tmp += (n - cur + d - 1) / d;
            int o = (n - cur) % d;
            if(o < 1)o = d;

            tmp = tmp * tmp;


            int cur_poz = 0;
            while(tmp > 0){
                stack[++ cur_poz] = tmp % 10;
                tmp /= 10;
            }

            fr(i,1, d / 2){
                int tmp = stack[i];
                stack[i] = stack[d - i + 1];
                stack[d - i + 1] = tmp;
            }

            printf("%d", stack[o]);
            return 0;
        }
    }

    return 0;
}

/*
149162536496481100

количество цифер
ласт разряд
сколько прошло
*/
