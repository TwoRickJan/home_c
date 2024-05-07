//D18
#include <stdio.h>


void revfun(int num)
{
    if (num != 0){
        
        revfun(num/10); 
        printf("%d ",num%10);
    }
       
}


int main(void){
    int num;
    scanf("%d",&num);
    if(num != 0){revfun(num);}else{printf("%d",0);}
    return 0;
}
