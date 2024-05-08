#include <stdio.h>



void bubbleSortE11(int a[], int n);
void printArray(int a[], int size);
void scanfArray(int a[], int n);


int main (){
    int n = 10;
    int a[n];
    scanfArray(a,n);
    bubbleSortE11(a,n);
    printArray(a,n);
    return 0;
}


void bubbleSortE11(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if(a[j]%10 > a[j + 1]%10){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
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