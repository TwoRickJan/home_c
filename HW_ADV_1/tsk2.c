/* Шифр Цзаря p = mod((n+N),K)
 */

#include <stdio.h>

int main()
{
    int n = 0;
    int flag = 0;
    char c;
    int K = 'z'-'a';
    
    scanf("%d",&n);
    c=getchar();
    while((c=getchar())!='.')
    {
        if((c>='a')&&(c<='z'))
            printf("%c",(((c-'a')+n)%K)+'a');
        else if((c>='A')&&(c<='Z'))
            printf("%c",(((c-'A')+n)%K)+'A');
    }
    putchar(c);
	return 0;
}
