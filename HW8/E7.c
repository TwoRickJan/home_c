//E7-Инверсия половин
#include <stdio.h> 
int main() { 
    int n = 10;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for (int i = n/2-1; i >= 0; i--)
    {
        printf("%d ",a[i]);
    }
    for (int i = n-1; i >= n/2; i--)
    {
        printf("%d ",a[i]);
    }
    


    return 0;
}