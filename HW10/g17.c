#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 1000
#define SIZE_CHR_IN_STR 1000
#define SIZE_CHR_IN_FILE 1000

void divine_str(char *s,int *sp_char, int *sp_adrs,char *s1);
void swap_neighbor_str(char *s1,char *s2);
void paste_char(char *s,char *s3,char *s2,int *sp_adrs,int *sp_char);
void g17_f(char *s,char *s3);

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
    char s3[SIZE_STR]="";
    g17_f(s,s3);
    j=0;
    while (1) {
		putc(s3[j],fp);
		if (s3[j+2]==0) break;
		j++;
	}

    //putc(s1[0],fp);
        /*ЗАКРЫТЬ*/
    fclose(fp);
    return 0;
}
                    /*END MAIN*/

void g17_f(char *s,char *s3)
{
    char s1[SIZE_STR]="",s2[SIZE_STR]="";
    //char s3[SIZE_STR]="";
    int sp_char[SIZE_STR]={0},sp_adrs[SIZE_STR]={0};
    divine_str(s,sp_char,sp_adrs,s1);
    swap_neighbor_str(s1,s2);
    paste_char(s,s3,s2,sp_adrs,sp_char);
}

void divine_str(char *s,int *sp_char, int *sp_adrs,char *s1)
{
    int s_len = strlen(s);
    int i = 0,k = 0,j = 0;
    for(; i < s_len;i++)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {
            s1[k++] = s[i];
        }
        else
        {
           sp_adrs[j] = i;
           sp_char[j++] = s[i];
        }
    }
}
void swap_neighbor_str(char *s1,char *s2)
{
    int s1_len = strlen(s1);
    for(int i = 0,k = 0; i < s1_len;)
    {
        s2[k++]=s1[i+1];
        s2[k++]=s1[i];
        i+=2;
    }
}
void paste_char(char *s,char *s3,char *s2,int *sp_adrs,int *sp_char)
{
    int j = 0,k=0;
    for(int i = 0; i < strlen(s);i++)
    {
        if(i==sp_adrs[j])
            s3[i]=sp_char[j++];
            //printf("%c",sp_char[j++]);
        else
            s3[i]=s2[k++];
            //printf("%c",s2[k++]);
    }
}