//E18 - Кратность от 2 до 99
#include <stdio.h>

int main(){ 

    
    int num;

    scanf("%d",&num);
    for (int i = 2; i <= 9; i++)
    {
       
        printf("%d %d\n",i, num/i);
        
    }

    return 0;
}
