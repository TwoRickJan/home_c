//посик последовательности битов с максимальным значением

#include <stdio.h>
void printbits(unsigned int v) {
  int i;
  for(i = 31; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  putchar('\n');
}
int main()
{
    int K;
    unsigned int x, N,max = 0;
    scanf("%u%d",&N,&K);
    unsigned int mask = (1 << K)-1;
    for (int i = 0; i < 33 - K; i++)
    {
        x = (N >> i) & mask;
        if (x > max)
            max = x;
    }
   printf("%u\n",max);
   //printbits(mask);
}

