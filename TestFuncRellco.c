#include <stdio.h>
#include <stdlib.h>
//про то как работает малок и каллок

/*#define SIZE_N 5
void creat_b(int a[], int b[], int size)
{
    int counter=0;
    *b = NULL;
    counter++;
    b = malloc(sizeof(int)*counter);
    b[0] = a[0];
    counter++;
    b = realloc(b,sizeof(int)*counter)
    b[1] = a[1];




}*/
int main()
{
    //int *mas = NULL;
    int a[] = {1};
    int *b = NULL;
    b = (int*)malloc(sizeof(int));
    //b = realloc(b,sizeof(int)*2);
    int *p = NULL;
    p = (int*) malloc(100);
    printf("%p\n",(int*)sizeof(p));
    printf("%p",(int*)sizeof(a));
   // mas = malloc(sizeof(int)*cnt);
    // не сохронит данные в массиве
    /* free(mas);
    mas = malloc(sizeof(int)*5);*/
    //mas = realloc(mas, sizeof(int)*5);



    //free(b);
    //b = NULL;
    return 0;
}