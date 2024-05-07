//D11 - Количество двоичных 1
#include <stdio.h>
int sum_one_in_bin(int num)
{   
    int q,r; 
    static int p=0;
    if(num==0) return 0;  
    p+=num%2;
    r=num/2;
    q = dec_to_bin(r);
    return p;
}

int main(void){
    int num;
    scanf("%d",&num);
    printf("%d",dec_to_bin(num));
    return 0;
}