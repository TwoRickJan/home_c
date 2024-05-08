//E3-Найти минимум, максимум и их поз.
#include <stdio.h> 

int main() { 
    int n = 10;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //тело
    int min = a[0],i_min = 0;
    int max = a[0],i_max = 0;
    for(int i=0;i<n;i++){
        if (min>a[i])
        {
            min = a[i];
            i_min = i;
        }
        if (max<a[i])
        {
            max = a[i];
            i_max = i;
        }
        
        
    }    
    //оутпут
    printf("%d %d %d %d",i_max+1,max,i_min+1,min);
    return 0;

}