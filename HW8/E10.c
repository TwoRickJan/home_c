//E10-Циклический сдвиг вправо на 4
#include <stdio.h>
int main() { 
    int n = 12;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for (int i = 8; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    for (int i = 0; i < n-4; i++)
    {
        printf("%d ",a[i]);
    }



    return 0;
}