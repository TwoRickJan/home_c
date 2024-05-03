//численный косинус
#include <stdio.h>
#include <math.h>
#define eps 0.0001
int factorial(int n);
double sin_i(int i, double x);
double cos_i(int i, double x);
double power(double x, int n);
double cosinus(float x){
    float cosinus = cos_i(0,x),cosinus_save,diff;
    for(int i = 1; i < 50;i++)
    {
       cosinus_save = cosinus;
       cosinus += cos_i(i,x);
       diff = (cosinus - cosinus_save);
       if((diff<eps)&&(diff>-eps)){break;}
    }

    return cosinus;
}



int main(){
    float x;
    
    scanf("%f",&x);
    x /= (180/3.1415);

    
    printf("%.3f\n",cosinus(x));
    //printf("%.3f\n",cos(x));

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
double cos_i(int i, double x)
{
    return (power(-1,i)*power(x,(2*i)))/factorial(2*i);

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
