// Iterative

#include<stdio.h>
#include<math.h>

float polyFunc(float x) {
    return (2 * x - (log(x) / log(10)) - 7);  
}

float xForm(float x) {
    return (7 + (log(x) / log(10))) / 2; 
}

int steps = 0;

void callIterative(float x, float allowErr) {
    float newX = xForm(x);
    steps++;
    printf("%d Iteration, the value of x = %f\n", steps, newX);

    if(fabs(polyFunc(newX)) <= allowErr) {
        printf("Converged after %d iterations.\n", steps);
        return;
    }


    callIterative(newX, allowErr);
}

int main() {
    float x0, error;

    
    printf("Enter the initial guess: \n");
    scanf("%f", &x0);
    printf("Enter the allowable error: \n");
    scanf("%f", &error);

   
    callIterative(x0, error);

    return 0;
}
