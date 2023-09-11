#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct CircularQueue
{
    int items[MAX_SIZE];
    int front, rear;
};

void initialize(struct CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct CircularQueue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct CircularQueue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
}

int dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    return item;
}

int peek(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->items[queue->front];
}

int main()
{
    struct CircularQueue queue;
    initialize(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("Front of queue: %d\n", peek(&queue));
    while (!isEmpty(&queue))
        printf("Dequeued: %d\n", dequeue(&queue));
}