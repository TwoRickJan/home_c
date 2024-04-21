#include <stdio.h>

int main(){
	int a,b,c,num;
	scanf("%d",&num);

	a = num/100;
	b = num%100/10;
	c = num%100%10;

	if((a>b)&&(a>c)){printf("%d", a);}
	if((b>a)&&(b>c)){printf("%d", b);}
	if((c>b)&&(c>a)){printf("%d", c);}
	if((a==b)&&(b==c)&&(c==a)){printf("%d", c);}

	return 0;
}
