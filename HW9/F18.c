//F18-Сумма максимумов

//Дана целочисленная квадратная матрица 10 х 10. 
//реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. 
//Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный. 
//Реализовать функцию поиска максимума в строке из SIZE_M элементов

#include <stdio.h>

#define SIZE_N 10
#define SIZE_M 10

float main_diag_avg(int a[][SIZE_M]);
void scan_matrix_2d(int a[][SIZE_M]);
void print_matrix_2d(int a[][SIZE_M]);
int cnt_elem_above_num(int a[][SIZE_M],float avg);
int max_in_row_sum(int a[][SIZE_M]);

int main()
{
    int a[SIZE_N][SIZE_M];
    //printf("Scning\n");
    scan_matrix_2d(a);
    //printf("max in row sum\n");
    printf("%d",max_in_row_sum(a));
    return 0;
}

float main_diag_avg(int a[][SIZE_M])
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < SIZE_N; i++ )
    {
        sum+=a[i][i];
        cnt++;
    }
    return sum*1./cnt;          
}

int cnt_elem_above_num(int a[][SIZE_M],float avg)
{
    int cnt=0;
    for (int i = 0; i < SIZE_N; i++)
        for (int j = 0; j < SIZE_M; j++)
           if (a[i][j]>avg)   
            cnt++;     
    return cnt;
}

void scan_matrix_2d(int a[][SIZE_M])
{
    for (int i = 0; i < SIZE_N; i++)
        for (int j = 0; j < SIZE_M; j++)
                scanf("%d[^\n]",&a[i][j]);
}

void print_matrix_2d(int a[][SIZE_M])
{
    for (int i = 0; i < SIZE_N; i++){
        for (int j = 0; j < SIZE_M; j++)
                printf("%d ",a[i][j]);
         printf("\n");}
}

int max_in_row_sum(int a[][SIZE_M])
{
    int max,sum=0;
    for (int i = 0; i < SIZE_N; i++)
    {
        for (int j = 0; j < SIZE_M; j++)
        {
            if(j==0)
                max = a[i][j];
            else if (max<a[i][j])
                max = a[i][j];
        }

        sum+=max;
        
    }
    return sum;
    
}