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

    int max = strlen(p[0]);
    int j = 0,strl_i;
    for (int i = 0; i<n; i++)
    {
        strl_i = strlen(p[i]);
        if(p[i][strl_i-1] == 'a')
            j++;
    }
    fprintf(fp, "%d", j);

    fclose(fp);
    fclose(fp);
	fflush(stdin);
    getchar();
    return 0;
}

                    /*END MAIN*/


 