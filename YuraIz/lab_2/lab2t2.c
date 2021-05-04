#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fact(double a) {
        if(a == 0) return 1;
        for(int i = a - 1; i > 0; i--) {
                a *= i;
        }
        return a;
}

double power(double a, int n) {
        if(n == 0) {
                return 1;
        }
        for(int a2 = a; n > 1; n--) {
                a *= a2;
        }
        return a;
}

double partOfDecomposition(double x, int n) {
        return ((n % 2) ? 1 : -1) * ((power(x, 2 * n - 1) / fact(2 * n - 1)));
}

struct LastPOD {
        double x;
        int n;
        double value;
} lastPOD;


double newPOD(double x, int n) {
        if(lastPOD.x == x - 1 && lastPOD.n == n - 1) {
                lastPOD.x++;
                lastPOD.n++;
                lastPOD.value = lastPOD.value * x / n;
                return lastPOD.value;
        }
        double output = (n % 2) ? 1 : -1;
        for(int i = 1; i <= 2 * n - 1; output *= x / i++);
        lastPOD.x = x;
        lastPOD.n = n;
        lastPOD.value = output;
        return output;
}

double decomposition(double x, int n) {
        double output = 0;
        for(int i = 1; i < n; i++) {
                output += newPOD(x, i);
        }
        return output;
}

int main() {
        double x = 20;
        double e = 0.1;
        //printf("x = ");
        //scanf("%lf", &x);
        int n = 10000;
        for(int x = 0; x <= 30; x++) {
                //printf("sin(x) = %.50lf\n", sin(x));
                //if((int)decomposition(x, n)) {
                printf("x: %d\n", x);
                printf("%lf\n", decomposition(x, n));
                printf("%lf\n", sin(x));
                // break;
         //}
        }
}