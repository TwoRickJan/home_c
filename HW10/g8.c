#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define INPUT_ "input.txt"
#define OUTPUT_ "output.txt"

#define SIZE_STR 1000
int exrct_int(char *s,int *a);
void swap(int* arr, int i, int j);
void bubbleSort(int arr[], int n);

                    /*BEGIN MAIN*/
int main() {

    FILE *fp;
    fp = fopen(INPUT_, "rt");
    if (fp == NULL) 
    {
		printf("\nCan't open file to read!");
		exit(1);
	}
            /*ПОЛУЧЕНИЕ СТРОК*/
    char s[SIZE_STR],j=0;
    while (1) {
		s[j] = getc(fp);
		if (feof(fp)) break;
		j++;
	}

    int a[50]={0};
    int num = 0,k=0,f1 = 0;
    /*SBORKA CHISEL V MASSIV INT*/
    int a_len = exrct_int(s,a);
    /*SORTIROVKA*/
    bubbleSort(a,a_len);

        
    fclose(fp);
    fp = fopen(OUTPUT_, "wt");

	if (fp == NULL) 
    {
		printf("\nCan't open file to write!");
		exit(1);
	}
    for(int i = 0; i < a_len;i++)
        fprintf(fp,"%d ",a[i]);
    
    
    fclose(fp);
	fflush(stdin);
    return 0;
}

                    /*END MAIN*/


/*STR CHISEL V MASSIV INT. VOZVRAT LENGTH INT ARR*/
int exrct_int(char *s,int *a)
{
    int s_len = strlen(s);
    int num = 0,k=0,f1 = 0;
    for(int i = 0;i<=s_len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num = num*10+(s[i]-'0');
            f1 = 1;
        }
        else if (f1)
        {
            //printf("%d ",num);
            a[k] = num;
            k++;
            num = 0;
            f1=0;
        }
    }
    return k;
}


// Swap function
void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}
 