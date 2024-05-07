//D7-Печать от N до 1
#include <stdio.h>
void rev_one_to_N(int n){
    printf("%d ",n);
    if(n>1) rev_one_to_N(n-1);
    
}

int main(void){
    int n;
    scanf("%d",&n);
    rev_one_to_N(n);
    return 0;
}
