#include <stdio.h>
#include <stdlib.h>
//про то как работает малок и каллок


int main()
{
    int *mas = NULL;
    it cnt = 4;
    mas = malloc(sizeof(int)*cnt);
    // не сохронит данные в массиве
    /* free(mas);
    mas = malloc(sizeof(int)*5);*/
    mas = realloc(mas, sizeof(int)*5);
    free(mas);
    mas = NULL;
    return 0;
}