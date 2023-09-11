/*
Write a program to evaluate a postfix expression
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack
{
    int items[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, int item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0')
    {
        char token = postfix[i];

        if (isdigit(token))
        {
            push(&stack, token - '0'); // Convert char digit to integer
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (token)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by zero is not allowed\n");
                    exit(1);
                }
                result = operand1 / operand2;
                break;
            }

            push(&stack, result);
        }
        i++;
    }

    if (!isEmpty(&stack) && stack.top == 0)
    {
        return stack.items[0];
    }
    else
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main()
{
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
