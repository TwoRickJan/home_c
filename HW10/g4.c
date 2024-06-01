
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_WORD 1000
#define SIZE_TXT 1000
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"

void sovpadenye_bykv(char *w1,char *w2,char *output){    
    int f1 = 0,f2 = 0;
    int w1_len,w2_len;
    w1_len = strlen(w1);
    w2_len = strlen(w2);
    for(int i = 0,s = 0;i<w1_len;i++)
    {
        /*ISHETSYA POVTOR VNYTRY SLOVA*/
        for(int k = 0;k<w1_len;k++)
            if(w1[i]==w1[k]&&i!=k)
                f1 = 1;
        /*ISHETSYA POVTOR VO 2OM SLOVE*/
        if(f1 == 0)
            for(int j = 0;j<w2_len;j++)
                if(w1[i]==w2[j])
                    f2++;
        /*ESLI VO 2OM SLOVE ROVNO 1 SOVPADENYE*/
        if(f2==1)
        {
            output[s++] = w1[i];
            output[s++] = ' ';
        }
        f1 = 0;
        f2 = 0;
    }
}
int main() {

    char w1[SIZE_WORD]="";
    char w2[SIZE_WORD]="";
    char output[SIZE_TXT]="";
    /*ОТКРТЬ ЧТЕНИЕ*/
    FILE *fp;
	int i, j, n = 0;
    fp = fopen(INPUT_, "rt");
    
	if (fp == NULL) {
		printf("\nCan't open file to read!");
		exit(1);
	}
    fscanf(fp, "%s %s", w1,w2);
    //printf("%s %s",w1,w2);
    sovpadenye_bykv(w1,w2,output);
    //printf("%s",output);
    
    fclose(fp);

    fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) {
		printf("\nCan't open file to write!");
		exit(1);
	}
    fprintf(fp, "%s",output);
    fclose(fp);


    return 0;
}