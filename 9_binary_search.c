#include <stdio.h>
#include <stdbool.h>

bool binary_search(int array[], int n, int val)
{
    int l_bound, up_bound, mid;
    l_bound = 0;
    up_bound = n - 1;

    while (l_bound <= up_bound)
    {
        mid = (l_bound + up_bound) / 2;
        if (array[mid] == val)
        {
            return true;
        }
        else if (array[mid] > val)
        {
            up_bound = mid - 1;
        }
        else if (array[mid] < val)
        {
            l_bound = mid + 1;
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
    if (binary_search(array, n, val))
    {
        printf("Value found\n");
    }
    else
    {
        printf("Value not found\n");
    }
}