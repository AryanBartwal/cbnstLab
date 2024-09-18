#include <stdio.h>

// Function to perform Gaussian elimination (upper triangular form)
void gaussianElimination(float matrix[20][20], int n) {
    int i, j, k;
    float ratio;

    // Loop to apply elimination to all rows
    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            ratio = matrix[k][i] / matrix[i][i];  // Calculate the ratio to eliminate below element
            for (j = i; j <= n; j++) {  // Perform row operations for all columns (including constants)
                matrix[k][j] -= ratio * matrix[i][j];
            }
        }
    }
}

// Function to perform back substitution
void backSubstitution(float matrix[20][20], float result[20], int n) {
    int i, j;
    // Start from the last row and move upwards
    for (i = n - 1; i >= 0; i--) {
        result[i] = matrix[i][n];  // Start with the constant term (last column)
        for (j = i + 1; j < n; j++) {
            result[i] -= matrix[i][j] * result[j];  // Subtract known variable terms
        }
        result[i] /= matrix[i][i];  // Divide by the coefficient of the variable
    }
}

int main() {
    int n, i, j;
    float matrix[20][20], result[20];  // Declare matrix and result array for variables

    // Input the number of variables
    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    // Input the augmented matrix (coefficients + constants)
    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {  // j goes up to n (to include the constant column)
            scanf("%f", &matrix[i][j]);
        }
    }

    // Perform Gaussian elimination to form upper triangular matrix
    gaussianElimination(matrix, n);

    // Perform back substitution to solve for variables
    backSubstitution(matrix, result, n);

    // Output the results (solutions to the variables)
    printf("The solutions are:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, result[i]);
    }

    return 0;
}                                                                                             