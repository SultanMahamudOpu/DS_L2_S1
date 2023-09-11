/*
Write a program to develop the second pattern matching algorithm
(Finite Automata based).
*/

#include <stdio.h>
#include <string.h>
#define MAX_CHARS 256

void computeFailureFunction(const char *pattern, int M, int *failure)
{
    int len = 0; // Length of the previous longest prefix suffix

    failure[0] = 0; // The first character always matches with itself

    int i = 1;

    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            failure[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = failure[len - 1];
            }
            else
            {
                failure[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform pattern matching using Finite Automaton
void finiteAutomatonSearch(const char *text, const char *pattern)
{
    int M = strlen(pattern);
    int N = strlen(text);

    int failure[M]; // Failure function (partial match table)

    computeFailureFunction(pattern, M, failure);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            printf("Pattern found at index %d\n", i - j);
            j = failure[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = failure[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Matching positions:\n");
    finiteAutomatonSearch(text, pattern);

    return 0;
}
