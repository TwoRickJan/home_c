//C3-Среднее арифметическое

//Среднее арифметическое чисел
//Написать функцию, которая возвращает среднее арифметическое двух 
//переданных ей аргументов (параметров). int middle(int a, int b)

//Input format
//Два целых не отрицательных числа
//Output format
//Одно целое число
#include <stdio.h>
int middle(int a, int b)
{
    int avg;
    avg = (a+b)/2;
    return avg;
}

int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",middle(a,b));
    return 0;
}