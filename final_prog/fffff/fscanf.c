#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int getline(FILE * file,char * file_str);
int main()
{
    FILE *file;
    //open_csv(file,"temperature_small.csv");
    file = fopen("temperature_big.csv", "rt");
    if (file == NULL)
    {
        printf("\nCan't open file to read!");
        exit(1);
    }
    else
    {
        printf("Open file to read!\n");
    }
    char file_str[30] = "\0";
    int SENSOR_SIZE = 0;
    while(getline(file,file_str))
    {
        SENSOR_SIZE++;  
    }

    fclose(file);
    return 0;   
}
int getline(FILE * file,char * file_str)
{
    int k = 0;
    while ((file_str[k++]=getc(file)) != '\n')
    {
        if (file_str[k-1] == ' ')
        {
            file_str[k-1] = '0';
        }
        
        if (feof(file))
        {
            printf("%s\n",file_str);
            printf("eof found\n");
            return 0;
        }
    }
    file_str[strlen(file_str)-1] = '\0';
    printf("%s\n",file_str);
    return 1;
}

