#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_functions.h"
#define SIZE 1000
#define n_char 4
#define n_str SIZE
#define n_feature 6
#define STRUCT_SIZE 10

typedef struct
{
    uint8_t min;   // минтуты
    uint8_t hour;  // часы
    uint8_t day;   // дни
    uint8_t month; // месяц
    uint16_t year; // год
    int8_t t;      // температу  
} sensor;

int is_digit(char c);
int is_length_4(char * str);
int is_length_max_2(char * str);
int is_length_3(char * str);
int is_length_max_3(char * str);
int is_all_digit(char * str,int i);

void str_to_sensor(sensor info[],char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in,int number,int err_vec[],int * itr_err_vec);

int result_debug_features(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in);

float YearMeanT(sensor info[], int number);
int YearMaxT(sensor info[], int number);
int YearMinT(sensor info[], int number);
int MonthMinT(sensor info[], int number, int month_num);
int MonthMaxT(sensor info[], int number, int month_num);
float MonthMeanT(sensor info[], int number, int month_num);
void print_and_debug_info(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in);
void my_strtok(char *str,char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in);
int debug_t(char * str);
int debug_month_min_hour_day(char * str);
int debug_year(char * str);
void printSTR(char * str);
void free_features(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in);
void str_to_6str(char *str);
void print_struct(sensor info[], int number,int err_vec[],int * itr_err_vec);

void open_csv(FILE * fp,char * name);

int main()
{
    

    char year_s[10] = "\0", month_s[10] = "\0", day_s[10] = "\0";
    char hour_s[10] = "\0", min_s[10] = "\0", t_s[10] = "\0";
    // int i = 0;
    // print_struct(rec,STRUCT_SIZE);
    char str[30] ="\0";
    char fp[30][30] = {{"2021;01;16;01;01;-47"},
                                {"2021;01;16;01;03;-44"},
                                {"2021;01;16;01;04;-43"},
                                {"2021;01;16;01;05;-0"},
                                {"2021;02;16;01;01;-xx"},
                                {"2021;02;17;01;01;-11"},
                                {"2021;03;16;01;01;-47"},
                                {"2021;0x;16;01;01;0"},
                                {"2021;01;16;01;01;1x"},
                                {"2021;06;16;01;01;25"},
                                {"202;07;16;01;01;0"},
                                {"2021;08;16;01;01;99"},
                                {"2021;09;16;01;01;18"},
                                {"2021;10;16;01;01;2"},
                                {"2021;11;16;01;01;-5"},
                                {"2021;12;16;01;01;-20"}};


    uint64_t SENSOR_SIZE = 0;
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

    while(1)
    {
        fscanf(file,"%s",file_str);
        //printf("%s, eof = %d \n",file_str,feof(file));
        if (feof(file))
        {
            rewind(file);
            break;
        }
        SENSOR_SIZE++;  
    }
    printf("SENSOR_SIZE = %d\n",++SENSOR_SIZE);
    sensor rec[SENSOR_SIZE];
    
    /*-------------BEGIN LOOP----------------*/
    int iter_err_vec = 0;
    
    int err_vec[100] = {-10};
    for (int i = 0; i < 100; i++)
    {
        err_vec[i] = -1;
    }


    for (int i = 0; i < SENSOR_SIZE; i++) // fp[i] = facanf(fp);
    {
        fscanf(file,"%s",file_str);
        my_strtok(file_str, year_s, month_s, day_s, hour_s, min_s, t_s);
        str_to_sensor(rec, year_s, month_s, day_s, hour_s, min_s, t_s, i, err_vec, &iter_err_vec); // gen int in rec
        free_features(year_s, month_s, day_s, hour_s, min_s, t_s);
        
    }



    /*--------------END LOOP----------------*/
    iter_err_vec = 0;
    //print_struct(rec,SENSOR_SIZE,err_vec,&iter_err_vec);

    char argc = '0';
    int arc_month = 3;
    int NuValue = 0, ErValue = 0;

    fclose(file);

printf(" # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");

    for (int j = 0; j < 12; j++)
    {
        ErValue = 0;
        NuValue = 0;
        for (int i = 0; i < SENSOR_SIZE; i++)
            if (rec[i].month == j+1)
            {
                iter_err_vec = 0;
                NuValue++;
                while (err_vec[iter_err_vec] != -1)
                    if (err_vec[iter_err_vec++] == i)
                        ErValue++;
            }
        printf("%2d %4d %3d %6d %7d\n", j, 2021, j+1, NuValue, ErValue);
    }

    /*     switch(argc)
        {
            case 'm':

                printf("Avg T in Month %d:t=%.0f ",arc_month,MonthMeanT(rec,STRUCT_SIZE,arc_month));
                printf("Min T :t=%.0f ",arc_month,MonthMaxT(rec,STRUCT_SIZE,arc_month));
                printf("Max T :t=%.0f \n",arc_month,MonthMinT(rec,STRUCT_SIZE,arc_month));
                break;
            case '0':
                for(int i = 0;i<12;i++)
                {
                    //printf("%2d %4d %2d\n",i,year01,i+1);
                }
                for(int i = 0;i<12;i++){
                    printf("Avg T in Month %d:t=%.0f ",i+1,MonthMeanT(rec,STRUCT_SIZE,i+1));
                    printf("Min T :t=%.0f ",i+1,MonthMaxT(rec,STRUCT_SIZE,i+1));
                    printf("Max T :t=%.0f \n",i+1,MonthMinT(rec,STRUCT_SIZE,i+1));
                }
                printf("Avg temp in year 2021 is %f\nMax temp %d\nMin temp %d\n",YearMeanT(rec, STRUCT_SIZE),YearMaxT(rec, STRUCT_SIZE),YearMinT(rec,STRUCT_SIZE));
                break;
        } */
    return 0;
}


void open_csv(FILE * fp,char * name)
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
}



int is_digit(char c){
    return (c>='0')&&(c<='9');
}
int is_length_4(char * str){
    return strlen(str) == 4;}

int is_length_max_2(char * str){
    return strlen(str) <= 2;}

int is_length_3(char * str){
    return strlen(str) == 3;}
    
int is_length_max_3(char * str){
    return strlen(str) <= 3;}
   
int is_all_digit(char * str,int i){   
    for(i; i <strlen(str);i++)
        if(!is_digit(str[i]))
            return 0;
    return 1;
}

void str_to_sensor(sensor info[],char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in,int number,int err_vec[],int * itr_err_vec)
{
    
    if(result_debug_features(year_in,month_in,day_in,hour_in,min_in,t_in)){//solver to int
        info[number].year = (year_in[0]-'0')*1000+(year_in[1]-'0')*100+(year_in[2]-'0')*10+(year_in[3]-'0');
        info[number].month = (month_in[0]-'0')*10+(month_in[1]-'0');
        info[number].day = (day_in[0]-'0')*10+(day_in[1]-'0');
        info[number].hour = (hour_in[0]-'0')*10+(hour_in[1]-'0');
        info[number].min = (min_in[0]-'0')*10+(min_in[1]-'0');
        info[number].t = (t_in[0]-'0')*10+(t_in[1]-'0');
    } else{
        err_vec[*itr_err_vec]=number;
        *itr_err_vec=*itr_err_vec+1;
        info[number].year = (year_in[0]-'0')*1000+(year_in[1]-'0')*100+(year_in[2]-'0')*10+(year_in[3]-'0');
        info[number].month = (month_in[0]-'0')*10+(month_in[1]-'0');
        info[number].day = (day_in[0]-'0')*10+(day_in[1]-'0');
        info[number].hour = (hour_in[0]-'0')*10+(hour_in[1]-'0');
        info[number].min = (min_in[0]-'0')*10+(min_in[1]-'0');
        info[number].t = (t_in[0]-'0')*10+(t_in[1]-'0');
        //printf("\nSTR_ERROR in %d\n",number);
    }

}


int result_debug_features(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in)
{
    return debug_year(year_in)*debug_month_min_hour_day(month_in)*debug_month_min_hour_day(day_in)*debug_month_min_hour_day(hour_in)*debug_month_min_hour_day(min_in)*debug_t(t_in); 

}

float YearMeanT(sensor info[], int number)
{
    float meanT = 0;
    int cnt = 0;
    for (int i = 0; i < number; i++)
            meanT += info[i].t;
            cnt++;
    return meanT / cnt;
}

int YearMaxT(sensor info[], int number)
{
    int maxT = -274;
    for (int i = 0; i < number; i++)
        if (maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}

int YearMinT(sensor info[], int number)
{
    int minT = 500;
    for (int i = 0; i < number; i++)
        if (info[i].t < minT)
            minT = info[i].t;
    return minT;
}

int MonthMinT(sensor info[], int number, int month_num)
{
    int minT = 500;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && info[i].t < minT)
            minT = info[i].t;
    return minT;
}

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

int MonthMaxT(sensor info[], int number, int month_num)
{
    int maxT = -274;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}


int debug_year(char * str){
    return is_length_4(str)&&is_all_digit(str,0);
}
    
int debug_month_min_hour_day(char * str){
    return is_length_max_2(str)&&is_all_digit(str,0);}

int debug_t(char * str){
    if(str[0]!='-') // нет минуса
        return is_length_max_2(str)&&is_all_digit(str,0);
    return is_all_digit(str,1);
}


void print_struct(sensor info[], int number,int err_vec[],int * itr_err_vec)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
     if(i == err_vec[*itr_err_vec])
      { *itr_err_vec=*itr_err_vec+1;
       /* printf("%04d-%02d-%02d %d:%d t=%3d - >",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].min,
               info[i].t);
                
                info[i].year = 0;
               info[i].month = 0;
               info[i].day = 0;
               info[i].hour = 0;
               info[i].min = 0;
               info[i].t = -128; */
        printf("Error -> %04d-%02d-%02d %d:%d t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].min,
               info[i].t);
    }else{ 
        printf("%04d-%02d-%02d %d:%d t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].min,
               info[i].t);}
    printf("===================================\n");
    *itr_err_vec=0;
}




void printSTR(char * str)
{   
    int i = 0;
    printf("STR = ");
    while(str[i]!='\n')
    {
        printf("%c",str[i++]);
    }
    putchar('\n');
}

void my_strtok(char *str,char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in)
{
    char *year_i,*month_i,*day_i;
    char *hour_i,*min_i,*t_i;
    
    year_i = strtok(str,";");
    month_i = strtok(NULL,";");
    day_i = strtok(NULL,";");
    hour_i = strtok(NULL,";");
    min_i = strtok(NULL,";");
    t_i = strtok(NULL,";");

    for(int i = 0;i<strlen(year_i);i++)
            year_in[i] = year_i[i]; 
    for(int i = 0;i<strlen(month_i);i++)
            month_in[i] = month_i[i];
    for(int i = 0;i<strlen(day_i);i++)
            day_in[i] = day_i[i];
     for(int i = 0;i<strlen(hour_i);i++)
            hour_in[i] = hour_i[i];       
     for(int i = 0;i<strlen(min_i);i++)
            min_in[i] = min_i[i];
     for(int i = 0;i<strlen(t_i);i++)
            t_in[i] = t_i[i];
    
}
void free_features(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in)
{
    for(int i = 0;i<10;i++)
            year_in[i] = '\0'; 
    for(int i = 0;i<10;i++)
            month_in[i] = '\0'; 
    for(int i = 0;i<10;i++)
            day_in[i] = '\0'; 
     for(int i = 0;i<10;i++)
            hour_in[i] = '\0';       
     for(int i = 0;i<10;i++)
            min_in[i] = '\0'; 
     for(int i = 0;i<10;i++)
            t_in[i] = '\0';     
}
void str_to_6str(char *str)
{
    char year_s[10] = "\0",month_s[10]= "\0",day_s[10]= "\0";
    char hour_s[10]= "\0",min_s[10]= "\0",t_s[10]="\0";
    
    my_strtok(str,year_s,month_s,day_s,hour_s,min_s,t_s);
    
    printf("year_s = %s\n",year_s);
    printf("month_s = %s\n",month_s);
    printf("day_s = %s\n",day_s);
    printf("hour_s = %s\n",hour_s);
    printf("min_s = %s\n",min_s);
    printf("t_s = %s\n",t_s);
}
void print_and_debug_info(char *year_in, char *month_in, char *day_in, char *hour_in, char *min_in, char *t_in)
{
    printf("==========print=======\n");
    printf("year_s = %s ",year_in);
    printf("month_s = %s ",month_in);
    printf("day_s = %s\n",day_in);
    printf("hour_s = %s ",hour_in);
    printf("min_s = %s ",min_in);
    printf("t_s = %s\n",t_in);
    printf("==========debug======= 0 - error 1 - nice\n");
    printf("year_debug = %d ",debug_year(year_in));
    printf("month_debug = %d ",debug_month_min_hour_day(month_in));
    printf("day_debug = %d\n",debug_month_min_hour_day(day_in));
    printf("hour_debug = %d ",debug_month_min_hour_day(hour_in));
    printf("min_debug = %d ",debug_month_min_hour_day(min_in));
    printf("t_debug = %d\n",debug_t(t_in)); 
    printf("\n END FUNC \n");
}
