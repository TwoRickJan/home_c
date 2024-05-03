// B14 - Посчитать числа
// Дана последовательность ненулевых целых чисел, 
// в конце последовательности число 0. Посчитать количество чисел.
// input: Целые ненулевые числа. В конце последовательности ноль. 0 в последовательность не входит. 
// output: Количество чисел в последовательности.
#include <stdio.h>
#include <stdbool.h>
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
    return ((c-'0')%2 == 0);
}
int main(){
    char c,c1 =' ';
    int count = 0;
    while(1)
    {
        begin:
        c = getchar();
        if(is_null(c)&&is_space(c1)){break;}
        else if(is_digit(c)) {
            if (!is_digit(c1))
            {
                count++;
            }
        }
        c1 = c;
        goto begin;
            
    }
    printf("%d",count);
    return 0;
}
