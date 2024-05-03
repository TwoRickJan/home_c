// B7 - две одинаковые цифры не рядом в числе
//
// input: Одно целое число 
// output: YES/NO

#include <stdio.h>

int main() {
    int n1,n2,n;
	int i=0,j=0;
    scanf("%d",&n);
    n1 = n;
    n2 = n;
    
    //if(n1%10 == n2%10){printf("YES");return 0;}
    
    while(n1)
    {
        //printf("%d\n", n1%10);
        while(n2)
        {
            if(i!=j)
            {
               // printf("%d ", n2%10);
                if(n1%10 == n2%10){printf("YES");return 0;}
            }
            n2 /= 10;
            j++;
        }
        j=0;
        //printf("\n");
        n1 /= 10;
        n2 = n;
        i++;
    }
    printf("NO");
    return 0;
}