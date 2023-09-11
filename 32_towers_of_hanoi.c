#include <stdio.h>

void tower(int n, char beg, char aux, char end)
{
    if (n <= 0)
    {
        printf("Illegal entry\n");
    }
    else if (n == 1)
    {
        printf("move to disc from %c to %c\n", beg, end);
    }
    else
    {
        tower(n - 1, beg, end, aux);
        tower(1, beg, aux, end);
        tower(n - 1, aux, beg, end);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char a, b, c;
    tower(n, 'a', 'b', 'c');
}

// 2^n-1