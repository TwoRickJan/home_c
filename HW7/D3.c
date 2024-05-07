//D3-В обратном порядке
#include <stdio.h>
void fun(int num)
{
    if (num != 0){
        printf("%d ",num%10);
        fun(num/10); 
        
    }
       
}


int main(void){
    int num;
    scanf("%d",&num);
    if(num != 0){fun(num);}else{printf("%d",0);}
    return 0;
}
