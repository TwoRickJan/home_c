void sort_even_odd(int size, int a[])
{
    int tmp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
        {
            tmp = a[j];
            if (tmp % 2 != 0 && a[j + 1] % 2 == 0)
            {
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
}