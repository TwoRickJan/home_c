//F20-Четные и нечетные
#include <stdio.h>

#define SIZE_N 10

int main()
{
   // int a[] = {48,31,20,61,97,12,18,100,200,123}; 
    //int b[] = {48,31,20,61,97,12,18,100,200,123};//{48,25,57,34,23,91,90,85,30,79}; 
    int b[SIZE_N];
    int sum_odd = 0, sum_even = 0;
    int num,product;
    for (int i = 0; i < SIZE_N; i++)
            scanf("%d",&b[i]);
    
    
    for (int i = 0; i < SIZE_N; i++)
        if (b[i]%2)
            sum_even++;
        else
            sum_odd++;
    
    if (sum_odd>sum_even) //заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. 
    {   
        //printf("%d\n",sum_odd);
        for (int i = 0; i < SIZE_N; i++){
            if (b[i]%2!=0)
            {
                //printf("%d\n",b[i]);
                product=1;
                num = b[i];
                do
                {
                    if ((num%10)%2!=0)
                        product *= (num%10);
                    num/=10;
                } while (num);
                b[i] = product;
            }
        }
    }else{ //заменить каждое чётное число на произведение чётных цифр в его десятичной записи
        for (int i = 0; i < SIZE_N; i++){
            if (b[i]%2==0)
            {
                //printf("%d\n",b[i]);
                product=1;
                num = b[i];
                do
                {
                    if ((num%10)%2==0)
                        product *= (num%10);
                    num/=10;
                } while (num);
                b[i] = product;
            }
        }
    }
        for (int i = 0; i < SIZE_N; i++)
            printf("%d ",b[i]);
            

   

    return 0;
}

