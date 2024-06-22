// F5 - Максимум в массиве

#include <stdio.h>
#define SIZE 10

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);
int find_max_array(int size, int a[]);

int main(void)
{
    int a[SIZE];
    printf("Scning\n");
    scan_mas_1d(a);
    printf("Printing max: %d\n",find_max_array(SIZE, a));
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
int find_max_array(int size, int a[])
{
    int max = -2147483648;
    for (int i = 0; i < size; i++)
            if (max <= a[i])
                max = a[i];
    return max;
}

