#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_functions.h"
//УСЛОВИЯ


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
