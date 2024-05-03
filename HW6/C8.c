#include <stdio.h>
void func(){
    char c;
    while((c = getchar())!='.')//спецсимвол строки
        if(c>='a' && c<='z') //диапазон букв
            putchar('A'+(c-'a'));
        else
            putchar(c);

}
int main() {
    func();
    return 0;
}