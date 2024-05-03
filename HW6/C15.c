//C15-Цифры по возрастанию функцией

#include <stdio.h>

int grow_up(int n1){
        int n2;
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


int main() {
    int n1;
	
    scanf("%d",&n1);
    grow_up(n1);
    return 0;
}