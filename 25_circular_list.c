#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list node;

struct list
{
    int data;
    node *next;
};

node *creat_new_node(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
}

node *insertion_at_head(node *head, int val)
{
    node *new_node = creat_new_node(val);

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        return head;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new_node->next = head;
    head = new_node;
    temp->next = head;

    return head;
}

node *insertion_at_tail(node *head, int val)
{
    node *new_node = creat_new_node(val);

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        return head;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = head;

    return head;
}

node *deletiong_at_head(node *head)
{
    if (head == NULL)
    {
        printf("Underflow!!!\n");
        return head;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;

    return head;
}

node *deletiong_at_tail(node *head)
{
    if (head == NULL)
    {
        printf("Underflow!!!\n");
        return head;
    }

    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    temp->next = head;

    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

int main()
{
    node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        // head = insertion_at_head(head, a);
        head = insertion_at_tail(head, a);
    }

    // head = deletiong_at_head(head);
    // head = deletiong_at_tail(head);

    display(head);
}