


#include <stdio.h>
 

unsigned int factorial(unsigned int n)
{
    int result = 1, i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main()
{
    int num;
    scanf("%d",&num);
    printf("%d", factorial(num));
    return 0;
}