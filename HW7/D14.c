//D14 - Печать все нечетные

#include <stdio.h>

 
void printf_odd()
{
    int x;
    scanf("%d", &x);
    if ((x % 2) != 0)
        printf("%d ", x);
    if (x != 0)
        printf_odd();
}
 
int main(void)
{
    printf_odd();
    return 0;
}
 
