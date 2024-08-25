#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 20
#define false 0
#define true 1

float st[MAX_STACK_SIZE];

int pst=0;

void push(float v) {

	st[pst++]=v;
}
int pop() {
	if(pst<=0) {
		fprintf(stderr, "Error. Stack underflow");
		        return 1;
	} else if(pst>MAX_STACK_SIZE) {
		fprintf(stderr, "Error. Stack overflow");
		        return 1;
	}
	return st[--pst];
}

int isEmpty() {
	return (pst<=0);
}
void operate(char c) {
	float arg1=pop(),arg2=pop();

	if (c=='+') push(arg1+arg2);
	else if (c=='-') push(arg1-arg2);
	else if (c=='*') push(arg1*arg2);
	else if (c=='/') push(arg2/arg1);

}
int isDigit(char c) {

	return ((c>='0')&&(c<='9'));
}

int main(void) {
	int i=0, isMinus=false;
	int ret;
	int number;
	char c;
	
	char str[20] = "2 2 + 2 /";
	char * pSTOL = NULL;
	scanf("%[^.]s",str);
	//printf("%s",str);
	char *elm[10];
	char *ptr = strtok(str," ");
    char *ptr_copy = ptr;
    
    int s = 0;
    elm[s++] = ptr_copy;
    
	while(1)
	{
	    ptr = strtok (NULL," ");
	    
	    if(!ptr)
	        break;
	    ptr_copy = ptr;
	    elm[s++] = ptr_copy;
	}
	
	for(int j = 0;j<s;j++)
	{
	    if(isDigit(elm[j][0]))
	    {
	        number = strtol(elm[j],pSTOL,10);
	        //printf(" %0.2f \n",(float)number);
	       push((float)number);
	    }else
	    {
            operate(elm[j][0]);
	        //printf(" %s ",elm[j]);
	    }
	}
	
	printf("ans = %f\n",st[0]);

	return 0;
}