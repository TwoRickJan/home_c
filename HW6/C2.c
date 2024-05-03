//C2 - Возвести в степень
//Составить функцию, возведение числа N в 
//степень P. int power(n, p) и привести пример ее использования.

//INPUT
//Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0

//OUTPUT
//Одно целое число


#include <stdio.h>
int power(int n, int p);
int main(void)
{
	int n, p;
	scanf("%d %d",&n, &p);
	printf("%d",power(n,p));
	return 0;
}
int power(int n, int p)
{
	int save=1;
	for(int i =1; i <= p; i++)
	{
		save = save*n;
	}
	return save;
}
