// B13 - Количество четных и нечетных цифр в числе
//
// input: Одно целое число 
// output: Два числа через пробел. Количество четных и нечетных цифр в числе.


#include<stdio.h> 
int main()
{
   int n;
    int j=0,i=0;
   scanf("%d",&n);
   while(n){
       if(n%10%2==0){i++;}else{j++;}
       n/=10;
   }
   printf("%d %d",i,j);

return 0;
}

