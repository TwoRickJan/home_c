//Заглавные буквы в строчные
//Дан текст состоящий из английских букв и цифр, 
//заканчивается символом «.» Перевести все заглавные английские буквы в строчные.

//Input format
//Текст из маленьких, больших английских букв и пробелов. В конце текста символ точка.

//Output format
//Текст из маленьких английских букв.


#include <stdio.h>

int main() {
    char c;
    while((c = getchar())!='.')//спецсимвол строки
        if(c>='A' && c<='Z') //диапазон букв
            putchar('a'+(c-'A'));
        else
            putchar(c);
    return 0;
}