//B19 - Сумма цифр равна 10
//Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
//
//Input format
//Натуральное число

//Output format
//YES или NO

# include<stdio.h> 

int main() 
{ 
    int n;
    scanf("%d",&n);
    int sum = 0; 
    while (n != 0) 
    { 
        sum = sum + n % 10; 
        n = n/10; 
    } 
  
  if (sum == 10)
  {
    printf("YES");
    return 0;
  }
  printf("NO");

  return 0; 
} 