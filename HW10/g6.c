#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE_STR 1000
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
int palindrom(char s[]);
int main() {    
    FILE *fp;
    fp = fopen(INPUT_, "rt");
    if (fp == NULL) 
    {
		printf("\nCan't open file to read!");
		exit(1);
	}
            /*СКАНИРОВАНИЕ и ОБРАБОТКА*/
    char s[SIZE_STR];
    fscanf(fp, "%s", s);
            /*ЗАПИСЬ*/
    fclose(fp);
        
    fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
    if(palindrom(s))
        fprintf(fp, "%s","YES");
    else
        fprintf(fp, "%s","NO");
    fclose(fp);
	fflush(stdin);
	getchar();   
    return 0;
}

int palindrom(char s[])
{
    int l, i;
    l = strlen(s);
    for (i =0;i<l/2;i++)
    {
        if (s[i]!=s[l-1-i])
            return 0;
    }
    return 1;
}