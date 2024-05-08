//E4-Два максимума
#include <stdio.h> 

int main() { 
    int n = 10;
    int a[n];
    //инпут
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    
    //тело
    int max1 = a[0],i_max1;
    for(int i=0;i<n;i++){
        if (max1<a[i])
        {
            max1 = a[i];
            i_max1 = i;
        }
    }

    int max2 = -2000000;    
    for(int i=0;i<n;i++){
        if(i!=i_max1)
            if (max2<a[i])
            {
                max2 = a[i];  
            }
    }    
    //оутпут
    printf("%d",max1+max2);
    return 0;

}
