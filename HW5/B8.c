// B8 - Ровно одна цифра 9 в числе
//
// input: Одно целое число 
// output: YES/NO

#include <stdio.h>

int main() {
    int n=0,i=0;
    scanf("%d",&n);
    
    while(n)
    {
        while(n)
        {
            if(n%10 == 9){i++;break;}
            n/=10; 
        }
        n/=10;
        //printf("%d\n",n/=10);
    }
    if(i==1){printf("YES");}else{printf("NO");}

    return 0;
}
