#include <stdio.h>
#include <string.h>

void insert_string(char st[], char insert[], int pos)
{
    char final[100];

    for (int i = 0; i < strlen(st); i++)
    {
        final[i] = st[i];
    }

    for (int i = strlen(st) + strlen(insert) - 1; i >= pos - 1; i--)
    {
        final[i] = final[i - strlen(insert)];
    }

    for (int i = 0; i < strlen(insert); i++)
    {
        final[i + pos - 1] = insert[i];
    }

    int size = strlen(st) + strlen(insert);
    final[size] = '\0';
    puts(final);
}

int main()
{
    char st[100];
    char insert[100];

    gets(st);
    gets(insert);
    int pos;
    scanf("%d", &pos);

    insert_string(st, insert, pos);
}