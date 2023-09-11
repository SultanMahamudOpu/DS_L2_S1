#include <stdio.h>
void insertion_sort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (array[j] > key && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    insertion_sort(array, n);
}