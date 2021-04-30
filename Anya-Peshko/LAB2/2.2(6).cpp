//Task 2.2 Variant 6
#include <stdio.h>
#include <math.h>

const double PI = 3.14;

int fact(int a) {
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    return  a * fact(a - 1);
}

int result(int x, double e) {//computation by iteration function
    int n = 0;
    double curr = 0;
    do {
        n++;
        curr += pow(-1, n - 1 ) * pow(x, 2 * n - 1)  / fact(2 * n - 1);
    } while (fabs(sin(x) - curr) >= e);
    return n;
}

double sin(int n, double x) { //recursive computation
    if (n == 1)
        return x;
    if (((n - 1) / 2) % 2 != 0)
        return  sin(n - 2, x) - (pow(x, n) / fact(n));
    else
        return  sin(n - 2, x) + (pow(x, n) / fact(n));
}

int main(){
    double eps, x;
    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Sin x by inline function: ");
    printf("%f\n", sin(x));
    printf("Sin x by recursive function: ");
    printf("%lf\n", sin(5, x));
    printf("Enter epsilon: ");
    scanf_s("%lf", &eps);
    printf("n at which the investigated expression differs from sin x by less than the specified error e:");
    printf(" = %d \n", result(x, eps));

    return 0;
}

