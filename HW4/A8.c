#include <stdio.h>

int main(){

	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if((a>b)&&(a>c)){printf("%d", a);return 0;}
	if((b>a)&&(b>c)){printf("%d", b);return 0;}
	if((c>b)&&(c>a)){printf("%d", c);return 0;}
	printf("%d", c);
    return 0;

}