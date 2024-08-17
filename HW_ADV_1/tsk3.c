/* Циклический побитовый сдвиг
 */

#include <stdio.h>
void printbits(unsigned int v) {
  int i;
  for(i = 31; i >= 0; i--) putchar('0' + ((v >> i) & 1));
  putchar('\n');
}

unsigned int rightrot (unsigned int a, int offset)
{
       return a>>offset|a << (32 - offset);
}
int main()
{
    int offset;
    unsigned int n;
    scanf("%u%d",&n,&offset);
    printf("%u",rightrot(n,offset));

}
