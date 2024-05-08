//E5-Сумма положительных элементов

#include <stdio.h> 

int main() { 
    int n = 10;
    int sum = 0;
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++) 
        if(a[i]>0)
            sum+=a[i];

    printf("%d",sum);
    return 0;

}
