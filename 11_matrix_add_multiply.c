#include <stdio.h>
int matrix[100][100];
int matrix_1[100][100];
int matrix_2[100][100];
void set_matrix(int n, int m)
{
    printf("Enter 1st matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix_1[i][j]);
    }
    printf("Enter 2nd matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix_2[i][j]);
    }
}
void add_matrix(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
    printf("The sum of two martix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void mul_matrix(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < n; k++)
                matrix[i][j] = matrix[i][j] + matrix_1[i][j] * matrix_2[i][j];
        }
    }
    printf("Multipation of two martix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Enter row and column: ");
    scanf("%d%d", &n, &m);
    set_matrix(n, m);
    add_matrix(n, m);
    mul_matrix(n, m);
}