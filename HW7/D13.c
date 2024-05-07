//D13-Печать простых множителей
#include <stdio.h>
void prime_div(int n, int k) {
// k- дополнительный параметр. При вызове должен быть равен 2
// Базовый случай
    if(n == 1)
        return;
    if (k > n / 2) {
        printf("%d ",n);
        return;
    }
    if (n % k == 0) {
        printf("%d ",k);
        prime_div(n / k, k);
    }
    else {
        prime_div(n, ++k);
    }
}
int main(void) {
    int num;
    scanf("%d",&num);
    prime_div(num,2);
}