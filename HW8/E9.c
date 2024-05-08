//E9-Циклический сдвиг вправо
#include <stdio.h>
int main() { 
    int n = 10;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    printf("%d ",a[n-1]);

    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}