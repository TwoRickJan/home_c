int find_max_array(int size, int a[])
{
    int max = -2147483648;
    for (int i = 0; i < size; i++)
            if (max <= a[i])
                max = a[i];
    return max;
}