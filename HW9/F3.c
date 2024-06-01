//F3-Цифры по возрастанию
#include <stdio.h>

void digit_f3(char *str);
int main() {
    char num[1000] = "";
    scanf("%s", num);
    digit_f3(num);

    return 0;
} 

void digit_f3(char *str)
{
    int digit_counter[10] = {0};
    int i =0;
    do
    {
        //printf("%d",num%10);
        digit_counter[str[i]-'0']++;

    } while (str[i++]!='\0');

    for (int i = 0; i < 10; i++)
    {
        if(digit_counter[i])
            printf("%d %d\n",i,digit_counter[i]);
    }
}