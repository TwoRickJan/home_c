#include <stdio.h>

int main(){
	int x1,x2,y1,y2;
	float k,b;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	k = 1.*(y2-y1)/(x2-x1);
	b = 1.*y1-1.*(y2-y1)/(x2-x1)*x1;
	printf("%.2f %.2f",k,b);

	return 0;
}
