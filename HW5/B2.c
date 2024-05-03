// B2 - Квадраты чисел
// input: int a,b <= 100 каждый
// output: Квадраты чисел от a до b.
#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	//if(a>=b){return 0;}
	for(int i=a;i<=b;i++)
	{
		printf("%d ",i*i);
	}
	return 0;
}
