//C14-Сумма цифр четна

#include<stdio.h> 
#include <stdbool.h>

void sumChetQ(int n)
{
    int sum = 0; 
    while (n != 0) 
    { 
        sum = sum + n % 10; 
        n = n/10; 
    } 
    if(sum%2 == 0){printf("YES");}else{printf("NO");}
}

int main() 
{ 
    int n;
    scanf("%d",&n);
    sumChetQ(n);
    return 0; 
} 