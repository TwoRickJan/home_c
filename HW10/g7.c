#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"
#define SIZE_STR 10000



int main() {    
    FILE *fp;
    fp = fopen(INPUT_, "rt");
    if (fp == NULL) 
    {
		printf("\nCan't open file to read!");
		exit(1);
	}
            /*ПОЛУЧЕНИЕ СТРОК*/
    char s[SIZE_STR]="\0",j=0;
    //fscanf(fp,"%s",s);
/*     while (1) {
		s[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	} */
    /* char s[SIZE_STR];
	char *p[SIZE_STR], *temp;
    char str[SIZE_STR] */;
    while (1) {
		fscanf(fp, "%s", s);
		if (feof(fp)) break;
	}

	fclose(fp);
            
            /*ЗАПИСЬ*/
    fclose(fp);
    fp = fopen(OUTPUT_, "wt");

	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
/* fprintf(fp,"%s",s); 
printf("%s",s);  */
            /*ОБРАБОТКА*/
    unsigned int let_d = 0,let_u = 0,i = 0; 
    while(s[i] != '\0')
    {
        if(s[i]>='a'&&s[i]<='z')
            let_d++;
        else if(s[i]>='A'&&s[i]<='Z')
            let_u++;

        i++;
    }
    fprintf(fp,"%u %u",let_d,let_u);
    
       
    fclose(fp);

    return 0;
}

