#include <stdio.h>

void marge_array(int array_1[], int array_2[], int n, int m)
{
    int a = n + m;
    int marge[a];
    for (int i = 0; i < n; i++)
    {
        marge[i] = array_1[i];
    }
    for (int i = 0; i < m; i++)
    {
        marge[i + n] = array_2[i];
    }

    for (int i = 0; i < a; i++)
    {
        printf("%d ", marge[i]);
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int array_1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array_1[i]);
    }
    scanf("%d", &m);
    int array_2[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &array_2[i]);
    }

    marge_array(array_1, array_2, n, m);
}