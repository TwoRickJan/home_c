#include <stdio.h>


int mybits(unsigned int v)
{
	int i;
	int f = 1;
	int cnt = 0;
	for(i = 31; i >= 0; i--)
	{
	    if(((v >> i) & 1)&&f)
	        f = 0;
	    if(!f&&!((v >> i) & 1))
	    {
	      //putchar(((v >> i) & 1)+'0');
	      cnt++;   
	    }
	}
	//putchar('\n');
	return cnt;
}

int main()
{
	unsigned N;
	unsigned cnt = 0;
	unsigned K;
	scanf("%u%d",&N,&K);
	for(int i = N;i>0;i--)
	{
	    if(K==mybits(i))
            cnt++;
	}
	printf("%d",cnt);
	return 0;
}
