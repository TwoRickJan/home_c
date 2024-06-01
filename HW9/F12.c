void change_max_min(int size, int a[])
{
    int min_i, max_i, min_1, max_2;
    max_2 = a[0];
    min_1 = a[0];
    for (int i = 0; i < size; i++)
    {
        if (min_1 > a[i])
        {
            min_i = i;
            min_1 = a[i];
        }
        if (max_2 < a[i])
        {
            max_i = i;
            max_2 = a[i];
        }
    }
    min_1 = a[min_i];
    a[min_i] = a[max_i];
    a[max_i] = min_1;
}