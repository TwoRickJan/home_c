#include <stdio.h>
#include <math.h>
#define eps 0.0001
int factorial(int n);
double sin_i(int i, double x);
double power(double x, int n);



int main(){
    float x,diff;
    
    scanf("%f",&x);
    x /= (180/3.1415);
    float sinus = sin_i(0,x),sinus_save;
    //printf("%f\n",x);
    for(int i = 1; i < 50;i++)
    {
       sinus_save = sinus;
       sinus += sin_i(i,x);
       diff = (sinus - sinus_save);
       if((diff<eps)&&(diff>-eps)){break;}
    }
    printf("%.3f\n",sinus);
    //printf("%f\n",sin(x));

    /*while(){
        n=1
        my_sin = (pow(-1,n-1)*x(2*n-1))/fact(2*n-1);
    }*/
        

    return 0;
}




int factorial(int n)
{
    int result = 1, i;
 
    // loop from 2 to n to get the factorial
    for (i = 2; i <= n; i++) {
        result *= i;
    }
 
    return result;
}
double sin_i(int i, double x)
{
    return (power(-1,i)*power(x,(2*i+1)))/factorial(2*i+1);

}
double power(double x, int n)
{
    // Initialize result to 1
    double pow = 1;

    // Multiply x for n times
    for (int i = 0; i < n; i++) {
        pow = pow * x;
    }

    return pow;
}
