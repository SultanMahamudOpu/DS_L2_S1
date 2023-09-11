#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int cnt = 0;

typedef struct QUEUE queue;

struct QUEUE
{
    int front;
    int rear;
    int size;
    int *array;
};

bool empty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return true;
    }

    return false;
}

bool is_full(queue *q)
{
    if (q->rear == q->size - 1)
    {
        return true;
    }
    return false;
}

void PUSH(queue *q, int val)
{
    if (is_full(q))
    {
        printf("Queue is Overflow!!!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    cnt++;
    q->array[q->rear] = val;
}

void POP(queue *q)
{
    if (empty(q))
    {
        printf("Queue is Underflow!!!\n");
        return;
    }

    q->front++;
    cnt--;
    if (q->front == q->rear + 1)
    {
        q->front = -1;
        q->rear = -1;
    }
}

int TOP(queue *q)
{
    return q->array[q->front];
}

int SIZE()
{
    return cnt;
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = 1e3;
    q->array = (int *)malloc(q->size * sizeof(int));

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        PUSH(q, a);
    }
    printf("%d\n", SIZE());
    while (!empty(q))
    {
        printf("%d ", TOP(q));
        POP(q);
    }
}