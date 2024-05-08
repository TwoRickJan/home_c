//E16-Чаще всего
#include <stdio.h>

void scanfArray(int a[], int n);

int main()
{
    int n = 10;
    int a[n]; 
    int num, count, max_c;
    scanfArray(a,n);
    num = a[0];
    max_c = 1;
        
    for (int i = 0; i < n - 1; i++) {
        count = 1;
        for(int k = i + 1; k<n; k++){
            if(a[i] == a[k])
                count ++;
            if(count > max_c) {
                max_c = count;
                num = a[i];
            }
        }
    }
    if(max_c > 1)
        printf("%d",num);

    return 0;
}

void scanfArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

}