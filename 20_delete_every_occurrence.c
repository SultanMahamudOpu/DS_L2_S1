#include <stdio.h>
#include <string.h>

void delete_every_occurence(char st[], char ch)
{
    for (int i = 0; st[i] != '\0'; i++)
    {
        if (st[i] != ch)
        {
            printf("%c", st[i]);
        }
    }
}

int main()
{
    char st[1000];
    gets(st);
    char ch;
    scanf("%c", &ch);
    delete_every_occurence(st, ch);
}