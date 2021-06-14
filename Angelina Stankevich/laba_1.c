
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define MAX_TRIPLES 20

typedef struct struct_triple {
    int side_a;
    int side_b;
    int side_c;
} triple;

bool is_pythagorean_triple(int a, int b, int c)
{
    return a * a + b * b == c * c;
}

int find_pythagorean_triples(triple* pythagorean_triples, int n)
{
    int cur_triple = 0;
    for (int c = 5; c <= INT_MAX; ++c) {
        for (int b = 2; b < c; ++b) {
            for (int a = 1; a < b; ++a) {
                if (is_pythagorean_triple(a, b, c)) {
                    pythagorean_triples[cur_triple].side_a = a;
                    pythagorean_triples[cur_triple].side_b = b;
                    pythagorean_triples[cur_triple].side_c = c;
                    if (++cur_triple == n) return n;
                }
            }
        }
    }
    return cur_triple;
}

int main(void)
{
    triple triples[MAX_TRIPLES];

    int ntriples = find_pythagorean_triples(triples, MAX_TRIPLES);
    printf("Found pythagorean_triples: %d\n", ntriples);

    for (int i = 0; i < ntriples; ++i) {
        printf("Triple #%d: %d, %d, %d\n", i, triples[i]);
    }

    return 0;
}
