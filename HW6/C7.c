//C7-Число N в P-ую систему
#include <stdio.h>
#include <math.h>
int n_to_p(int n, int p)
{

}
int main()
{
    int n,p,num = 0,count = 0;
    char c;
    scanf("%d %d",&n,&p);

    while(n)
    {   
        num += (n%p)*pow(10,count);
        count++;
        n/=p;
    }

    printf("%d",num);
    return 0;
}
