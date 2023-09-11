/*  Stacks using linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void initialize(struct Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);
    return item;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top of stack: %d\n", peek(&stack));

    while (!isEmpty(&stack))
    {
        printf("Popped: %d\n", pop(&stack));
    }

    return 0;
}
