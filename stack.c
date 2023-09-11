#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int cnt = 0;
typedef struct STACK stack;
struct STACK
{
    int top;
    int size;
    int *array;
};

bool empty(stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

bool is_full(stack *s)
{
    if (s->top == s->size - 1)
        return true;
    return false;
}

void PUSH(stack *s, int val)
{
    if (is_full(s))
    {
        printf("Stack is Overflow!!!\n");
        return;
    }
    s->top++;
    cnt++;
    s->array[s->top] = val;
}

void POP(stack *s)
{
    if (empty(s))
    {
        printf("Stack is Underflow!!!\n");
        return;
    }
    s->top--;
    cnt--;
}

int TOP(stack *s)
{
    return s->array[s->top];
}

int SIZE()
{
    return cnt;
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = 1e3;
    s->array = (int *)malloc(sizeof(int));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        PUSH(s, a);
    }
    printf("%d\n", SIZE());
    while (!empty(s))
    {
        printf("%d ", TOP(s));
        POP(s);
    }
}