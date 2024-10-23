#include <stdio.h>

void gaussJordan(float matrix[20][20], int n) {
    int i, j, k;
    float ratio;

    for (i = 0; i < n; i++) {
        float pivot = matrix[i][i];
        for (j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        for (k = 0; k < n; k++) {
            if (k != i) {
                ratio = matrix[k][i];
                for (j = 0; j <= n; j++) {
                    matrix[k][j] -= ratio * matrix[i][j];
                }
            }
        }
    }
}

void printMatrix(float matrix[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    float matrix[20][20];

    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussJordan(matrix, n);

    printf("The solutions are:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}
