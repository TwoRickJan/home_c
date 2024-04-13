#include <stdio.h>

int main(){

	int num;
	scanf("%d",&num);
	printf("%d", num/100+num%100/10+num%100%10);
	return 0;

}