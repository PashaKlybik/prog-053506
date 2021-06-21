//Task 2.1. Variant 16

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void outputNormal(int a3, int b3, int c3, int d3) {
	if (a3 != 0) {
		printf("%d", a3);
		printf("x^3");
	}
	if (b3 > 0 && a3 != 0) {
		printf("+");
		printf("%d", b3);
		printf("x^2");
	}
	if (b3 < 0 && a3 != 0) {
		printf("%d", b3);
		printf("x^2");
	}
	if (b3 != 0 && a3 == 0) {
		printf("%d", b3);
		printf("x^2");
	}
	if (c3 > 0 && (b3 != 0 || a3 != 0)) {
		printf("+");
		printf("%d", c3);
		printf("x");
	}
	if (c3 < 0 && (a3 != 0 || b3 != 0)) {
		printf("%d", c3);
		printf("x^2");
	}
	if (c3 != 0 && (a3 == 0 && b3 == 0)) {
		printf("%d", c3);
		printf("x^2");
	}
	if (d3 > 0 && (b3 != 0 || a3 != 0 || c3 != 0)) {
		printf("+");
		printf("%d", d3);
	}
	if (d3 < 0 && (b3 != 0 || a3 != 0 || c3 != 0)) {
		printf("%d", d3);
	}
	if (d3 < 0 && (b3 == 0 && a3 == 0 && c3 == 0)) {
		printf("%d", d3);
	}
}

void outputMultiplication(int a3, int b3, int c3, int d3, int e3, int f3, int g3) {
	if (a3 != 0) {
		printf("%d", a3);
		printf("x^6");
	}
	if (b3 > 0 && a3 != 0) {
		printf("+");
		printf("%d", b3);
		printf("x^5");
	}
	if (b3 < 0 && a3 != 0) {
		printf("%d", b3);
		printf("x^5");
	}
	if (b3 != 0 && a3 == 0) {
		printf("%d", b3);
		printf("x^5");
	}
	if (c3 > 0 && (b3 != 0 || a3 != 0)) {
		printf("+");
		printf("%d", c3);
		printf("x^4");
	}
	if (c3 < 0 && (a3 != 0 || b3 != 0)) {
		printf("%d", c3);
		printf("x^4");
	}
	if (c3 != 0 && (a3 == 0 && b3 == 0)) {
		printf("%d", c3);
		printf("x^4");
	}
	if (d3 > 0 && (b3 != 0 || a3 != 0 || c3 != 0)) {
		printf("+");
		printf("%d", d3);
		printf("x^3");
	}
	if (d3 < 0 && (b3 != 0 || a3 != 0 || c3 != 0)) {
		printf("%d", d3);
		printf("x^3");
	}
	if (d3 < 0 && (b3 == 0 && a3 == 0 && c3 == 0)) {
		printf("%d", d3);
		printf("x^3");
	}
	if (e3 > 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0)) {
		printf("+");
		printf("%d", e3);
		printf("x^2");
	}
	if (e3 < 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0)) {
		printf("%d", e3);
		printf("x^2");
	}
	if (e3 < 0 && (b3 == 0 && a3 == 0 && c3 == 0 && d3 == 0)) {
		printf("%d", e3);
		printf("x^2");
	}
	if (f3 > 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0 || e3 != 0)) {
		printf("+");
		printf("%d", f3);
		printf("x");
	}
	if (f3 < 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0 || e3 != 0)) {
		printf("%d", f3);
		printf("x");
	}
	if (f3 < 0 && (b3 == 0 && a3 == 0 && c3 == 0 && d3 == 0 && e3 == 0)) {
		printf("%d", f3);
		printf("x");
	}
	if (g3 > 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0 || e3 != 0 || f3 != 0)) {
		printf("+");
		printf("%d", g3);
	}
	if (g3 < 0 && (b3 != 0 || a3 != 0 || c3 != 0 || d3 != 0 || e3 != 0 || f3 != 0)) {
		printf("%d", g3);
	}
	if (g3 < 0 && (b3 == 0 && a3 == 0 && c3 == 0 && d3 == 0 && e3 == 0 && f3 == 0)) {
		printf("%d", g3);
	}
}


void polynomialAddition(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
{
	int a3, b3, c3, d3;
	a3 = a1 + a2;
	b3 = b1 + b2;
	c3 = c1 + c2;
	d3 = d1 + d2;
	outputNormal(a3, b3, c3, d3);
}

void polynomialSubtraction(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
{
	int a3, b3, c3, d3;
	a3 = a1 - a2;
	b3 = b1 - b2;
	c3 = c1 - c2;
	d3 = d1 - d2;
	outputNormal(a3, b3, c3, d3);
}

void polynomialMultiplication(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
{
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, a3, b3, c3, d3, e3, f3, g3;
	a = a1 * a2;
	b = a1 * b2;
	c = a1 * c2;
	d = a1 * d2;
	e = b1 * a2;
	f = b1 * b2;
	g = b1 * c2;
	h = b1 * d2;
	i = c1 * a2;
	j = c1 * b2;
	k = c1 * c2;
	l = c1 * d2;
	m = d1 * a2;
	n = d1 * b2;
	o = d1 * c2;
	p = d1 * d2;
	a3 = a;
	b3 = b + e;
	c3 = c + f + i;
	d3 = d + g + j + m;
	e3 = h + k + n;
	f3 = l + o;
	g3 = p;
	outputMultiplication(a3, b3, c3, d3, e3, f3, g3);
}

void polynomialDivision(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2)
{	
	int a3, b3, c3, d3;
	if ((a1 == b1 == c1 == d1) && (a2 == b2 == c2 == d2)) {
		if (a1 > a2) {
			a3 = a1 / a2;
			b3 = b1 / b2;
			c3 = c1 / c2;
			d3 = d1 / d2;
			outputNormal(a3, b3, c3, d3);
		}
		else {
			a3 = a2 / a1;
			b3 = b2 / b1;
			c3 = c2 / c1;
			d3 = d2 / d1;
			outputNormal(a3, b3, c3, d3);
		}
	}
	else {
		printf("\nCannot further divide the polynomials");
	}	
}

void about()
{
	printf("\nAPCT: Algebraic Polynomial Calculation Tool, Made by Andrew K., 2021");
}

int main()
{
	int input;
	int a1, b1, c1, d1, a2, b2, c2, d2;
	printf("Welcome to the Algebraic Polynomial Calculation Tool, to begin, enter the polynomial coefficients\n");
	while (1) {
		printf("\nA 3 power polynomial has a form of ax^3 + bx^2 + cx + d\n");
		printf("a1 = ");
		scanf("%d", &a1);
		printf("b1 = ");
		scanf("%d", &b1);
		printf("c1 = ");
		scanf("%d", &c1);
		printf("d1 = ");
		scanf("%d", &d1);
		printf("a2 = ");
		scanf("%d", &a2);
		printf("b2 = ");
		scanf("%d", &b2);
		printf("c2 = ");
		scanf("%d", &c2);
		printf("d2 = ");
		scanf("%d", &d2);
		printf("Enter a number corresponding to an operation\n 1. Polynomial addition\n 2. Polynomial subtraction\n 3. Polynomial multiplication\n 4. Polynomial division\n 5. About\n 6. Exit\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			polynomialAddition(a1, b1, c1, d1, a2, b2, c2, d2);
			break;
		case 2:
			polynomialSubtraction(a1, b1, c1, d1, a2, b2, c2, d2);
			break;
		case 3:
			polynomialMultiplication(a1, b1, c1, d1, a2, b2, c2, d2);
			break;
		case 4:
			polynomialDivision(a1, b1, c1, d1, a2, b2, c2, d2);
			break;
		case 5:
			about();
			break;
		case 6:
			return 0;
		default:
			do
			{
				printf("\nIncorrect input, try again\n");
				scanf("%d", &input);
			} while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6);
		}
	}
	return 0;
}