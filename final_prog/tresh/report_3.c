#include <string.h>
#include <stdio.h>
//char *strtok(char *str, const char *sep);
#define YEAR 0
#define MONTH 1
#define DAY 2
#define HOUR 3
#define MIN 4
#define TEMP 5

void my_strtok(char *str,char * year,char *month,char *day,char *hour,char *min,char *t)
{
    char sep[]=";";
    char *istr;
    int i = 0;
    istr = strtok (str,sep);
    //printf("%s\n",istr);
    strcpy(year, istr);
    printf("%s\n",year);
    while (i<=5)
    {
      
      switch(i){
        case YEAR:

            //printf ("%d ",strlen(year));
            break;
        case MONTH:
            istr = strtok (NULL,sep);
            strcpy(month, istr);
            break;
        case DAY:
            istr = strtok (NULL,sep);
            strcpy(day, "01");
            break;
        case HOUR:
            istr = strtok (NULL,sep);
            strcpy(hour, "HU");
            break;
        case MIN:
            istr = strtok (NULL,sep);
            //strcpy(min, "01");
            //printf ("%d ",strlen(min));
            break; 
        case TEMP:
            istr = strtok (NULL,sep);
            //strcpy(t, "01");
            //printf ("%d ",strlen(t));

            
            break; 
      }
      //istr = strtok (NULL,sep);
      i++;
    }
    putchar('\n');
}

int main()
{
    char fstr1[]="2002;1;01;12;20;-xx";
/*     char fstr2[]="2002;10;01;12;20;5";
    char fstr3[]="2002;10;01;12;20;-99";
    char fstr4[]="2002;10;01;12;20;45";
    char fstr5[]="2002;10;01;12;20;-1"; */

    char year_str[4]="\0";
    char month_str[2] ="\0";
    char day_str[2] ="\0";
    char hour_str[2] ="\0";
    char min_str[2] ="\0";
    char t_str[2] ="\0";
 
    my_strtok(fstr1,year_str,month_str,day_str,hour_str,min_str,t_str);

    printf("Year = %s \n",year_str);
    printf("Month = %s \n",month_str);
    printf("Day = %s \n",day_str);
    printf("Hour = %s \n",hour_str);
    printf("Min = %s \n",min_str);
    printf("Temp = %s \n",t_str);

    
    return 0;
}