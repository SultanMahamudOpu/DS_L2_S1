#include <stdio.h>
#include <string.h>

void replace(char st[], char ch, char rep)
{
    for (int i = 0; st[i] != '\0'; i++)
    {
        if (st[i] == ch)
        {
            printf("%c", rep);
        }
        else
        {
            printf("%c", st[i]);
        }
    }
}

int main()
{
    char st[1000];
    gets(st);
    char ch, rep;
    scanf(" %c", &ch);
    scanf(" %c", &rep);
    replace(st, ch, rep);
}