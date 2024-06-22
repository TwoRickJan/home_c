#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
// #include "temp_api.h"

void print_help();
typedef struct
{
    uint8_t min;   // минтуты
    uint8_t hour;  // часы
    uint8_t day;   // дни
    uint8_t month; // месяц
    uint16_t year; // год
    int8_t t;      // температу
} sensor;

void AddRecord(sensor info[], int number, uint16_t year, uint8_t month, uint8_t day, int8_t t, int8_t min, int8_t hour)
{

    info[number].min = min;
    info[number].hour = hour;
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].t = t;
}
/*
   ===================Добавление нескольких записей без файла
*/
int AddInfo(sensor info[])
{
    int counter = 0;
    AddRecord(info, counter++, 2021, 9, 16, 9, 30, 4);
    AddRecord(info, counter++, 2022, 9, 2, -9, 30, 4);
    AddRecord(info, counter++, 2021, 1, 7, 8, 30, 4);
    AddRecord(info, counter++, 2021, 9, 5, 1, 30, 4);
    return counter;
}
/*
    ===================Вывод массива структур
*/
void print(sensor info[], int number)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d %d:%d t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].min,
               info[i].t);
}
/*
    ===================Средняя температура по месяцу
*/
float MonthMeanT(sensor info[], int number, int month_num)
{
    float meanT = 0;
    int cnt = 0;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month)
        {
            meanT += info[i].t;
            cnt++;
        }
    return meanT / cnt;
}

/*
    ===================Средняя температура по году
*/
float YearMeanT(sensor info[], int number, int year_num)
{
    float meanT = 0;
    int cnt = 0;
    for (int i = 0; i < number; i++)
        if (year_num == info[i].year)
        {
            meanT += info[i].t;
            cnt++;
        }
    return meanT / cnt;
}

/*
    ===================Макс. температура по месяцу
*/
int MonthMaxT(sensor info[], int number, int month_num)
{
    int maxT = -274;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}
/*
    ===================Мин. температура по месяцу
*/
int MonthMinT(sensor info[], int number, int month_num)
{
    int minT = 500;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && info[i].t < minT)
            minT = info[i].t;
    return minT;
}
/*
    ===================Макс. температура по году
*/
int YearMaxT(sensor info[], int number, int year_num)
{
    int maxT = -274;
    for (int i = 0; i < number; i++)
        if (year_num == info[i].year && maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}
/*
    ===================Мин. температура по году
*/
int YearMinT(sensor info[], int number, int year_num)
{
    int minT = 500;
    for (int i = 0; i < number; i++)
        if (year_num == info[i].year && info[i].t < minT)
            minT = info[i].t;
    return minT;
}

void open_csv(FILE * fp,char * name,char * str)
{
   
    fp = fopen(name, "rt");
    if (fp == NULL)
    {
        printf("\nCan't open file to read!");
        exit(1);
    }
    else
    {
        printf("\nOpen file to read!");
    }

    fscanf(fp,"%s", &str);
    fclose(fp);
}
/*void cmd_arg_read()
{
        int rez = 0;
    while ((rez = getopt(argc, argv, "hf::m:u")) != -1)
    {
        switch (rez)
        {
        case 'f':
            printf("found arg %c = %s\n", rez, optarg);
            break;
        case 'm':
            printf("found arg %c = %s\n", rez, optarg);
            break;
        case 'h':
            print_help();
            break;
        case '?':
            printf("Error found !\n");
            break;
        }
    }
}*/


/*================================      MAIN     ================================*/

#define SIZE 1000

int main(void)
{
    FILE *fp; // переменная под файл
    sensor info[SIZE]; // массив из 1000 структур
    char * filename = "temperature_small.csv";
    //char str[SIZE] = "\0";
    
    char *c;
    int i; // для считывания одного символа
    // количество считываемых байтов
    int size = sizeof(sensor);
    // выделяем память для считываемой структуры
    sensor * ptr = malloc(size);
    fp = fopen(filename, "r");     // открываем файл для бинарного чтения
    if (!fp)
    {
        printf("Error occured while opening file \n");
        return 0;
    }
  
    // устанавливаем указатель на начало блока выделенной памяти
    //c = (char *)ptr;
    // считываем посимвольно из файла
/*     while ((i = getc(fp))!='\n')
    {
        printf("%c",i);
        *c = i;
        c++;
    } */
    char str[6][SIZE];
    int cnt_0 = 0;//номер слова в массиве строк
    int cnt_1 = 0;//номер символа в массиве строк
    sensor rec;

    
    while (1)
    {
        i = getc(fp);
        if (i != ';' && i != ' ' &&  i != '\n' )
        {
            str[cnt_0][cnt_1++] = i; 
        }
        else if (i == ';' ||  i == '\n')
        {
            printf("%d\n",cnt_0);
            /* ПРОВЕРКА ЦЕЛОСТНОСТИ РЕЗУЛЬТАТА */
            switch (cnt_0)
            {
                case 0: // ГОД
                    /* Должен иметь длину = 4 и все цифры */
                    if (strlen(str[cnt_0]) == 4)
                        for (int j = 0; j < strlen(str[cnt_0]); j++)
                        {
                            if (str[cnt_0][j]>='0'&& str[cnt_0][j]<='9')
                            {
                                rec.year += (str[cnt_0][j]-'0');
                                if (j != strlen(str[cnt_0])-1)
                                {
                                    rec.year *= 10; 
                                }
                            }
                            else
                            {
                                printf("Err. Non digit year: %s", str[cnt_0]);
                                return 0;                            
                            }
                            
                        }
                    else
                    {
                        printf("Err year lenght %d",strlen(str[cnt_0]));
                        return 0;
                    }
                    printf("year = %d\n",rec.year);
                    break;
                case 1: // МЕСЯЦ
                    /* Должен иметь длину = 2 или 1 и все цифры */
                    if (strlen(str[cnt_0]) == 2 && str[cnt_0][0]>='0'&& str[cnt_0][0]<='9'&& str[cnt_0][1]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.month = (str[cnt_0][0]-'0')*10+(str[cnt_0][1]-'0') ; 
                    }
                    else if (strlen(str[cnt_0]) == 1 && str[cnt_0][0]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.month = (str[cnt_0][0]-'0'); 
                    }
                    else
                    {
                        printf("Err in month %s",str[cnt_0]);
                        return 0;
                    }
                    printf("month = %d\n",rec.month);
                    break;
                case 2: // ДЕНЬ
                    /* Должен иметь длину = 2 или 1 и все цифры */
                    if (strlen(str[cnt_0]) == 2 && str[cnt_0][0]>='0'&& str[cnt_0][0]<='9'&& str[cnt_0][1]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.day = (str[cnt_0][0]-'0')*10+(str[cnt_0][1]-'0'); 
                    }
                    else if (strlen(str[cnt_0]) == 1 && str[cnt_0][0]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.day = (str[cnt_0][0]-'0'); 
                    }
                    else
                    {
                        printf("Err in day %s",str[cnt_0]);
                        return 0;
                    }
                    printf("day = %d\n",rec.day);
                    break;
                case 3: // ЧАС
                    if (strlen(str[cnt_0]) == 2 && str[cnt_0][0]>='0'&& str[cnt_0][0]<='9'&& str[cnt_0][1]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.hour = (str[cnt_0][0]-'0')*10+(str[cnt_0][1]-'0') ; 
                    }
                    else if (strlen(str[cnt_0]) == 1 && str[cnt_0][0]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.hour = (str[cnt_0][0]-'0'); 
                    }
                    else
                    {
                        printf("Err in hour %s",str[cnt_0]);
                        return 0;
                    }
                    printf("hour = %d\n",rec.hour);
                    break;

                case 4: // МИНУТА
                    /* Должен иметь длину = 2 или 1 и все цифры */
                    if (strlen(str[cnt_0]) == 2 && str[cnt_0][0]>='0'&& str[cnt_0][0]<='9'&& str[cnt_0][1]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.min = (str[cnt_0][0]-'0')*10+(str[cnt_0][1]-'0') ; 
                    }
                    else if (strlen(str[cnt_0]) == 1 && str[cnt_0][0]>='0'&& str[cnt_0][1]<='9')
                    {
                        rec.min = (str[cnt_0][0]-'0'); 
                    }
                    else
                    {
                        printf("Err in min %s",str[cnt_0]);
                        return 0;
                    }
                    printf("min = %d\n",rec.min);
                    break;
                case 5: // ТЕМПЕРАТУРА
                    if (str[cnt_0][0] == '-')
                    {
                        printf("DEBUG POINT 0 len %s\n",str[cnt_0]);
                        if (strlen(str[cnt_0])==3)
                        {
                            printf("DEBUG POINT 1");
                            rec.t = (str[cnt_0][2]-'0') + (str[cnt_0][1]-'0')*10;
                        }else if (strlen(str[cnt_0])==2)
                        {
                            printf("DEBUG POINT 2");
                           rec.t = (str[cnt_0][1]-'0');
                        }
                        rec.t *= -1;
                    }
                    else
                    {
                        rec.t = (str[cnt_0][1]-'0') + (str[cnt_0][0]-'0')*10;
                    }
                        printf("t = %d\n",rec.t);
                    return(0);           
                    break;             
            }
            
            cnt_0++;//переход к следующему слову
            cnt_1 = 0;// с новой строки
        }
    }
/*     printf("year = %d\n",rec.year);
    printf("month = %d\n",rec.month);
    printf("day = %d\n",rec.day);
    printf("hour = %d\n",rec.hour);
    printf("min = %d\n",rec.min);
    printf("t = %d\n",rec.t); */







/*     fscanf(fp,"%4s", &str);
    printf("%d\n",(str[0]-'0')*1000);
    printf("%d\n",(str[1]-'0')*100);
    printf("%d\n",(str[2]-'0')*10);
    printf("%d\n",str[3]-'0'); */

    //int int_year
    fclose(fp);
    // вывод на консоль загруженной структуры
/*     printf("%c %c %c %c %c %c\n", 
            ptr->year, 
            ptr->month,
            ptr->day,
            ptr->hour,
            ptr->min,
            ptr->t
    ); */
    //free(ptr);
    return 0;

}

/*================================      MAIN     ================================*/

void print_help()
{
    printf("Temp statistic app. Please enter key:\n");
    printf("-h for help.\n");
    printf("-f file_name for load this file.\n");
    printf("-m xx statistic for xx month.\n");
    printf("-u enable interractive mode.\n");
}
/*
void print_f()
{
    printf("Temp statistic app. Please enter key:\n");
    printf("-h for help.\n");
    printf("-f file_name for load this file.\n");
    printf("-m xx statistic for xx month.\n");
    printf("-u enable interractive mode.\n");
}

void print_m(optarg)
{
    printf("================================\n");
    printf("print statistic for %d month\n", optarg);
}

void print_u()
{
    printf("Temp statistic app. Please enter key:\n");

}
    printf("# Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
    printf("1 2021    2     2       0       -27      -25      -30\n");
    printf("Year statistic: averege is -0.08, max is 30, min is -47");*/