//Написать прототипы
//УСЛОВИЯ
typedef struct
{
    uint8_t min;   // минтуты
    uint8_t hour;  // часы
    uint8_t day;   // дни
    uint8_t month; // месяц
    uint16_t year; // год
    int8_t t;      // температу  
}sensor;

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