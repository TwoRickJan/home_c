#include <stdio.h>


int main(){

    unsigned long long int a,n = 1;
    scanf("%llu",&a);
    if(a == 1){
        printf("%llu",a);
        return 0;    
    }
    for (unsigned long long int i = 2; i <= a; i++)
    {
        n*=2;
    }


    printf("%llu",n);

    return 0;
}