#include <stdio.h>
#include "stack.h"
char *infix_to_postfix(char *infix)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 1e3;
    s->top = -1;
    s->array = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(TOP(s)))
            {
                PUSH(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = TOP(s);
                POP(s);
                j++;
            }
        }
    }
    while (!is_empty(s))
    {
        postfix[j] = TOP(s);
        POP(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a-b+t/6";
    printf("%s", infix_to_postfix(infix));
}