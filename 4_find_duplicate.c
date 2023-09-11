#include <stdio.h>
#include <stdbool.h>

bool duplicate(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                return true;
            }
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

    if (duplicate(array, n))
    {
        printf("Find Duplicate\n");
    }
    else
    {
        printf("No Duplicate found\n");
    }
}