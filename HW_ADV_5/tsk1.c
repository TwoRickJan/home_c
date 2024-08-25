#include <stdio.h>
#include <string.h>
void printa(int *array, int a_size)
{
    //int len = sizeof(array)/sizeof(int);
    for(int j = 0; j < a_size; j++) 
    {
        printf("%d  ", array[j]);
    }
    printf("\n");
}

void f1(int *a,int size)
{
    int SUM = 0;
    for(int i = 0;i<size;i++){
        if(a[i]!=0)
            SUM++;
    }
    printf("%d",SUM);
}

void f2(int *a,int size)
{
        
        //ЗАМНА ВСЕХ ПОВТОРОК НА НУЛИ '0'//
        
        for(int i = 0;i<size;i++){
        //a[i]
        //printf("i\n");
        for(int j = i+1;j<size;j++)
            if(a[j]==a[i]){
                //printf("%d == %d ",a[i],a[j]);
                a[i] = 0;
                break;
            }
    }
}




void cnk(char *str) {
    int n = strlen(str);
    int a[400];
    int ii = 0;
    int cnt = 0;
    if(n<3)return;
    
    for(int i = 0;i<n-2;i++)
    {
        if(str[i] == '0')continue;
        for(int j = i + 1;j<n-1;j++)
            for(int k = j + 1;k<n;k++)
            {
                
                a[ii] = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0');
                /*ТУТ НУЖНО УЮРАТЬ ПОВТОРЫ*/
                //printf("%d\n",a[ii]);
                /*-----------------------*/    
                
                ii++;
            }
    }
    
    //printa(a, ii);
    f2(a, ii);
    //printa(a, ii);
    f1(a, ii);
}


int main()
{
    char str[30];
    scanf("%10[1-9]s",str);
    cnk(str);
	return 0;
}