//B18 - Числа Фибоначчи
//Input format
//Одно натуральное число

//Output format
//Ряд чисел Фибоначчи через пробел

#include<stdio.h> 
int main()
{
   int n, f1 = 0, f2 = 1, fi;

   scanf("%d",&n);

   for (int i = 1 ; i <= n ; i++ )
   {
      if ( i <= 1 )
         fi = i;
      else
      {
         fi = f1 + f2;
         f1 = f2;
         f2 = fi;
      }
      printf("%d ",fi);
   }
return 0;
}
