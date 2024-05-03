// B1 - Квадраты и кубы
// input: int number <= 100
// output: Для каждого из чисел от 1 до введенного числа 
//			напечатать квадрат числа и его куб.
#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",i);
		printf("%d ",i*i);
		printf("%d\n",i*i*i);
	}
	return 0;
}