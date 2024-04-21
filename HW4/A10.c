#include <stdio.h>

int main(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	if((a<=b)&&(a<=c)&&(a<=d)&&(a<=e)){printf("%d", a);return 0;}
	if((b<=a)&&(b<=c)&&(b<=d)&&(b<=e)){printf("%d", b);return 0;}
	if((c<=a)&&(c<=b)&&(c<=d)&&(c<=e)){printf("%d", c);return 0;}
	if((d<=a)&&(d<=b)&&(d<=c)&&(d<=e)){printf("%d", d);return 0;}
	if((e<=a)&&(e<=b)&&(e<=c)&&(e<=d)){printf("%d", e);return 0;}

}
