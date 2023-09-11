#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack
{
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    initialize(&stack);
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        char token = infix[i];
        if (isalnum(token))
            postfix[j++] = token; // Append operands to postfix
        else if (token == '(')
            push(&stack, token);
        else if (token == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                postfix[j++] = pop(&stack); // Pop operators until '('
            if (!isEmpty(&stack) && peek(&stack) != '(')
            {
                printf("Mismatched parentheses\n");
                exit(1);
            }
            else
                pop(&stack); // Pop '('
        }
        else
        { // Operator encountered
            while (!isEmpty(&stack) && precedence(token) <= precedence(peek(&stack)))
                postfix[j++] = pop(&stack); // Pop higher precedence operators
            push(&stack, token);            // Push the current operator
        }
        i++;
    }
    while (!isEmpty(&stack))
    {
        char op = pop(&stack);
        if (op == '(')
        {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = op; // Append remaining operators to postfix
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}
