#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include "numeric.h"


/**/
void usage (FILE *fp, const char *path);
void optarg_handler(int argc, char *argv[]);

/**/

int help_flag = 0;
int roots_flag = 0; 
int iters_flag = 0; 
int test_flag = 0; 

unsigned int num_iter = 0;
int opt=0;



struct option longopts[] = {
	//fields: name, has_arg, flag, val
    { "help", no_argument, &help_flag, 1 },
    { "roots", no_argument, &roots_flag, 1 },
    { "iters", no_argument, &iters_flag, 1 },
    { "test", no_argument, &test_flag, 1 },
    { 0 }
}; 




                /*  main  */
                /*  main  */
                /*  main  */
                /*  main  */
int main(int argc, char *argv[]){
    float ig[][2] = {{-6,-0.1},{0.5,5}};
    optarg_handler(argc,argv);
    const float eps = 0.0001;
    unsigned itr1 = 0,itr2 = 0,itr3= 0,itr4=0,itr5=0,itr6=0,itr7=0;
	
	float point1 = rootFindCombine(-6,-0.1,eps,f,u,df,du,ddf,ddu,&itr1);
	float point2 = rootFindCombine(-6,-0.1,eps,f,f0,df,df0,ddf,ddf0,&itr2);
	float point3 = rootFindCombine(-6,-0.1,eps,g,u,dg,du,ddg,ddu,&itr3);
	float point4 = rootFindCombine(0.5,5,eps,f,u,df,du,ddf,ddu,&itr4);
	float point5 = rootFindCombine(0.5,5,eps,g,f0,dg,df0,ddg,ddf0,&itr5);
	float point6 = rootFindCombine(0.5,5,eps,g,u,dg,du,ddg,ddu,&itr6);	
	float point7 = rootFindCombine(0.5,5,eps,f,g,df,dg,ddf,ddg,&itr7);
	
    /*slou integral v.1*/
    float eps2 = 0.0001;
    unsigned itr_solu1 = 0;
    float s1 = calcIntegral(point1,point2,f,eps2,&itr_solu1);//printf("squere 1 =%.3f\n", s1);
    float s2 = calcIntegral(point1,point3,u,eps2,&itr_solu1);//printf("squere 2 =%.3f\n", s2);
    float s3 = calcIntegral(point3,point5,g,eps2,&itr_solu1);//printf("squere 3 =%.3f\n", s3);
    float s4 = calcIntegral(point2,point7,f,eps2,&itr_solu1);//printf("squere 4 =%.3f\n", s4);
    float s5 = calcIntegral(point5,point7,g,eps2,&itr_solu1);//printf("squere 5 =%.3f\n", s5);
    float solu1 = s4-s5+s1-s2-s3;
    
    unsigned itr_solu2 = 0;
    float s6 = calcIntegral(point4,point7,f,eps2,&itr_solu2);//printf("squere 6 =%.3f\n", s6);
    float s7 = calcIntegral(point4,point6,u,eps2,&itr_solu2);//printf("squere 7 =%.3f\n", s7);
    float s8 = calcIntegral(point6,point7,g,eps2,&itr_solu2);//printf("squere 8 =%.3f\n", s8);
    float solu2 = s6-s7-s8;
    
    unsigned itr_solu3 = 0;
    float solu3 = solu1 - solu2;
    
    if (help_flag) {
        usage (stdout, argv[0]);
    }
    
    if (roots_flag)
    {
        printf("----------------------------------------------\n");
        printf("             roots of eqautions:\n");
        printf("----------------------------------------------\n");
        printf("root of eq.1 = %.3f\n",point1);
        printf("root of eq.2 = %.3f\n",point2);
        printf("root of eq.3 = %.3f\n",point3);
        printf("root of eq.4 = %.3f\n",point4);
        printf("root of eq.5 = %.3f\n",point5);
        printf("root of eq.6 = %.3f\n",point6);
        printf("root of eq.7 = %.3f\n",point7);
    }
    if (iters_flag)
    {
        printf("----------------------------------------------\n");
        printf("             iteration for eqautions:\n");
        printf("----------------------------------------------\n");
        printf("iter for eq.1 = %u\n",itr1);
        printf("iter for eq.2 = %u\n",itr2);
        printf("iter for eq.3 = %u\n",itr3);
        printf("iter for eq.4 = %u\n",itr4);
        printf("iter for eq.5 = %u\n",itr5);
        printf("iter for eq.6 = %u\n",itr6);
        printf("iter for eq.7 = %u\n",itr7);
    }
    printf("----------------------------------------------\n");
    printf("             SOLUTIONS:\n");
    printf("----------------------------------------------\n");
    printf("solution 1 = %.3f\n", solu1);
    printf("solution 2 = %.3f\n", solu2);
    printf("solution 3 = %.3f\n", solu3);
    
    if (test_flag)
    {
        float analytical_s1 = 40.315934;
        float analytical_s2 = 7.48841;
        float analytical_s3 = 32.827524;
        printf("----------------------------------------------\n");
        printf("      compare numerical and analytical:\n");
        printf("----------------------------------------------\n");
        printf("error reletive analytical solution 1: %.2f\%\n",fabs(analytical_s1-solu1)/analytical_s1*100);
        printf("error reletive analytical solution 2: %.2f\%\n",fabs(analytical_s2-solu2)/analytical_s2*100);
        printf("error reletive analytical solution 3: %.2f\%\n",fabs(analytical_s3-solu3)/analytical_s3*100);
        printf("----------------------------------------------\n");
    }
    


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
    fprintf (fp, "  -h or --help\t\t"
                 "print help and exit.\n");
    fprintf (fp, "  -r or --roots \t"
                 "print all find roots of functions.\n");
    fprintf (fp, "  -i or --iters\t"
                 "print algorithms number of iteration of algorithm.\n");
    fprintf (fp, "  -t or --tests\t"
                 "compare of numerical and analytical solutions.\n\n\n");
}



void optarg_handler(int argc, char *argv[]){
        while ( (opt = getopt_long(argc,argv,"hrit",longopts,0)) != -1){
        switch (opt){
            case 'h': 
                help_flag = 1; 
                break;
            case 'r': 
                roots_flag = 1;
                break;
            case 'i': 
                iters_flag = 1;
                break;
            case 't': 
                test_flag = 1;
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
