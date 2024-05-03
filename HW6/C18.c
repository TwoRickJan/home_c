//C18-Количество цифр в тексте

#include <stdio.h>

int is_digit(char c)
{
    int i=0;
    while((c = getchar())!='.'){//спецсимвол строки
        if(c>='0' && c<='9'){ //диапазон букв
                i++;}}
    return i;

}

int main() {
    char c;
    
    printf("%d", is_digit(c));
    return 0;
}