// F9-Поменять местами
// в массиве находит максимальный из отрицательных
// поменяет его местами с последним элементом.
// Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
// Прототип функции: void swap_negmax_last(int size, int a[])

#include <stdio.h>
#define SIZE 10
#define INT_MIN -2147483648

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);
void swap_negmax_last(int size, int a[]);
void swap_negmax_last(int size, int a[])
{
    int negmax = -2147483648, negmax_i;
    int tmp, f = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > negmax && a[i] < 0)
        {
            negmax = a[i];
            negmax_i = i;
            f = 1;
        }
    }
    if (f)
    {
        tmp = a[size - 1];
        a[size - 1] = a[negmax_i];
        a[negmax_i] = tmp;
    }

    // printf("\nNegmax: %d\n", negmax);
}
int main(void)
{
    int a[SIZE];
    printf("Scning\n");
    scan_mas_1d(a);

    swap_negmax_last(SIZE, a);

    printf("Printing\n");
    print_mas_1d(a);
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