// B4 - ровно три цифры 
// Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
// input: Целое положительное число
// output: YES или NO
#include <stdio.h>

int main(void){
	int a;
	scanf("%d",&a);
	if((a/1000==0)&&(a/100!=0)){printf("YES");return 0;}
	printf("NO");
	return 0;
}