#include <stdio.h>
#include <string.h>
void first_pattern(char st[], char chk[])
{
    for (int i = 0; i <= strlen(st) - strlen(chk); i++)
    {
        int flag = 0;
        for (int j = 0; j < strlen(chk); j++)
        {
            if (st[i + j] != chk[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("Index: %d\n", i + 1);
    }
}

int main()
{
    char st[1000];
    char chk[1000];
    gets(st);
    gets(chk);
    first_pattern(st, chk);
}