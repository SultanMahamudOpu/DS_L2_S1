#include <stdio.h>

void seive_prime(int n)
{
    int prime[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    seive_prime(n);
}