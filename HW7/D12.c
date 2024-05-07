//D12-Вывести k раз
#include <stdio.h>

void output_k_raz(int n) {
        int sum = 0;
        int j = 0; 
        if (n == 1) {
            printf("1 ");
        } else {
            for (int i = 1; sum < n; i++) {
                sum += i;
                j = i;
            }
            output_k_raz(--n);
            printf("%d ",j);
        }
        return;
    }
int main() {
    int n;
    scanf("%d",&n);
    output_k_raz(n);
    return 0;
}