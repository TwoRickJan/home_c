#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 1000
#define SIZE_CHR_IN_STR 1000
#define SIZE_CHR_IN_FILE 1000

#define ENG_ALPH 26

void creat_alph(int alph[2][ENG_ALPH]);
void print_alph(int alph[2][ENG_ALPH],FILE *fp);
void div_05_alph(int alph[2][ENG_ALPH]);
void count_letters(char *s, int alph[2][ENG_ALPH]);
void print_alph_rot(int alph[2][ENG_ALPH],FILE *fp);
void mod_05_alph(int alph[2][ENG_ALPH]);


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
    int alph[2][ENG_ALPH];
    int alph1[2][ENG_ALPH];
     //Cozdat pustoi massiv alphbet
    creat_alph(alph);
    creat_alph(alph1);
    count_letters(s,alph);
    count_letters(s,alph1);
    print_alph(alph,fp);
    fprintf(fp,"\n----------------div05------------------------------\n");


    div_05_alph(alph);

    print_alph(alph,fp);
    fprintf(fp,"\n----------------mod05-----------------------------\n");

    mod_05_alph(alph1);
    
    print_alph(alph1,fp);
    fprintf(fp,"\n----------------div05 rot------------------------\n");

    print_alph_rot(alph,fp);
    fprintf(fp,"\n");
     /*Vivisty alphbet
    print_alph(alph);
    printf(n);
    print_alph_rot(alph);*/
    fclose(fp);

    return 0;
}

void count_letters(char *s, int alph[2][ENG_ALPH])
{
    for(int i = 0; i<strlen(s);i++)
    {
        for(int j = 0; j<ENG_ALPH;j++)
        {   
            if(s[i] == alph[0][j])
                alph[1][j]++;
        }    
    }
}

void print_alph(int alph[2][ENG_ALPH],FILE *fp)
{
    for(int j = 0;j<ENG_ALPH;j++)
    {
        fprintf(fp,"%c " ,alph[0][j]);
    }
    fprintf(fp,"\n");
    for(int j = 0;j<ENG_ALPH;j++)
    {
        if(alph[1][j]!=0)
            fprintf(fp,"%d " ,alph[1][j]);
        else fprintf(fp,"  ");
    }
}

void print_alph_rot(int alph[2][ENG_ALPH],FILE *fp)
{
    for(int j = ENG_ALPH-1;j>=0;j--)
    {
        fprintf(fp,"%c " ,alph[0][j]);
    }
    fprintf(fp,"\n");
    for(int j = ENG_ALPH-1;j>=0;j--)
    {
        if(alph[1][j]!=0)
            fprintf(fp,"%d " ,alph[1][j]);
        else fprintf(fp,"  ");
    }
}


void creat_alph(int alph[2][ENG_ALPH])
{
    for(int j = 0, let = 'a';j<ENG_ALPH;j++)
    {
        alph[0][j] = let++;
        alph[1][j] = 0; 
    }
}
void div_05_alph(int alph[2][ENG_ALPH])
{
    int div;
    for(int j = 0;j<ENG_ALPH;j++)
    {
        alph[1][j] /= 2;
        /*
        if((alph[1][j] % 2) == 0)
                alph[1][j] /= 2;
        else
            alph[1][j] = 0;*/
    }
}

void mod_05_alph(int alph[2][ENG_ALPH])
{
    int div;
    for(int j = 0;j<ENG_ALPH;j++)
    {
        alph[1][j] %= 2;
        /*
        if((alph[1][j] % 2) == 0)
                alph[1][j] /= 2;
        else
            alph[1][j] = 0;*/
    }
}