#include <stdio.h>
#include <string.h>

void concatenate(char st_1[], char st_2[])
{
    char string[strlen(st_1) + strlen(st_2)];

    for (int i = 0; st_1[i] != '\0'; i++)
    {
        string[i] = st_1[i];
    }
    for (int i = 0; st_2[i] != '\0'; i++)
    {
        string[i + strlen(st_1)] = st_2[i];
    }
    string[strlen(st_1) + strlen(st_2)] = '\0';

    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c", string[i]);
    }
}

int main()
{
    char st_1[1000], st_2[1000];
    gets(st_1);
    gets(st_2);

    concatenate(st_1, st_2);
}