//D8-Числа от A до B
#include <stdio.h>
void rev_one_to_N(int a, int b){
    if(a>=b){
        printf("%d ",a);
        if(a>b) rev_one_to_N(a-1,b);
    }else if(a<=b){
        
        if(a<b) rev_one_to_N(a,b-1);
        printf("%d ",b);
    }
    
}

int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    rev_one_to_N(a,b);
    return 0;
}
