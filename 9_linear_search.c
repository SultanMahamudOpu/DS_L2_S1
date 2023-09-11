#include <stdio.h>
#include <stdbool.h>

bool linear_search(int array[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == val)
        {
            return true;
        }
    }
    return false;
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

    int val;
    scanf("%d", &val);
    if (linear_search(array, n, val))
    {
        printf("Value found\n");
    }
    else
    {
        printf("Value not found\n");
    }
}