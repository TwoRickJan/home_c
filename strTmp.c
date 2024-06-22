
#include <stdio.h>
#define SIZE 1000



int main()
{
    char str[SIZE] = "";
    char str1[SIZE] = "";
    scanf("%s[^.]", str);
    int i = 0, j = 0,cnt = 0;
    do
    {
       if (str[i]==str[i+1])
            cnt++;
        else 
           { str1[j++]=str[i];
            str1[j++]=cnt+'0';
            cnt = 0;}
        i++;
    } while (str[i]!='.');

    printf("%s",str1);


    return 0;

}