//D5-Перевод в двоичную систему

#include <stdio.h>
void dec_to_bin(int num)
{
    if(num!=0)
    {
        
        dec_to_bin(num/2);
        printf("%d",num%2);
    }

}

int main(void){
    int num;
    scanf("%d",&num);
    if(num != 0){dec_to_bin(num);}else{printf("%d",0);}

    return 0;
}