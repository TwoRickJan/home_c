//B20 - Проверка на простоту
//Проверить число на простоту.

//Input format
//Натуральное число

//Output format
//Если число является простым напечатать YES, иначе NO

# include<stdio.h> 

int main() 
{ 
    int n;
    scanf("%d",&n);
    if(n==1){printf("NO"); return 0;}
    for (int i = 2; i < n; i++)
    {
        
        if(n%i==0){printf("NO"); return 0;}
    }

    printf("YES");
    return 0; 
} 