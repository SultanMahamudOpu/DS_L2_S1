#include <stdio.h>

int sum_of_diagonal(int n, int m)
{
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = sum_of_diagonal(n, m);

    printf("Sum of Diagonal element: %d\n", sum);
}