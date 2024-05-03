// B12 - Наименьшая и наибольшая цифра в числе
//
// input: Одно целое число 
// output: Две цифры через пробел. Сначала наименьшая цифра числа, затем наибольшая.
#include <stdio.h>

int main() {
    int n,max,min;
	
    scanf("%d",&n);
    min=n%10;
    max=n%10;
    //if(n1%10 == n2%10){printf("YES");return 0;}
    
    while(n)
    {
        if(max<=n%10){max=n%10;};
        if(min>=n%10){min=n%10;};
        n /= 10;

    }
    printf("%d %d", min, max);
    return 0;
}
