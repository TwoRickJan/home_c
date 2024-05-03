//B16 - Наибольший общий делитель
//Составить программу для вычисления НОД с помощью алгоритма Евклида. 
//Даны два натуральных числа. Найти наибольший общий делитель.
//Input format
//Два неотрицательных целых числа
//Output format
//Одно целое число наибольший общий делитель

#include<stdio.h> 
int main()
{

    int a,b;
    scanf("%d %d",&a,&b);

    while (a!=0 && b!=0){
        if (a > b){
            a=a%b;
        }
        else
        {
            b=b%a;
        }
    }
    printf("%d",a+b);
    return 0;
}
