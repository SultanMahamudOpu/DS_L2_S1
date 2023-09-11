#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct STACK stack;
int cnt = 0;

struct STACK{
    int top;
    int size;
    char *array;
};

bool is_empty(stack *s){
    if (s->top == -1)
        return true;
    return false;
}

bool is_full(stack *s){
    if (s->top == s->size - 1)
        return true;
    return false;
}

void PUSH(stack *s, char val){
    if (is_full(s)){
        printf("Stack is full!!!");
        return;
    }
    s->top++;
    cnt++;
    s->array[s->top] = val;
}

void POP(stack *s){
    if (is_empty(s)){
        printf("Stack is under flow!!!");
        return;
    }
    s->top--;
    cnt--;
}

int SIZE(){
    return cnt;
}

char TOP(stack *s){
    return s->array[s->top];
}

int precedence(char ch){
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

bool is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}