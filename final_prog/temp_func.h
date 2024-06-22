typedef struct sensor
{
    uint8_t min;   // минтуты
    uint8_t hour;  // часы
    uint8_t day;   // дни
    uint8_t month; // месяц
    uint16_t year; // год
    int8_t t;      // температу  
}sensor;

#define YEAR 2021

void print_month_statistic(FILE *fp,int month);
void print_year_statistic(FILE *fp);
int file_line_cnt(FILE *fp);
int my_getline(FILE * fp,char * file_str);

int AddInfo(FILE *fp,sensor info[],int ErV[]);
void DelRecord(sensor info[],int *number,int i);
void AddRecord(sensor info[],int *number,int i,int year,int month,int day,
                                                   int hour,int min,int t);
int YearMaxT(sensor info[], int number);
int YearMinT(sensor info[], int number);
float YearAvgT(sensor info[], int number);

void cgangeIJ(sensor info[],int i, int j);
void SortByT(sensor info[],int n);
unsigned int DateToInt(sensor info[]);
void SortByDate(sensor info[],int n);

int is_in_form(char *str);
int is_cor_val(sensor rec);


int NuValue_month_cnt(sensor info[], int number, int month_num);


int MonthMinT(sensor info[], int number, int month_num);
int MonthMaxT(sensor info[], int number, int month_num);
float MonthAvgT(sensor info[], int number, int month_num);
