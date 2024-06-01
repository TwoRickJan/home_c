#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 1000
#define SIZE_CHR_IN_STR 1000
#define SIZE_CHR_IN_FILE 1000

void del_space(char *s,char *s1);

                        /*BEGIN MAIN*/
int main() {
                    /*СЧИТЫВАНИЕ СТРОКИ*/
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
	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
                      /*ПРОГАММА*/
    char s1[SIZE_STR]="";
    del_space(s,s1);
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
void del_space(char *s,char *s1)
{
    int f = 1;
    int k = 0;
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
        {
            //printf("%c", s[i]);
            s1[k++]=s[i];
            f = 0;
        }
        else if (f==0)
        {
            //printf("%c", s[i]);
            s1[k++]=s[i];
            f =1;
        }

    }
}