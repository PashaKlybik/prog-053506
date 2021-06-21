//Task 3.2. Variant 15

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int a = 3;
const int b = 3;
const int c = 3;

int*** threeDimAlloc(int x, int y, int z) {
    int*** ptr = (int***)malloc(x * sizeof(int**));
    int i, j;
    for (i = 0; i < x; i++) {
        ptr[i] = (int**)malloc(y * sizeof(int*));
        for (j = 0; j < y; j++) {
            ptr[i][j] = (int*)malloc(z * sizeof(int));
        }
    }
    return ptr;
}

int** twoDimAlloc(int x, int y) {
    int** twoDimArr = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++) {
        twoDimArr[i] = (int*)malloc(y * sizeof(int));
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            twoDimArr[i][j] = 0;
        }
    }
    return twoDimArr;
}

void twoDimDisplay(int** arr, int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void twoDimClear(int** arr, int x) {
    int i;
    for (i = 0; i < x; i++) {
        free(arr[i]);
    }
    free(arr);
}

void threeDimClear(int*** arr, int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int*** xyz = NULL;
    xyz = threeDimAlloc(a, b, c);
    int** xy = twoDimAlloc(a, b);
    int** xz = twoDimAlloc(a, c);
    int** yz = twoDimAlloc(b, c);
    xyz[0][0][0] = 1;
    xyz[1][1][0] = 1;
    xyz[0][2][1] = 1;
    xyz[2][1][0] = 1;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                if (xyz[i][j][k] == 1) {
                    if (xy[i][j] == 0) xy[i][j] = 1;
                    if (xz[i][k] == 0) xz[i][k] = 1;
                    if (yz[j][k] == 0) yz[j][k] = 1;
                }
            }
        }
    }
    printf("XY projection\n");
    twoDimDisplay(xy, a, b);
    printf("\n\nXZ projection\n");
    twoDimDisplay(xy, a, c);
    printf("\n\nYZ projection\n");
    twoDimDisplay(yz, b, c);
    twoDimClear(xy, a);
    twoDimClear(xz, a);
    twoDimClear(yz, b);
    threeDimClear(xyz, a, b);
    return 0;
}