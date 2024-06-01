// F11-Сумма минимальна

#include <stdio.h>
#define SIZE 30

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);
void min_sum_i(int a[], int size);

void min_sum_i(int a[], int size)
{
    int pos1 = 0, pos2 = 1;
    int min_sum = a[0] + a[1];

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((i != j) && (a[i] + a[j] < min_sum))
            {
                min_sum = a[i] + a[j];
                if (i > j)
                {
                    pos1 = j;
                    pos2 = i;
                }
                else
                {
                    pos1 = i;
                    pos2 = j;
                }
        }
        }
    }
    //printf("\nMin sum: %d\n", min_sum);
    printf("%d %d", pos1, pos2);
}

int main(void)
{
    int a[SIZE];
   // printf("Scning\n");
    scan_mas_1d(a);
    //printf("Printing\n");
    //print_mas_1d(a);
    min_sum_i(a, SIZE);
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
