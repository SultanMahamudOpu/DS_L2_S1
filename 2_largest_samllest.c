#include <stdio.h>

int largest_element(int array[], int size)
{
    int mx = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] > mx)
        {
            mx = array[i];
        }
    }
    return mx;
}

int smallest_element(int array[], int size)
{
    int mn = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] < mn)
        {
            mn = array[i];
        }
    }
    return mn;
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
    int largest = largest_element(array, n);
    int smallest = smallest_element(array, n);

    printf("Largest element is: %d\nSmallest element is:%d\n", largest, smallest);
}