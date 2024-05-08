//E12-По возрастанию и по убыванию
#include <stdio.h>


void bubbleSortUp(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}
void bubbleSortLow(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if(a[j] < a[j + 1]){
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
int main() { 
    int n = 10;
    int a[n],a1[n/2],a2[n/2];

    scanfArray(a,n);

    for (int i = 0; i < n/2; i++)
    {
        a1[i] = a[i];
        //printf("%d ",a1[i]);
    }
    int j = 0;
    for (int i = n/2; i < n; i++)
    {
        a2[j] = a[i];
        //printf("%d ",a2[j]);
        j++;
    }
    
    bubbleSortLow(a2,n/2);//по убыванию
    bubbleSortUp(a1,n/2);//по возпроостанию
        for (int i = 0; i < n/2; i++)
    {
        a[i] = a1[i];
        //printf("%d ",a1[i]);
    }
    j = 0;
    for (int i = n/2; i < n; i++)
    {
        a[i] = a2[j];
        //printf("%d ",a2[j]);
        j++;
    }
    printArray(a,n);
    return 0;
}