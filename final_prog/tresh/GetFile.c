#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    FILE *file;
    char str[100] ="\0";
    //open_csv(file,"temperature_small.csv");
    file = fopen("temperature_small.csv", "rt");
    if (file == NULL)
    {
        printf("\nCan't open file to read!");
        exit(1);
    }
    else
    {
        printf("Open file to read!\n");
    }
    int k = 0,kk = 0,str_len = 0;



    
    k=0;
    kk++;
}

    
    return 0;
}