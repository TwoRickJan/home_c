//C17-Сумма цифр равна произведению
#include <stdio.h>
int is_happy_number(int n)
{
        int sum = 0, prod = 1; 
        while (n != 0) 
        { 
            prod *= n % 10;
            sum  += n % 10;
            n = n/10; 
        }
        if (sum == prod){
            printf("YES");
            return 0;
        }else{
            printf("NO");
            return 0;
        }



}

#include<stdio.h> 
int main()
{
    int n;
    scanf("%d",&n);
    is_happy_number(n);
    return 0;
}
