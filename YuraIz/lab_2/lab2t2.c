#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884L

struct {
        double x;
        int n;
        double value;
} podCache, dCache;

double POD(double x, int n) {
        double output = (podCache.x == x && podCache.n == n - 1) ? -podCache.value : (n % 2) ? 1 : -1;
        for(int i = (podCache.x == x && podCache.n == n - 1) ? 2 * podCache.n : 1; i <= 2 * n - 1; output *= x / i++);
        podCache.x = x;
        podCache.n = n;
        podCache.value = output;
}

double decomposition(double x, int n) {
        double output = 0;
        for(int i = 1048576; i > 2; i /= 2) {
                while(x > i * PI) {
                        x -= i * PI;
                }
        }
        if(dCache.x == x && podCache.n < n) {
                output = podCache.value;
                for(int i = podCache.n; i < n; output += POD(x, i++));
        } else {
                for(int i = 1; i < n; output += POD(x, i++));
        }
        dCache.x = x;
        dCache.n = n;
        dCache.value = output;
}

int main() {
        unsigned int n = 1000000000;
        double e = 0.01;
        double temp = 0;
        for(int i = 0; i < 10000; i++) {
                temp = decomposition(5000, i) - sin(5000);
                if(temp < e && temp > -e) {
                        printf("%d\n", i);
                        break;
                }
        }

        //printf("%.14lf\n", decomposition(5000, n));
        //printf("%.14lf\n", sin(5000));
        //for(double x = 0; x <= 40; x++) {
        //        printf("x: %d\n", x);
        //        printf("%.10lf\n", decomposition(x, n));
        //        printf("%.10lf\n", sin(x));
        //}
}