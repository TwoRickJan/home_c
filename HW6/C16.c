//C16-Простое число
# include<stdio.h> 
int is_prime(int n){
    if(n==1){printf("NO"); return 0;}
    if(n==0){printf("NO"); return 0;}
    for (int i = 2; i < n; i++)
    {
        
        if(n%i==0){printf("NO"); return 0;}
    }

    printf("YES");
}
int main() 
{ 
    int n;
    scanf("%d",&n);
    is_prime(n);
    return 0; 
} 