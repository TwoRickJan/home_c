//Посчитать кол-во едениц в двичном представлении числа

#include <stdio.h>
void printbits(unsigned int v) {
  int i;
  for(i = 31; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  putchar('\n');
}

unsigned int cntSetOnBits(unsigned int num) {
  int cnt = 0;
  for(int i = 31; i >= 0; i--)
    if((num >> i) & 1==1) 
        cnt++;
    return cnt;
}

int main()
{
    unsigned int N;
    scanf("%u",&N);

    printf("%u\n",cntSetOnBits(N));
   //printbits(mask);
}

