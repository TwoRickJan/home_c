#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE_STR 1000
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"

int main() {    
    
    
    FILE *fp;
    fp = fopen(INPUT_, "rt");
    if (fp == NULL) 
    {
		printf("\nCan't open file to read!");
		exit(1);
	}

    char s[SIZE_STR];
    fscanf(fp, "%s", s);
    
    fclose(fp);

    fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
    int s_len = strlen(s);
    for(int i = 0;i<s_len;i++)
    {
        switch(s[i])
        {
            case 'a': s[i]++;break;
            case 'b': s[i]--;break;
            case 'A': s[i]++;break;
            case 'B': s[i]--;break;
        }
    }

    fprintf(fp, "%s",s);
    fclose(fp);
	fflush(stdin);
	getchar();   
    return 0;
}