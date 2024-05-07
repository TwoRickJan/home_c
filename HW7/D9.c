//D9-Сумма цифр
#include <stdio.h>
int sum_digits(int x){
    int    q,r;
    static int p=0;

    if(x == 0) return 0;    
    p+=x%10;
    r=x/10;
    
    q=sum_digits(r);
    
    return(p);

    
}

int main(void){
    int num;
    scanf("%d",&num);
    printf("%d",sum_digits(num));
    return 0;
}
