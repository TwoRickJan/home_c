
//E17-Только один раз
#include <stdio.h>



void scanfArray(int a[], int n);

int main() {
    int n = 10;
    int a[n], i, j, f;

    scanfArray(a,n);


    for (i=0; i< n; i++) {
        f = 1;
        for (j=0; j< n; j++) 
            if (a[i] == a[j] && i != j) {
                f = 0;
                break;
            }
        if (f == 1) printf("%d ", a[i]);
    }

    return 0;
}


void scanfArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

}