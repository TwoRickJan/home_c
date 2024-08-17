//Распоковать порядок
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int extractExp(float num)
{
    union {
        float    fl;
        unsigned long int dw;
    } f;
    f.fl = num;
    int e = ( f.dw >> 23 ) & 0xFF;
    return e;
}


int main()
{
    float num = 3.99999;
    printf("%d",extractExp(num));


    return 0;
}

