// B5 - cумма цифр в числе
//
// input: Одно целое число большее или равное нулю.
// output: сумма цифр числа

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
  printf("%d", sum); 
  return 0; 
} 