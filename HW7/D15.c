//D15-Найти наибольшее
#include <stdio.h>
#include <math.h>
int max_find() {
    int n;
    scanf("%d", &n);
    if (n == 0) 
        return -2147483648;
    else 
        return fmax(n, max_find());
}
    
int main(void) {
    //int num;
    //scanf("%d",&num);
    
    printf("%d",max_find());
    return 0;
}

