#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 1000
#define SIZE_CHR_IN_STR 1000
#define SIZE_CHR_IN_FILE 1000

                    /*BEGIN MAIN*/
int main() {
    FILE *fp;
    fp = fopen(INPUT_, "rt");
	if (fp == NULL) {
		printf("\nCan't open file to read!");
		exit(1);
	}
    char s[SIZE_STR]="";
    int j = 0;
    while (1) {
		s[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	}
    fclose(fp);
        /*ОТКРЫТЬ ФАЙЛ (ЗАПИСЬ)*/
	fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) {
		printf("\nCan't open file to write!");
		exit(1);
	}
    char s1[SIZE_STR]="";
    char name1[SIZE_STR]="Ling",name2[SIZE_STR]="Cao";
    int s_len = strlen(s);   
    // a[SIZE_STR] = {-1};
    for(int i = 0,k=0; i < s_len;i++,k++)
    {
        if(s[i] == name1[0] && s[i+1] == name1[1] && s[i+2] == name1[2]&& s[i+3] == name1[3]){
            strcat(s1,"Cao");
            //printf("Ling");
            k+=2;
            i+=3;
        }else
        {
            s1[k]=s[i];
        }
    }
    j = 0;
    while (1) {
		putc(s1[j],fp);
		if (s1[j+2]==0) break;
		j++;
	}

    //putc(s1[0],fp);
        /*ЗАКРЫТЬ*/
    fclose(fp);
    return 0;
}