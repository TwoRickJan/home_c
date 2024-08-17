//Взять К младших битов (не понял что нужно сделать) Программа берет первых К битов 
// числа N и выводит число из этих битов

#include <stdio.h>
void printbits(unsigned int v) {
  int i;
  for(i = 31; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  putchar('\n');
}
int main()
{
    int K;
    unsigned int x, N;
    scanf("%u%d",&N,&K);
    unsigned int mask = (1 << K)-1;

   printf("%u\n",N & mask);
   //printbits(mask);
}
