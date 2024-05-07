//D20-Возвести в степень
#include <stdio.h>


int recurs_power(int n, int p)
{
    if (p==0)
    {
        return 1;
    }
    
    if (p == 1)
        return n;
    else
        return n * recurs_power(n, p - 1);
}

int main()
{
    int num,p;
    scanf("%d%d",&num,&p);
    printf("%d",recurs_power(num, p));

    return 0;
}
    
   