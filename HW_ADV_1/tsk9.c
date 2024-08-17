
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    //1 Считываем кол-во элементов
    //2 В цикле Читаем эдемент и записываем его в список
    int M = 8;
    
	scanf("%d",&M);
    int K;
    int k = 0;
    while(K<M) {
       K=(pow(3,k)-1)/2;
        k++;
    }

    int dec = K+M;
    int x;
    int left = M;
    int right = 0;
    int i = 0;
    int cnt = 0;
    while(dec!=0)
    {
        x = dec % 3;
        dec /= 3;
        if (x < 0)
            dec += 1;
        if (x < 0)
            printf("%d",x + (3 * -1));
        else
        {
            if(x == 0){//left with M
                left+=pow(3,i);
                //printf("%d C mass\n",(int)(pow(3,i)));
                cnt++;}
            else if(x == 2){//reigt
                right+=pow(3,i);
               //printf("%d Без\n",(int)(pow(3,i)));
                cnt++;}
            else if(x == 1){
               // printf("%d Неучаствует\n",(int)(pow(3,i)));
            }
        }
        i++;
    }
    if(left==right){
        printf("%d",cnt);
        return 0;
    }
    printf("%d",-1);
    return 0;
}


