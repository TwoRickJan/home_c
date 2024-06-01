// F15-Больше модуля

// Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел,
// сколько элементов превосходят по модулю максимальный элемент. Прототип функции int count_bigger_abs(int n, int a[]);
// Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
//  func  определяет в массиве сколько элементов
// это максимальный элемент по модулу?
#include <stdio.h>
#define SIZE 10

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);
int absm(int n);

int maxF(int a, int b);
int count_bigger_abs(int n, int a[])
{
    int max = a[0];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        max = (a[i] > max) ? a[i] : max;

    //printf("%d\n",max);
    for (int i = 0; i < n; i++)
        if(a[i]<=0)
        {
            if ((-1*a[i])>max){
                //printf("%d \n",a[i]);
                cnt++;  }
            
        }
        else if (a[i]>0)
        {
            if (a[i]>max)
                cnt++;
        }
    return cnt;
}
int main(void)
{
    int a[SIZE];
    printf("Scning\n");
    scan_mas_1d(a);
    printf("Printing\n");
    print_mas_1d(a);

    printf("\nABS>MAS\n");
    printf("%d",count_bigger_abs(SIZE,a));

    return 0;
}

void scan_mas_1d(int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d[^\n]", &a[i]);
    }
}
void print_mas_1d(int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
}


int maxF(int a, int b)
{
    return (a > b) ? a : b;
}

int absm(int n)
{
    return (n < 0) ? -n : n;
}
