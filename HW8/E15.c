
//E15-Разложить по двум
#include <stdio.h> 
void scanfArray(int a[], int n);
void ZeroArray(int a[], int n);

int main() { 
    int n = 10;
    int a[n],a1[n],a2[n];
    //инпут
    scanfArray(a,n);
    ZeroArray(a1,n);
    ZeroArray(a2,n);
    for (int i = 0; i < n; i++)
    {
        if (a[i]>0)
        {
            a1[i]=a[i];
        }
        if (a[i]<0)
        {
            a2[i]=a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a1[i]!=0)
        {
            printf("%d ",a1[i]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if (a2[i]!=0)
        {
            printf("%d ",a2[i]);
        }
        
    }

    return 0;
}


void scanfArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

}
void ZeroArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        a[i] = 0;

}