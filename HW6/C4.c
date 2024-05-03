//C4-Функция по фомрмуле

//Описать функцию вычисления f(x) по формуле:
//f(x)= x*x при -2 ≤ x < 2;
//x*x+4x+5 при x ≥ 2;
//4 при x < -2.
//Используя эту функцию для n заданных чисел, вычислить f(x). 
//Среди вычисленных значений найти наибольшее.

//Input format
//Последовательность не нулевых целых чисел, в конце последовательности число 0.

//Output format
//Одно целое число


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//int rotate(int n);
bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
bool is_space(char c)
{
    return (c == ' ');
}

bool is_null(char c)
{
    return (c == '0');
}
bool is_even(char c)
{
    return (c=='2'||c=='4'||c=='6'||c=='8'||c=='0');
}

int to_int(char c)
{
    return (c - '0');
}
int func(int x);
int main(){
    char c,c1 =' ';
    int count = 0,minus = 1,max;
    int num = 0,num_begin = 0;
    while(1)
    {
  
        c = getchar();
        if(is_null(c)&&is_space(c1)){break;}
        else if(is_digit(c))
        {
            if (is_digit(c1))
            {
                if(num == 0)
                    num += to_int(c1)*10 + to_int(c);
                else
                    num = num*10 + to_int(c);
            }else
            {
                
            }
        }else if (is_space(c)){
            if (is_digit(c1))
            {
                if(num == 0)
                    num+=to_int(c1);
                if (count == 0)
                {
                    max = func(num*minus);
                    count = 1;
                }
                if (max <= func(num*minus))
                {
                    max = func(num*minus);
                }
                
                //printf("%d ",func(num*minus));
                num = 0;
                num_begin = 0;
                minus = 1;
            }
            
        }else if (c == '-')
            {
                minus = -1;
            }
        c1 = c;
    
    }
    printf("%d ",max);
    return 0;
}



int func(int x)
{
    if ((x<2)&&(x>=-2))
    {
        return x*x;
    }
    if (x>=2)
    {
        return x*x+4*x+5;
    }
    if (x<-2)
    {
        return 4;
    }
}