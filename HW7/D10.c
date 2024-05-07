//D10-Проверка на проостоту
#include <stdio.h>



void is_prime(int n,int delitel);

int main(void){
    int num;
    scanf("%d",&num);
    is_prime(num,2);
    return 0;
}

void is_prime(int n, int delitel){
    if(n <= 2){
        if(n == 2){
            printf("YES");
            return;
            }
        else{
            printf("NO");return;}
    }   
    if(n % delitel == 0)
        {printf("NO");return;}
    if(delitel * delitel > n)
        {printf("YES");return;}

    return is_prime(n, delitel + 1);
}