#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"

#define SIZE_STR 1000
#define SIZE 1000

                    /*BEGIN MAIN*/
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
    char s1[SIZE_STR]="";
    for(int i = strlen(s)-1, int k = 0;i>=0;i--)
        s1[k++]=s[i];

    //циклом проходи с конца нового массива до точки или до 0ой поз
    //после чего перписывай все символы и в конце добваь .html


    
    fclose(fp);
    fclose(fp);
	fflush(stdin);
    getchar();
    return 0;
}

                    /*END MAIN*/


 