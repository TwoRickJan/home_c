#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, cnt = 10, dg_cnt = 1;
    num = cnt;
    int new_num = 0;
    do // подсчет кол-ва цифр
    {
        dg_cnt *= 10;
        num /= 10;
    } while (num);

    num = cnt;
    dg_cnt /= 10;
    printf("%d", dg_cnt);
    int f = 0;
    do
    {
        if (f == 0)
        {
            printf("\n%d", cnt / dg_cnt);
        }
        else
        {
            printf("\n%d", cnt / dg_cnt % 10);
        }
        f = 1;
        dg_cnt /= 10;
        num /= 10;

    } while (num);

    return 0;
}