// B10 - Все цифры в порядке возрастания
//
// input: Одно целое число 
// output: YES/NO

#include <stdio.h>

int main() {
    int n1,n2;
	
    scanf("%d",&n1);
    n2=n1/10;
    
    //if(n1%10 == n2%10){printf("YES");return 0;}
    
    while(n2)
    {
        if(n1%10 <= n2%10){printf("NO");return 0;}
        n1 /= 10;
        n2 /= 10;
    }
    printf("YES");
    return 0;
}