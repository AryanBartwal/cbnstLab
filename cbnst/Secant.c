#include<stdio.h>
#include<math.h>

#define f(x) x*x*x -4*x-9;

int main()
{
    double x0,x1,x2,f0,f1,f2,error;
    int ittration=0;
    printf("Enter the inital Guess \n");
    scanf("%lf %lf",&x0,&x1);
    printf("Enter the percentage error \n");
    scanf("%lf",&error);

    f0=f(x0);
    f1=f(x1);
    if(f0*f1>0)
    {
        printf("Intital Guess are wrong \n");
        return -1;
    }
do{
    x2=x1-(f1*(x1-x0)/(f1-f0));
    f2=f(x2);

    x0=x1;
    x1=x2;
    f0=f1;
    f1=f2;
    ittration++;
      printf("Iteration %d: x2 = %lf, f(x2) = %lf\n", ittration, x2, f2);
}while(fabs(f2)>error);

    printf("The root is %lf\n", x2);
    printf("The error is %lf\n",f2 );
    printf("The number of iterations is %d\n", ittration);

    return 0;

}
