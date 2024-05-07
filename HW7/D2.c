//D2-Сумма от 1 до N
#include <stdio.h>


int sum_one_to_N(int n){
    
    if(n<=1)
        return 1;
    int sum = n + sum_one_to_N(n-1);
    return  sum;
}

int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",sum_one_to_N(n));
    return 0;
}
