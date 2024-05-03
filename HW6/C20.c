//C20 - Проверка закрытия скобок
// сумма открытых = сумма закрытых

#include <stdio.h>

int main(){
    int i = 0,j=0,k=0;;
    char c;
    char save_c = '0';
    int flag=0;

    while((c = getchar())!='.'){//спецсимвол строки
        if(c==')') //диапазон букв
        {   //putchar(c);
            i++;}
        else if(c=='(')
        {
            //putchar(c);
            j++;
        }
        if (save_c ==')' && c == '(' && flag == 1 && k == 1)
        {
            printf("NO");
            return 0;
        }
        
        save_c = c;
        k++;
        flag = 1;
    }
        
    //printf("%d\n",i);
    //printf("%d\n",j);
   
    
    if (i==j)
    {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
    }
