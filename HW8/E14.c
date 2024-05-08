//E14-Более одного раза
#include <stdio.h>


void printArray(int a[], int size);
void scanfArray(int a[], int n);
void bubbleSortUp(int a[], int n);

int main()
{
    int n = 10;
    int a[n];
    scanfArray(a,n);
    bubbleSortUp(a,n);

    int f=0;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]==a[i+1])
        {
            f++;
            if(f == 1)
                printf("%d ",a[i]);
        } else if (a[i]!=a[i+1])
        {
            f=0;
        }
        
    }

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

void GenArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        a[i] = 0;

}

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