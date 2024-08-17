/* Cоздали набор, содержащий N (1 ≤ N ≤ 1 000 000) натуральных чисел
 * ,не превосходящих 1 000 000. Известно, что ровно одно число в этом наборе встречается один раз, а
 * остальные — ровно по два раза. Найти это число. Входные данные: в первой входной
 * строке вводится число N, затем по одному числу в строке вводятся N натуральных чисел, не
 * превосходящих 2 000 000 000. Выходные данные: ваша программа должна определить число,
 * встречающееся один раз, и вывести его на экран.
 * Указание: использовать массивы запрещается.
 */


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;//адрес на структуру новую
}



int main()
{
    //1 Считываем кол-во элементов
    //2 В цикле Читаем эдемент и записываем его в список
    int n,a;
	scanf("%d",&n);
	Node* head = NULL;
	Node* head2 = NULL;
	Node* tmp_head = NULL;
	int uniq_n;
	
	for(int i=0; i<n; i++) {
		scanf("%d",&a);
		push(&head, a);
		push(&head2, a);
	}

    tmp_head = head;
    int cnt = 0;
    while (head2) {
        //printf("%d: ", head2->value);
        while (head) {
            if(head2->value == head->value){cnt++;}
            //printf("%d ", head->value);
            head = head->next;
        }
        //printf("%d", cnt); 
        if(cnt == 1){uniq_n = head2->value;}
        cnt=0;
        head2 = head2->next;
        head = tmp_head;
        //printf("\n");      
    }
    
    printf("%d", uniq_n); 

	return 0;
}