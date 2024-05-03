// B3 - Сумма квадратов маленьких чисел
// input: int a,b <= 100 каждый
// output: Сумма квадратов от первого введенного числа до второго
#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	//if(a>=b){return 0;}
	int sum=0;
	for(int i=a;i<=b;i++)
	{
		sum+=i*i;
	}
	printf("%d ",sum);
	return 0;
}