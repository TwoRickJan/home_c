//E6-Среднее 2
#include <stdio.h> 

int main() { 
    int n = 12;
    float sum = 0;
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++) 
        sum+=a[i];

    printf("%.2f",sum/n);
    return 0;

}