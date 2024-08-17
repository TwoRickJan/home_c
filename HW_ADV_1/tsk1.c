/* На стандартном потоке ввода задается натуральное число N (N > 0), после которого следует
 * последовательность из N целых чисел.
 * На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается
 * максимум.
 * Указание: использовать массивы запрещается.
 * Пример №1
 * Данные на входе: 6 1 2 3 2 0 3
 * Данные на выходе: 2
 * Пример №2
 * Данные на входе: 3 5 2 -1
 * Данные на выходе: 1
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX(c,b) (((c) < (b)) ? (b) : (c)) 

int main()
{
	int n,a,cnt = 0;
	int max = INT_MIN;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a);
		if (max != MAX(a,max)){
		    max = MAX(a,max);
		    cnt = 1;
		    if(i==n-1)
		        cnt++;
		}
		else if (a == max){
		    cnt++;
		}
	}
	//printf("%d\n",max);
	printf("%d",cnt);
	return 0;
}