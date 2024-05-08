#include <stdio.h>


int NumLength(int num);
void ZeroArray(int a[], int n);
void bubbleSortLow(int a[], int n);
void printArray(int a[], int size);


int main (){
    int num;
    scanf("%d",&num);
    int n = NumLength(num);
    
    int a[n];
    ZeroArray(a,n);
    int i = 0;

    
    while (num!=0)
    {
        a[i++] = num%10;
        num/=10;
    }

    bubbleSortLow(a,n);
    num = 0;
    //printArray(a,n);
    //printf("\n\n");
    for(i = 0; i < n; i++)
    {
        num=num*10+a[i];
        
    }
    printf("%d ",num);

    return 0;
}


int NumLength(int num)
{
    int count = 0;
    while (num!=0)
    {
        count++;
        num/=10;
    }

    return count;
}

void ZeroArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        a[i] = 0;

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
