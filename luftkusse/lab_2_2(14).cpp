#include <stdio.h>
#include <math.h>

int Fact(int n);
float Recursion(float x, float accuracy, float value, float* n);
int Iter(float x, float accuracy, float* n);

int main() {
	system("chcp 1251");
    float  x = 0, counter = 1, accuracy = 0;
    printf("Введите  x: ");
    scanf("%f", &x);

    printf("Задайте точность: ");
    scanf("%f",&accuracy);

    printf("sin(x): %f\n", sinf(x));
    printf("Результат: %f\n n = %d", iter(x, accuracy, &counter), counter);
    counter = 1;
    printf("Рекурсия: %f\n ", recursion(x, accuracy, 0, &counter));

    return 0;
}

int Fact(int n) {
    return n == 0 ? 1 : n * Fact(n-1);
}

float Recursion(float x, float accuracy, float value, float* n) {
    float cur = (powf(-1,(*n)-1) * powf(x, 2*(*n)-1)/fact(2*(*n)-1));

    value -= cur;

    if(fabs(value) <  accuracy) return value;

    (*n)++;


    return (value + recursion(x, accuracy, value, n));
}

int Iter(float x, float accuracy, float* n) {
    float expression = 0, r = 0, orig = sinf(x);

    do
    {
        expression = powf(-1,(*n)-1) * powf(x, 2*(*n)-1) / fact(2*(*n)-1);
        r += expression;
        (*n)++;
    }
    while (fabs(expression - orig) <= accuracy);

    return r;
}