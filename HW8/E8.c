//E8-Инверсия каждой трети
#include <stdio.h> 
int main() { 
    int n = 12;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for (int i = 3; i >= 0; i--)
    {
        printf("%d ",a[i]);
    }
    for (int i = 7; i >= 4; i--)
    {
        printf("%d ",a[i]);
    }
    for (int i = 11; i >= 8; i--)
    {
        printf("%d ",a[i]);
    }
    


    return 0;
}