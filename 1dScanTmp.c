
#include <stdio.h>
#define SIZE 10

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);

int main(void)
{
    int a[SIZE];
    printf("Scning\n");
    scan_mas_1d(a);
    printf("Printing\n");
    print_mas_1d(a);
    return 0;
}

void scan_mas_1d(int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
       scanf("%d[^\n]",&a[i]);
    }
}
void print_mas_1d(int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
       printf("%d ",a[i]);
    }
}
