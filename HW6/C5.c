#include <stdio.h>
int funcsum(int a)
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        sum += i;
    }
    
    return sum;
}

int main(){

    int a;
    scanf("%d",&a);
    printf("%d",funcsum(a));
    return 0;
}