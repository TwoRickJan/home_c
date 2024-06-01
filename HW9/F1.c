void sort_array(int size, int a[])
{
   int i,j,tmp;
   
   for(i = 0;i < size - 1;i++)
    for(j = 0;j < size - 1;j++)
      if(a[j] > a[j + 1])
         {
           tmp = a[j];
           a[j]=a[j+1];
           a[j+1]=tmp;
         }

}