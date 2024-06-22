//F7-Упаковать массив 0 1
#include <stdio.h>
#include <stdlib.h>
int compression(int a[], int b[], int N);

int main()
{   
    int N1 = 10;
    int a1[] = {1,1,1,0,0,1,1,1,2,1};
    int *b;
    
    compression(a1,b,N1);


    for (int i = 0; i < 10; i++)
    {
        printf("%d ",b[i]);
    }


    return 0;
}


int compression(int a[], int b[], int N)
{
    int k = 1;                                    
    int * block_mem;
    b = (int*) malloc(1);
    unsigned int sreial_count = 1;
    //////////////////////////////////////////////
    for (int i = 0; i < N; i++)
    {
        if (a[i]==1 && i==0)
        {
            block_mem = (int*) realloc (b, k * sizeof(int));
            if (block_mem != NULL)
            {
                b = block_mem;
                b[k-1] = 0; 
                k++;                     // добавить к массиву только что введённое число
            }
        }
        
        if (a[i]==a[i+1])
            sreial_count++;
        else
        {
            block_mem = (int*) realloc (b, k * sizeof(int));
            if (block_mem != NULL)
            {
                
                b = block_mem;
                b[k-1] = sreial_count;
                k++;
            }
            sreial_count = 1;
        }
        
    }
    
    
    return 0;
    
}

