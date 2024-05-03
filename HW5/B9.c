// B9 - Все цифры четные
//
// input: Одно целое число 
// output: YES/NO
#include <stdio.h>

int main() {

    int n=0,i=0,j=0;
    scanf("%d",&n);
    
    while(n)
    {   
        if(n%10%2==0){i++;};
        n/=10;j++;
        
    }
if(i==j){printf("YES");return 0;}
printf("NO");

    return 0;
}
