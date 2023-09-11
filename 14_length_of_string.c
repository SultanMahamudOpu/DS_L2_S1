#include <stdio.h>
#include <string.h>

int length(char string[])
{
    int size = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}

int main()
{
    char string[1000];
    gets(string);
    int size = length(string);

    printf("%d \n", size);
}