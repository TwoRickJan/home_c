//F6-Два одинаковых
#include <stdio.h>

int is_two_same(int size, int a[]);
int main() {
    int size = 6;
    int a[] = {1,2,3,4,5,0};
    
    
    is_two_same(size,a)?printf("YES"):printf("NO");

    return 0;
} 

int is_two_same(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                return 1;
            }
            
        }
        
    }
    return 0;

}