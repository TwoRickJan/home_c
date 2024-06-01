//F19 - Больше среднего
#include <stdio.h>


float main_diag_avg(int a[][5]);
void scan_matrix_2d(int a[][5]);
void print_matrix_2d(int a[][5]);
int cnt_elem_above_num(int a[][5],float avg);

int main()
{
   // int a[] = {48,31,20,61,97,12,18,100,200,123}; 
    //int b[] = {48,31,20,61,97,12,18,100,200,123};//{48,25,57,34,23,91,90,85,30,79}; 
    int a[5][5];
    //printf("Scning\n");
    scan_matrix_2d(a);
    /*printf("Printing\n");
    print_matrix_2d(a);
    printf("Avg of major diag\n");
    printf("%.3f\n",main_diag_avg(a));
    printf("Num in matrix above avg\n");*/
    printf("%d",cnt_elem_above_num(a,main_diag_avg(a)));

    return 0;
}

float main_diag_avg(int a[][5])
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < 5; i++ )
    {
        sum+=a[i][i];
        cnt++;
    }
    return sum*1./cnt;          
}
int cnt_elem_above_num(int a[][5],float avg)
{
    int cnt=0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
           if (a[i][j]>avg)   
            cnt++;     
    return cnt;
}
void scan_matrix_2d(int a[][5])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
                scanf("%d[^\n]",&a[i][j]);
}
void print_matrix_2d(int a[][5])
{
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
                printf("%d ",a[i][j]);
         printf("\n");}
}