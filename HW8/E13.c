//E13-Вторая с конца ноль
#include <stdio.h>


void printArray(int a[], int size);
void scanfArray(int a[], int n);

int main()
{
    int n = 10;
    int a[n]; 
    scanfArray(a,n);
    for (int i = 0; i < n; i++)
    {
        if(a[i]%100/10 == 0){
            printf("%d ",a[i]);
        }
    }
    

    //printArray(a,n);


    
    return 0;
}


void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void scanfArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

}