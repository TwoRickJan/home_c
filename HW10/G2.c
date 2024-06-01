/* G2-строка и цифры
  Считать число N из файла input.txt. Сформировать строку из N символов. 
  N четное число, не превосходящее 26. На четных позициях должны находится четные 
  цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в 
  порядке следования в английском алфавите. Результат записать в файл output.txt
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 1000
#define SIZE_CHR_IN_STR 1000
#define SIZE_CHR_IN_FILE 1000

int main() 
{
    /*БЛОК ИНИТ*/
    char s[SIZE_STR][SIZE_CHR_IN_STR],ch[SIZE_CHR_IN_FILE];
	char txt1[SIZE_STR],txt2[SIZE_STR]="2468246824682468";
    int n = 0,j=0;
    FILE *fp;
    
    /*ОТКРЫТЬ ФАЙЛ (ЧТЕНИЕ)*/
    fp = fopen(INPUT_, "rt");
	if (fp == NULL) {
		printf("\nCan't open file to read!");
		exit(1);
	}

    /*СОСКАНИТЬ ВСЕ СИМВОЛЫ*/
    while (1) {
		ch[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	}
	/*ЭТО ЧИСЛО В ФАЙЛЕ ИНПУТ*/
	int num = (j==1)?(ch[0]-'0'):(ch[0]-'0')*10+(ch[1]-'0');
	/*СТРКА К ЗАПИСИ В ФАЙЛ*/
	for(int i = 0,k=0,k2 = 0,f=1; i<num; i++)
	{
		if(f)
		{
			f=0;
			txt1[i] = 'A'+k;
			k++;
		}
		else
		{
			f=1;
			txt1[i] = txt2[k2++];
		}	
	}
    /*ЗАКРЫТЬ*/
    fclose(fp);
    /*ОТКРЫТЬ ФАЙЛ (ЗАПИСЬ)*/
	fp = fopen(OUTPUT_, "wt");
	if (fp == NULL) {
		printf("\nCan't open file to write!");
		exit(1);
	}
    /*ЗАПИСАТЬ В ФАЙЛ ТОЖЕ САМОЕ А ТАК ЖЕ ВЫВЕСТИ В КОНСОЛЬ*/
	
	fprintf(fp, "%s\n", txt1);

    /*ЗАКРЫТЬ*/
    fclose(fp);

    return 0;
}