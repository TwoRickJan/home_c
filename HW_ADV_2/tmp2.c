#include <stdio.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;



size_t totalMemoryUsage(const list *head)
{
    if(head == NULL)
    {
        //printf("%ld\n",(size_t)NULL);
        return (size_t)NULL;
    }else{
        size_t sum = 0;
        while(head)
        {
            sum += head->size;
            head = head->next;
        }
        return sum;
    }
}


int main()
{
    return 0;
}