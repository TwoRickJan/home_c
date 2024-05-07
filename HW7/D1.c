//D1-От 1 до N
#include <stdio.h>


void one_to_N(int n){
    
    if(n>1) one_to_N(n-1);
    printf("%d ",n);
}

int main(void){
    int n;
    scanf("%d",&n);
    one_to_N(n);
    return 0;
}
