#include <stdio.h>
#include <string.h>

void extract_substring(char st[], int pos, int size)
{
    for (int i = pos - 1; i < (pos + size) - 1; i++)
    {
        printf("%c", st[i]);
    }
}

int main()
{
    char st[1000];
    gets(st);
    int pos, size;
    scanf("%d%d", &pos, &size);
    extract_substring(st, pos, size);
}
