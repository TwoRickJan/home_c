#include <stdio.h> 

int main() { 
    int n = 5;
    float sum = 0;
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++) 
        sum+=a[i];

    printf("%.3f",sum/n);
    return 0;

}