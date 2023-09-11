#include <stdio.h>
#include <string.h>

void reverse(char st[])
{
    for (int i = strlen(st) - 1; i >= 0; i--)
    {
        printf("%c", st[i]);
    }
}

int main()
{
    char st[1000];
    gets(st);
    reverse(st);
}