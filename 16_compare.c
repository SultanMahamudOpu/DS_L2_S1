#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool compare(char st_1[], char st_2[])
{
    if (strlen(st_1) != strlen(st_2))
    {
        return false;
    }
    else
    {
        for (int i = 0; st_1[i] != '\0'; i++)
        {
            if (st_1[i] != st_2[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char st_1[1000];
    char st_2[1000];
    gets(st_1);
    gets(st_2);

    if (compare(st_1, st_2))
    {
        printf("Two string are same\n");
    }
    else
    {
        printf("String are not same\n");
    }
}