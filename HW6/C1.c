// C1 - Модуль числа
//Составить функцию, модуль числа и привести пример ее использования.

//Input
//Целое число

//Output
//Целое не отрицательное число

#include <stdio.h>
int absm(int n);
int main(void)
{
	int a;
	scanf("%d",&a);
	printf("%d",absm(a));
	return 0;
}
int absm(int n)
{
	if(n<0){return -n;}else{return n;}
}
