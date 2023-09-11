// Write a program to insert a number at a given location in an array.

#include <stdio.h>

void insert_number(int array[], int size, int pos, int val)
{
    for (int i = size; i >= pos - 1; i--)
    {
        array[i + 1] = array[i];
    }

    array[pos - 1] = val;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int pos, val;
    scanf("%d%d", &pos, &val);
    insert_number(array, n + 1, pos, val);
}