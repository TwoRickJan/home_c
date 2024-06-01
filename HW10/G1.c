
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE 1000


int main() {
	//const int SIZE = 40;
	char s[SIZE]="\0";
//ОТКРЫТИЕ***************************************************************
    FILE *fp;
	int j = 0;
    fp = fopen(INPUT_, "rt");
	if (fp == NULL) {
		printf("\nCan't open file to read!");
		exit(1);
	}
//ТЕЛО----------------------------------------------------------------------
    //ЧТЕНИЕ В МАССИВ*******************************************************

    while (1) {
		s[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	}
	fclose(fp);
//СОЗДАНИЕ ДЛЯ ЗАПИСИ----------------------------------------------------------------------
	fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) {
		printf("\nCan't open file to write!");
		exit(1);
	}
//
	//s[strlen(s)]='\0';
	int k = 0;
	for(int i = 0;i<3;i++)
	{
		while (1) {
			putc(s[k],fp);
			if (s[k+1] == 0)
			{
				k = 0;
				break;
			} 
			k++;
		}
		if (i!=2)
		{
			putc(',',fp);
		}
		putc(' ',fp);
		
	}
	fprintf(fp, "%d", strlen(s)-1);
	fclose(fp);


	return 0;
}