#include <stdio.h>
#include <stdlib.h>

// перевыделение памяти на кажое число,. массив растет
int main()
{
  int input;
  int counter = 0;                                     // счетчик введенных чисел
  int * values = NULL;
  int * many_numbers;

 
  do {
     //printf("input int num (0 - exit): ");
     scanf("%d",&input);
     counter++;
 
     many_numbers = (int*) realloc (values, counter * sizeof(int)); // при добавлении нового числа, увеличиваем массив на 1
 
     if (many_numbers != NULL)
     {
       values = many_numbers;
       values[counter - 1] = input;                      // добавить к массиву только что введённое число
     }
     else
     {
       free (values);               // удалить массив
       printf("memory error");                    
       exit (1);                                          // завершить работу программы
     }

     
  } while (input != 0);                                   // пока не введён 0
    printf("/n");
  printf("Input number is: ");
  for (int ix = 0; ix < counter; ix++) 
    printf("%d ",values[ix]);

  free (values);                                         // удалить массив
 
  return 0;
}