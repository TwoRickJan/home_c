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
    char s[SIZE][SIZE_STR],n = 0;
    char *p[SIZE];
	while (1) {
		fscanf(fp, "%s", &s[n][0]);
		p[n++] = &s[n][0];
		if (feof(fp)) break;
	}
    
    fclose(fp);
    fp = fopen(OUTPUT_, "wt");

	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}



    fprintf(fp, "Hello, %s %s!", p[1],p[0]);
    fclose(fp);
    fclose(fp);
	fflush(stdin);
    getchar();
    return 0;
}

                    /*END MAIN*/


 