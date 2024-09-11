#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x - 4*x - 9)      
#define df(x) (3*x*x - 4)           

int main()
{
    double x0, x1, f0, df0, error;
    int iteration = 0;

    printf("Enter the initial guess \n");
    scanf("%lf", &x0);
    printf("Enter the percentage error \n");
    scanf("%lf", &error);

    do
    {
        f0 = f(x0);
        df0 = df(x0);

        if(fabs(df0) < 1e-6) 
        {
            printf("Derivative too small, potential division by zero.\n");
            return -1;
        }

        x1 = x0 - f0 / df0;  
        f0 = f(x1);         
        x0 = x1;           

        iteration++;
        printf("Iteration %d: x1 = %lf, f(x1) = %lf\n", iteration, x1, f0);

    } while(fabs(f0) > error);  

    printf("The root is %lf\n", x1);
    printf("The error is %lf\n", f0);
    printf("The number of iterations is %d\n", iteration);

    return 0;
}
