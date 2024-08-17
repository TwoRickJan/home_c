//Упаковать массив
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
struct pack_array {
long unsigned int array; // поле для хранения упакованного массива из 0 и 1
long unsigned int count0: 8; // счетчик нулей в array
long unsigned int count1: 8; // счетчик единиц в array
};
void array2struct(int a[], struct pack_array *my_pack_array)
{
    my_pack_array->count0 = 0;
    my_pack_array->count1 = 0;
    my_pack_array->array = 0;
    int k = 0;
    for(int i = 31;i>=0;i--){
        
        my_pack_array->array += a[i]*pow(2,k);
        k++;
    }
    
    for(int i = 31;i>=0;i--)
    {
        
        if(a[i] == 0)
        {
            my_pack_array->count0++;
        }
        else if(a[i] == 1)
        {
            my_pack_array->count1++;
        }
        
    }
    printf("my_pack_array.array = %08x\nmy_pack_array.count0 = %d\nmy_pack_array.count1 = %d",my_pack_array->array,my_pack_array->count0,my_pack_array->count1);
}
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
int main()
{
    //1 Считываем кол-во элементов
    //2 В цикле Читаем эдемент и записываем его в список
    int a[32];
    struct pack_array my_pack_array;
    for(int i = 0;i<32;i++){
	    scanf("%d",&a[i]);
	    
    }
    printf("\n");
	 array2struct(a,&my_pack_array);

    return 0;
}
