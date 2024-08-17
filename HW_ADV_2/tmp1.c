#include <stdio.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void * findMaxBlock(list *head)
{   
    if(head == NULL)
    {
        printf("NULL\n");
    }else{
        void * max = head->address;
        while(head)
        {
            max = (max<(head->address))?head->address:max;
            head = head->next;
        }
        printf("%p\n", max);
    }
}



int main()
{
    return 0;
}