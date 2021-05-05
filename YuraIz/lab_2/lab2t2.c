#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884L

struct {
        double x;
        int n;
        double value;
} cache;

double POD(double x, int n) {
        double output = (cache.x == x && cache.n == n - 1) ? -cache.value : (n % 2) ? 1 : -1;
        for(int i = (cache.x == x && cache.n == n - 1) ? 2 * cache.n : 1; i <= 2 * n - 1; output *= x / i++);
        cache.x = x;
        cache.n = n;
        cache.value = output;
}

double decomposition(double x, int n) {
        double output = 0;
        for(int i = 1048576; i > 2; i /= 2) {
                while(x > i * PI) {
                        x -= i * PI;
                }
        }
        for(int i = 1; i < n; output += POD(x, i++));
}

int main() {

        double e, x, temp;
        printf("x = ");
        scanf("%lf", &x);
        printf("e = ");
        scanf("%lf", &e);
        if(e > 1e-50) {
                for(int n = 1; n < 50; n++) {
                        temp = decomposition(x, n) - sin(x);
                        if(temp < e && temp > -e) {
                                printf("n: %d\n", n);
                                return 0;
                        }
                }
        }
        printf("Such precision cannot be achieved\n");
        return 0;
}