//E2-Найти минимум
#include <stdio.h> 

int main() { 
    int n = 5;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //тело
    int min = a[0];
    for(int i=0;i<n;i++) 
        min = (min>a[i])?a[i]:min;
        
    //оутпут
    printf("%d",min);
    return 0;

}