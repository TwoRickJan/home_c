#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "temp_func.h"




int MonthMinT(sensor info[], int number, int month_num){
    int minT = INT_MAX;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && info[i].t < minT)
            minT = info[i].t;
    return minT;
}
int MonthMaxT(sensor info[], int number, int month_num){
    int maxT = INT_MIN;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month && maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}
float MonthAvgT(sensor info[], int number, int month_num){
    float AvgT = 0;
    int cnt = 0;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month)
        {
            AvgT += info[i].t;
            cnt++;
        }
        return AvgT / cnt;
}

void print_month_statistic(FILE *fp,int month){
    int num_str_size = file_line_cnt(fp)+1;
    sensor *info;
    info = malloc(num_str_size*sizeof(sensor));
    int ErV[12] = {0};
    int no_err_size = AddInfo(fp,info,ErV);
    int NuValue = 0;
    if(NuValue = NuValue_month_cnt(info,num_str_size,month)){
        printf("\n # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
        printf("%2d %4d  %2d %6d %7d %10.2f %8d %8d\n\n\n",month-1,YEAR,month,
                                                NuValue,
                                                ErV[month-1],
                                                MonthAvgT(info,num_str_size,month),
                                                MonthMaxT(info,num_str_size,month),
                                                MonthMinT(info,num_str_size,month));}
    else
            printf("--------------------No info for month %d-------------------\n\n\n",month);
}

void print_year_statistic(FILE *fp)
{
    int num_str_size = file_line_cnt(fp)+1;
    
    sensor *info;
    info = malloc(num_str_size*sizeof(sensor));
    
    int ErV[12] = {0};
    
    int no_err_size = AddInfo(fp,info,ErV);
    /*for(int i =0;i<12;i++){
        printf("%d ",ErV[i]);
    }*/
    int NuValue = 0;

    
    printf("\n # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
   
    for(int i = 0;i<12;i++){
        if((NuValue = NuValue_month_cnt(info,num_str_size,i+1)))
            printf("%2d %4d  %2d %6d %7d %10.2f %8d %8d\n",i,YEAR,i+1,
                                                NuValue,
                                                ErV[i],
                                                MonthAvgT(info,num_str_size,i+1),
                                                MonthMaxT(info,num_str_size,i+1),
                                                MonthMinT(info,num_str_size,i+1));
        else
            printf("--------------------No info for month %d-------------------\n",i+1);
    }
    printf("------------------------------------------------------------\n");
    printf("Year ststistic average is %0.2f, max is %d,min is %d\n\n\n\n",YearAvgT(info,no_err_size),YearMaxT(info,no_err_size),YearMinT(info,no_err_size));
    
}

int NuValue_month_cnt(sensor info[], int number, int month_num){
    int cnt = 0;
    for (int i = 0; i < number; i++)
        if (month_num == info[i].month)
            cnt++;
    return cnt;
}

float YearAvgT(sensor info[], int number)
{
    float AvgT = 0;
    int i = 0;
    for (; i < number; i++)
            AvgT += info[i].t;
    return AvgT / i;
}

int YearMaxT(sensor info[], int number){
    int maxT = INT_MIN;
    for (int i = 0; i < number; i++)
        if (maxT < info[i].t)
            maxT = info[i].t;
    return maxT;
}

int YearMinT(sensor info[], int number)
{
    int minT = INT_MAX;
    for (int i = 0; i < number; i++)
        if (info[i].t < minT)
            minT = info[i].t;
    return minT;
}

int AddInfo(FILE *fp,sensor info[],int ErV[]){
    char file_str[30] = "\0";
    char *endptr = NULL;
    int counter = 0;
    
    while(my_getline(fp,file_str))
    {
        
        info[counter].year = strtol(file_str,&endptr,10);
        info[counter].month = strtol(endptr+1,&endptr,10);
        info[counter].day = strtol(endptr+1,&endptr,10);
        info[counter].hour = strtol(endptr+1,&endptr,10);
        info[counter].min = strtol(endptr+1,&endptr,10);
        info[counter].t = strtol(endptr+1,&endptr,10);
        
        if(!(is_in_form(file_str)&&is_cor_val(info[counter])))
        {
            if(info[counter].month-1>=0&&info[counter].month-1<12){
                ErV[info[counter].month-1]++;
            }
            counter--;       
        }
        /*
        else                
            printf("%04d-%02d-%02d %02d:%02d  temperature = %d\n",  info[counter].year,
                                                            info[counter].month,
                                                            info[counter].day,
                                                            info[counter].hour,
                                                            info[counter].min,
                                                            info[counter].t);*/
        counter++;  
    }
    
    info[counter].year = strtol(file_str,&endptr,10);
    info[counter].month = strtol(endptr+1,&endptr,10);
    info[counter].day = strtol(endptr+1,&endptr,10);
    info[counter].hour = strtol(endptr+1,&endptr,10);
    info[counter].min = strtol(endptr+1,&endptr,10);
    info[counter].t = strtol(endptr+1,&endptr,10);
    if(!(is_in_form(file_str)&&is_cor_val(info[counter])))
    {
        if(info[counter].month-1>=0&&info[counter].month-1<12){
            ErV[info[counter].month-1]++;
        }
        counter--;       
    }
    else {
    info[counter].year = strtol(file_str,&endptr,10);
    info[counter].month = strtol(endptr+1,&endptr,10);
    info[counter].day = strtol(endptr+1,&endptr,10);
    info[counter].hour = strtol(endptr+1,&endptr,10);
    info[counter].min = strtol(endptr+1,&endptr,10);
    info[counter].t = strtol(endptr+1,&endptr,10);
    /*
    printf("%04d-%02d-%02d %02d:%02d  temperature = %d\n",  info[counter].year,
                                                            info[counter].month,
                                                            info[counter].day,
                                                            info[counter].hour,
                                                            info[counter].min,
                                                            info[counter].t);*/
    }
    rewind(fp);
    
    
    return counter;
}

int is_in_form(char *str)
{
    /*printf("%c\n",*(str+4));
    printf("%c\n",*(str+7));
    printf("%c\n",*(str+10));
    printf("%c\n",*(str+13));
    printf("%c\n",*(str+16));*/
    int i = 0,s=0;
    while(str[i]!='\0')
    {
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
                //printf("incorrect format\n");
                return 0;}
        if(str[i]==';')
            s++;
        i++;
    }

    if(s==5)
    {
                //printf("correct format\n");
                return 1;
    }
    //printf("incorrect format\n");
    return 0;
}


int is_cor_val(sensor rec)
{
    int form_year = (rec.year>=2000)&&(rec.year<=2025);
    int form_month = (rec.month>=1)&&(rec.month<=31);
    int form_day = (rec.day>=1)&&(rec.day<=31); 
    int form_hour = (rec.hour>=0)&&(rec.hour<=23);
    int form_min = (rec.min>=0)&&(rec.min<=60);
    int form_t = (rec.t>=-99)&&(rec.t<=99);
    if(form_year&&form_month&&form_day&&form_hour&&form_min&&form_t)
    {
        //printf("correct value\n");
        return 1;
    }
    //printf("incorrect value\n");
    return 0;
}

int file_line_cnt(FILE *fp){
    
    int counter = 0;
    char file_str[30] = "\0";

   while(my_getline(fp,file_str))
    {
        //printf("file line size = %d; file line = %s\n",counter,file_str);
        counter++;  
    }
    //printf("file line size = %d; file line = %s\n",counter,file_str);
    rewind(fp);
    return counter;
}

int my_getline(FILE * fp,char * file_str){
    int k = 0;
    while (file_str[k]!='\0')
            file_str[k++]='\0';
    
    k = 0;
    while ((file_str[k++]=getc(fp)) != '\n')
    {
        if (file_str[k-1] == ' ')
            file_str[k-1] = '0';
        
        if (feof(fp))
        {
            file_str[strlen(file_str)-1] = '\0';
            return 0;
        }
    }
    file_str[strlen(file_str)-1] = '\0';

    return 1;
}

void cgangeIJ(sensor info[],int i, int j){
    sensor temp;
        temp=info[i];
        info[i]=info[j];
        info[j]=temp;   
}


void SortByT(sensor info[],int n){
    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j)
            if(info[i].t>=info[j].t)
                cgangeIJ(info,i,j);
}

unsigned int DateToInt(sensor info[]){
    return info->year << 16 | info->month << 8 |
           info->day;
}

void SortByDate(sensor info[],int n){
    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j)          
            if(DateToInt(info+i)>=
               DateToInt(info+j))
                  cgangeIJ(info,i,j);            
}

void DelRecord(sensor info[],int *number,int i){
    info[i].year = info[*number].year;
    info[i].month =info[*number].month; 
    info[i].day = info[*number].day;
    info[i].hour = info[*number].hour;
    info[i].min = info[*number].min;
    info[i].t = info[*number].t;
    *number = *number - 1;
}

void AddRecord(sensor info[],int *number,int i,int year,int month,int day,
                                                   int hour,int min,int t){
    info[i].year = year;
    info[i].month =month; 
    info[i].day = day;
    info[i].hour = hour;
    info[i].min = min;
    info[i].t = t;
    *number = *number - 1;
}

