//C19-Сумма цифр в тексте

#include <stdio.h>

int digit_to_num(char c)
{
    int i=0;
    while((c = getchar())!='.'){//спецсимвол строки
        if(c>='0' && c<='9'){ //диапазон букв
                i+=(c-'0');}}
    return i;

}

int main() {
    char c;
    
    printf("%d", digit_to_num(c));
    return 0;
}