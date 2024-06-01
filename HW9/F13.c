// F13-Количество элементов
#include <stdio.h>
#define SIZE 10

void scan_mas_1d(int a[]);
void print_mas_1d(int a[]);
int count_between(int from, int to, int size, int a[]);

int count_between(int from, int to, int size, int a[])
{
    int cnt = 0;
    int tmp;
    if (to < from)
    {
        tmp = from;
        from = to;
        to = tmp;
    }
    else if (to == from)
    {
        for (int i = 0; i < size; i++)
            if (from == a[i])
                cnt ++;
        return cnt;
    }
    for (int i = 0; i < size; i++)
    {
        if (from <= a[i] && a[i] <= to)
        {
            cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    int a[SIZE];
    int from, to;
    scanf("%d%d", &from, &to);
    printf("Scning\n");
    scan_mas_1d(a);
    printf("Printing\n");
    print_mas_1d(a);
    printf("\n%d", count_between(from, to, SIZE, a));
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
