#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"

#define SIZE_STR 1000
void copy_unic(char *s,char *s1);
                    /*BEGIN MAIN*/
int main() {

    FILE *fp;
    fp = fopen(INPUT_, "rt");
    if (fp == NULL) 
    {
		printf("\nCan't open file to read!");
		exit(1);
	}
    char s[SIZE_STR],j=0;
    while (1) {
		s[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	}

    char s1[SIZE_STR]="";
    copy_unic(s,s1);
    fclose(fp);
    fp = fopen(OUTPUT_, "wt");

	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
    fprintf(fp,"%s ",s1);

    fclose(fp);
    fclose(fp);
	fflush(stdin);
    getchar();
    return 0;
}

                    /*END MAIN*/




                    /*FUNC*/
void copy_unic(char *s,char *s1)
{
    int s_len = strlen(s);
    int s1_len;
    int f1 = 1,k=0,j=0;
    /*COPY UNICK CHAR V S1*/
    for(int i = 0;i<s_len;i++)
    {
        //for(int j = 0;j<s_len;j++)
            s1_len = strlen(s1);
        do{
                if(s[i]==s1[k])
                    f1 = 0;
        }while(k++<s1_len);
        if(f1&&s[i]>='a'&&s[i]<='z')
        {
            s1[j++] = s[i];
        }
        f1 = 1;
        k=0;
    }
    printf("%s ",s1);

}
 