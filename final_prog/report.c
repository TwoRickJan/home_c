#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "temp_func.h"


void usage (FILE *fp, const char *path);
void optarg_handler(int argc, char *argv[]);
void open_file(FILE **fp, char *filename);



int help_flag = 0;
int filename_flag = 0;
int month_flag = 0; 

char filename[256] = "\0";
char num_month[256] = "\0";

int opt=0;

struct option longopts[] = {
	//fields: name, has_arg, flag, val
    { "help", no_argument, &help_flag, 1 },
    { "file", required_argument, NULL, 'f' },
    { "month", required_argument, NULL, 'm' },
    { 0 }
}; 





                /*  main  */
                /*  main  */
                /*  main  */
                /*  main  */
int main(int argc, char *argv[]){
	FILE *fp;
    optarg_handler(argc,argv);

    if (help_flag) {
        usage (stdout, argv[0]);
    }
    
    if (month_flag) {
        int month = strtol(num_month,NULL,10);
        if(month>=1&&month<=12) {
            if (filename_flag) {
                open_file(&fp,filename);             //opening file....
            } else {
                printf("need -f key\n");
                usage (stdout, argv[0]);
                return 0;
            }
            print_month_statistic(fp,month);
            return 0;
        } else {
            printf("month arg error"); 
            return 0;
        }
    } else if (filename_flag) {
        open_file(&fp,filename);                    //opening file....
        print_year_statistic(fp);
        return 0;
    }     
    if(!help_flag&&!month_flag&&!filename_flag)
        printf("\ntemperature sttistic program\nrerun with -h or --help for check usage\n\n\n");
    
    
    
    return 0;
};
                /*  main  */
                /*  main  */
                /*  main  */
                /*  main  */


void usage (FILE *fp, const char *path){
    const char *basename = strrchr(path, '/');
    basename = basename ? basename + 1 : path;

    fprintf (fp, "usage: %s [OPTION]\n", basename);
    fprintf (fp, "  -h or --help\t\t\t"
                 "Print help and exit.\n");
    fprintf (fp, "  -f \"file_name.scv\" \n   or  --file \"file_name.scv\"\t"
                 "for load this file.\n");
    fprintf (fp, "  -m xx or --month xx\t\t"
                 "statistic for xx month.\n\n\n");
}

void open_file(FILE **fp, char *filename){
  if ((*fp = fopen(filename, "rt")) == NULL)
    {
        printf("\nCan't open file to read!\nMaybe wrong file name. Check help (-h or --help).");
        exit(1);
    }
    //else
      //  printf("Open file to read!\n");
}


void optarg_handler(int argc, char *argv[]){
        while ( (opt = getopt_long(argc,argv,"hf:m:",longopts,0)) != -1){
        switch (opt){
            case 'h': 
                help_flag = 1; 
                break;
            case 'f': 
                strncpy (filename, optarg, sizeof (filename));
                filename_flag = 1;
                break;
            case 'm': 
                strncpy (num_month, optarg, sizeof (num_month));
                month_flag = 1;
                break;
            case '?': 
                usage (stdout, argv[0]);
                exit(1);
                break;
            default:
                break;
        };
    };
        
}
