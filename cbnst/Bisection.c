#include<stdio.h>
#include<math.h>

#define f(x) x*x*x -4*x- 9;

int main()
{
double x0,x1,error,f0,f1,f2,mid,f3;
printf("Enter th inital guess \n");
scanf("%lf%lf",&x0,&x1);
printf("Enter the percentage error \n");
scanf("%lf",&error);
f0=f(x0);
f1=f(x1);
if(f0*f1>0)
{
    printf("Inital guess are wrong\n");
}
do
{
   mid=(x0+x1)/2;
   f3=f(mid);
   if(f0*f3<0)
   {
       x1=mid;
   }
   else
   {
       x0=mid;
   }
}while(fabs(f3)>error);
printf("The error is %lf \n",f3);
printf("The root is %lf",mid);
}
