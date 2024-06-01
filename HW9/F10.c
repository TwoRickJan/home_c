// F10-Упаковать строку
#include <stdio.h>
#define SIZE 1000

int main()
{
    char str[SIZE] = "";
    char str1[SIZE] = "";
    int num, dg_cnt = 1;
    int f = 0;
    scanf("%s[^.]", str);
    int i = 0, j = 0, cnt = 1;
    do
    {
        if (str[i] == str[i + 1])
            cnt++;
        else
        {
            str1[j++] = str[i];
            if (cnt <= 9)
            {
                str1[j++] = cnt + '0';
                cnt = 1;
            }
            else
            {
                // printf("Bykv bolshe 9, schitaem kol-vo bykv: %d\n", cnt);
                do // подсчет кол-ва цифр
                {
                    dg_cnt *= 10;
                    num /= 10;
                } while (num);
                // printf("razmernost num: %d\n", dg_cnt);
                num = cnt;
                // dg_cnt /= 10;
                // printf("kol-vo bykv: %d\n", cnt);
                do
                {
                    if (f == 0)
                    {
                        str1[j++] = cnt / dg_cnt + '0';
                        // printf("pervaya cifra: %c\n", str1[j-1]);
                    }
                    else
                    {
                        str1[j++] = cnt / dg_cnt % 10 + '0';
                        // printf("cifra++ : %c\n", str1[j-1]);
                    }
                    f = 1;
                    dg_cnt /= 10;
                    num /= 10;

                } while (num);
                dg_cnt = 1;
                cnt = 1;
            }
        }
        i++;
    } while (str[i] != '.');

    printf("%s", str1);

    return 0;
}
