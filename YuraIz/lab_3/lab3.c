#include <stdio.h>
#include <stdlib.h>
//Lab 3.2(21) YuraIz
double** GaussJordan(double** matrix, int n) {
        double** invertibleMatrix = (double**)calloc(n, sizeof(double*));
        double** bigMatrix = (double**)calloc(n, sizeof(double*));
        for(int i = 0; i < n; i++) {
                invertibleMatrix[i] = (double*)calloc(n, sizeof(double));
                bigMatrix[i] = (double*)calloc(2 * n, sizeof(double));
                invertibleMatrix[i][i] = 1;
                for(int j = 0; j < n; j++) {
                        bigMatrix[i][j] = matrix[i][j];
                        bigMatrix[i][j + n] = invertibleMatrix[i][j];
                }
        }

        for(int k = 0; k < n; k++) {
                for(int i = 0; i < 2 * n; i++) {
                        bigMatrix[k][i] = bigMatrix[k][i] / matrix[k][k];
                }
                for(int i = k + 1; i < n; i++) {
                        double K = bigMatrix[i][k] / bigMatrix[k][k];
                        for(int j = 0; j < 2 * n; j++) {
                                bigMatrix[i][j] = bigMatrix[i][j] - bigMatrix[k][j] * K;
                        }
                }
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                matrix[i][j] = bigMatrix[i][j];
                        }
                }
        }

        for(int k = n - 1; k > -1; k--) {
                for(int i = 2 * n - 1; i > -1; i--) {
                        bigMatrix[k][i] = bigMatrix[k][i] / matrix[k][k];
                }
                for(int i = k - 1; i > -1; i--) {
                        double K = bigMatrix[i][k] / bigMatrix[k][k];
                        for(int j = 2 * n - 1; j > -1; j--) {
                                bigMatrix[i][j] = bigMatrix[i][j] - bigMatrix[k][j] * K;
                        }
                }
        }

        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        invertibleMatrix[i][j] = bigMatrix[i][j + n];
                }
        }

        for(int i = 0; i < n; i++) {
                free(bigMatrix[i]);
        }
        free(bigMatrix);
        return invertibleMatrix;
}

int main() {
        double TextM[3][3] = {
                {5, 2, 3},
                {1, 4, 6},
                {8, 7, 9}
        };

        double** matrix = (double**)calloc(3, sizeof(double*));
        for(int i = 0; i < 3; i++) {
                matrix[i] = (double*)calloc(3, sizeof(double));
                for(int j = 0; j < 3; j++) {
                        matrix[i][j] = TextM[i][j];
                }
        }

        double** invertibleMatrix = GaussJordan(matrix, 3);
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        printf("%2.3f, ", invertibleMatrix[i][j]);
                }
                printf("\n");
        }

        for(int i = 0; i < 3; i++) {
                free(invertibleMatrix[i]);
                free(matrix[i]);
        }
        free(invertibleMatrix);
        free(matrix);
}