//D6-Строка наоборот

#include <stdio.h>
void reverse_string()
{
    char c;
    if((c=getchar()) != '.')
    {
        
        reverse_string();
        putchar(c);
    }
    return;
    

}

int main(void){
    //int num;
    reverse_string();
    

    return 0;
}