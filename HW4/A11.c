#include <stdio.h>


int main(){
	int a,b,c,d,e,max,min, sum;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	
	if((a>=b)&&(a>=c)&&(a>=d)&&(a>=e)){max =a;}
	if((b>=a)&&(b>=c)&&(b>=d)&&(b>=e)){max =b;}
	if((c>=a)&&(c>=b)&&(c>=d)&&(c>=e)){max =c;}
	if((d>=a)&&(d>=b)&&(d>=c)&&(d>=e)){max =d;}
	if((e>=a)&&(e>=b)&&(e>=c)&&(e>=d)){max =e;}

	if((a<=b)&&(a<=c)&&(a<=d)&&(a<=e)){min =a;}
	if((b<=a)&&(b<=c)&&(b<=d)&&(b<=e)){min =b;}
	if((c<=a)&&(c<=b)&&(c<=d)&&(c<=e)){min =c;}
	if((d<=a)&&(d<=b)&&(d<=c)&&(d<=e)){min =d;}
	if((e<=a)&&(e<=b)&&(e<=c)&&(e<=d)){min =e;}
    sum = max+min;
	printf("%d", sum);
	return 0;
}
